#pragma once
#include <undertale/sheetloader.hpp>

#include <raylib.h>
#include <vector>
#include <string_view>
#include <cstdint>


namespace Undertale {

	struct BBox {

		float left;
		float right;
		float top;
		float bottom;

	};

	struct Sprite {

		std::vector<std::string> frames = { };
		Vector2 size = { };
		BBox bbox = { };
		

	};

	Sprite LoadSprite(std::string_view spriteName);
	void DrawSprite(const Sprite& sprite, Vector2 position, int frame, Sheets& sheets);

}
