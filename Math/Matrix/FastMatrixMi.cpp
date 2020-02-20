/*
 * 矩阵的快速幂
 */

#include <iostream>
#include <cstdio>

using namespace std;

struct Matrix{
    int matrix[10][10];
    int row, col;
    Matrix(int r,int c):row(r),col(c){}
};

Matrix Multiply(Matrix x,Matrix y){ //矩阵乘法
    Matrix answer(x.row, y.col);
    for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < y.col; ++j) {
            answer.matrix[i][j] = 0;
            for (int k = 0; k < x.col; ++k) {
                answer.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
            }
        }
    }
    return answer;
}

void PrintMatrix(Matrix x){     //输出矩阵
    for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < x.col; ++j) {
            printf("%d ", x.matrix[i][j]);
        }
        printf("\n");
    }
}

Matrix FastExponentiation(Matrix x,int k){  //矩阵快速幂
    Matrix answer(x.row, x.col);
    for (int i = 0; i < answer.row; ++i) {  //初始化为单位矩阵
        for (int j = 0; j < answer.col; ++j) {
            if (i == j) {
                answer.matrix[i][j] = 1;
            } else
                answer.matrix[i][j] = 0;
        }
    }
    while (k!= 0) { //不断将k转换为二进制
        if (k%2 == 1){  //累乘2^k次幂
            answer = Multiply(answer, x);
        }
        k /= 2;
        x = Multiply(x, x);     //x不断平方
    }
    return answer;
}

int main(){
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        Matrix x(n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &x.matrix[i][j]);
            }
        }
        Matrix result = FastExponentiation(x, k);
        PrintMatrix(result);
    }
    return 0;
}