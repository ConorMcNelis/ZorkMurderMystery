#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include <QInputDialog>
#include "Command.h"
#include "Room.h"
#include "item.h"
#include "Character.h"
#include "main.h"
//#include "MainCharacter.h"
#include <iostream>
#include <QString>
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
    Room *currentRoom;
   // MainCharacter *player;
    void createRooms();
    void printWelcome();
    void printHelp();
    void createItems();
    void displayItems();
    void createCharacters();
    void displayCharacters();
    void go(string direction);


private slots:

    void on_ExitButton_clicked();

    void on_HTPButton_clicked();

    void on_StartButton_clicked();

    void on_ReturnButton_clicked();

    void on_GoNorthButton_clicked();

    void on_GoEastButton_clicked();

    void on_GoWestButton_clicked();

    void on_GoSouthButton_clicked();
private:
    Ui::MainWindow *ui;
    //MainWindow();
    void play();
    void goRoom(Command command);
};
#endif // MAINWINDOW_H
