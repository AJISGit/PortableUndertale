#include <undertale.hpp>
#include <undertale/undertale.hpp>
#include <iostream>


const float cameraSpeed = 200.0f;


int main(int argc, char** argv) {

	//SetTraceLogLevel(LOG_WARNING);
	InitWindow(640, 480, "UNDERTALE");
	InitAudioDevice();
	SetTargetFPS(30);
	std::string filename = "room_ruins5";
	if (argc > 1) {
		filename = argv[1];
	}
	filename = "../rooms/" + filename + ".room.gmx";

	Undertale::Sheets sheets;
	Undertale::Room testRoom = Undertale::LoadRoomFromFile(filename, sheets);

	Camera2D& camera = testRoom.GetCamera();

	while (!WindowShouldClose()) {

		if (Undertale::currentSong != nullptr) {
			UpdateMusicStream(*Undertale::currentSong);
		}
			BeginDrawing();
			ClearBackground(BLACK);
			BeginMode2D(camera);	
				testRoom.Draw();
		testRoom.Update(GetFrameTime());


			

			EndMode2D();

			DrawFPS(10, 10);
			
		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();

	return 0;

}
