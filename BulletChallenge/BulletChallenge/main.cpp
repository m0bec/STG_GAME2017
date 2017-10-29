#include "DxLib.h"
#include "main.h"

// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// ��ʃ��[�h�̐ݒ�
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 16);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1) return -1;

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	ScoreManager &score_manager = ScoreManager::GetInstance();
	score_manager.LoadScore();

	bool exit_flag = false;
	int main_state = LoadGraphState;
	GraphLoader& graph_loader = GraphLoader::GetInstance();
	TitleDrawer title_drawer;
	graph_loader.Load();

	GameBackDrawer game_back_drawer;
	Player player;
	EnemyController enemy_controller;
	GameSystem& game_system = GameSystem::GetInstance();


	while (true)
	{
		graph_loader.LoadError();
		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen();
		if (GetASyncLoadNum() != 0) {
			DrawGraph(0, 0, graph_loader.load_gr, TRUE);
		}
		else {
			switch(main_state) {
				case LoadGraphState:
					main_state = TitleDispState;
					player.SetPlayerData(graph_loader.ziki_gr, graph_loader.player_bullet_gr, graph_loader.core_gr);
					enemy_controller.SetEnemyGr(graph_loader.enemy_gr);
					enemy_controller.BulletGrSet(graph_loader.blue_bullet_gr);
					break;

				case TitleDispState:
					title_drawer.DrawTitle(graph_loader.title_back_gr, graph_loader.start_gr, graph_loader.exit_gr, graph_loader.manual_gr, graph_loader.manual_disp);
					title_drawer.TitleSystem();
					title_drawer.Select(exit_flag, main_state);
					enemy_controller.SetVar();
					game_system.SetVar();
					player.SetVar();
					break;

				case GameState:
					switch (game_system.state) {
					case StateInGame::Play:
						game_back_drawer.GameBackDraw(graph_loader.game_back_gr);
						enemy_controller.EnemyExe();
						player.Exe();
						for (Bullet &t_ : player.bullet) {
							for (Enemy &ene_ : enemy_controller.enemy_array) {
								enemy_controller.EnemyHit(ene_, t_);
							}
						}
						enemy_controller.EnemyShotMove(player.ziki);
						enemy_controller.PlayerHit(player.ziki);
						game_back_drawer.WriteWord(player.ziki);
						game_system.CheckGoToStop();
						enemy_controller.EnemyDeathNumCheck(game_system.state);
						game_system.ZikiHpCheck(player.ziki.hp);
						break;

					case StateInGame::Stop:
						game_back_drawer.GameBackDraw(graph_loader.game_back_gr);
						enemy_controller.OnlyDraw();
						player.OnltDraw();
						enemy_controller.OnlyShotDraw();
						game_back_drawer.WriteWord(player.ziki);
						game_back_drawer.StopDraw(game_system.stop_state, game_system.state, graph_loader.stop_continue_gr, graph_loader.stop_exit_gr, graph_loader.stop_back_gr);
						break;

					case StateInGame::GameOver:
						game_back_drawer.GameBackDraw(graph_loader.game_back_gr);
						enemy_controller.OnlyDraw();
						player.OnltDraw();
						enemy_controller.OnlyShotDraw();
						game_back_drawer.WriteWord(player.ziki);
						game_back_drawer.GameOverDraw(main_state, game_system.state, graph_loader.game_over_gr);
						title_drawer.SetPushKeyFlag();
						break;

					case StateInGame::NextStage:
						game_back_drawer.GameBackDraw(graph_loader.game_back_gr);
						enemy_controller.OnlyDraw();
						player.OnltDraw();
						game_back_drawer.WriteWord(player.ziki);
						game_back_drawer.GameNextStage(main_state, game_system.state, graph_loader.clear_gr);
						break;
					}
					break;

				case SetEnemy:
					DrawGraph(0, 0, graph_loader.load_gr, TRUE);
					enemy_controller.SetEnemy();
					enemy_controller.EnemyShotClean();
					main_state = GameState;
					break;
					
			}
		}
		

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip();

		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) || exit_flag) break;
	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}