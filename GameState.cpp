#include "GameState.h"
using namespace std;

namespace colours {
    const QString darkBlue = "background-color: rgb(51, 51, 255)";
    const QString lightBlue = "background-color: rgb(153, 204, 255)";

    const QString darkGreen = "background-color: rgb(0, 204, 0)";
    const QString lightGreen = "background-color: rgb(153, 255, 153)";

    const QString darkRed = "background-color: rgb(255, 51, 51)";
    const QString lightRed = "background-color: rgb(255, 102, 102)";
}

GameState::GameState(bool teamTurn, bool kingInCheck) : teamTurn_(teamTurn), kingInCheck_(kingInCheck) {};

void GameState::setPressedSquare(Square* pressedSquare) { pressedSquare_ = pressedSquare; };

void GameState::setChessboard(Chessboard* chessboard) { chessboard_ = chessboard; };

void GameState::setPressedPiece(Piece* pressedPiece) { pressedPiece_ = pressedPiece; };

void GameState::squareClicked(Square* clickedSquare) {
    using namespace colours;
    if (clickedSquare->getPiece() != nullptr && pressedPiece_ == nullptr) {
        if (clickedSquare->getPiece()->getColour() == teamTurn_) {
            pressedSquare_ = clickedSquare;
            pressedPiece_ = clickedSquare->getPiece();

            baseFilters(possibleSquares_, pressedPiece_);
            filterChecks(possibleSquares_, pressedPiece_, pressedSquare_);

            chessboard_->changeSquareColour(clickedSquare, darkBlue, lightBlue);
            colourPossibleSquares(possibleSquares_);
        }
    }
    else if (pressedPiece_ != nullptr) {
        for (Square* chessboardSquare : possibleSquares_) {
            chessboardSquare->setStyleSheet(chessboardSquare->getBaseColour());
            if (clickedSquare == chessboardSquare) {
                pressedSquare_->removePiece();
                pressedPiece_->movePiece(clickedSquare);
                kingInCheck_ = checkCheck(teamTurn_);
                teamTurn_ = !teamTurn_;
            }
        }
        if (kingInCheck_) {
            if (checkMate(teamTurn_)) {
                if (teamTurn_) {
                    chessboard_->messageBox("White player won");
                }
                else {
                    chessboard_->messageBox("Black player won");
                }
            }
        }
        kingInCheck_ = false;
        pressedSquare_->setStyleSheet(pressedSquare_->getBaseColour());
        pressedSquare_ = nullptr;
        pressedPiece_ = nullptr;
    }
};

void GameState::colourPossibleSquares(vector<Square*>& squares) {
    using namespace colours;
    for (Square* chessboardSquare : squares) {
        if (chessboardSquare->getPiece() != nullptr)
            chessboard_->changeSquareColour(chessboardSquare, darkRed, lightRed);
        else
            chessboard_->changeSquareColour(chessboardSquare, darkGreen, lightGreen);
    }
};

void GameState::setSquaresEnemyPieces(vector<Square*>& squares, Piece* pieceToCheck) {
    for (Square* chessboardSquare : squares) {
        if (chessboardSquare->getPiece() != nullptr)
            if (chessboardSquare->getPiece()->getColour() != pieceToCheck->getColour())
                temporaryEnemyPiecesSquares_.push_back(chessboardSquare);
    }
};

void GameState::removeObstacleSquare(vector<Square*>::iterator it, vector<Square*>& squares, bool& firstPiece, Piece* pieceToCheck) {
    if (it != squares.end()) {
        if (firstPiece) {
            squares.erase(it);
        }
        else if ((*it)->getPiece() != nullptr) {
            firstPiece = true;
        }
    }
};

void GameState::baseFilters(vector<Square*>& squares, Piece* pieceToCheck) {
    squares = pieceToCheck->possibleMoves(chessboard_->getSquares());
    filterObstruction(squares, pieceToCheck);
    filterTeam(squares, pieceToCheck);
};

