#include "ChessBoard.h"
#include "GameState.h"
#include "QMessageBox"
using namespace std;

namespace constants {
    const QString blackSquareColour = "background-color: rgb(128, 128, 128)";
    const QString whiteSquareColour = "background-color: rgb(255, 255, 215)";

    const int chessboardSize = 800;
    const int messageBoxSize = 500;
    const int messageBoxLength = 200;
}

Chessboard::Chessboard(GameState* gameState) {
    gameState_ = gameState;
    gameState_->setChessboard(this);
};

vector <Piece*> Chessboard::getPieces() const { return pieces_; };

vector <Square*> Chessboard::getSquares() const { return squares_; };

QBoxLayout* Chessboard::getBox() const { return box_; };

void Chessboard::createPieces(vector<Piece*> pieces) {
    pieces_ = {};
    for (Piece* piece : pieces)
        pieces_.push_back(piece);
};

void Chessboard::createChessboard(vector<Piece*> pieces) {
    using namespace constants;
    createPieces(pieces);

    squares_ = {};
    int counter = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Square* chessboardSquare = new Square(i, j, chessboardSize / 8, gameState_);
            squares_.push_back(chessboardSquare);
            if (counter % 2 == 0) {
                chessboardSquare->setBaseColour(blackSquareColour);
                chessboardSquare->setBaseColourName("black");
            }
            else {
                chessboardSquare->setBaseColour(whiteSquareColour);
                chessboardSquare->setBaseColourName("white");
            }
            chessboardSquare->setStyleSheet(chessboardSquare->getBaseColour());

            addWidget(chessboardSquare, i, j, 1, 1);
            counter++;
            for (Piece* p : pieces_) {
                if (p->getPosX() == i && p->getPosY() == j)
                    chessboardSquare->addPiece(p);
            }
        }
        counter--;
    }

    createUi();
};

void Chessboard::recreateChessboard(vector<Piece*> pieces) {
    createPieces(pieces);
    for (Square* chessboardSquare : squares_) {
        chessboardSquare->removePiece();
        for (Piece* p : pieces_) {
            if (p->getPosX() == chessboardSquare->getPosX() && p->getPosY() == chessboardSquare->getPosY())
                chessboardSquare->addPiece(p);
        }
    }
    gameState_->reset();
};

void Chessboard::createUi() {
    using namespace constants;

    QWidget* square = new QWidget;
    square->setLayout(this);
    square->setMaximumHeight(chessboardSize);
    square->setMaximumWidth(chessboardSize);
    QBoxLayout* chessboardBox = new QBoxLayout((QBoxLayout::LeftToRight));
    box_ = chessboardBox;
    box_->addWidget(square);
};

void Chessboard::changeSquareColour(Square* chessboardSquare, QString darkColor, QString lightColor) {
    if (chessboardSquare->getBaseColourName() == "black")
        chessboardSquare->setStyleSheet(darkColor);
    else
        chessboardSquare->setStyleSheet(lightColor);
};

void Chessboard::messageBox(QString text) {
    using namespace constants;
    QMessageBox message;
    message.setFixedSize(messageBoxSize, messageBoxLength);
};