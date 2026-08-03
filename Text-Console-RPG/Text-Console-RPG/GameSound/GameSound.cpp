#include "GameSound.h"

#include <windows.h>
#include <mmsystem.h>
#include <string>

#pragma comment(lib, "Winmm.lib")
using namespace std;

// 호출할 때는 GameSound::함수이름() 형태로 사용
namespace GameSound {

    namespace {

        // BGM하고 sfx 하고 같이사용하려면 MCI 형태로 사용해야되는 것으로 확인완료
        constexpr const wchar_t* BgmAlias = L"game_bgm";
        constexpr const wchar_t* EffectAlias = L"game_effect";

        // Sound 폴더에 있는 BGM 파일 경로
        constexpr const wchar_t* StartAdventureBgm = L"Sound\\StartAdventureBgm.wav";
        constexpr const wchar_t* TownDayBgm = L"Sound\\TownDayBgm.wav";
        constexpr const wchar_t* TownNightBgm = L"Sound\\TownNightAmbience.wav";
        constexpr const wchar_t* ShopAmbienceBgm = L"Sound\\ShopAmbienceBgm.wav";
        constexpr const wchar_t* InnRestBgm = L"Sound\\InnRestBgm.wav";
        constexpr const wchar_t* DungeonBgm = L"Sound\\DungeonBgm.wav";
        constexpr const wchar_t* BattleBgm = L"Sound\\BattleBgm.wav";
        constexpr const wchar_t* BossBattleBgm = L"Sound\\BossBattleBgm.wav";

        // Sound 폴더에 있는 효과음 파일 경로
        constexpr const wchar_t* MenuMoveSfx = L"Sound\\MenuMoveSfx.wav";
        constexpr const wchar_t* MenuSelectSfx = L"Sound\\MenuSelectSfx.wav";
        constexpr const wchar_t* CancelSfx = L"Sound\\CancelSfx.wav";
        constexpr const wchar_t* SceneTransitionSfx = L"Sound\\SceneTransitionSfx.wav";
        constexpr const wchar_t* AttackSfx = L"Sound\\AttackSfx.wav";
        constexpr const wchar_t* StrongSkillSfx = L"Sound\\StrongSkillSfx.wav";
        constexpr const wchar_t* MonsterHitSfx = L"Sound\\MonsterHitSfx.wav";
        constexpr const wchar_t* CriticalHitSfx = L"Sound\\CriticalHitSfx.wav";
        constexpr const wchar_t* EscapeSfx = L"Sound\\EscapeSfx.wav";
        constexpr const wchar_t* BossEntranceSfx = L"Sound\\BossEntranceSfx.wav";
        constexpr const wchar_t* HealSfx = L"Sound\\HealSfx.wav";
        constexpr const wchar_t* RewardSfx = L"Sound\\RewardSfx.wav";
        constexpr const wchar_t* LevelUpSfx = L"Sound\\LevelUpSfx.wav";
        constexpr const wchar_t* EnhanceSuccessSfx = L"Sound\\EnhanceSuccessSfx.wav";
        constexpr const wchar_t* EnhanceFailSfx = L"Sound\\EnhanceFailSfx.wav";
        constexpr const wchar_t* DungeonClearSfx = L"Sound\\DungeonClearSfx.wav";
        constexpr const wchar_t* PlayerDeathSfx = L"Sound\\PlayerDeathSfx.wav";

        bool IsValidFilePath(const wchar_t* filePath) {
            return filePath != nullptr && filePath[0] != L'\0';
        }

        bool SendMciCommand(const wstring& command) {
            return mciSendStringW(command.c_str(), nullptr, 0, nullptr) == 0;
        }

        bool OpenWaveFile(const wchar_t* filePath, const wchar_t* alias) {
            if (!IsValidFilePath(filePath)) {
                return false;
            }

            SendMciCommand(wstring(L"close ") + alias);

            const wstring openCommand =
                wstring(L"open \"") + filePath + L"\" type waveaudio alias " + alias;
            return SendMciCommand(openCommand);
        }

    }
    // Beep는 안쓰긴 하는데 나중에 혹시 몰라 추가
    void PlayBeepTest() {
        Beep(523, 120);
        Beep(659, 120);
        Beep(784, 180);
    }

    void PlayAttackBeep() { Beep(900, 70); }
    void PlayHitBeep() { Beep(350, 100); }

    void PlayLevelUpBeep() {
        Beep(600, 100);
        Beep(800, 100);
        Beep(1100, 180);
    }

    void PlayErrorBeep() { Beep(250, 200); }

    bool PlayWave(const wchar_t* filePath) {
        if (!IsValidFilePath(filePath)) {
            return false;
        }

        return PlaySoundW(filePath, nullptr, SND_FILENAME | SND_ASYNC) != FALSE;
    }

