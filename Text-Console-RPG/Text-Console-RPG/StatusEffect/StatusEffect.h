#pragma once

#include <string>

class Character;

class StatusEffect {
protected:
    std::string name_;
    int damage_;
    int turn_;

public:
    StatusEffect(const std::string& name, int damage, int turn);
    virtual ~StatusEffect() = default;

    virtual void ApplyEffect(Character& target);
    bool IsExpired() const;

    std::string GetName() const { return name_; }
    int GetDamage() const { return damage_; }
    int GetTurn() const { return turn_; }
};

class BleedEffect : public StatusEffect {
public:
    BleedEffect(int damage = 10, int turn = 3);
};

class PoisonEffect : public StatusEffect {
public:
    PoisonEffect(int damage = 15, int turn = 2);
};

class BurnEffect : public StatusEffect {
public:
    BurnEffect(int damage = 20, int turn = 2);
};

