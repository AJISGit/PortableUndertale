#include <undertale/undertale.hpp>
#include <undertale/objects/time.hpp>
#include <undertale/animmanager.hpp>


Music* Undertale::currentSong = nullptr;
#ifndef NDEBUG
bool Undertale::debug = true;
#else
bool Undertale::debug = false;
#endif

Undertale::ObjTime Undertale::objTimeInst = Undertale::ObjTime();
Undertale::AnimationManager Undertale::animManager = Undertale::AnimationManager();