    bool PlayLoopingWave(const wchar_t* filePath) {
        if (!IsValidFilePath(filePath)) {
            return false;
        }

        return PlaySoundW(filePath, nullptr, SND_FILENAME | SND_ASYNC | SND_LOOP) != FALSE;
    }

    void StopWave() { PlaySoundW(nullptr, nullptr, 0); }

    bool PlayBgm(const wchar_t* filePath) {
        if (!OpenWaveFile(filePath, BgmAlias)) {
            return false;
        }

        return SendMciCommand(wstring(L"play ") + BgmAlias + L" from 0");
    }

    bool PlayEffect(const wchar_t* filePath) {
        if (!OpenWaveFile(filePath, EffectAlias)) {
            return false;
        }

        return SendMciCommand(wstring(L"play ") + EffectAlias + L" from 0");
    }

    void StopBgm() {
        SendMciCommand(wstring(L"stop ") + BgmAlias);
        SendMciCommand(wstring(L"close ") + BgmAlias);
    }

    void StopEffect() {
        SendMciCommand(wstring(L"stop ") + EffectAlias);
        SendMciCommand(wstring(L"close ") + EffectAlias);
    }

    void StopAllSound() {
        StopWave();
        StopBgm();
        StopEffect();
    }
    // 장면별 BGM 호출
    bool PlayStartAdventureBgm() { return PlayBgm(StartAdventureBgm); }
    bool PlayStartAdventureBgmLoop() {
        return PlayLoopingWave(StartAdventureBgm);
    }
    bool PlayTownDayBgm() { return PlayBgm(TownDayBgm); }
    bool PlayTownDayBgmLoop() {
        return PlayLoopingWave(TownDayBgm);
    }
    bool PlayTownNightBgm() { return PlayBgm(TownNightBgm); }
    bool PlayTownNightBgmLoop() {
        return PlayLoopingWave(TownNightBgm);
    }
    bool PlayShopAmbienceBgm() { return PlayBgm(ShopAmbienceBgm); }
    bool PlayShopAmbienceBgmLoop() {
        return PlayLoopingWave(ShopAmbienceBgm);
    }
    bool PlayInnRestBgm() { return PlayBgm(InnRestBgm); }
    bool PlayInnRestBgmLoop() {
        return PlayLoopingWave(InnRestBgm);
    }
    bool PlayDungeonBgm() { return PlayBgm(DungeonBgm); }
    bool PlayDungeonBgmLoop() {
        return PlayLoopingWave(DungeonBgm);
    }
    bool PlayBattleBgm() { return PlayBgm(BattleBgm); }
    bool PlayBattleBgmLoop() {
        return PlayLoopingWave(BattleBgm);
    }
    bool PlayBossBattleBgm() { return PlayBgm(BossBattleBgm); }
    bool PlayBossBattleBgmLoop() {
        return PlayLoopingWave(BossBattleBgm);
    }
    // UI와 장면 전환 효과음 호출
    bool PlayMenuMoveSfx() { return PlayEffect(MenuMoveSfx); }
    bool PlayMenuSelectSfx() { return PlayEffect(MenuSelectSfx); }
    bool PlayCancelSfx() { return PlayEffect(CancelSfx); }
    bool PlaySceneTransitionSfx() { return PlayEffect(SceneTransitionSfx); }
    // 전투 효과음 호출
    bool PlayAttackSfx() { return PlayEffect(AttackSfx); }
    bool PlayStrongSkillSfx() { return PlayEffect(StrongSkillSfx); }
    bool PlayMonsterHitSfx() { return PlayEffect(MonsterHitSfx); }
    bool PlayCriticalHitSfx() { return PlayEffect(CriticalHitSfx); }
    bool PlayEscapeSfx() { return PlayEffect(EscapeSfx); }
    bool PlayBossEntranceSfx() { return PlayEffect(BossEntranceSfx); }
    // 성장, 상점, 결과 효과음 호출
    bool PlayHealSfx() {
        return PlayEffect(HealSfx);
    }
    bool PlayRewardSfx() {
        return PlayEffect(RewardSfx);
    }
    bool PlayPurchaseCompleteSfx() {
        return PlayRewardSfx();
    }
    bool PlayGoldRewardSfx() {
        return PlayRewardSfx();
    }
    bool PlayLevelUpSfx() {
        return PlayEffect(LevelUpSfx);
    }
    bool PlayEnhanceSuccessSfx() {
        return PlayEffect(EnhanceSuccessSfx);
    }
    bool PlayEnhanceFailSfx() {
        return PlayEffect(EnhanceFailSfx);
    }
    bool PlayDungeonClearSfx() {
        return PlayEffect(DungeonClearSfx);
    }
    bool PlayPlayerDeathSfx() {
        return PlayEffect(PlayerDeathSfx);
    }

}
