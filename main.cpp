#include "MainWindow.h"
/*
* Livrable 1 du projet de INF1015
* \file main.cpp
* \author Aziz Hidri et Patrick Leonnel Nzudom Ketchateu
* \date 15 avril 2024
* Cree le 09 avril 2024
* Les images viennent de cette page wikipedia : https://commons.wikimedia.org/wiki/Category:PNG_chess_pieces/Standard_transparent
*/
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MainWindow* mainWindow = new MainWindow();
    mainWindow->getWindow()->show();

    return a.exec();
}
