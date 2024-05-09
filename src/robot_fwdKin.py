import sympy as sym

# 定义符号变量
x, y, z, rx, ry, rz = sym.symbols("x y z rx ry rz")
q1, q2, q3, q4, q5, q6 = sym.symbols("q1 q2 q3 q4 q5 q6")
q7 = sym.symbols("q7")

# 定义机器人关节变量
d1, d2, d3, d4, d5, d6 = sym.symbols("d1 d2 d3 d4 d5 d6")
a0, a1, a2, a3, a4, a5 = sym.symbols("a0 a1 a2 a3 a4 a5")
alpha0, alpha1, alpha2, alpha3, alpha4, alpha5 = sym.symbols(
    "alpha0 alpha1 alpha2 alpha3 alpha4 alpha5"
)

# /*
# * DH Parameters
# | -   | $\alpha$(deg) | a(mm) | $\theta$(deg) | d(mm) |
# | --- | ------------- | ----- | ------------- | ----- |
# | j1  | 0             | 0     | 0             | 375   |
# | j2  | -90           | 0     | -90           | 20    |
# | j3  | 0             | 290   | -90           | 0     |
# | j4  | -90           | 0     | 0             | 310   |
# | j5  | 90            | 0     | 0             | 0     |
# | j6  | -90           | 0     | 180           | 70    |

# */


def form_HomoMatrix(q_i, alpha_0, a_0, d_i):
    return sym.Matrix(
        [
            [
                sym.cos(q_i),
                -sym.sin(q_i) * sym.cos(alpha_0),
                sym.sin(q_i) * sym.sin(alpha_0),
                a0 * sym.cos(q_i),
            ],
            [
                sym.sin(q_i),
                sym.cos(q_i) * sym.cos(alpha_0),
                -sym.cos(q_i) * sym.sin(alpha_0),
                a_0 * sym.sin(q_i),
            ],
            [0, sym.sin(alpha_0), sym.cos(alpha_0), d_i],
            [0, 0, 0, 1],
        ]
    )


# 机器人base 到关节1 的其次矩阵
T0_1 = sym.Matrix(
    [
        [
            sym.cos(q1),
            -sym.sin(q1) * sym.cos(alpha0),
            sym.sin(q1) * sym.sin(alpha0),
            a0 * sym.cos(q1),
        ],
        [
            sym.sin(q1),
            sym.cos(q1) * sym.cos(alpha0),
            -sym.cos(q1) * sym.sin(alpha0),
            a0 * sym.sin(q1),
        ],
        [0, sym.sin(alpha0), sym.cos(alpha0), d1],
        [0, 0, 0, 1],
    ]
)


# 关节1 到 关节2的齐次矩阵
T1_2 = sym.Matrix(
    [
        [
            sym.cos(q2),
            -sym.sin(q2) * sym.cos(alpha1),
            sym.sin(q2) * sym.sin(alpha1),
            a1 * sym.cos(q2),
        ],
        [
            sym.sin(q2),
            sym.cos(q2) * sym.cos(alpha1),
            -sym.cos(q2) * sym.sin(alpha1),
            a1 * sym.sin(q2),
        ],
        [0, sym.sin(alpha1), sym.cos(alpha1), d2],
        [0, 0, 0, 1],
    ]
)

# 关节2 到 关节3的齐次矩阵
T2_3 = sym.Matrix(
    [
        [
            sym.cos(q3),
            -sym.sin(q3) * sym.cos(alpha2),
            sym.sin(q3) * sym.sin(alpha2),
            a2 * sym.cos(q3),
        ],
        [
            sym.sin(q3),
            sym.cos(q3) * sym.cos(alpha2),
            -sym.cos(q3) * sym.sin(alpha2),
            a2 * sym.sin(q3),
        ],
        [0, sym.sin(alpha2), sym.cos(alpha2), d3],
        [0, 0, 0, 1],
    ]
)

# 关节3 到 关节4的齐次矩阵
T3_4 = sym.Matrix(
    [
        [
            sym.cos(q4),
            -sym.sin(q4) * sym.cos(alpha3),
            sym.sin(q4) * sym.sin(alpha3),
            a3 * sym.cos(q4),
        ],
        [
            sym.sin(q4),
            sym.cos(q4) * sym.cos(alpha3),
            -sym.cos(q4) * sym.sin(alpha3),
            a3 * sym.sin(q4),
        ],
        [0, sym.sin(alpha3), sym.cos(alpha3), d4],
        [0, 0, 0, 1],
    ]
)

