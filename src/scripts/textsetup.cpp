#include <undertale/scripts/textsetup.hpp>


void Undertale::ScrTextSetup(Undertale::ObjBaseWriter& writer, Font* font, Color color, float writingX, float writingY, float writingXEnd, bool shake, float textSpeed, Sound* txtSound, float spacing, float vSpacing) {

	writer.myFont = font;
	writer.myColor = color;
	writer.writingX = writingX;
	writer.writingY = writingY;
	writer.writingXEnd = writingXEnd;
	writer.writingXEndBase = writingXEnd;
	writer.shake = shake;
	writer.textSpeed = textSpeed;
	writer.txtSound = txtSound;
	writer.spacing = spacing;
	writer.vSpacing = vSpacing;
	writer.vText = false;
	writer.hTextScale = 1.0f;
	writer.vTextScale = 1.0f;

}

