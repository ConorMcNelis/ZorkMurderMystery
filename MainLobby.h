#ifndef MAINLOBBY_H
#define MAINLOBBY_H

#include "Room.h"
#include "Character.h"

class MainLobby : public Room
{
    private:
        QString description;
        map<string, Room*> exits;
        QString exitString();
        vector <Item> itemsInRoom;
        vector <Character> CharactersInRoom;
        friend class mainwindow;

    public:
        MainLobby(QString description, Item *newItem, Item *newItem2);
        QString shortDescription();
        void addCharacter(Character *character);
        Character getCharacter(QString name);
        QString displayCharacter();
        int isCharacterInRoom(QString inQString);
        vector<Character> getCharacterList();
        int numberOfCharacters();

};

#endif // MAINLOBBY_H
