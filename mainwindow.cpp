#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->GameWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ExitButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_HTPButton_clicked()
{
    ui->GameWidget->setCurrentIndex(1);
}

void MainWindow::on_StartButton_clicked()
{
    ui->GameWidget->setCurrentIndex(2);
    createRooms();
    //play();
}

void MainWindow::on_ReturnButton_clicked()
{
     ui->GameWidget->setCurrentIndex(0);
}

void MainWindow::on_GoNorthButton_clicked(){
    go("north");
}

void MainWindow::on_GoEastButton_clicked(){
    go("east");
}

void MainWindow::on_GoWestButton_clicked(){
    go("west");
}

void MainWindow::on_GoSouthButton_clicked(){
    go("south");
}

void MainWindow::on_ExamineButton_clicked(){
    bool exists = false;
    bool Icheck = false;
    int counter = 0;
    Items = currentRoom->getItemList();
    Characters = a->getCharacterList();
    it = Characters.begin();
    for(int i = 0; i < currentRoom->numberOfItems(); i++)
    {
        if (ui->ItemList->currentText() == Items[i].getShortDescription())
        {
            ui->Descriptions->setText(Items[i].getLongDescription());
            Icheck = true;
        }
        else if(i < (int)Characters.size())
            if (ui->ItemList->currentText() == Characters[i].shortDescription()){
                it += i;
                currentCharacter = &(*it);
                MainLobbyMethod(currentCharacter);
            }

        for(int x = 0; x < 4; x++)
        {
            if(Items[i].getShortDescription() == Inventory[i])
            {
               exists = true;
            }
        }
    }

    if(exists == false && Icheck == true)
    {
        counter++;
        if(counter == 4)
        {
            ui->Descriptions->setText("Your Inventory is full!");
        }
        else
        {
            Inventory[counter] = ui->ItemList->currentText();
            ui->InventoryList->addItem(Inventory[counter]);
        }
    }
}

void MainWindow::on_Option1_clicked(){
    ui->DialogueBox->setText(currentCharacter->getDialogue(1));
}

void MainWindow::on_Option2_clicked(){
    ui->DialogueBox->setText(currentCharacter->getDialogue(2));
}

void MainWindow::on_Option3_clicked(){
    ui->DialogueBox->setText(currentCharacter->getDialogue(3));
}

void MainWindow::on_BackButton_clicked(){
    ui->GameWidget->setCurrentIndex(2);
}

void MainWindow::createRooms()  {
    //MainCharacter *player;
    Room *b, *c, *d, *e, *f, *g, *h, *i, *j;
    Item *soup, *rustedSword, *rock, *stick;
    Character *Gardener, *Butler;


    //Create Items
    soup = new Item("soup", 10, 2);
        soup->setLongDescription("On the oaken table you see a bowl of soup, steaming and filling the room with a pungent odour.");
        soup->setExamination(readFile(":/Examinations/Text/Examinations/SoupExamination.txt"));
    rustedSword = new Item("sword", 10, 2);
        rustedSword->setLongDescription(readFile(":/CharacterLongDescriptions/Text/Sword.txt"));
    stick = new Item("stick", 1, 11);
        stick->setLongDescription("A broken treebranch lays snapped in the grass, it could be used as a crude weapon. ");
    rock = new Item("rock", 2, 22);
        rock->setLongDescription("A heavy rock is wedged in the dirt, it could fit in the palm of your hand. ");

    //create Characters
    Gardener = new Character("The Gardener");
        Gardener->setDialogueLocation(":/Examinations/Dialogue/Text/Examinations/Character Dialogue/Gardener Dialogue.txt");
    Butler = new Character("The Butler");
        Butler->setDialogueLocation(":/Examinations/Dialogue/Text/Examinations/Character Dialogue/Butler Dialogue.txt");

    a = new MainLobby("The Main Lobby:");
        a->addItem(stick);
        a->addItem(rock);
        a->addCharacter(Gardener);
        a->addCharacter(Butler);
    b = new Room("b");
    c = new Room("c");
    d = new Room("d");
        d->addItem(new Item("xx", 3, 33));
    e = new Room("e");
    f = new Room("f");
        f->addItem(new Item("yy", 4, 44));
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("You enter a cozy cottage, a roaring fireplace crackles at the west side of the room, and an oaken table lies in the centre. ");
         j->addItem(soup);
         j->addItem(rustedSword);



//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(j, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL, NULL, f, NULL);

       currentRoom = b;

       go("west");
}

void MainWindow::printWelcome() {
    ui->Descriptions->setText("start\n"
                              "'info' for help\n\n"+
                              currentRoom->longDescription()+"\n");
}


void MainWindow::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        ui->Descriptions->setText("There's nothing in that direction\n"+currentRoom->longDescription()+"\n");
    else
    {
        //ui->Descriptions->setText("Current Room: "+currentRoom->shortDescription()+"\nNext Room: "+nextRoom->shortDescription());
       currentRoom = nextRoom;
       ui->Descriptions->setText(currentRoom->longDescription()+"\n");
       if (currentRoom->shortDescription() != "" ){
           //ui->Descriptions->setText("This isn't the main lobby");
           vector<Item> Items = currentRoom->getItemList();
           ui->ItemList->clear();
           for(int i = 0; i < currentRoom->numberOfItems(); i++)
               ui->ItemList->addItem(Items[i].getShortDescription());
       }
       else{
           MainLobby *CurrentRoom = a;
           vector<Character> Characters = CurrentRoom->getCharacterList();
           ui->Descriptions->setText(CurrentRoom->longDescription()+"\n");
           ui->ItemList->clear();
           for(int i = 0; i < CurrentRoom->numberOfCharacters(); i++)
               ui->ItemList->addItem(Characters[i].shortDescription());
       }
    }
}

void MainWindow::MainLobbyMethod(Character *suspect){
    ui->GameWidget->setCurrentIndex(3);
    ui->DialogueBox->setText(suspect->getDialogue(0));
}

QString MainWindow::readFile(QString fileLocation){
    QString ret = "";
    QFile file(fileLocation);
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




