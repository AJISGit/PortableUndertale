#pragma once
#include <undertale/sheetloader.hpp>
#include <undertale/sprite.hpp>
#include <string>


namespace Undertale {

	constexpr char OBJ_FILEPREFIX[] = "GameData/objects/";
	constexpr char OBJ_FILEEXTENSION[] = ".object.gmx";

	class Instance {

		private:
		int spriteFrame = 0;
		bool solid = false;

		protected:
		std::string filename;
		void LoadBasicInstance(bool hasSprite = true);
		Sprite sprite = { };
		bool hasSprite = false;

		public:

		Vector2 position = { };

		Instance(std::string_view filename = "NO_FILE_PLACEHOLDER");
		virtual ~Instance();
		virtual void Update(float deltaTime, void* arg = nullptr);

		bool HasSprite() const;
		Sprite GetSprite() const;

		int GetSpriteFrame() const;
		void SetSpriteFrame(int frame);
		void IncrementSpriteFrame();
		void DecrementSpriteFrame();

		bool IsSolid() const;

	};

	// You have to delete it yourself.
	Instance* CreateInstanceFromObjName(std::string_view objName);
	void DrawInstance(Instance& inst, Sheets& sheets);

}

