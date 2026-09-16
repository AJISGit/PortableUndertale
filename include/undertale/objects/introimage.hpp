#pragma once
#include <undertale/instance.hpp>


namespace Undertale {

	class ObjIntroImage : public Instance {

		private:
		float startTime = 1.0f;
		Music musicStream = { };

		public:
		ObjIntroImage(std::string_view filename = "obj_introimage");
		virtual ~ObjIntroImage();
		virtual void Update(float deltaTime, void* arg = nullptr) override;

	};

}

