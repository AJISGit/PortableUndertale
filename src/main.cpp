#include <undertale.hpp>
#include <undertale/undertale.hpp>
#include <undertale/animmanager.hpp>
#include <iostream>


const float cameraSpeed = 200.0f;


int main(int argc, char** argv) {

	SetTraceLogLevel(LOG_WARNING);
	InitWindow(640, 480, "UNDERTALE");
	InitAudioDevice();
	SetTargetFPS(30);
	std::string filename = "room_ruins5";
	if (argc > 1) {
		filename = argv[1];
	}
	filename = "GameData/rooms/" + filename + ".room.gmx";

	Undertale::Sheets sheets;
	Undertale::Room testRoom = Undertale::LoadRoomFromFile(filename, sheets);

	RenderTexture2D renderTexture = LoadRenderTexture(640, 480);
	SetTextureFilter(renderTexture.texture, TEXTURE_FILTER_POINT);
	Camera2D& camera = testRoom.GetCamera();
	bool fullscreen = false;
	int monitor = GetCurrentMonitor();


	while (!WindowShouldClose()) {

		if (IsKeyPressed(KEY_F4)) {
			ToggleFullscreen();
		}
		float screenWidth = GetScreenWidth();
		float screenHeight = GetScreenHeight();
		float scale = (int) screenHeight / 480.0f;

		if (Undertale::currentSong != nullptr) {
			UpdateMusicStream(*Undertale::currentSong);
		}
		testRoom.Update(GetFrameTime());
		Undertale::animManager.Update();

		BeginTextureMode(renderTexture);

			ClearBackground(BLACK);
			if (IsWindowFullscreen()) {
				camera.target.x += 340.0f / 4.0f;
				camera.target.y += 240.0f / 4.0f;
				std::cout << "Hey\n";
			}
			BeginMode2D(camera);	
				testRoom.Draw();
			EndMode2D();

		EndTextureMode();

		BeginDrawing();

			ClearBackground(PINK);
			Rectangle destRect = { };
			float texWidth = renderTexture.texture.width;
			float texHeight = renderTexture.texture.height;


			destRect = { screenWidth / 2.0f, screenHeight / 2.0f, 640 * scale, 480 * scale };
			DrawTexturePro(
				renderTexture.texture,
				{ 0.0f, 0.0f, texWidth, -texHeight },
				destRect,
				{ (texWidth * scale) / 2.0f , (texHeight * scale) / 2.0f },
				0.0f,
				WHITE
			);

			//DrawTextureEx(renderTexture.texture, { 0.0f, 0.0f }, 0.0f, scale, WHITE);

			DrawFPS(10, 10);
			
		EndDrawing();
	}

	UnloadRenderTexture(renderTexture);
	CloseAudioDevice();
	CloseWindow();

	return 0;

}
