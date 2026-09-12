#pragma once
#include <undertale/sheetloader.hpp>
#include <raylib.h>
#include <string>

namespace Undertale {

	constexpr float TILE_WIDTH = 20.0f;
	constexpr float TILE_HEIGHT = 20.0f;
	constexpr float TILE_SCALE = 4.0f;

	struct Tile {

		std::string sheetName;
		Vector2 position = { 0.0f, 0.0f };
		Vector2 origin = { 0.0f, 0.0f };
		Vector2 size = { };

	};

	void DrawTile(const Tile& tile, Sheets& sheets);

}

