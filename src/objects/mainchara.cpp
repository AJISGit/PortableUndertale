#include <undertale/objects/mainchara.hpp>
#include <undertale/objects/time.hpp>
#include <undertale/room.hpp>


Undertale::ObjMainChara::ObjMainChara(std::string_view filename) : Undertale::Instance::Instance(filename) {
	LoadBasicInstance();
	upSprite = LoadSprite("spr_maincharau");
	downSprite = LoadSprite("spr_maincharad");
	leftSprite = LoadSprite("spr_maincharal");
	rightSprite = LoadSprite("spr_maincharar");
}


void Undertale::ObjMainChara::Update(float deltaTime, void* arg) {

	if (arg == nullptr) {
		return;
	}

	Undertale::Room* room = reinterpret_cast<Undertale::Room*>(arg);
	std::vector<Instance*>& solidInstances = room->GetSolidInstances();
	Undertale::Sheets& sheetloader = room->GetSheetloader();

	// ---- Movement code ----
	constexpr float speed = 50.0f;
	Vector2 lastPos = position;

	if (Undertale::objTimeInst.left) {
		position.x -= speed * deltaTime;
	}
	if (Undertale::objTimeInst.up) {
		position.y -= speed * deltaTime;
	}
	if (Undertale::objTimeInst.right) {
		position.x += speed * deltaTime;
	}
	if (Undertale::objTimeInst.down) {
		position.y += speed * deltaTime;
	}

	// ---- Sprite code ----

	if (Undertale::objTimeInst.right) {
		if (sprite != rightSprite) {
			sprite = rightSprite;
		}
	}

	if (Undertale::objTimeInst.left) {
		if (sprite != leftSprite) {
			sprite = leftSprite;
		}
	}

	if (Undertale::objTimeInst.up) {
		if (sprite != upSprite) {
			sprite = upSprite;
		}
	}

	if (Undertale::objTimeInst.down) {
		if (sprite != downSprite) {
			sprite = downSprite;
		}
	}

	// ---- Collision code ----
	Vector2 pos = position;
	pos.y += 19.0f;//GetSprite().size.y;
	Rectangle plrRect = { pos.x + 2, pos.y + 15, 16, 14 };

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

		if (CheckCollisionRecs(plrRect, instRect)) {
			position = lastPos;
			break;
		}

	}

}

