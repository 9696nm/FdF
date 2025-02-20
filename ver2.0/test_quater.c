
#include "include/fdf.h"

// typedef struct {
// 	double w, x, y, z;
// } Quaternion;

// typedef struct {
// 	double x, y, z;
// } Vector3;

// // クォータニオンの乗算
// Quaternion quaternion_multiply(Quaternion q1, Quaternion q2) {
// 	Quaternion result;
// 	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
// 	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
// 	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
// 	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
// 	return result;
// }

// // クォータニオンの共役
// Quaternion quaternion_conjugate(Quaternion q) {
// 	Quaternion result = { q.w, -q.x, -q.y, -q.z };
// 	return result;
// }

// // ベクトルをクォータニオンで回転
// Vector3 rotate_vector(Vector3 v, Quaternion q) {
// 	Quaternion vq = { 0, v.x, v.y, v.z };
// 	Quaternion q_conj = quaternion_conjugate(q);

// 	// q * v * q^-1
// 	Quaternion rotated_q = quaternion_multiply(quaternion_multiply(q, vq), q_conj);

// 	// 回転後のベクトルを取得
// 	Vector3 rotated_v = { rotated_q.x, rotated_q.y, rotated_q.z };
// 	return rotated_v;
// }

// // 正規化された回転クォータニオンを作成（軸と角度から）
// Quaternion quaternion_from_axis_angle(Vector3 axis, double angle) {
// 	double half_angle = angle / 2.0;
// 	double s = sin(half_angle);
// 	Quaternion q;
// 	q.w = cos(half_angle);
// 	q.x = axis.x * s;
// 	q.y = axis.y * s;
// 	q.z = axis.z * s;
// 	return q;
// }

// int main() {
// 	// 回転軸と角度
// 	Vector3 axis = { 0, 0, 1 }; // Y軸回転
// 	double angle = 0; // 90度回転

// 	// クォータニオンを生成
// 	Quaternion q = quaternion_from_axis_angle(axis, angle);

// 	// 回転させるベクトル
// 	Vector3 v = { 1, 1, 0 };

// 	// 回転後のベクトル
// 	Vector3 rotated_v = rotate_vector(v, q);

// 	// 結果の表示
// 	printf("回転後のベクトル: (%f, %f, %f)\n", rotated_v.x, rotated_v.y, rotated_v.z);

// 	return 0;
// }



typedef struct t_quaternion
{
	double w, x, y, z;
}	t_quater;

typedef struct {
	double x, y, z;
} Vector3;

// クォータニオンの正規化
t_quater quater_normalize(t_quater q) {
		double norm = sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
		q.w /= norm;
		q.x /= norm;
		q.y /= norm;
		q.z /= norm;
		return q;
	}
	
	// クォータニオンの積
t_quater quater_multiply(t_quater q1, t_quater q2) {
	t_quater result;
	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return result;
}

// クォータニオンによる3Dベクトルの回転
t_quater rotate_vector(t_quater qv, t_quater q) {
	t_quater q_conjugate = { q.w, -q.x, -q.y, -q.z };
	
	t_quater q_res = quater_multiply(quater_multiply(q, qv), q_conjugate);
	
	t_quater result = { q_res.w, q_res.x, q_res.y, q_res.z };
	return result;
}

// 軸と角度からクォータニオンを作成
t_quater quater_axis_angle(Vector3 axis, double angle) {
	double half_angle = angle / 2.0;
	double s = sin(half_angle);
	t_quater q;
	q.w = cos(half_angle);
	q.x = axis.x * s;
	q.y = axis.y * s;
	q.z = axis.z * s;
	return quater_normalize(q);
}

int main() {
	Vector3 	axis = { 1, 0, 0 }; // Z軸を回転軸にする
	t_quater 	qv = { 0, 1, 1, 0 }; // X軸方向のベクトル
	double 		angle = M_PI; // 90度回転
	
	t_quater q = quater_axis_angle(axis, angle);
	qv = quater_normalize(qv);
	t_quater rotated_v = rotate_vector(qv, q);
	// rotated_v = rotate_vector(qv, rotated_v);
	
	printf("vector: (%.2f, %.2f, %.2f, %.2f)\n", rotated_v.w, rotated_v.x, rotated_v.y, rotated_v.z);
	
	return 0;
}
