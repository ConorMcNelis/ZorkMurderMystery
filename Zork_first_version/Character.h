#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"
#include <fstream>
#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
public:
    string description;
         vector < Item > itemsInCharacter;
    //void addItem(Item *item);

	Character(string description);
	string shortDescription();
    string longDescription();
};


#endif /*CHARACTER_H_*/
