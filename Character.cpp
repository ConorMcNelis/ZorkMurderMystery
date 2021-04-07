#include "Character.h"

Character::Character(QString inDescription)
    : description(inDescription)
{
}

QString Character::shortDescription(){
    return description;
}

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

void Character::setDialogueLocation(QString location){
    dialogueLocation = location;
}

QString Character::getDialogueLocation(){
    return dialogueLocation;
}

QString Character::getDialogue(int choice){
    QFile file(dialogueLocation);
    QTextStream stream(&file);
    int line = 0;
    if(file.open(QIODevice::ReadOnly))
        while(!stream.atEnd()) {
            if(line == choice)
                dialogue = stream.readLine();
            else
                stream.readLine();
            line++;
        }
    return dialogue;
}



