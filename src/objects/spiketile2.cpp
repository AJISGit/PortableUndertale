#include <undertale/objects/spiketile2.hpp>


Undertale::ObjSpiketile2::ObjSpiketile2(std::string_view filename) : Undertale::Instance::Instance(filename) {
	LoadBasicInstance();
	SetSpriteFrame(1);
}

