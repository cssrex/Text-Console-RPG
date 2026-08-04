#include <iostream>
#include <limits>

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

    // 스킬 목록 출력
    caster.ShowAllSkill();
    cout << "0. 돌아가기 (취소)\n";
    cout << "▶ 선택: ";

    int inputChoice = 0;
    cin >> inputChoice;

    // 문자 입력 등 입력 실패 처리
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "잘못된 문구입니다.\n";
        return false;
    }

    // 0번(돌아가기) 또는 입력 범위 초과(잘못된 숫자) 처리 (턴 소모하지 않고 메인 메뉴로 복귀)
    if (inputChoice <= 0 || inputChoice > static_cast<int>(skills.size())) {
        cout << "잘못된 문구입니다.\n";
        return false; 
    }

    // 선택한 스킬 객체 가져오기
    Skill* selectedSkill = skills[inputChoice - 1];

    // MP 부족 검사 (MP 부족 시에도 스킬 취소로 처리하여 턴 소모 안 함)
    if (!selectedSkill->CanUse(caster.GetMp())) {
        log.PrintSkillMpLack(selectedSkill->GetName());
        return false; 
    }

    // MP가 충분할 때 스킬 시전 및 true 반환 (턴 소모)
    selectedSkill->Use(caster, target);
    return true;
}