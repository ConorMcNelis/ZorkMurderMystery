#include "Character.h"

Character::Character(string description) {
	this->description = description;
}
/*void Character::addItem(Item &item) {
    itemsInCharacter.push_back(item);
}*/

string Character::longDescription()
{
    string ath = "\\Users\\Conor\\Documents\\College Work\\Event Driven Programming\\Zork_first_version\\";
  string ret = this->description;
  ret += ":\n";
  ifstream inFile{};
  inFile.open("\\Users\\Conor\\Documents\\College Work\\Event Driven Programming\\Zork_first_version\\Text\\TestText.txt");
  //programmer defined exception (I think)
    if (!inFile){
        cerr << "Unable to open the file TestText.txt";
        exit(1);
    }
    for (std::string line; std::getline(inFile, line); )
    {
        //std::cout << line << std::endl;
        ret += line + "\n";
    }
    inFile.close();
  return ret;
}




