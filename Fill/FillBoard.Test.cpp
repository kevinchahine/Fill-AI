#include "FillBoard.Test.h"

bool FillBoard_Test::init()
{
	vector<vector<FillBoard::Space>> board(2);
	board[0].resize(5);
	board[1].resize(3);
	board[0] = { FillBoard::Empty, FillBoard::Obstacle, FillBoard::UpRight, FillBoard::Horizontal, FillBoard::Vertical };
	board[1] = { FillBoard::DownLeft, FillBoard::DownRight, FillBoard::UpLeft };

	FillBoard b1;			// default
	FillBoard b2(7, 8);		// 
	FillBoard b3(board);	// full
	FillBoard b4(b3);		// copy

	cout << "---b1---" << endl;
	b1.print();

	cout << "---b2---" << endl;
	b2.print();

	cout << "---b3---" << endl;
	b3.print();

	cout << "---b4---" << endl;
	b4.print();
	
	return true;
}

bool FillBoard_Test::full()
{
	bool constructor = FillBoard_Test::init();

	return constructor;
}
