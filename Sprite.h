#pragma once
//メモリリークチェック
#include "D3DResourceLeakChacker.h"
#include <memory>

#include "Vector2.h"
#include "Vector4.h"
#include "Matrix.h"

#include <d3d12.h>
#include <string>
#include <wrl.h>

class Sprite
{
public:
	//static std::shared_ptr<D3DResourceLeakChacker> leakchecker;
	enum class BlendMode
	{
		None,
		Normal,
		Add,
		Subtract,
		Multiply,
		Screen,
		CountofBlendMode, //PSO作成に使う値、使用出来ない
	};

	struct VertexData
	{
		Vector4 position;
		Vector2 texcoord;
	};
	struct Material
	{
		Vector4 color;
		Matrix4x4 uvTransform;
	};

	struct TransformationMatrix
	{
		Matrix4x4 WVP;
		Matrix4x4 World;
	};

	struct SRT
	{
		Vector3 scale;
		Vector3 rotate;
		Vector3 translate;
	};

	// 頂点数
	static const int kVertNum = 4;
	// デバイス
	static ID3D12Device* sDevice;
	// デスクリプタサイズ
	static UINT sDescriptorHandleIncrementSize;
	// コマンドリスト
	static ID3D12GraphicsCommandList* sCommandList;
	// ルートシグネチャ
	static Microsoft::WRL::ComPtr<ID3D12RootSignature> sRootSignature;
	// パイプラインステートオブジェクト
	//static Microsoft::WRL::ComPtr<ID3D12PipelineState> sPipelineState;

	static std::array<Microsoft::WRL::ComPtr<ID3D12PipelineState>, size_t(BlendMode::CountofBlendMode)> sPipelineStates;

	static void StaticInitialize(
		ID3D12Device* device, int window_width, int window_height,
		const std::wstring& directoryPath = L"Resources/");

	static void PreDraw(ID3D12GraphicsCommandList* cmdList);
	void Draw();
	static void PostDraw();

	static Sprite* Create(
		uint32_t textureHandle, Vector2 position, Vector2 size, Vector4 color = { 1, 1, 1, 1 });

	void Initialize();

	//座標指定(スクリーン座標)
	inline void SetPosition(const Vector2& pos) { position_ = pos; };

	
	//inline void SetWVP(const Matrix4x4& wvp) { wvp_ = wvp; };

	//カラー(RGBA)の設定
	inline void SetColor(const Vector4& color) { materialData_->color = color; };
	// アンカーポイントの設定
	inline void SetAnchorPoint(const Vector2& anchorPoint) { anchorPoint_ = anchorPoint; };

	//uvTransformの直接指定(基本使わない)
	inline void SetUVTransform(const Matrix4x4& uvTransform) { uvTransform_ = uvTransform; };

	//ブレンドモードの指定
	inline void SetBlendMode(const BlendMode& blendmode) { blendMode_ = blendmode; };

	//z軸回転
	inline void SetRotate(float rotate) { rotate_ = rotate; };

	//テクスチャの範囲切り出し
	void SetRange(const Vector2& leftTop, const Vector2& rightDown);

private:
	Microsoft::WRL::ComPtr<ID3D12Resource> vertexResource_;
	Microsoft::WRL::ComPtr<ID3D12Resource> indexResource_;
	Microsoft::WRL::ComPtr<ID3D12Resource> materialResource_;
	Microsoft::WRL::ComPtr<ID3D12Resource> transformResource_;
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView_{};
	D3D12_INDEX_BUFFER_VIEW indexBufferView_{};
	VertexData* vertexDataSprite_ = nullptr;
	uint32_t* indexData_ = nullptr;
	Material* materialData_ = nullptr;
	TransformationMatrix* transformationMatrixDataSprite = nullptr;
	Vector2 position_;
	Vector2 size_;
	Vector4 color_;
	Vector2 anchorPoint_;
	float rotate_;
	uint32_t textureHandle_;

	Matrix4x4 uvTransform_;

	Matrix4x4 wvp_;

	BlendMode blendMode_;

	D3D12_RESOURCE_DESC resourceDesc_;
};

