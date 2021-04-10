#include "item.h"

Item::Item (QString inDescription, int inWeightGrams, float inValue/**, int weaponCheck*/)
    : description(inDescription), weightGrams(inWeightGrams), value(inValue)
{

}

Item::Item(QString inDescription)
    : description(inDescription)
{

}

/*
Item::Item(const Item& other)
    : description(other.description)
{

}
*/

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 3000 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<10" ;
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

QString Item::shortDescription()
{
	return description;
}

void Item::setLongDescription(QString RoomDescription)
{
    LongDescription = RoomDescription;
}

QString Item::longDescription()
{
    return LongDescription;
}

void Item::setExamination(QString examinationString)
{
    Examination = examinationString;
}

QString Item::getExamination()
{
    return Examination;
}


