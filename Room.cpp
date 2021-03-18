#include "Room.h"


Room::Room(int p, bool ie, std::vector<Item> is, std::vector<GameCharacter> gcs)
{
    pos = p; 
    isExit = ie; 
    items = is; 
    ene = gcs; 
} 

void Room::clearLoot() 
{
    items.clear();
}

void Room::clearEnemies()
{
    enemies.clear();
}
