#include "Room.h"
#include "Command.h"


Room::Room(QString description) {
	this->description = description;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

QString Room::shortDescription() {
	return description;
}

QString Room::longDescription() {
    QString plusItemsDescription = description;
    for (int i = 0; i < (int)itemsInRoom.size(); i++)
        plusItemsDescription = plusItemsDescription + itemsInRoom[i].getLongDescription();
    return "room = " + plusItemsDescription + "\n" + displayItem() + exitString();
}

QString Room::exitString() {
    string returnString = "\nexits =";
    for (std::map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    QString ReturnString = QString::fromStdString(returnString);
    return ReturnString;
}

Room* Room::nextRoom(string direction) {
    std::map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

QString Room::displayItem() {
    QString tempQString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempQString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempQString = tempQString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempQString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(QString inQString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inQString with short description
            int tempFlag = inQString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}
