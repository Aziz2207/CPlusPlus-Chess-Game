#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPainter>
#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QBoxLayout>
#include "GameState.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    QWidget* getWindow() const;
    void init();
    vector<Piece*> game();

public slots:
    void newGame();

private:
    Chessboard* chessboard_;
    QWidget* window_;
};
#endif MAINWINDOW_H