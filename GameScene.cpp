#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include <list>
#include <fstream>
#include  "Primitive3D.h"
#include "Input.h"
//ImGui
#include "externals/imgui/imgui.h"
#include "externals/imgui/imgui_impl_dx12.h"
#include "externals/imgui/imgui_impl_win32.h"
#include <cassert>
#include <list>
#include <numbers>
#include "collision.h"
#include "DeltaTime.h"
#include "VectorFunction.h"
GameScene::GameScene() {

}

GameScene::~GameScene() {

}

void GameScene::Initialize(DirectXCommon* dxCommon) {

	dxCommon_ = dxCommon;

	player_.reset(new Player);
	player_->Initialize();
	inputHandler_.reset(new InputHandler);

	inputHandler_->AssiignMoveRightCommand2PressD();
	inputHandler_->AssiignMoveLeftCommand2PressA();
}

void GameScene::Update() {

	command_=(inputHandler_->HandleInput());

	if (command_) {
		command_->Exec(*player_.get());
	}

	player_->Update();
}

void GameScene::Draw2D() {
	player_->Draw();
}

void GameScene::Draw3D() {

	Model::PreDraw(dxCommon_->GetCommandList());

	Model::PostDraw();

}

