#include"SOUND_MANEGER.h"
#include"sound.h"



SOUND_MANEGER::SOUND_MANEGER() {
	
	

	TitelBgm = loadSound("�^�C�g��BGM.wav");
	GameBgm = loadSound("GamePlayBGM.wav");

	ScoreBgm = loadSound("�X�R�A���BGM.wav");
	//����ƑI����
	SelectSE = loadSound("�I�� ver2.wav");
	DecisionSE = loadSound("����SE.wav");
	//�Q�[���֘ASE
	FruitGetSE = loadSound("�ʕ��L���b�`SE.wav");
	RotFruitGetSE = loadSound("�������ʕ��L���b�`.wav");
	TimeUpSE = loadSound("���v�L���b�`UP.wav");
	TimeDownSE = loadSound("���v�L���b�`DOWN ver2.wav");
	ShoesGetSE = loadSound("�C�L���b�`SE.wav");
	TimwNotice = loadSound("�������ԒʒmSE.wav");
	//�X�R�A�֘ASE
	ScoreAppearSE = loadSound("�X�R�A�\��SE.wav");
	ScoreWindowAppearSE = loadSound("�X�R�A��ʕ\��.wav");
}


void SOUND_MANEGER::getTitelBgm() { playLoopSound(TitelBgm); }
void SOUND_MANEGER::getGameBgm() {playLoopSound(GameBgm);}
void SOUND_MANEGER::getScoreBgm() {playLoopSound(ScoreBgm);}

void SOUND_MANEGER::getSelectSE() { playSound(SelectSE); }
void SOUND_MANEGER::getDecisionSE() { playSound(DecisionSE); }
void SOUND_MANEGER::getFruitGetSE() { playSound(FruitGetSE); }
void SOUND_MANEGER::getRotFruitGetSE() { playSound(RotFruitGetSE); }
void SOUND_MANEGER::getTimeUpSE() { playSound(TimeUpSE); }
void SOUND_MANEGER::getTimeDownSE() { playSound(TimeDownSE); }
void SOUND_MANEGER::getShoesGetSE() { playSound(ShoesGetSE); }
void SOUND_MANEGER::getTimwNotice() { playSound(TimwNotice); }
void SOUND_MANEGER::getScoreAppearSE() { playSound(ScoreAppearSE); }
void SOUND_MANEGER::getScoreWindowAppearSE() { playSound(ScoreWindowAppearSE); }


void SOUND_MANEGER::stopBgm() {
	stopSound(TitelBgm);
	stopSound(GameBgm);
	stopSound(ScoreBgm);
}