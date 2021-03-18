#include<iostream> 
#include<vector>
#include<string>
#include "Player.cpp"
#include "Dungeon.cpp"
#include "Item.cpp"
#include "GameCharacter.cpp"
#include "Room.cpp"



int main() 
{
//PLAYER 
// Set up Player 
std::cout << "Welcome to The Dungeon. What is your name?\n"; 
std::string playerName;
std::cin >> playerName;
Player player = Player(playerName,100, 20,10); 

//ROOMS
//Set up First Room 
Room firstRoom = Room(0, false, std::vector<Item>(), std::vector<GameCharacter>()); 

//Set up Second Room
Item sword = Item("Sword", 0,20,0); 
std::vector<Item>secondRoomItems; 
secondRoomItems.push_back(sword);  
Room secondRoom = Room(1, false, secondRoomItems, std::vector<GameCharacter>());

//Set up Third Room
GameCharacter firstEnemy = GameCharacter("Little Monster",50,15,5); 
std::vector<GameCharacter>thirdRoomEnemies; 
thirdRoomEnemies.push_back(firstEnemy);
Room thirdRoom = Room(2, false, std::vector<Item>(),thirdRoomEnemies); 

//Set up Fourth Room 
GameCharacter secondEnemy = GameCharacter("Big Monster", 100,10,20);
std::vector<GameCharacter>fourthRoomEnemies; 
fourthRoomEnemies.push_back(secondEnemy); 
Room fourthRoom = Room(3, true, std::vector<Item>(), fourthRoomEnemies); 

//LAYOUT 
Dungeon dungeon = Dungeon(player); 
dungeon.room[0] = firstRoom; 
dungeon.room[1] = secondRoom; 
dungeon.room[2] = thirdRoom; 
dungeon.room[3] = fourthRoom; 

while(true)
    {
        int result = dungeon.runDungeon(); 
        if(result == 0)
           { break; }
    }
    std::cout << "Farewell Traveler!"; 



return 0;
}

