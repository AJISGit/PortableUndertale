#include <undertale/instance.hpp>
#include <undertale/objects/spiketile1.hpp>
#include <undertale/objects/ruinsmusic.hpp>
#include <undertale/objects/mainchara.hpp>
#include <undertale/objects/introimage.hpp>
#include <undertale/supportedinstances.hpp>

#include <pugixml.hpp>
#include <iostream>

const std::unordered_set<const char*> Undertale::supportedObjs = {
//		"obj_ruinsmusic",
		"obj_spiketile1"//, "obj_spiketile2"
};


Undertale::Instance::Instance(std::string_view filename) {
	this->filename = filename;
}


Undertale::Instance::~Instance() {
}


void Undertale::Instance::LoadBasicInstance(bool hasSpriteArg) {

	std::string filepath = Undertale::OBJ_FILEPREFIX + filename + Undertale::OBJ_FILEEXTENSION;
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filepath.c_str());
	if (result.status != pugi::xml_parse_status::status_ok) {
		std::cerr << result.description() << '\n';
		std::exit(1);
	}

	std::string spriteName = doc.child("object").child("spriteName").text().as_string();
	bool isSolid = doc.child("object").child("solid").text().as_int();

	if (isSolid == 0) {
		solid = false;
	} else {
		solid = true;
	}

	if (!hasSpriteArg) { return; }
	sprite = Undertale::LoadSprite(spriteName);
	hasSprite = true;

}


void Undertale::Instance::Update(float deltaTime, void* arg) {
	return;
}


bool Undertale::Instance::HasSprite() const {
	return hasSprite;
}


Undertale::Sprite Undertale::Instance::GetSprite() const {
	return sprite;
}


int Undertale::Instance::GetSpriteFrame() const {
	return spriteFrame;
}


void Undertale::Instance::SetSpriteFrame(int frame) {
	spriteFrame = frame;
}


void Undertale::Instance::IncrementSpriteFrame() {
	SetSpriteFrame(spriteFrame + 1);
}


void Undertale::Instance::DecrementSpriteFrame() {
	SetSpriteFrame(spriteFrame - 1);
}


void Undertale::DrawInstance(Undertale::Instance &inst, Undertale::Sheets& sheets) {

	if (!inst.HasSprite()) { return; }
	Undertale::DrawSprite(inst.GetSprite(), inst.position, inst.GetSpriteFrame(), sheets);

}


Undertale::Instance* Undertale::CreateInstanceFromObjName(std::string_view objName) {

	if (objName == "obj_spiketile1") {
		return new Undertale::ObjSpiketile1();
	} else if (objName == "obj_spiketile2") {
		return new Undertale::ObjSpiketile2();
	} else if (objName == "obj_ruinsmusic") {
		return new Undertale::ObjRuinsMusic();
	} else if (objName == "obj_mainchara") {
		return new Undertale::ObjMainChara();
	} else if (objName == "obj_introimage") {
		return new Undertale::ObjIntroImage();
	}

	return nullptr;	

}


bool Undertale::Instance::IsSolid() const {
	std::cout << "Is Solid: " << solid << '\n';
	return solid;
}

