#include "Piece.h"
#include "Square.h"
using namespace std;

Piece::Piece(bool colour, int posX, int posY) : colour_(colour), posX_(posX), posY_(posY) {};

QString Piece::getPieceName() const { return name_; };
void Piece::setPieceName(QString name) { name_ = name; };

int Piece::getPosX() const { return posX_; };
int Piece::getPosY() const { return posY_; };
bool Piece::getColour() const { return colour_; };

QString Piece::getImagePath() const { return imagePath_; };
void Piece::setImagePath(QString imagePath) { imagePath_ = imagePath; };

void Piece::movePiece(Square* squareToMove) {
    posX_ = squareToMove->getPosX();
    posY_ = squareToMove->getPosY();
    squareToMove->addPiece(this);
};

Piece* Piece::movePieceSimulation(Square* squareToMove) {
    Piece* pieceMemory = squareToMove->getPiece();
    posX_ = squareToMove->getPosX();
    posY_ = squareToMove->getPosY();
    squareToMove->setPiece(this);
    return pieceMemory;
};

vector<Square*> Piece::possibleMoves(vector<Square*> squares) {
    vector<Square*> possibleSquares;
    for (Square* chessboardSquare : squares) {
        if (movementCriteria(chessboardSquare))
            possibleSquares.push_back(chessboardSquare);
    }
    return possibleSquares;
};

bool Piece::movementCriteria(Square* chessSquare) {
    return chessSquare->getPosX() == 0;
};

bool Piece::isSquareOfPiece(Square* chessSquare) {
    if (chessSquare->getPosX() == posX_ && chessSquare->getPosY() == posY_)
        return true;
    return false;
};

bool Piece::isKing() { return false; };
bool Piece::isPawn() { return false; };

King::King(bool colour, int posX, int posY) : Piece(colour, posX, posY) {
    if (colour) {
        name_ = "Black King";
        imagePath_ = "BlackKing.png";
    }
    else {
        name_ = "White King";
        imagePath_ = "WhiteKing.png";
    }
};

bool King::movementCriteria(Square* chessSquare) {
    if (isSquareOfPiece(chessSquare))
        return false;

    return (chessSquare->getPosX() >= posX_ - 1
        && chessSquare->getPosX() <= posX_ + 1)
        &&
        (chessSquare->getPosY() >= posY_ - 1
            && chessSquare->getPosY() <= posY_ + 1);
};

bool King::isKing() { return true; };

Rook::Rook(bool colour, int posX, int posY) : Piece(colour, posX, posY) {
    if (colour) {
        name_ = "Black Rook";
        imagePath_ = "BlackTower.png";
    }
    else {
        name_ = "White Rook";
        imagePath_ = "WhiteTower.png";
    }
};

bool Rook::movementCriteria(Square* chessSquare) {
    if (isSquareOfPiece(chessSquare))
        return false;

    return chessSquare->getPosX() == posX_
        || chessSquare->getPosY() == posY_;
};

Knight::Knight(bool colour, int posX, int posY) : Piece(colour, posX, posY) {
    if (colour) {
        name_ = "Black Knight";
        imagePath_ = "BlackHorse.png";
    }
    else {
        name_ = "White Knight";
        imagePath_ = "WhiteHorse.png";
    }
};

bool Knight::movementCriteria(Square* chessSquare) {
    if (isSquareOfPiece(chessSquare))
        return false;

    return (abs(posX_ - chessSquare->getPosX()) == 2 || abs(posY_ - chessSquare->getPosY()) == 2)
        &&
        (abs(posX_ - chessSquare->getPosX()) == 1 || abs(posY_ - chessSquare->getPosY()) == 1);
};

Queen::Queen(bool colour, int posX, int posY) : Piece(colour, posX, posY) {
    if (colour) {
        name_ = "Black Queen";
        imagePath_ = "BlackQueen.png";
    }
    else {
        name_ = "White Queen";
        imagePath_ = "WhiteQueen.png";
    }
};

bool Queen::movementCriteria(Square* chessSquare) {
    if (isSquareOfPiece(chessSquare)) {
        return false;
    }
    return chessSquare->getPosX() == posX_ || chessSquare->getPosY() == posY_
        || (abs(chessSquare->getPosX() - posX_) == abs(chessSquare->getPosY() - posY_));
};

Bishop::Bishop(bool colour, int posX, int posY) : Piece(colour, posX, posY) {
    if (colour) {
        name_ = "Black Bishop";
        imagePath_ = "BlackBishop.png";
    }
    else {
        name_ = "White Bishop";
        imagePath_ = "WhiteBishop.png";
    }
};

bool Bishop::movementCriteria(Square* chessSquare) {
    if (isSquareOfPiece(chessSquare)) {
        return false;
    }
    return (abs(chessSquare->getPosX() - posX_) == abs(chessSquare->getPosY() - posY_));
};

Pawn::Pawn(bool colour, int posX, int posY) : Piece(colour, posX, posY) {
    if (colour) {
        name_ = "Black Pawn";
        imagePath_ = "BlackPawn.png";
    }
    else {
        name_ = "White Pawn";
        imagePath_ = "WhitePawn.png";
    }
};

bool Pawn::movementCriteria(Square* chessSquare) {
    if (isSquareOfPiece(chessSquare)) {
        return false;
    }
    if (colour_) {
        return (chessSquare->getPosX() - posX_ == 1 && (posY_ == chessSquare->getPosY() || abs(chessSquare->getPosY() - posY_) == 1))
            ||
            (chessSquare->getPosX() - posX_ == 2 && posY_ == chessSquare->getPosY() && posX_ == 1);
    }
    else {
        return (posX_ - chessSquare->getPosX() == 1 && (posY_ == chessSquare->getPosY() || abs(chessSquare->getPosY() - posY_) == 1))
            ||
            (posX_ - chessSquare->getPosX() == 2 && posY_ == chessSquare->getPosY() && posX_ == 6);;
    }
};

bool Pawn::isPawn() { return true; };
