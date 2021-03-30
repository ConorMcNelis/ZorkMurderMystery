#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <QString>
#include <iostream>
using namespace std;

class Item {
private:
    QString description;
    QString longDescription;
	int weightGrams;
	float value;
	bool weaponCheck;

public:
    Item (QString description, int inWeight, float inValue);
    Item (QString description);
    QString getShortDescription();
    void setLongDescription(QString RoomDescription);
    QString getLongDescription();
	int getWeight();
	void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);

    friend class Character;
};

#endif /*ITEM_H_*/
