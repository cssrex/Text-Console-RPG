#include <iostream>
#include "SkillManager.h"
#include "Character.h"
#include "Skill.h"
#include "LogManager.h"

using namespace std;

bool SkillManager::ProcessSkillSelection(Character& caster, Character& target) {
    LogManager& log = LogManager::GetInstance();
    const auto& skills = caster.GetSkills();

    // 보유한 스킬이 없는 경우 처리
    if (skills.empty()) {
        log.PrintInpuErrorMessage();
        return false;
    }

    while (true) {
        // Character 내부의 스킬 목록 출력 메서드 호출 (LogManager 기반)
        caster.ShowAllSkill();
        cout << "0. 돌아가기 (취소)\n";
        cout << "▶ 선택: ";

        int inputChoice = 0;
        cin >> inputChoice;

        // 0번(돌아가기) false를 반환 (턴을 소비하지 않고 행동 선택으로 복귀)
        if (inputChoice == 0) {
            cout << "스킬 사용을 취소했습니다.\n";
            return false;
        }

        // 입력 범위 초과 검사
        if (inputChoice < 1 || inputChoice > static_cast<int>(skills.size())) {
            log.PrintInpuErrorMessage();
            continue;
        }

        // 선택한 스킬 객체 가져오기
        Skill* selectedSkill = skills[inputChoice - 1];

        // MP 부족 검사
        if (!selectedSkill->CanUse(caster.GetMp())) {
            log.PrintSkillMpLack(selectedSkill->GetName());
            continue; // 다시 스킬을 선택하도록 루프 재실행
        }

        // MP가 충분할 때 스킬 시전 및 true 반환 (턴 소모)
        selectedSkill->Use(caster, target);
        return true;
    }
}