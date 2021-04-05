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
    QString description;
    QString dialogue;
    QString dialogueLocation;
    //vector < Item > itemsInCharacter;
    //void addItem(Item *item);

    Character(QString description);
    QString shortDescription();
    QString longDescription();
    QString getDialogue(int choice);
    QString getDialogueLocation();
    void setDialogueLocation(QString location);
};


#endif /*CHARACTER_H_*/
