#include <Novice.h>
#include"MyMath.h"

const char kWindowTitle[] = "LE2C_07_オオサキ_ハルキ_タイトル";

MyMath* myMath = new MyMath();

static const int kRowHeight = 20;
static const int kColumnWidth = 70;

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* name) {
	Novice::ScreenPrintf(x, y, "%s", name);
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + 20 + row * kRowHeight, "%.03f", matrix.m[row][column]);
		}
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 axis = myMath->Normalize({ 1.0f,1.0f,1.0f });
	float angle = 0.44f;
	Matrix4x4 rotateMatrix = myMath->MakeRotateAxisAngle(axis, angle);





	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(0, 0, rotateMatrix, "rotateMatrix");

		//Matrix4x4 r;

//r.m[0][0] = cos(angle);
//r.m[0][1] = 0;
//r.m[0][2] = 0;
//r.m[1][0] = 0;
//r.m[1][1] = cos(angle);
//r.m[1][2] = 0;
//r.m[2][0] = 0;
//r.m[2][1] = 0;
//r.m[2][2] = cos(angle);

//Matrix4x4 p;

//p.m[0][0] = axis.x * axis.x;//二乗
//p.m[0][1] = axis.x * axis.y;
//p.m[0][2] = axis.x * axis.z;
//p.m[1][0] = axis.x * axis.y;
//p.m[1][1] = axis.y * axis.y;//二乗
//p.m[1][2] = axis.y * axis.z;
//p.m[2][0] = axis.x * axis.z;
//p.m[2][1] = axis.y * axis.z;
//p.m[2][2] = axis.z * axis.z;//二乗

//Matrix4x4 c;

//c.m[0][0] = 0;
//c.m[0][1] = -axis.z;
//c.m[0][2] = axis.y;
//c.m[1][0] = axis.z;
//c.m[1][1] = 0;
//c.m[1][2] = -axis.x;
//c.m[2][0] = -axis.y;
//c.m[2][1] = axis.x;
//c.m[2][2] = 0;


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
