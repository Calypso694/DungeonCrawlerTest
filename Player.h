#include "Room.h" 

#ifndef PLAYER_H
#define PLAYER_H 

class Player : public GameCharacter 
{
    public: 
    Room * currentRoom; 
    Room * previousRoom; 
    std::vector<Item> inventory;
    Player(std::string = "", int= 0, int = 0, int = 0);
    void addItem(Item); 
    void increaseStats(int,int,int); 
    void lootRoom(Room *);
    void changeRoom(Room *);  
}

#endif 
