#include "Character.h"

Character::Character(QString description) {
	this->description = description;
}
/*void Character::addItem(Item &item) {
    itemsInCharacter.push_back(item);
}*/

QString Character::longDescription()
{
  QString ret = this->description;
  ret += ":\n";
  QFile file(":/CharacterLongDescriptions/Text/TestText.txt");
  if (!file.exists())
      qDebug() << file.fileName() << "does not exist";
   else if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
      cerr << "read in";
  QTextStream in(&file);
  in.seek(0);
  while (!in.atEnd()){
      QString line = in.readLine();
      ret = ret + line + "\n";
  }
  file.close();
  }
  else
  {
      qDebug() << "Couldn't open file";
  }
  return ret;
}




