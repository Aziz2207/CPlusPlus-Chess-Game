#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "ChessBoard.h"
using namespace std;

class GameState {
public:
    GameState(bool teamTurn, bool kingInCheck);
    ~GameState() = default;

    void setChessboard(Chessboard* chessboard);
    void setPressedSquare(Square* pressedSquare);
    void setPressedPiece(Piece* pressedPiece);

    void squareClicked(Square* clickedSquare);
    void colourPossibleSquares(vector<Square*>& squares);
    void filterObstruction(vector<Square*>& squares, Piece* pieceToCheck);
    void removeObstacleSquare(vector<Square*>::iterator it, vector<Square*>& squares, bool& firstPiece, Piece* pieceToCheck);
    void baseFilters(vector<Square*>& squares, Piece* pieceToCheck);
    void filterTeam(vector<Square*>& squares, Piece* pieceToCheck);
    void filterPawn(vector<Square*>& squares, Piece* pieceToCheck);
    void filterChecks(vector<Square*>& squares, Piece* pieceToCheck, Square* startingSquare);
    void setSquaresEnemyPieces(vector<Square*>& squares, Piece* pieceToCheck);
    bool checkCheck(bool colour);
    bool checkMate(bool colour);
    void reset();

private:
    Chessboard* chessboard_ = nullptr;
    Square* pressedSquare_ = nullptr;
    Piece* pressedPiece_ = nullptr;
    vector<Square*> possibleSquares_;
    vector<Square*> temporaryPossibleSquares_;
    vector<Square*> temporaryEnemyPiecesSquares_;
    bool teamTurn_ = false;
    bool kingInCheck_ = false;
};
#endif GAMESTATE_H