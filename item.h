#include<string> 
#ifndef ITEM_H 
#define ITEM_H 

class Item 
{
    public:
    std::string name; 
    int health, attack, defense; 
    Item(std::string name, health, attack, defense);
}; 

#endif 