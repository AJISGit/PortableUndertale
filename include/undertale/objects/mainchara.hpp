#pragma once
#include <undertale/instance.hpp>


namespace Undertale {

	class ObjMainChara : public Instance {

		private:
		Sprite upSprite = { };
		Sprite downSprite = { };
		Sprite leftSprite = { };
		Sprite rightSprite = { };

		public:
		ObjMainChara(std::string_view filename = "obj_mainchara");
		virtual void Update(float deltaTime, void* arg = nullptr) override;

	};

}

