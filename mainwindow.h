#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include <QInputDialog>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "Room.h"
#include "MainLobby.h"
#include "item.h"
#include "Character.h"
#include "main.h"
#include <iostream>
#include <QString>
#define InventorySize (6)
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MainLobby *a;
    Room *currentRoom;
    QFile *descriptionText;
    Character *currentCharacter;
   // MainCharacter *player;

private:
    Ui::MainWindow *ui;

private slots:

    void on_ExitButton_clicked();

    void on_HTPButton_clicked();

    void on_StartButton_clicked();

    void on_ReturnButton_clicked();

    void on_GoNorthButton_clicked();

    void on_GoEastButton_clicked();

    void on_GoWestButton_clicked();

    void on_GoSouthButton_clicked();

    void on_ExamineButton_clicked();

    void on_Option1_clicked();

    void on_Option2_clicked();

    void on_Option3_clicked();

    void on_BackButton_clicked();

    void on_InventoryList_activated(const QString &arg1);

    void on_VicButton_clicked();

    void on_MCButton_clicked();

protected:

    vector<Item> Items;
    vector<Item> AllItems;
    vector<Character> Characters;
    vector<Character>::iterator it;
    Item Inventory[InventorySize];
    Item *ptr;
    int counter : 4;
    void createRooms();
    void printWelcome();
    void printHelp();
    void createItems();
    void displayItems();
    void createCharacters();
    void displayCharacters();
    void go(string direction);
    void MainLobbyMethod(Character *suspect);
    void createInventory();
    QString readFile(QString fileLocation);

};
#endif // MAINWINDOW_H
