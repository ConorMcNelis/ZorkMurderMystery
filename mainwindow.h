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
#include "animateobject.h"
#include "map.h"
#include "accusationcheck.h"
#include <iostream>
#include <QString>
#include <QSound>
#define InventorySize (5)
#define DoorNoise QSound::play("://door_creak_closing.wav")

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


    template <class T>
    void bubbleSort(T a[], int n) {
        for (int i = 0; i < n - 1; i++)
            for (int j = n - 1; i < j; j--)
                if (a[j] < a[j - 1] && a[j] != "" && a[j-1] != "")
                  swap(a[j], a[j - 1]);
    }


private:
    Ui::MainWindow *ui;
    Map *map;
    AccusationCheck *check;

private slots:

    void on_ExitButton_clicked();

    void on_HTPButton_clicked();

    void on_StartButton_clicked();

    void on_ReturnButton_clicked();

    void on_GoNorthButton_clicked();

    void on_GoEastButton_clicked();

    void on_GoWestButton_clicked();

    void on_GoSouthButton_clicked();

    void on_TalkButton_clicked();

    void on_ExamineButton_clicked();

    void on_Option1_clicked();

    void on_Option2_clicked();

    void on_Option3_clicked();

    void on_BackButton_clicked();

    void on_InventoryList_activated(const QString &arg1);

    void on_OpenMapButton_clicked();

    void on_AccuseButton_clicked();

    void on_takeButton_clicked();

    void on_VictimInfo_clicked();

    void on_CharacterInfo_clicked();

protected:

    vector<Item> Items;
    vector<Character> Characters;
    vector<Character>::iterator it;
    #ifdef InventorySize
    Item Inventory[InventorySize];
    Item *ptr = Inventory;
    int counter :4;
    #endif
    union
    {
        QString output;
        bool exists;
        QString ret;
    };

    void createRooms();
    void printWelcome();
    void printHelp();
    void createItems();
    void displayItems();
    void createCharacters();
    void displayCharacters();
    void createInventory();
    void go(string direction);
    void MainLobbyMethod(Character *suspect);
    QString readFile(QString fileLocation);
};
#endif // MAINWINDOW_H
