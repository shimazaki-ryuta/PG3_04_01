#pragma once
#include "Vector2.h"
#include "Sprite.h"

#include <sstream>
#include <vector>

#include "Input.h"

#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Model.h"

#include "CommonFiles/DirectXCommon.h"

#include "DebugCamera.h"

#include "Player.h"
#include "InputHandler.h"


#include <array>
#include <memory>
class GameScene
{
public:

	GameScene();
	~GameScene();
	void Initialize(DirectXCommon* dxCommon);
	void Update();
	void Draw3D();
	void Draw2D();

	

private:
	
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;

	std::unique_ptr <InputHandler> inputHandler_ = nullptr;
	ICommand* command_ = nullptr;

	std::unique_ptr<Player> player_;
	
};

