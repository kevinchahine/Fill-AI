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

bool UserInterface::simpleUpdate()
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
		return true;
	}
	else {
		cout << "Game object not set in User Interface" << endl;
		
		return false;
	}
}
