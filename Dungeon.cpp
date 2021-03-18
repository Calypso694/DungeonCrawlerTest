#include<iostream> 
#include "Player.h"
#include "Dungeon.h"


Dungeon::Dungeon(Player p) 
{
    player = p; 
}

void Dungeon::printActions(int numActions, std::string action[])
{
    std::cout << "Choose an action:\n "; 
    for(int i = 0; i = numActions; i++) 
        { std::cout<< action[i] << "Action:\n"; }
}

void Dungeon::handleEmptyRoom(Room * Room)
{
    std::cout << "You enter a Room but it is empty. \n "; 
    std::string action[] = {"a. Move to another Room. \n"}; 
    while(true)
    {
        printActions(1, action); 
        std::string input; 
        std::cin >> input; 
        if(input == "a")
            {
                return; 
                }
        else
            {
                std::cout << "Incorrect input. Choose another. \n ";
            }

    } 

}

void Dungeon::handleLootActions(Room * room) {
player.lootRoom(room);
for (int i = 0; i < room->items.size(); i++) {
std::cout << "You open the chest and find a " <<room->items[i].name << ".\n";
std::cout << "Your health is now " << player.currentHealth << ", your attack is now "
<< player.attack << ", and your defence is now " << player.defense << "\n";
}
room->clearLoot();
}

void Dungeon::handleRoomWithChest(Room * room)
{
    std::cout << "You see a Chest in the middle of the room. \n "; 
    std::string action[] = {"a. You Loot the Chest. \n" "b. Move to another Room. \n"}; 
    while(true)
    {
        printActions(2, actions); 
        std::string input; 
        cin >> input; 
    if(input == "a")
        { handleLootActions(room); 
        return; }
    else if (input == "b")
       { return; }
    else
      {  std::cout << "Invalid choice. \n"; }
    }
}

void Dungeon::handleFightActions(GameCharacter * enemy)
{
    std::string actions[]= {"a. Attack \n ", "b. Retreat \n"}; 
};
while (true) //handle Player actions
{
    printActions(2, actions); 
    std::string input; 
    cin >> input; 
if(input == "a") 
    {
        int damage = enemy->takeDamage(player.attack); 
        std::cout << "Your Attack does " << damage << "damage. \n"; 
    }
else if(intput == "b") 
    {
        player.changeRooms(player.previousRoom);
        enterRoom(player.currentRoom); 
        return; 
    }
else 
    {
        std::cout << "Incorrect Choice. \n "; 
        continue; 
    }
    //check if enemy is dead. 
if(enemy->checkIsDead)
    {
        std::cout<< "You Win! You have defeated the " << enemy->name << ".\n"; 
        player.increaseState(10, 5, 5);
        player.currentRoom->clearEnemies(); 
        return; 
    }
    //handle Enemey actions
   { int damage = player.takeDamage(enemy->attack);
    std::cout << enemy->name << "'s attack does " << damage << "damage. \n"; 
    std::cout << "You now have " << maxHealth << "Health. \n"; 
if(player.checkIsDead())
{return; } 

}

void::Dungeon::handleRoomWithEnemy(Room * room)
{
    GameCharacter enemy = room->enemies.front();
    std::cout << "You enter a Room and see a " enemy.name << ".\n"; 
    std::string actions[] = {"a. Fight the " + enemy.name, "b. Go back to other Room. "};
    while(true) 
    {
        printActions(2, actions);
        std::string intput; 
        cin >> input; 
    if(input == "a")
        {handleFightActions(&enemy);
        return; }
    else if (input == "b")
        {player.changeRooms(player.previousRoom);
        enterRoom(currentRoom);
        return; }
    else 
    {std::cout << "incorrent choice. \n";}   
    }
}

void::Dungeon::enterRoom(Room * room)
{
    if(room->enemies.size() != 0)
      {handleRoomWithEnemy(room);}
    else if (room->items.size() != 0)
      {handleRoomWithChest(room);}
    else
    {handleEmptyRoom(room);} 
}

void Dungeon::handleMovementActions(Room * room) 
{
    while(true) {
      if (room->pos == 0) {
        std::string actions[] = {"a. Move right", "b. Move down"};
        printActions(2, actions);
        std::string input;
s       td::cin >> input;
      if (input == "a") {
        player.changeRooms(&rooms[1]);
        return;
}     else if (input == "b") {
        player.changeRooms(&rooms[2]);
        return;
}     else 
        {std::cout << "Incorrect choice.\n";}
}     else if (room->pos == 1) {
      std::string actions[] = {"a. Move left"};
      printActions(1, actions);
      std::string input;
      std::cin >> input;
      if (input == "a") 
      {player.changeRooms(&rooms[0]);
      return; } 
      else 
      {std::cout << "Incorrect choice.\n";}
}   
      else if (room->pos == 2) 
      { std::string actions[] = {"a. Move up", "b. Move right"};
        printActions(2, actions);
        std::string input;
        std::cin >> input;
      if (input == "a") {
        player.changeRooms(&rooms[0]);
        return; } 
      else if (input == "b") {
        player.changeRooms(&rooms[3]);
        return; }       
        else 
            {std::cout << "Incorrect choice.\n";}
}       else 
            {std::string actions[] = {"a. Move left"};
            printActions(1, actions);
            std::string input;
            std::cin >> input;
        if (input == "a") {
        player.changeRooms(&rooms[2]);
        return;} 
        else 
            {std::cout << "Incorrect choice.\n";}
}
}
}
    int Dungeon::performEndGameLogic()
    {
      std::string actions[] = {"a.Ah Yes", "b.No"};
        while(true)
        {
        printActions(2, actions); 
        std::input; 
        std::cin >> input; 
          if(input == "a")
            {return 1;}
          else if 
            {return 0;}
          else 
            {std::cout << "Incorrect Choie."};
        }
    }

    int Dungeon::runDungeon()
    {
        std::cout << "Welcome to the Dungeon.\n";
        std::cout << "Inside Treasure awaits! But what else will you find? \n";
        std::cout << "Enter at your own risk! \n"; 
        player.currentRoom = &rooms[0]; 
        player.previousRoom = &rooms[0];

        while (true) 
        {
            enterRoom(player.currentRoom); 
            if(player.checkIsDead())
                {std::cout << "Game Over! Try Again?\n";
                return performEndGameLogic(); 
                }
            else 
                {
                    if(player.currentRoom->isExit)
                    {
                        if(player.currentRoom->enemies.size() == 0)
                        {
                            std::cout << "You Win! Play Again?\n"; 
                            return performEndGameLogic(); 
                        }
                    }
                }
            handleMovementActions(player.currentRoom); 
        } 

    }
