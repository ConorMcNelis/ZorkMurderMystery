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

    public:
        MainLobby(QString description);
        QString shortDescription();
        void addCharacter(Character *character);
        Character getCharacter(QString name);
        QString displayCharacter();
        int isCharacterInRoom(QString inQString);
        vector<Character> getCharacterList();
        int numberOfCharacters();
};

#endif // MAINLOBBY_H
