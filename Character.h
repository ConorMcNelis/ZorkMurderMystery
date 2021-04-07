#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "main.h"
#include <iostream>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;
#include <vector>
using std::vector;


class Character {
public:
    //vector < Item > itemsInCharacter;
    //void addItem(Item *item);
    friend class MainLobby;
    Character(QString description);
    QString shortDescription();
    QString longDescription();
    QString getDialogue(int choice);
    QString getDialogueLocation();
    void setDialogueLocation(QString location);
private:
    QString description;
    QString dialogue;
    QString dialogueLocation;
};


#endif /*CHARACTER_H_*/
