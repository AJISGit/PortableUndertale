#pragma once
#include <undertale/tile.hpp>
#include <undertale/instance.hpp>
#include <undertale/objects/mainchara.hpp>
#include <undertale/sheetloader.hpp>
#include <undertale/supportedinstances.hpp>

#include <pugixml.hpp>

#include <string_view>
#include <vector>


namespace Undertale {

	class Room {
		
		private:

		std::vector<Tile> tiles = { };
		std::vector<Instance*> instances = { };
		std::vector<Instance*> solidInstances = { };
		Sheets& sheets;
		Camera2D camera = { };
		ObjMainChara* plr = nullptr;

		public:

		Room(const std::vector<Tile>& tiles, const std::vector<Instance*>& instances, const std::vector<Instance*>& solidInstances, Sheets& sheets, int mainCharaIdx);
		~Room();

		std::vector<Tile> GetTiles() const;

		void Update(float deltaTime);
		void Draw();

		Camera2D& GetCamera();
		std::vector<Instance*>& GetMainInstances();
		std::vector<Instance*>& GetSolidInstances();
		Sheets& GetSheetloader();

	};

	Room LoadRoomFromFile(std::string_view filename, Sheets& sheets);

}