void GameState::filterObstruction(vector<Square*>& squares, Piece* pieceToCheck) {

    bool firstPiece = false;
    for (int i = pieceToCheck->getPosX(); i < 8; i++) {
        vector<Square*>::iterator it = find_if(squares.begin(), squares.end(), [&](Square* s) { return s->getPosX() == i && s->getPosY() == pieceToCheck->getPosY(); });
        removeObstacleSquare(it, squares, firstPiece, pieceToCheck);
    }

    firstPiece = false;
    for (int i = pieceToCheck->getPosX(); i > -1; i--) {
        vector<Square*>::iterator it = find_if(squares.begin(), squares.end(), [&](Square* s) { return s->getPosX() == i && s->getPosY() == pieceToCheck->getPosY(); });
        removeObstacleSquare(it, squares, firstPiece, pieceToCheck);
    }

    firstPiece = false;
    for (int i = pieceToCheck->getPosY(); i > -1; i--) {
        vector<Square*>::iterator it = find_if(squares.begin(), squares.end(), [&](Square* s) { return s->getPosY() == i && s->getPosX() == pieceToCheck->getPosX(); });
        removeObstacleSquare(it, squares, firstPiece, pieceToCheck);
    }

    firstPiece = false;
    for (int i = pieceToCheck->getPosY(); i < 8; i++) {
        vector<Square*>::iterator it = find_if(squares.begin(), squares.end(), [&](Square* s) { return s->getPosY() == i && s->getPosX() == pieceToCheck->getPosX(); });
        removeObstacleSquare(it, squares, firstPiece, pieceToCheck);
    }

    firstPiece = false;
    int counter = 0;
    for (int i = pieceToCheck->getPosX(); i < 8; i++) {
        vector<Square*>::iterator it = find_if(squares.begin(), squares.end(), [&](Square* s) {return s->getPosX() == i && s->getPosY() == pieceToCheck->getPosY() - counter; });
        removeObstacleSquare(it, squares, firstPiece, pieceToCheck);
        counter++;
    }

    firstPiece = false;
    counter = 0;
    for (int i = pieceToCheck->getPosX(); i < 8; i++) {
        vector<Square*>::iterator it = find_if(squares.begin(), squares.end(), [&](Square* s) {return s->getPosX() == i && s->getPosY() == pieceToCheck->getPosY() + counter; });
        removeObstacleSquare(it, squares, firstPiece, pieceToCheck);
        counter++;
    }

    firstPiece = false;
    counter = 0;
    for (int i = pieceToCheck->getPosX(); i > -1; i--) {
        vector<Square*>::iterator it = find_if(squares.begin(), squares.end(), [&](Square* s) {return s->getPosX() == i && s->getPosY() == pieceToCheck->getPosY() - counter; });
        removeObstacleSquare(it, squares, firstPiece, pieceToCheck);
        counter++;
    }

    firstPiece = false;
    counter = 0;
    for (int i = pieceToCheck->getPosX(); i > -1; i--) {
        vector<Square*>::iterator it = find_if(squares.begin(), squares.end(), [&](Square* s) {return s->getPosX() == i && s->getPosY() == pieceToCheck->getPosY() + counter; });
        removeObstacleSquare(it, squares, firstPiece, pieceToCheck);
        counter++;
    }
};

void GameState::filterTeam(vector<Square*>& squares, Piece* pieceToCheck) {
    squares.erase(remove_if(squares.begin(), squares.end(), [&](Square* s) {
        if (s->getPiece() == nullptr)
            return false;
        return s->getPiece()->getColour() == pieceToCheck->getColour();
        }), squares.end());
};

void GameState::filterPawn(vector<Square*>& squares, Piece* pieceToCheck) {
    squares.erase(remove_if(squares.begin(), squares.end(), [&](Square* s) {
        return (s->getPiece() == nullptr && s->getPosY() != pieceToCheck->getPosY())
            ||
            (s->getPiece() != nullptr && s->getPosY() == pieceToCheck->getPosY());
        }), squares.end());
};

bool GameState::checkCheck(bool colour) {
    temporaryEnemyPiecesSquares_ = {};

    for (Square* chessboardSquare : chessboard_->getSquares()) {
        Piece* piece = chessboardSquare->getPiece();
        if (piece != nullptr)
            if (piece->getColour() == colour) {
                baseFilters(temporaryPossibleSquares_, piece);
                setSquaresEnemyPieces(temporaryPossibleSquares_, piece);

                for (Square* enemySquare : temporaryEnemyPiecesSquares_)
                    if (enemySquare->getPiece()->isKing())
                        return true;
            }
    }
    return false;
};

void GameState::filterChecks(vector<Square*>& squares, Piece* pieceToCheck, Square* startingSquare) {
    squares.erase(remove_if(squares.begin(), squares.end(), [&](Square* s) {
        Piece * pieceMemory = pieceToCheck->movePieceSimulation(s);
        startingSquare->setPiece(nullptr);
        bool check = checkCheck(!pieceToCheck->getColour());

        pieceToCheck->movePieceSimulation(startingSquare);
        if (pieceMemory == nullptr)
            s->setPiece(nullptr);
        else
            pieceMemory->movePieceSimulation(s);

        return check;
        }), squares.end());
};

bool GameState::checkMate(bool colour) {
    vector<Square*> squaresToCheck = {};

    for (Square* chessboardSquare : chessboard_->getSquares()) {
        Piece* piece = chessboardSquare->getPiece();
        if (piece != nullptr)
            if (piece->getColour() == colour) {
                baseFilters(squaresToCheck, piece);
                filterChecks(squaresToCheck, piece, chessboardSquare);

                if (!squaresToCheck.empty())
                    return false;
            }
    }
    return true;
};

void GameState::reset() {
    if (pressedSquare_ != nullptr)
        pressedSquare_->setStyleSheet(pressedSquare_->getBaseColour());
    pressedSquare_ = nullptr;
    pressedPiece_ = nullptr;
    for (Square* chessboardSquare : possibleSquares_) {
        chessboardSquare->setStyleSheet(chessboardSquare->getBaseColour());
    }
    teamTurn_ = false;
    kingInCheck_ = false;
};