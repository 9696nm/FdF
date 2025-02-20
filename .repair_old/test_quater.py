#!/usr/bin/python3 

import numpy as np

# 定義: 四元数 q = cos(θ/2) + u sin(θ/2)
theta = np.pi / 2  # 90度回転
q = np.array([0, 1, 5, 2])

q = np.array([np.cos(theta / 2), 0, np.sin(theta / 2), 0])  # (w, x, y, z)
q_conj = np.array([q[0], -q[1], -q[2], -q[3]])  # 共役四元数

# 点 P を純四元数として表現 (0, x, y, z)
p = np.array([0, 1, 5, 2])

# 四元数の積: qpq⁻¹ を計算
def quaternion_multiply(q1, q2):
    w1, x1, y1, z1 = q1
    w2, x2, y2, z2 = q2
    w = w1*w2 - x1*x2 - y1*y2 - z1*z2
    x = w1*x2 + x1*w2 + y1*z2 - z1*y2
    y = w1*y2 - x1*z2 + y1*w2 + z1*x2
    z = w1*z2 + x1*y2 - y1*x2 + z1*w2
    return np.array([w, x, y, z])

# 計算: p' = q * p * q⁻¹
qp = quaternion_multiply(q, p)
p_prime = quaternion_multiply(qp, q_conj)

# 回転後の座標 (x, y, z)
print('w, x, y, z :', p_prime)
