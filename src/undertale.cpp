#include <undertale/undertale.hpp>
#include <undertale/objects/time.hpp>


Music* Undertale::currentSong = nullptr;
#ifndef NDEBUG
bool Undertale::debug = true;
#else
bool Undertale::debug = false;
#endif

Undertale::ObjTime Undertale::objTimeInst = Undertale::ObjTime();

