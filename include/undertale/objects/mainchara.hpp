#pragma once
#include <undertale/instance.hpp>


namespace Undertale {

	class ObjMainChara : public Instance {

		public:
		ObjMainChara(std::string_view filename = "obj_mainchara");
		virtual void Update(float deltaTime, void* arg = nullptr) override;

	};

}

