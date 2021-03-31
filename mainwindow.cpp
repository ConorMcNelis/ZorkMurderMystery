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

void MainWindow::createRooms()  {

    //MainCharacter *player;
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
    Item *soup, *rustedSword, *rock, *stick;
    Character *Gardener;

   // player = new MainCharacter("Player");

    soup = new Item("soup", 10, 2);
        soup->setLongDescription("On the oaken table you see a bowl of soup, steaming and filling the room with a pungent odour. ");
    rustedSword = new Item("sword", 10, 2);
        rustedSword->setLongDescription("At the east side of the room a rusted sword is jammed into a crack in the wall. There must have been a fight here. ");
    stick = new Item("stick", 1, 11);
        stick->setLongDescription("A broken treebranch lays snapped in the grass, it could be used as a crude weapon. ");
    rock = new Item("rock", 2, 22);
        rock->setLongDescription("A heavy rock is wedged in the dirt, it could fit in the palm of your hand. ");

    Gardener = new Character("The Gardener");
        //ui->Descriptions->setText(Gardener->longDescription());

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

/**
 *  Main play routine.  Loops until end of play.
 */
/*
void MainWindow::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        //Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        //finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
       // delete command;
    }
    ui->Descriptions->setText("\nend\n");
}
*/
void MainWindow::printWelcome() {
    ui->Descriptions->setText("start\n"
                              "'info' for help\n\n"+
                              currentRoom->longDescription()+"\n");
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
/*
bool MainWindow::processCommand(Command command) {
    if (command.isUnknown()) {
        ui->Descriptions->setText("invalid input\n");
        return false;
    }

    QString commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        ui->Descriptions->setText("        [j]        \n"
                                  "         |         \n"
                                  "         |         \n"
                                  "[h] --- [f] --- [g]\n"
                                  "         |         \n"
                                  "         |         \n"
                                  "[c] --- [a] --- [b]\n"
                                  "         |         \n"
                                  "         |         \n"
                                  "[i] --- [d] --- [e]\n");

        }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        ui->Descriptions->setText("incomplete input\n");
        }
        else
         if (command.hasSecondWord()) {
        ui->Descriptions->setText("you're trying to take " + command.getSecondWord()+"\n");
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            ui->Descriptions->setText("item is not in room \n");
        else{
            ui->Descriptions->setText("item is in room\n"
"index number "+QString::number(location)+"\n\n"+
currentRoom->longDescription()+"\n");
     }
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"\n");;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() \n");;
            itemsInRoom.push_Back;
        }
    }
/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            ui->Descriptions->setText("overdefined input\n");
        else
            return true; /**signal to quit/
    }
    else if (commandWord.compare("inventory") == 0){
        if (command.hasSecondWord())
            ui->Descriptions->setText("overdefined input");
        //else
     //       cout << player->getInventory();
    }
    return false;
}
*/
/** COMMANDS **/
/*
void MainWindow::printHelp() {
    ui->Descriptions->setText("valid inputs are\n");
    parser.showCommands();

}

*/


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
       ui->Descriptions->setText(currentRoom->longDescription()+"\n");
      // return currentRoom->longDescription();
    }
}




