#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "item.h"
#include <fstream>
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
         vector < Item > itemsInCharacter;
    //void addItem(Item *item);

    Character(QString description);
    QString shortDescription();
    QString longDescription();
};


#endif /*CHARACTER_H_*/
