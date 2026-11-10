#pragma once
#include <undertale/instance.hpp>
#include <raylib.h>


namespace Undertale {

	class ObjBaseWriter : public Instance {

		public:

		// I'm not completely sure about some of these data types.
		Font* myFont = nullptr;
		Color myColor = { };
		float writingX = 0.0f;
		float writingY = 0.0f;
		float writingXEnd = 0.0f;
		float writingXEndBase = 0.0f;
		bool shake = false;
		float textSpeed = 0.0f;
		Sound* txtSound = nullptr;
		float spacing = 0.0f;
		float vSpacing = 0.0f;
		bool vText = false;
		float hTextScale = 1.0f;
		float vTextScale = 1.0f;

		// Especially these ones.
		int stringno = 0;
		float stringpos = 0;
		int halt = 0;
		bool dfy = 0; // What does this mean?
		bool sound_enable = true;

		// Nice name pick toby! This name is totally not misleading at all!
		std::vector<std::string> myString;

		std::string originalString = "";
		

		ObjBaseWriter(std::string_view filename = "obj_base_writer");		

	};

}

