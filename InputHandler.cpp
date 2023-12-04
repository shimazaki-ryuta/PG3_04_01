#include "InputHandler.h"
#include "Input.h"
void InputHandler::AssiignMoveLeftCommand2PressA() {
	ICommand* command = new MoveLeftCommand();
	this->PressKeyA_ = command;
}

void InputHandler::AssiignMoveRightCommand2PressD() {
	ICommand* command = new MoveRightCommand();
	this->PressKeyD_ = command;
}

ICommand* InputHandler::HandleInput() {
	if (Input::GetKey(DIK_D)) {
		return PressKeyD_;
	}
	if (Input::GetKey(DIK_A)) {
		return PressKeyA_;
	}
	return nullptr;
}