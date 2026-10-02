#include <undertale/objects/time.hpp>


Undertale::ObjTime::ObjTime(std::string_view filename) : Undertale::Instance::Instance(filename) {
	LoadBasicInstance(false);
}


void Undertale::ObjTime::ProcessPlrInput() {

	if (IsKeyDown(Undertale::UpKey)) {
		up = true;
	} else {
		up = false;
	}
	if (IsKeyDown(Undertale::DownKey)) {
		down = true;
	} else {
		down = false;
	}
	if (IsKeyDown(Undertale::LeftKey)) {
		left = true;
	} else {
		left = false;
	}
	if (IsKeyDown(Undertale::RightKey)) {
		right = true;
	} else {
		right = false;
	}

}


void Undertale::ObjTime::Update(float deltaTime, void* arg) {

	ProcessPlrInput();	

}

