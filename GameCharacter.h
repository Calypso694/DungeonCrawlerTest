#include <string>
#ifndef GAMECHARACTER_H 
#define GAMECHARACTER_H

class GameCharacter
{
    public: 
    std::string name; 
    int maxHealth, currentHealth, attack, defense; 
    GameCharacter(std::string,int,int,int); 
    int takeDamage(int);  
    bool checkIsDead();  
};

#endif