# 关节4 到 关节5的齐次矩阵
T4_5 = sym.Matrix(
    [
        [
            sym.cos(q5),
            -sym.sin(q5) * sym.cos(alpha4),
            sym.sin(q5) * sym.sin(alpha4),
            a4 * sym.cos(q5),
        ],
        [
            sym.sin(q5),
            sym.cos(q5) * sym.cos(alpha4),
            -sym.cos(q5) * sym.sin(alpha4),
            a4 * sym.sin(q5),
        ],
        [0, sym.sin(alpha4), sym.cos(alpha4), d5],
        [0, 0, 0, 1],
    ]
)

# 关节5 到 末端执行器的齐次矩阵
T5_6 = sym.Matrix(
    [
        [
            sym.cos(q6),
            -sym.sin(q6) * sym.cos(alpha5),
            sym.sin(q6) * sym.sin(alpha5),
            a5 * sym.cos(q6),
        ],
        [
            sym.sin(q6),
            sym.cos(q6) * sym.cos(alpha5),
            -sym.cos(q6) * sym.sin(alpha5),
            a5 * sym.sin(q6),
        ],
        [0, sym.sin(alpha5), sym.cos(alpha5), d6],
        [0, 0, 0, 1],
    ]
)

# 末端执行器到 基座齐次矩阵
# T6_G = sym.Matrix([[sym.cos(q7), -sym.sin(q7)*sym.cos(alpha6), sym.sin(q7)*sym.sin(alpha6), a6*sym.cos(q7)],
#                        [sym.sin(q7), sym.cos(q7)*sym.cos(alpha6), -sym.cos(q7)*sym.sin(alpha6), a6*sym.sin(q7)],
#                             [0, sym.sin(alpha6), sym.cos(alpha6), d7],
#                             [0, 0, 0, 1]
# ])

# 计算 基座到关节3的齐次矩阵
T0_3 = T0_1 * T1_2 * T2_3

# 计算 关节3到关节6的齐次矩阵
T3_6 = T3_4 * T4_5 * T5_6


# 计算 基座到 末端执行器的齐次矩阵
T0_6 = T0_3 * T3_6


r11 = T0_6[0, 0]
r12 = T0_6[0, 1]
r13 = T0_6[0, 2]
r21 = T0_6[1, 0]
r22 = T0_6[1, 1]
r23 = T0_6[1, 2]
r31 = T0_6[2, 0]
r32 = T0_6[2, 1]
r33 = T0_6[2, 2]

# 计算末端执行器的坐标
X = r13
Y = r23
Z = r33


# print("r11=",r11)
# print("r12=",r12)
# print("r13=",r13)
# print("r21=",r21)
# print("r22=",r22)
# print("r23=",r23)
# print("r31=",r31)
# print("r32=",r32)
# print("r33=",r33)
# print("X=",X)
# print("Y=",Y)
# print("Z=",Z)

Pi,HalfPi = sym.symbols('Pi,HalfPi')

# d1, d2, d3, d4, d5, d6 = 375, 20, 0, 310, 0, 70
# a0, a1, a2, a3, a4, a5 = 0, 0, 290, 0, 0, 0
# alpha0, alpha1, alpha2, alpha3, alpha4, alpha5 = 0, -HalfPi, 0, -HalfPi, HalfPi, -HalfPi
# theta1, theta2, theta3, theta4, theta5, theta6 = 0, -HalfPi, -HalfPi, 0, 0, Pi
# theta1, theta2, theta3, theta4, theta5, theta6 = 0, 0,0, 0, 0,0

d1, d2, d3, d4, d5, d6 = 0, 0, 20, 310, 0, 70
a0, a1, a2, a3, a4, a5 = 0, 290, 0, 0, 0, 0
alpha0, alpha1, alpha2, alpha3, alpha4, alpha5 = -HalfPi,0, HalfPi, -HalfPi, HalfPi, 0
theta1, theta2, theta3, theta4, theta5, theta6 = 0, -HalfPi, HalfPi, 0, 0, 0

T0_1 = form_HomoMatrix(q1, alpha0, a0, d1)
T1_2 = form_HomoMatrix(q2+theta2, alpha1, a1, d2)
T2_3 = form_HomoMatrix(q3+theta3, alpha2, a2, d3)
T3_4 = form_HomoMatrix(q4, alpha3, a3, d4)
T4_5 = form_HomoMatrix(q5, alpha4, a4, d5)
T5_6 = form_HomoMatrix(q6+theta6, alpha5, a5, d6)

T0_3 = T0_1 * T1_2 * T2_3

