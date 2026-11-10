#pragma once
#include <raylib.h>
#include <vector>
#include <string>
#include <string_view>


namespace Undertale {

	class ObjTime;
	class AnimationManager;

	extern Music* currentSong;
	extern bool debug;

	extern ObjTime objTimeInst;
	extern AnimationManager animManager;

	extern std::vector<std::string> msg;
	void SetMessage(size_t idx, std::string_view message);


	constexpr int UpKey = KEY_UP;
	constexpr int DownKey = KEY_DOWN;
	constexpr int LeftKey = KEY_LEFT;
	constexpr int RightKey = KEY_RIGHT;

}

