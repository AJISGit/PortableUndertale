#pragma once
#include <raylib.h>


namespace Undertale {

	class ObjTime;

	extern Music* currentSong;
	extern bool debug;
	extern ObjTime objTimeInst;


	constexpr int UpKey = KEY_UP;
	constexpr int DownKey = KEY_DOWN;
	constexpr int LeftKey = KEY_LEFT;
	constexpr int RightKey = KEY_RIGHT;

}

