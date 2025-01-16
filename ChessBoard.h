#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGridLayout>
#include "Square.h"
using namespace std;

class GameState;
class Chessboard : public QGridLayout {
public:
	Chessboard(GameState* gameState);

	vector <Piece*> getPieces() const;
	vector <Square*> getSquares() const;
	QBoxLayout* getBox() const;
	void changeSquareColour(Square* chessboardSquare, QString darkColor, QString lightColor);
	void messageBox(QString text);

	void createPieces(vector <Piece*> pieces);
	void createChessboard(vector <Piece*> pieces);
	void recreateChessboard(vector <Piece*> pieces);
	void createUi();

private:
	vector <Piece*> pieces_;
	vector <Square*> squares_;
	QBoxLayout* box_;
	GameState* gameState_;
};
#endif CHESSBOARD_H