#pragma once

#include <string>
#include <vector>

class Skill;
class StatusEffect;

class Character {
protected:
    std::string name_;
    int level_;
    int hp_;
    int maxHp_;
    int mp_;
    int maxMp_;
    int attack_;

    std::vector<Skill*> skills_;
    std::vector<StatusEffect*> statusEffects_;

public:
    Character(const std::string& name, int level, int maxHp, int maxMp, int attack);
    virtual ~Character();

    // 플레이어 & 몬스터 공통 동작 함수
    virtual void PrintStatus() const;
    void ShowAllSkill() const;

    virtual void TakeDamage(int damage);
    virtual void Heal(int value);
    void UseMp(int amount);
    void HealMp(int amount);
    bool IsDead() const;

    // 상태이상 연산
    void AddStatusEffect(StatusEffect* effect);
    void UpdateStatusEffects();

    std::string GetName() const { return name_; }
    int GetLevel() const { return level_; }
    int GetHp() const { return hp_; }
    int GetMaxHp() const { return maxHp_; }
    int GetMp() const { return mp_; }
    int GetMaxMp() const { return maxMp_; }
    int GetAttack() const { return attack_; }
    const std::vector<Skill*>& GetSkills() const { return skills_; }

    void SetHp(int hp) { hp_ = hp; }
    void SetMp(int mp) { mp_ = mp; }
    void SetAttack(int attack) { attack_ = attack; }
};

#endif