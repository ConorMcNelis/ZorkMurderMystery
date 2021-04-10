#ifndef ITEM_H_
#define ITEM_H_
#include "interface.h"
#include <map>
#include <QString>
#include <iostream>
using namespace std;

class Item : Interface {
private:
    QString description;
    QString LongDescription;
    QString Examination;
    int weightGrams : 15;
	float value;


public:
    Item (QString description, int inWeight, float inValue);
    Item (QString description);
    //Item (const Item& other);
    virtual QString shortDescription();
    virtual void setLongDescription(QString RoomDescription);
    virtual QString longDescription();
    void setExamination(QString examinationString);
    QString getExamination();
	int getWeight();
    void setWeight(int weightKG);
	float getValue();
	void setValue(float value);


    friend class Character;
};

#endif /*ITEM_H_*/
