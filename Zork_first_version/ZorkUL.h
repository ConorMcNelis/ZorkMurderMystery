#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Character.h"
//#include "MainCharacter.h"
#include <iostream>
//#include <filesystem>
#include <string>
using namespace std;
//namespace fs = std::filesystem;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
   // MainCharacter *player;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();
    void createCharacters();
    void displayCharacters();

public:
	ZorkUL();
	void play();
	string go(string direction);
};

#endif /*ZORKUL_H_*/
