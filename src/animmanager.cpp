#include <undertale/animmanager.hpp>
#include <raylib.h>


void Undertale::AnimationManager::Update() {

	for (AnimInstInfo& instInfo : insts) {

		if (GetTime() - instInfo.timeSinceLastUpdate >= (Undertale::animFrameDelay * (1.0f / instInfo.inst->imageSpeed))) {
			instInfo.inst->IncrementSpriteFrame();
			instInfo.timeSinceLastUpdate = GetTime();
		}

	}

}


size_t Undertale::AnimationManager::AddInst(Undertale::Instance* inst) {
	insts.push_back({ inst, 0.0f });
	return 0;
}


void Undertale::AnimationManager::RemoveInst(size_t idx) {
	insts.erase(insts.begin() + idx);
}

