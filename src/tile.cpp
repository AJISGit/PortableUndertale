#include <undertale/tile.hpp>


void Undertale::DrawTile(const Undertale::Tile &tile, Sheets& sheet) {

	Texture2D textureSheet = sheet.GetSheet(tile.sheetName);

	DrawTextureRec(textureSheet, { tile.origin.x, tile.origin.y, tile.size.x, tile.size.y }, tile.position, WHITE);

}

