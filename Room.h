#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <QString>
#include <vector>
#include "item.h"
//using namespace std;
using namespace std;

class Room {

private:
    QString description;
    map<string, Room*> exits;
    QString exitString();
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
    Room(QString inDescription);
    Room(QString inDescription, Item *newItem);
    Room(QString inDescription, Item *newItem, Item *newItem2);
    Room(Item *newItem, Item *newItem2);
    Room();
	void setExits(Room *north, Room *east, Room *south, Room *west);
    QString shortDescription();
    QString longDescription();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    QString displayItem();
    int isItemInRoom(QString inQString);
    vector<Item> getItemList();
    void removeItemFromRoom(int location);
};

#endif
