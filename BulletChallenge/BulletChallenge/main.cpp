#include "DxLib.h"
#include "main.h"

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	MainState main_state = LoadGraphState;
	GraphLoader graph_loader;
	graph_loader.Load();
	// 画面モードの設定
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 16);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	while (true)
	{
		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();

		if (GetASyncLoadNum() != 0) {
			
		}
		else {
			switch(main_state) {
				case LoadGraphState:
					main_state = TitleDispState;
					break;

				case TitleDispState:

					break;

				case GameState:

					break;
			}
		}
		

		// 裏画面の内容を表画面にコピーする
		ScreenFlip();

		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// -1 が返ってきたらループを抜ける
		if (ProcessMessage() < 0) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了
	return 0;
}