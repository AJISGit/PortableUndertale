#include <undertale/objects/mainchara.hpp>
#include <undertale/room.hpp>
#include <iostream>


Undertale::ObjMainChara::ObjMainChara(std::string_view filename) : Undertale::Instance::Instance(filename) {
	LoadBasicInstance();
	std::cout << "obj_mainchara sprite size: { " << GetSprite().size.x << ", " << GetSprite().size.y << " }\n";
}


void Undertale::ObjMainChara::Update(float deltaTime, void* arg) {

	if (arg == nullptr) {
		return;
	}

	Undertale::Room* room = reinterpret_cast<Undertale::Room*>(arg);
	std::vector<Instance*>& solidInstances = room->GetSolidInstances();
	Undertale::Sheets& sheetloader = room->GetSheetloader();

	constexpr float speed = 75.0f;
	Vector2 lastPos = position;

	if (IsKeyDown(KEY_LEFT)) {

		position.x -= speed * deltaTime;

	}
	if (IsKeyDown(KEY_RIGHT)) {

		position.x += speed * deltaTime;

	}
	if (IsKeyDown(KEY_DOWN)) {

		position.y += speed * deltaTime;
	}
	if (IsKeyDown(KEY_UP)) {

		position.y -= speed * deltaTime;

	}

	Vector2 pos = position;
	pos.y += 19.0f;//GetSprite().size.y;
	Rectangle plrRect = { pos.x, pos.y, GetSprite().size.x, GetSprite().size.y };

	for (Undertale::Instance* solidInst : solidInstances) {
		Vector2 sprSize = solidInst->GetSprite().size;
		Vector2 instPos = solidInst->position;
		Undertale::Sprite instSpr = solidInst->GetSprite();
		Texture2D texture = sheetloader.GetSheet(instSpr.frames[solidInst->GetSpriteFrame()], Undertale::SheetType::Sprite);

		instPos.x += instSpr.bbox.left;
		instPos.y += instSpr.bbox.top;
		instPos.y -= texture.height - instSpr.bbox.bottom;

		Rectangle instRect = { instPos.x, instPos.y, (float) texture.width, (float) texture.height };
		Color color = { (unsigned char) GetRandomValue(0, 255), (unsigned char) GetRandomValue(0, 255), (unsigned char) GetRandomValue(0, 255), 200 };
//		DrawRectangleLinesEx(instRect, 2.0f, color);
//		DrawRectangleLinesEx(plrRect, 2.0f, BLACK);

		if (CheckCollisionRecs(plrRect, instRect)) {
			std::cout << "Collision time: " << instSpr.frames[solidInst->GetSpriteFrame()] << '\n';
			position = lastPos;
			break;
		}

	}

}

