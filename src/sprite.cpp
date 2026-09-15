#include <undertale/sprite.hpp>
#include <pugixml.hpp>
#include <iostream>



Undertale::Sprite Undertale::LoadSprite(std::string_view spriteName) {

	const std::string prefix = "GameData/sprites/";
	std::string filename = prefix + std::string(spriteName) + ".sprite.gmx";

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename.data());
	if (result.status != pugi::xml_parse_status::status_ok) {
		std::cerr << result.description() << '\n';
		std::exit(1);
	}

	Undertale::Sprite sprite = { };

	for (pugi::xml_node node : doc.child("sprite").child("frames").children()) {

		std::string spriteName = node.text().as_string();
		sprite.frames.push_back(spriteName);

	}

	sprite.size.x = doc.child("sprite").child("width").text().as_float();
	sprite.size.y = doc.child("sprite").child("height").text().as_float();

	sprite.bbox.left = doc.child("sprite").child("bbox_left").text().as_float();
	sprite.bbox.right = doc.child("sprite").child("bbox_right").text().as_float();
	sprite.bbox.top = doc.child("sprite").child("bbox_top").text().as_float();
	sprite.bbox.bottom = doc.child("sprite").child("bbox_bottom").text().as_float();

	return sprite;

}


void Undertale::DrawSprite(const Undertale::Sprite &sprite, Vector2 position, int frame, Undertale::Sheets &sheets) {

	Texture2D texture = sheets.GetSheet(sprite.frames[frame], Undertale::SheetType::Sprite);
	Vector2 pos = position;
	pos.x += sprite.bbox.left;
	pos.y += sprite.bbox.top;
	pos.y -= texture.height - sprite.bbox.bottom;
	DrawTextureV(texture, pos, WHITE);

}

