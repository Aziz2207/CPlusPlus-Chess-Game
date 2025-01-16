#ifndef SQUARE_H
#define SQUARE_H
#include <QPushButton>
#include <QObject>
#include <QFont>
#include "Piece.h"
using namespace std;

class GameState;
class Square : public QPushButton {
    Q_OBJECT
public:
    Square(int posX, int posY, int size_, GameState* gameState, QWidget* parent = nullptr);
    ~Square() = default;
    void init();

    void addPiece(Piece* piece);
    void removePiece();

    int getPosX() const;
    int getPosY() const;
    string getBaseColourName() const;
    Piece* getPiece() const;
    QString getBaseColour() const;
    void setPiece(Piece* piece);
    void setBaseColour(QString baseColour);
    void setBaseColourName(string baseColourName);
    void setGameState(GameState* gameState);

public slots:
    void clickEvent();

private:
    int posX_, posY_, size_;
    Piece* piece_ = nullptr;
    QString baseColour_;
    string baseColourName_;
    GameState* gameState_;
};

#endif SQUARE_H