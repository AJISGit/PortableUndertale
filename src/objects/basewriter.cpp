#include <undertale/objects/basewriter.hpp>
#include <undertale/scripts/textsetup.hpp>
#include <cmath>


Undertale::ObjBaseWriter::ObjBaseWriter(std::string_view filename) {
	LoadBasicInstance(false);
	Undertale::ScrTextSetup(*this, nullptr, WHITE, position.x + 20, position.y + 20, position.x + (480 - 55), 1, 1, nullptr, 16, 32);

	position.x = std::round(position.x);
	position.y = std::round(position.y);
	writingX= std::round(writingX);
	writingY = std::round(writingY);
	stringno = 0;
	stringpos = 0;
	halt = 0;
	dfy = 0;
	sound_enable = true;



	myString.reserve(Undertale::msg.capacity());

	for (int n = 0; Undertale::msg[n] != "%%%"; n++) {
	    myString[n] = Undertale::msg[n];
	}

	originalString = myString[0];
}

