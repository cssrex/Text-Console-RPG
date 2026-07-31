#pragma once

class Character;

class SkillManager {
public:
    SkillManager() = default;
    ~SkillManager() = default;

public:
    static SkillManager& GetInstance() {
        static SkillManager instance;
        return instance;
    }

    // caster (스킬을 사용하는 캐릭터/플레이어), target (스킬 대상/몬스터)
    static bool ProcessSkillSelection(Character& caster, Character& target);
};