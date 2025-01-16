#include "Square.h"
#include "GameState.h"
using namespace std;

Square::Square(int posX, int posY, int size, GameState* gameState, QWidget* parent) : QPushButton(parent) {
    posX_ = posX;
    posY_ = posY;
    size_ = size;
    gameState_ = gameState;
    init();
};

void Square::init() {
    setFixedSize(QSize(size_, size_));
    setIconSize(QSize(size_, size_));
    connect(this, SIGNAL(clicked()), this, SLOT(clickEvent()));
}

int Square::getPosX() const { return posX_; };

int Square::getPosY() const { return posY_; };

Piece* Square::getPiece() const { return piece_; };

QString Square::getBaseColour() const { return baseColour_; };

string Square::getBaseColourName() const { return baseColourName_; };

void Square::setBaseColour(QString baseColour) { baseColour_ = baseColour; };

void Square::setBaseColourName(string baseColourName) { baseColourName_ = baseColourName; };

void Square::setGameState(GameState* gameState) { gameState_ = gameState; };

void Square::setPiece(Piece* piece) { piece_ = piece; };

void Square::clickEvent() { gameState_->squareClicked(this); };

void Square::addPiece(Piece* piece) {
    piece_ = piece;
    setIcon(QIcon(piece->getImagePath()));
}

void Square::removePiece() {
    piece_ = nullptr;
    setIcon(QIcon());
}