#include "GameCharacter.h"

GameCharacter::GameCharacter(std::string name, int h, int a, int d)
{
    name = name; 
    currentHealth = h; 
    maxHealth = h ; 
    attack = a; 
    defense = d; 
}; 

int GameCharacter::takeDamage(int amount) 
{
    int damage = amount - defense; 
    if (damage < 0)
        damage = 0; 
        

    currentHealth -= damage; 
    return damage; 
} 

bool GameCharacter::checkIsDead(); 
{
    return currentHealth <= 0; 
}

   