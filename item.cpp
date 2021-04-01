#include "item.h"

Item::Item (QString inDescription, int inWeightGrams, float inValue/**, int weaponCheck*/) {
	description = inDescription;
	setWeight(inWeightGrams);
	value = inValue;
	/**weaponCheck(isWeapon);*/
}

Item::Item(QString inDescription) {
	description = inDescription;
}

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
	   weightGrams = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}

/**void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}*/

QString Item::getShortDescription()
{
	return description;
}

void Item::setLongDescription(QString RoomDescription)
{
    longDescription = RoomDescription;
}

QString Item::getLongDescription()
{
    return longDescription;
}

void Item::setExamination(QString examinationString)
{
    Examination = examinationString;
}

QString Item::getExamination()
{
    return Examination;
}


