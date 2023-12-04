#include "Player.h"
//#include "ImGuiManager.h"
//ImGui
#include "externals/imgui/imgui.h"
#include "externals/imgui/imgui_impl_dx12.h"
#include "externals/imgui/imgui_impl_win32.h"

#include "MatrixFunction.h"
#include "VectorFunction.h"
#include <algorithm>
#include <cassert>
#include <numbers>
#include "Sprite.h"
#include "TextureManager.h"
void Player::Initialize() {

	position_ = {100,50};

	textureHandle_ = TextureManager::LoadTexture("uvChecker.png");
	sprite_.reset(Sprite::Create(textureHandle_, { 0,0 }, { 50,50 }, { 1.0f,1.0f,1.0f,1.0f }));
	sprite_->SetAnchorPoint({ 0.5f,0.5f });
	sprite_->SetPosition(position_);
	speed_ = 1.0f;
}

void Player::Update() {
	sprite_->SetPosition(position_);
}


void Player::Draw() {
	sprite_->Draw();
}
