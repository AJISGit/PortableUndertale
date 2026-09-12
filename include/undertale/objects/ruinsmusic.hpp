#pragma once
#include <undertale/instance.hpp>
#include <undertale/undertale.hpp>


namespace Undertale {

	class ObjRuinsMusic : public Instance {
	
		private:
		Music musicStream = { };

		public:
		ObjRuinsMusic(std::string_view filename = "obj_ruinsmusic");
		virtual ~ObjRuinsMusic();

	};

}

