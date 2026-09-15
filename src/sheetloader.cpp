#include <undertale/sheetloader.hpp>


Texture2D Undertale::Sheets::GetSheet(std::string_view name, Undertale::SheetType type) {

	if (sheets.find(name.data()) == sheets.end()) {
		
		std::string prefix;

		if (type == Undertale::SheetType::Bg) {
			prefix = "GameData/background/images/";
		} else {
			prefix = "GameData/sprites/";
		}

		std::string filename = prefix + std::string(name);

		if (type == Undertale::SheetType::Bg) {
			filename += ".png";
		}

		sheets[name.data()] = LoadTexture(filename.c_str());
		SetTextureFilter(sheets[name.data()], TEXTURE_FILTER_POINT);
	}

	return sheets[name.data()];

}


void Undertale::Sheets::DeleteSheet(std::string_view name) {
	if (sheets.find(name.data()) == sheets.end()) {
		return;
	}
	UnloadTexture(sheets[name.data()]);
	sheets.erase(name.data());
}


Undertale::Sheets::~Sheets() {
	for (auto& i : sheets) {
		DeleteSheet(i.first);
	}
}

