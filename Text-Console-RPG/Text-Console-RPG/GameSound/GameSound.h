#pragma once

// 호출할 때는 GameSound::함수이름() 형태로 사용
// GameSound::PlayTownDayBgm(); << 낮 마을 BGM 반복 재생 (예시)

namespace GameSound {

	// Beep 기반의 간단한 테스트 효과음(혹시 몰라서 추가)
	void PlayBeepTest();
	void PlayAttackBeep();
	void PlayHitBeep();
	void PlayLevelUpBeep();
	void PlayErrorBeep();

	// 파일 경로를 직접 지정하는 기본 재생 함수
	bool PlayWave(const wchar_t* filePath);
	bool PlayLoopingWave(const wchar_t* filePath);
	void StopWave();

	// MIC 형태로 BGM 1개와 효과음 1개를 동시에 재생하는 함수
	bool PlayBgm(const wchar_t* filePath);
	bool PlayEffect(const wchar_t* filePath);
	// GmaeSound::StopBgm(); // Bgm만 정지
	void StopBgm();
	// GmaeSound::StopEffect(); // 효과음만 정지
	void StopEffect();
	// GmaeSound::StopAllSound(); // 모든 사운드 정지
	void StopAllSound();

	// 장면별 BGM 호출
	bool PlayStartAdventureBgm();
	bool PlayStartAdventureBgmLoop();
	bool PlayTownDayBgm();
	bool PlayTownDayBgmLoop();
	bool PlayTownNightBgm();
	bool PlayTownNightBgmLoop();
	bool PlayShopAmbienceBgm();
	bool PlayShopAmbienceBgmLoop();
	bool PlayInnRestBgm();
	bool PlayInnRestBgmLoop();
	bool PlayDungeonBgm();
	bool PlayDungeonBgmLoop();
	bool PlayBattleBgm();
	bool PlayBattleBgmLoop();
	bool PlayBossBattleBgm();
	bool PlayBossBattleBgmLoop();
	bool PlayPrologueBgm();
	bool PlayPrologueBgmLoop();
	bool PlayHappyEndingBgm();
	bool PlayHappyEndingBgmLoop();
	bool PlayBadEndingBgm();
	bool PlayBadEndingBgmLoop();
	bool PlayPrologueBgm();
	bool PlayPrologueBgmLoop();

	// UI와 장면 전환 효과음 호출
	bool PlayMenuMoveSfx();
	bool PlayMenuSelectSfx();
	bool PlayCancelSfx();
	bool PlaySceneTransitionSfx();

	// 전투 효과음 호출
	bool PlayAttackSfx();
	bool PlayStrongSkillSfx();
	bool PlayMonsterHitSfx();
	bool PlayCriticalHitSfx();
	bool PlayEscapeSfx();
	bool PlayBossEntranceSfx();

	// 성장, 상점, 결과 효과음 호출
	bool PlayHealSfx();
	bool PlayRewardSfx();
	bool PlayPurchaseCompleteSfx();
	bool PlayGoldRewardSfx();
	bool PlayLevelUpSfx();
	bool PlayEnhanceSuccessSfx();
	bool PlayEnhanceFailSfx();
	bool PlayDungeonClearSfx();
	bool PlayPlayerDeathSfx();

}  // namespace GameSound
