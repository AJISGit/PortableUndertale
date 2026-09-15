#include <undertale/objects/ruinsmusic.hpp>
#include <iostream>


Undertale::ObjRuinsMusic::ObjRuinsMusic(std::string_view filename) : Undertale::Instance::Instance(filename) {
	std::cout << "Trying music yay\n";
	LoadBasicInstance(false);

	std::cout << "Music yay\n";

	musicStream = LoadMusicStream("GameData/sound/audio/mus_ruins.ogg");
	SetMusicPan(musicStream, 0.0f);
	SetMusicVolume(musicStream, 1.0f);
	PlayMusicStream(musicStream);
	Undertale::currentSong = &musicStream;

}


Undertale::ObjRuinsMusic::~ObjRuinsMusic() {
	Undertale::currentSong = nullptr;
	StopMusicStream(musicStream);
	UnloadMusicStream(musicStream);
}

