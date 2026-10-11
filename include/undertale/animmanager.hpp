#pragma once
#include <undertale/instance.hpp>
#include <vector>


namespace Undertale {

	// Just for testing. I'll find out how to get the animation fps later.
	constexpr float animFrameDelay = 0.2f;

	class AnimationManager {

		private:

		struct AnimInstInfo {
			Instance* inst = nullptr;
			float timeSinceLastUpdate = 0.0f;
		};
		std::vector<AnimInstInfo> insts = { };

		public:
		
		void Update();
		
		// Returns the index of the instance.
		size_t AddInst(Instance* inst);
		void RemoveInst(size_t idx);

	};

}

