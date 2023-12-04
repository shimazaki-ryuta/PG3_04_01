#pragma once
#include "Command.h"
class InputHandler
{
public:
	ICommand* HandleInput();

	void AssiignMoveLeftCommand2PressA();
	void AssiignMoveRightCommand2PressD();
private:
	ICommand* PressKeyD_;
	ICommand* PressKeyA_;
};

