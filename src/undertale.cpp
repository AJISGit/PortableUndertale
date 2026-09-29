#include <undertale/undertale.hpp>


Music* Undertale::currentSong = nullptr;
#ifndef NDEBUG
bool Undertale::debug = true;
#else
bool Undertale::debug = false;
#endif
