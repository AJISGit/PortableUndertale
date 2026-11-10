#include <undertale/undertale.hpp>
#include <undertale/objects/time.hpp>
#include <undertale/animmanager.hpp>


Music* Undertale::currentSong = nullptr;
#ifndef NDEBUG
bool Undertale::debug = true;
#else
bool Undertale::debug = false;
#endif

std::vector<std::string> Undertale::msg(6);
void Undertale::SetMessage(size_t idx, std::string_view message) {
	
	if (idx > Undertale::msg.capacity() - 1) {
		msg.push_back(message.data());
		return;
	}
	msg[idx] = message.data();

}

Undertale::ObjTime Undertale::objTimeInst = Undertale::ObjTime();
Undertale::AnimationManager Undertale::animManager = Undertale::AnimationManager();

