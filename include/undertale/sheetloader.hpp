#pragma once
#include <raylib.h>
#include <unordered_map>
#include <string>
#include <string_view>


namespace Undertale {

	enum class SheetType { Bg, Sprite };

	class Sheets final {

		private:
		std::unordered_map<std::string, Texture2D> sheets;

		public:
		Texture2D GetSheet(std::string_view name, SheetType type = SheetType::Bg);
		void DeleteSheet(std::string_view name);
		~Sheets();
		

	};

}

