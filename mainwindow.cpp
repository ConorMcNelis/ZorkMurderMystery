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
    vector<Item> Items = currentRoom->getItemList();
    for(int i = 0; i < currentRoom->numberOfItems(); i++)
        if (ui->ItemList->currentText() == Items[i].getShortDescription())
            ui->Descriptions->setText(Items[i].getExamination());
}

void MainWindow::createRooms()  {
    //MainCharacter *player;
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
    Item *soup, *rustedSword, *rock, *stick;
    Character *Gardener;

    //Create Items
    soup = new Item("soup", 10, 2);
        soup->setLongDescription("On the oaken table you see a bowl of soup, steaming and filling the room with a pungent odour.");
        soup->setExamination(readFile(":/CharacterLongDescriptions/Text/SoupExamination.txt"));
    rustedSword = new Item("sword", 10, 2);
        rustedSword->setLongDescription(readFile(":/CharacterLongDescriptions/Text/Sword.txt"));
    stick = new Item("stick", 1, 11);
        stick->setLongDescription("A broken treebranch lays snapped in the grass, it could be used as a crude weapon. ");
        ui->Inventory->addItem(stick->getShortDescription());
    rock = new Item("rock", 2, 22);
        rock->setLongDescription("A heavy rock is wedged in the dirt, it could fit in the palm of your hand. ");

    //create Characters
    Gardener = new Character("The Gardener");
        ui->Descriptions->setText(Gardener->longDescription());

    a = new Room("The Main Lobby:");
        a->addItem(stick);
        a->addItem(rock);
    b = new Room("");
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

       currentRoom = a;
       printWelcome();
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
        int x = 1;
        //return("direction null");
    else
    {
       currentRoom = nextRoom;
       vector<Item> Items = currentRoom->getItemList();
       ui->Descriptions->setText(currentRoom->longDescription()+"\n");
       ui->ItemList->clear();
       for(int i = 0; i < currentRoom->numberOfItems(); i++)
           ui->ItemList->addItem(Items[i].getShortDescription());
      // return currentRoom->longDescription();
    }
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



