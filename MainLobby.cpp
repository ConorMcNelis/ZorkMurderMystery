#include "MainLobby.h"

MainLobby::MainLobby(QString description)
{
    this->description = description;
}

QString MainLobby::shortDescription(){
    return "Butt";
}

void MainLobby::addCharacter(Character *character){
    CharactersInRoom.push_back(*character);
}

Character MainLobby::getCharacter(QString name){
    for (int i = 0; i<numberOfCharacters(); i++){
        if (name == CharactersInRoom[i].shortDescription())
            return CharactersInRoom[i];
    }
    Character *failsafe = new Character("error");
    return *failsafe;
}


QString MainLobby::displayCharacter() {
    QString tempQString = "Characters in room = ";
    int sizeCharacters = (CharactersInRoom.size());
    if (CharactersInRoom.size() < 1) {
        tempQString = "no Characters in room";
        }
    else if (CharactersInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeCharacters; n > 0; n--) {
            tempQString = tempQString + CharactersInRoom[x].shortDescription() + "  " ;
            x++;
            }
        }
    return tempQString;
    }

int MainLobby::numberOfCharacters() {
    return CharactersInRoom.size();
}

vector<Character> MainLobby::getCharacterList(){
    return CharactersInRoom;
}
