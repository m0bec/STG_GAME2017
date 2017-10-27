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
	GraphLoader graph_loader;
	TitleDrawer title_drawer;
	graph_loader.Load();

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