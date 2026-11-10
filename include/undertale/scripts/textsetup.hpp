#pragma once
#include <undertale/objects/basewriter.hpp>


namespace Undertale {
	
	void ScrTextSetup(ObjBaseWriter& writer, Font* font, Color color, float writingX, float writingY, float writingXEnd, bool shake, float textSpeed, Sound* txtSound, float spacing, float vSpacing);

}

