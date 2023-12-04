#pragma once
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "vector2.h"
class Player {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void MoveLeft() { position_.x -= speed_; };
	void MoveRight() { position_.x += speed_; };

private:
	
	uint32_t textureHandle_ = 0u;
	std::unique_ptr<Sprite> sprite_;
	Vector2 position_;
	float speed_;
};
