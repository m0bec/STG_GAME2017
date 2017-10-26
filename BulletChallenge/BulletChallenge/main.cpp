#include "DxLib.h"
#include "main.h"

// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	MainState main_state = LoadGraphState;
	GraphLoader graph_loader;
	graph_loader.Load();
	// ��ʃ��[�h�̐ݒ�
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 16);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1) return -1;

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	while (true)
	{
		// ��ʂ�������(�^�����ɂ���)
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
		

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip();

		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}