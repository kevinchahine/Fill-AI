#include "UserInterface.h"

UserInterface::UserInterface() :
	currentGamePtr(nullptr)
{}

UserInterface::~UserInterface()
{}

void UserInterface::setCurrentGamePtr(FillGame * gamePtr)
{
	this->currentGamePtr = gamePtr;
}

FillGame * UserInterface::getCurrentGamePtr()
{
	return currentGamePtr;
}

const FillGame * UserInterface::getCurrentGamePtr() const
{
	return currentGamePtr;
}

int UserInterface::simpleUpdate()
{
	if (currentGamePtr != nullptr) {
		FillGame & game = *currentGamePtr;

		game.print();

		char input;
		cin >> input;

		input = tolower(input);

		switch (input) {
		case 'a':
			game.moveLeft();
			break;
		case 'w':
			game.moveUp();
			break;
		case 's':
			game.moveDown();
			break;
		case 'd':
			game.moveRight();
			break;
		default:
			cout << "Input not regocnized" << endl;
			break;
		}

		switch (game.isSolved()) {
		case 2:
			cout << "Hurry You Won!!!" << endl;
			return 2;
		case 1:
			cout << "Play on" << endl;
			return 1;
		case 0:
			cout << "Game Lost no moves will lead to a win" << endl;
			return 0;
		default:
			cout << "Default case triggered" << endl;
			return -1;
		}
	}
	else {
		cout << "Game object not set in User Interface" << endl;
		
		return 0;
	}
}
