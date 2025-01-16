#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <QString>
#include <vector>
#include <QIcon>
using namespace std;

class Square;
class Piece {
public:
    Piece() = default;
    Piece(bool colour, int posX, int posY);
    virtual ~Piece() = default;

    QString getPieceName() const;
    void setPieceName(QString name);

    void movePiece(Square* squareToMove);
    Piece* movePieceSimulation(Square* squareToMove);
    vector<Square*> possibleMoves(vector<Square*> squares);
    virtual bool movementCriteria(Square* chessSquare);
    bool isSquareOfPiece(Square* chessSquare);

    int getPosX() const;
    int getPosY() const;
    bool getColour() const;

    QString getImagePath() const;
    void setImagePath(QString imagePath);
    virtual bool isKing();
    virtual bool isPawn();

protected:
    QString name_;
    bool colour_;
    int posX_, posY_;
    QString imagePath_;
};

class King : public Piece {
public:
    King() = default;
    King(bool colour, int posX, int posY);
    bool movementCriteria(Square* chessSquare);
    bool isKing();
private:
};

class Rook : public Piece {
public:
    Rook() = default;
    Rook(bool colour, int posX, int posY);
    bool movementCriteria(Square* chessSquare);
private:
};


class Knight : public Piece {
public:
    Knight() = default;
    Knight(bool colour, int posX, int posY);
    bool movementCriteria(Square* chessSquare);
private:
};

class Queen : public Piece {
public:
    Queen() = default;
    Queen(bool colour, int posX, int posY);
    bool movementCriteria(Square* chessSquare);
private: 
};

class Bishop : public Piece {
public:
    Bishop() = default;
    Bishop(bool colour, int posX, int posY);
    bool movementCriteria(Square* chessSquare);
private:
};

class Pawn : public Piece {
public:
    Pawn() = default;
    Pawn(bool colour, int posX, int posY);
    bool movementCriteria(Square* chessSquare);
    bool isPawn();
private:
};
#endif PIECE_H