# print("T0_3=", T0_3)
print("T0_3.r11=", T0_3[0, 0],";")
print("T0_3.r12=", T0_3[0, 1],";")
print("T0_3.r13=", T0_3[0, 2],";")
print("T0_3.r14=", T0_3[0, 3],";")
print("T0_3.r21=", T0_3[1, 0],";")
print("T0_3.r22=", T0_3[1, 1],";")
print("T0_3.r23=", T0_3[1, 2],";")
print("T0_3.r24=", T0_3[1, 3],";")
print("T0_3.r31=", T0_3[2, 0],";")
print("T0_3.r32=", T0_3[2, 1],";")
print("T0_3.r33=", T0_3[2, 2],";")
print("T0_3.r34=", T0_3[2, 3],";")


T3_6 = T3_4 * T4_5 * T5_6

print("T3_6.r11=", T3_6[0, 0],";")
print("T3_6.r12=", T3_6[0, 1],";")
print("T3_6.r13=", T3_6[0, 2],";")
print("T3_6.r14=", T3_6[0, 3],";")
print("T3_6.r21=", T3_6[1, 0],";")
print("T3_6.r22=", T3_6[1, 1],";")
print("T3_6.r23=", T3_6[1, 2],";")
print("T3_6.r24=", T3_6[1, 3],";")
print("T3_6.r31=", T3_6[2, 0],";")
print("T3_6.r32=", T3_6[2, 1],";")
print("T3_6.r33=", T3_6[2, 2],";")
print("T3_6.r34=", T3_6[2, 3],";")

# # print formated matrix
# def print_matrix(matrix):
#     for row in matrix:
#         print(' '.join(str(x) for x in row))

# print_matrix(T0_1)


T0_3.r11 = sym.symbols("T0_3.r11")
T0_3.r12 = sym.symbols("T0_3.r12")
T0_3.r13 = sym.symbols("T0_3.r13")
T0_3.r14 = sym.symbols("T0_3.r14")
T0_3.r21 = sym.symbols("T0_3.r21")
T0_3.r22 = sym.symbols("T0_3.r22")
T0_3.r23 = sym.symbols("T0_3.r23")
T0_3.r24 = sym.symbols("T0_3.r24")
T0_3.r31 = sym.symbols("T0_3.r31")
T0_3.r32 = sym.symbols("T0_3.r32")
T0_3.r33 = sym.symbols("T0_3.r33")
T0_3.r34 = sym.symbols("T0_3.r34")

T3_6.r11 = sym.symbols("T3_6.r11")
T3_6.r12 = sym.symbols("T3_6.r12")
T3_6.r13 = sym.symbols("T3_6.r13")
T3_6.r14 = sym.symbols("T3_6.r14")
T3_6.r21 = sym.symbols("T3_6.r21")
T3_6.r22 = sym.symbols("T3_6.r22")
T3_6.r23 = sym.symbols("T3_6.r23")
T3_6.r24 = sym.symbols("T3_6.r24")
T3_6.r31 = sym.symbols("T3_6.r31")
T3_6.r32 = sym.symbols("T3_6.r32")
T3_6.r33 = sym.symbols("T3_6.r33")
T3_6.r34 = sym.symbols("T3_6.r34")

TM0_3 = sym.Matrix(
    [
        [T0_3.r11, T0_3.r12, T0_3.r13, T0_3.r14],
        [T0_3.r21, T0_3.r22, T0_3.r23, T0_3.r24],
        [T0_3.r31, T0_3.r32, T0_3.r33, T0_3.r34],
        [0, 0, 0, 1],
    ]
)


TM3_6 = sym.Matrix(
    [
        [T3_6.r11, T3_6.r12, T3_6.r13, T3_6.r14],
        [T3_6.r21, T3_6.r22, T3_6.r23, T3_6.r24],
        [T3_6.r31, T3_6.r32, T3_6.r33, T3_6.r34],
        [0, 0, 0, 1],
    ]
)


TM0_6= TM0_3 * TM3_6

print("TM0_6.r11=", TM0_6[0, 0],";")
print("TM0_6.r12=", TM0_6[0, 1],";")
print("TM0_6.r13=", TM0_6[0, 2],";")
print("TM0_6.r14=", TM0_6[0, 3],";")
print("TM0_6.r21=", TM0_6[1, 0],";")
print("TM0_6.r22=", TM0_6[1, 1],";")
print("TM0_6.r23=", TM0_6[1, 2],";")
print("TM0_6.r24=", TM0_6[1, 3],";")
print("TM0_6.r31=", TM0_6[2, 0],";")
print("TM0_6.r32=", TM0_6[2, 1],";")
print("TM0_6.r33=", TM0_6[2, 2],";")
print("TM0_6.r34=", TM0_6[2, 3],";")


print("T0_1=",T0_1)
print("T1_2=",T1_2)
print("T2_3=",T2_3)
print("T3_4=",T3_4)
print("T4_5=",T4_5)
print("T5_6=",T5_6)
