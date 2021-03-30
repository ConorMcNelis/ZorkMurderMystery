#include "Character.h"
#include <QMessageBox>

Character::Character(QString description) {
	this->description = description;
}
/*void Character::addItem(Item &item) {
    itemsInCharacter.push_back(item);
}*/

QString Character::longDescription()
{
    QString ath = "\\Users\\Conor\\Documents\\College Work\\Event Driven Programming\\Zork_first_version\\";
  QString ret = this->description;
  ret += ":\n";
  ifstream inFile{};
  inFile.open("\\Users\\Conor\\Documents\\College Work\\Event Driven Programming\\Zork_first_version\\Text\\TestText.txt");
  //programmer defined exception (I think)
    if (!inFile){
        cerr << "Unable to open the file TestText.txt";
        exit(1);
    }
    for (string line; getline(inFile, line); )
    {
        //std::cout << line << std::endl;
        QString Line = QString::fromStdString(line);
        ret += Line + "\n";
    }
    inFile.close();
  return ret;
}




