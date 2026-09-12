#include <undertale/room.hpp>
#include <iostream>


Undertale::Room::Room(const std::vector<Undertale::Tile>& tiles, const std::vector<Undertale::Instance*>& instances, const std::vector<Undertale::Instance*>& solidInstances, Undertale::Sheets& textureSheets, int mainCharaIdx) : sheets(textureSheets) {

	this->tiles = tiles;
	this->instances = instances;
	this->solidInstances = solidInstances;
	camera.zoom = 2.0f;

	if (mainCharaIdx < 0) {
		return;
	}

	std::cout << "storing the player\n";
	plr = static_cast<ObjMainChara*>(instances[mainCharaIdx]);
	camera.target = plr->position;

}


Undertale::Room::~Room() {

	for (Instance* inst : instances) {
		delete inst;
	}

}


std::vector<Undertale::Tile> Undertale::Room::GetTiles() const {
	return tiles;
}


void Undertale::Room::Update(float deltaTime) {

	for (Undertale::Instance* inst : instances) {
		inst->Update(deltaTime);
	}
	for (Undertale::Instance* inst : solidInstances) {
		inst->Update(deltaTime);
	}

	if (plr == nullptr) { return; };
	plr->Update(deltaTime, this);
	camera.target.x = plr->position.x - (GetScreenWidth() / 2) / camera.zoom;
	camera.target.y = plr->position.y - (GetScreenHeight() / 2) / camera.zoom;
	camera.target.x += static_cast<int>(19.0f / 2.0f);
	camera.target.y += static_cast<int>(29.0f / 2.0f);

}


void Undertale::Room::Draw() {

	for (Undertale::Tile& tile : tiles) {
		Undertale::DrawTile(tile, sheets);
	}
	for (Undertale::Instance* inst : instances) {
		Undertale::DrawInstance(*inst, sheets);
	}
	for (Undertale::Instance* inst : solidInstances) {
		Undertale::DrawInstance(*inst, sheets);
	}

}


Camera2D& Undertale::Room::GetCamera() {
	return camera;
}


std::vector<Undertale::Instance*>& Undertale::Room::GetMainInstances() {
	return instances;
}


std::vector<Undertale::Instance*>& Undertale::Room::GetSolidInstances() {
	return solidInstances;
}


Undertale::Sheets& Undertale::Room::GetSheetloader() {
	return sheets;
}


Undertale::Room Undertale::LoadRoomFromFile(std::string_view filename, Undertale::Sheets& sheets) {

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename.data());
	if (result.status != pugi::xml_parse_status::status_ok) {
		std::cerr << result.description() << '\n';
		std::exit(1);
	}

	//std::cout << "----Loading Tiles----\n";
	std::vector<Undertale::Tile> tiles = { };

	for (pugi::xml_node node : doc.child("room").child("tiles").children()) {

		Vector2 pos = { node.attribute("x").as_float(), node.attribute("y").as_float() };
		Vector2 origin = { node.attribute("xo").as_float(), node.attribute("yo").as_float() };
		Vector2 size = { node.attribute("w").as_float(), node.attribute("h").as_float() };
		std::string sheetName = node.attribute("bgName").as_string();
		tiles.push_back({ sheetName, pos, origin, size });

	}

	//std::cout << "----Loading Instances----\n";
	
	int mainCharaIdx = -1;

	std::vector<Undertale::Instance*> instances = { };
	std::vector<Undertale::Instance*> solidInstances = { };
	size_t instanceIdx = 0;
	size_t solidIdx = 0;
	for (pugi::xml_node node : doc.child("room").child("instances").children()) {

		std::string objName = node.attribute("objName").as_string();
	
		Undertale::Instance* inst = Undertale::CreateInstanceFromObjName(objName);
		if (inst == nullptr) { continue; }
		inst->position = { node.attribute("x").as_float(), node.attribute("y").as_float() };


		if (objName == "obj_mainchara") {
			mainCharaIdx = instanceIdx;
		}

		if (!inst->IsSolid()) {
			instances.push_back(inst);
			instanceIdx++;
		} else {
			solidInstances.push_back(inst);
			solidIdx++;
			std::cout << "Added " << objName << " to solidInstances\n";
		}

	}

	return Undertale::Room(tiles, instances, solidInstances, sheets, mainCharaIdx);

}



