#include "DxLib.h"
#include "main.h"

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// 画面モードの設定
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 16);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	ScoreManager &score_manager = ScoreManager::GetInstance();
	score_manager.LoadScore();
	bool exit_flag = false;
	int main_state = LoadGraphState;
	GraphLoader graph_loader;
	TitleDrawer title_drawer;
	graph_loader.Load();

	while (true)
	{
		graph_loader.LoadError();
		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();
		if (GetASyncLoadNum() != 0) {
			DrawGraph(0, 0, graph_loader.load_gr, TRUE);
		}
		else {
			switch(main_state) {
				case LoadGraphState:
					main_state = TitleDispState;
					break;

				case TitleDispState:
					title_drawer.DrawTitle(graph_loader.title_back_gr, graph_loader.start_gr, graph_loader.exit_gr, graph_loader.manual_gr, graph_loader.manual_disp);
					title_drawer.TitleSystem();
					title_drawer.Select(exit_flag, main_state);
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
		if (CheckHitKey(KEY_INPUT_ESCAPE) || exit_flag) break;
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了
	return 0;
}