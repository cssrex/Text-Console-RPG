#ifndef SKILL_H
#define SKILL_H

#include <string>

class Character;
class StatusEffect;

class Skill {
protected:
    std::string name_;
    int cost_;
    StatusEffect* statusEffect_ = nullptr;
    int percent_;

public:
    Skill(const std::string& name, int cost, int percent, StatusEffect* statusEffect = nullptr);
    virtual ~Skill();

    virtual bool CanUse(int currentMp) const;
    virtual void Use(Character& caster, Character& target) = 0;

    std::string GetName() const { return name_; }
    int GetCost() const { return cost_; }
    int GetPercent() const { return percent_; }
};


// 평타 (Cost 사용 X)
class BasicAttack : public Skill {
public:
    BasicAttack();
    void Use(Character& caster, Character& target) override;
};

// 스킬 1 (출혈 부여)
class SkillOne : public Skill {
public:
    SkillOne();
    void Use(Character& caster, Character& target) override;
};

// 스킬 2 (화상 부여)
class SkillTwo : public Skill {
public:
    SkillTwo();
    void Use(Character& caster, Character& target) override;
};

#endif