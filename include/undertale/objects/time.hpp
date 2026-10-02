// This is an implementation of the obj_time object from the undertale src.
// From what I can tell, it isn't necessarily related to keeping track of time. It seems to be just something to control everything.
// See obj_time from the undertale src for more info.
#pragma once
#include <undertale/instance.hpp>


namespace Undertale {

	class ObjTime : public Instance {

		private:
		void ProcessPlrInput();

		public:

		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;

		ObjTime(std::string_view filename = "obj_time");
		virtual void Update(float deltaTime, void* arg = nullptr);

	};

}

