#include <undertale/objects/introimage.hpp>
#include <undertale/room.hpp>
#include <undertale/undertale.hpp>
#include <iostream>

Undertale::ObjIntroImage::ObjIntroImage(std::string_view filename) : Undertale::Instance::Instance(filename) {
	LoadBasicInstance();
	SetSpriteFrame(GetSprite().frames.size() - 1);

	musicStream = LoadMusicStream("GameData/sound/audio/mus_story.ogg");
	SetMusicPan(musicStream, 0.0f);
	SetMusicVolume(musicStream, 1.0f);
	SetMusicPitch(musicStream, 0.9f);
	PlayMusicStream(musicStream);
	Undertale::currentSong = &musicStream;
}


Undertale::ObjIntroImage::~ObjIntroImage() {
	Undertale::currentSong = nullptr;
	StopMusicStream(musicStream);
	UnloadMusicStream(musicStream);
}


void Undertale::ObjIntroImage::Update(float deltaTime, void* arg) {

	if (GetSpriteFrame() <= 0) {
		return;
	}

	if (GetTime() - startTime >= 5.0f) {
		startTime = GetTime();
		DecrementSpriteFrame();
	}

}

