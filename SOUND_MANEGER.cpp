#include"SOUND_MANEGER.h"
#include"sound.h"


SOUND_MANEGER* SOUND_MANEGER::SoundManeger = 0;

SOUND_MANEGER::SOUND_MANEGER() {
	TitelBgm = loadSound("タイトルBGM.wav");
	GameBgm = loadSound("ゲームプレイBGM.wav");
	ScoreBgm = loadSound("スコア画面BGM.wav");
	//決定と選択音
	SelectSE = loadSound("選択 ver2.wav");
	DecisionSE = loadSound("決定SE.wav");
	//ゲーム関連SE
	FruitGetSE = loadSound("果物キャッチSE.wav");
	RotFruitGetSE = loadSound("腐った果物キャッチ.wav");
	TimeUpSE = loadSound("時計キャッチUP.wav");
	TimeDownSE = loadSound("時計キャッチDOWN ver2.wav");
	ShoesGetSE = loadSound("靴キャッチSE.wav");
	TimwNotice = loadSound("制限時間通知SE.wav");
	//スコア関連SE
	ScoreAppearSE = loadSound("スコア表示SE.wav");
	ScoreWindowAppearSE = loadSound("スコア画面表示.wav");
}


SOUND_MANEGER* SOUND_MANEGER::getInstans() {
	if (!SoundManeger) {
		SoundManeger = new SOUND_MANEGER;
	}
	return SoundManeger;
}

SOUND_MANEGER* SOUND_MANEGER::Delete() {
	if (SoundManeger) {
		delete SoundManeger;
		SoundManeger = 0;
	}
	return SoundManeger;
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