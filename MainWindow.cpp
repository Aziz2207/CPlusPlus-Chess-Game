#include "MainWindow.h"
using namespace std;

vector<Piece*> MainWindow::game() {
    vector<Piece*> pieces = {};

    King* whiteKing = new King(false, 7, 4);
    King* blackKing = new King(true, 0, 4);

    Knight* whiteKnight0 = new Knight(false, 7, 1);
    Knight* whiteKnight1 = new Knight(false, 7, 6);
    Knight* blackKnight0 = new Knight(true, 0, 1);
    Knight* blackKnight1 = new Knight(true, 0, 6);

    Rook* whiteRook0 = new Rook(false, 7, 0);
    Rook* whiteRook1 = new Rook(false, 7, 7);
    Rook* blackRook0 = new Rook(true, 0, 0);
    Rook* blackRook1 = new Rook(true, 0, 7);

    Queen* whiteQueen = new Queen(false, 7, 3);
    Queen* blackQueen = new Queen(true, 0, 3);

    Bishop* whiteBishop0 = new Bishop(false, 7, 2);
    Bishop* whiteBishop1 = new Bishop(false, 7, 5);
    Bishop* blackBishop0 = new Bishop(true, 0, 2);
    Bishop* blackBishop1 = new Bishop(true, 0, 5);

    Pawn* whitePawn0 = new Pawn(false, 6, 0);
    Pawn* whitePawn1 = new Pawn(false, 6, 1);
    Pawn* whitePawn2 = new Pawn(false, 6, 2);
    Pawn* whitePawn3 = new Pawn(false, 6, 3);
    Pawn* whitePawn4 = new Pawn(false, 6, 4);
    Pawn* whitePawn5 = new Pawn(false, 6, 5);
    Pawn* whitePawn6 = new Pawn(false, 6, 6);
    Pawn* whitePawn7 = new Pawn(false, 6, 7);
    Pawn* blackPawn0 = new Pawn(true, 1, 0);
    Pawn* blackPawn1 = new Pawn(true, 1, 1);
    Pawn* blackPawn2 = new Pawn(true, 1, 2);
    Pawn* blackPawn3 = new Pawn(true, 1, 3);
    Pawn* blackPawn4 = new Pawn(true, 1, 4);
    Pawn* blackPawn5 = new Pawn(true, 1, 5);
    Pawn* blackPawn6 = new Pawn(true, 1, 6);
    Pawn* blackPawn7 = new Pawn(true, 1, 7);

    pieces.push_back(whiteKing);
    pieces.push_back(blackKing);

    pieces.push_back(whiteKnight0);
    pieces.push_back(whiteKnight1);
    pieces.push_back(blackKnight0);
    pieces.push_back(blackKnight1);

    pieces.push_back(whiteRook0);
    pieces.push_back(whiteRook1);
    pieces.push_back(blackRook0);
    pieces.push_back(blackRook1);

    pieces.push_back(whiteQueen);
    pieces.push_back(blackQueen);

    pieces.push_back(whiteBishop0);
    pieces.push_back(whiteBishop1);
    pieces.push_back(blackBishop0);
    pieces.push_back(blackBishop1);

    pieces.push_back(whitePawn0);
    pieces.push_back(whitePawn1);
    pieces.push_back(whitePawn2);
    pieces.push_back(whitePawn3);
    pieces.push_back(whitePawn4);
    pieces.push_back(whitePawn5);
    pieces.push_back(whitePawn6);
    pieces.push_back(whitePawn7);
    pieces.push_back(blackPawn0);
    pieces.push_back(blackPawn1);
    pieces.push_back(blackPawn2);
    pieces.push_back(blackPawn3);
    pieces.push_back(blackPawn4);
    pieces.push_back(blackPawn5);
    pieces.push_back(blackPawn6);
    pieces.push_back(blackPawn7);

    return pieces;
}


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) { init(); }

MainWindow::~MainWindow() = default;

void MainWindow::init() {
    const int buttonWidth = 200;
    const int buttonLength = 50;

    GameState* gameState = new GameState(false, false);
    chessboard_ = new Chessboard(gameState);
    chessboard_->createChessboard(game());

    QBoxLayout* buttonBox = new QBoxLayout((QBoxLayout::TopToBottom));

    QPushButton* newGameButton = new QPushButton("New Game");
    newGameButton->setFixedSize(QSize(buttonWidth, buttonLength));


    buttonBox->addWidget(newGameButton);

    connect(newGameButton, SIGNAL(clicked()), this, SLOT(newGame()));

    chessboard_->getBox()->addLayout(buttonBox);

    window_ = new QWidget();
    window_->setLayout(chessboard_->getBox());
    window_->setWindowTitle("Chess");
};

QWidget* MainWindow::getWindow() const {
    return window_;
};

void MainWindow::newGame() { chessboard_->recreateChessboard(game()); };