#include <iostream>
#include <cstdio>

using namespace std;

struct Matrix {
    int row;
    int col;
    int matrix[10][10];
    Matrix(int r,int c):row(r),col(c){}
};

Matrix MatrixSum(Matrix x,Matrix y){
    Matrix matrix(x.row, x.col);
    for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < x.col; ++j) {
            matrix.matrix[i][j] = (x.matrix[i][j] + y.matrix[i][j]);
        }
    }
    return matrix;
}
int Judge(Matrix x){ //判断行列零数
    int result = 0;
    for (int i = 0; i < x.row; ++i) {
        bool isZero = true;
        for (int j = 0; j < x.col; ++j) {
            if (x.matrix[i][j] != 0)
                isZero = false;
        }
        if (isZero)
            result++;
    }
    for (int i = 0; i < x.col; ++i) {
        bool isZero = true;
        for (int j = 0; j < x.row; ++j) {
            if (x.matrix[j][i] != 0)
                isZero = false;
        }
        if (isZero)
            result++;
    }
    return result;
}
void PrintMatrix(Matrix x){     //输出矩阵
    for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < x.col; ++j) {
            printf("%d ", x.matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int r, c;
    while (scanf("%d", &r) != EOF) {
        if (r == 0)
            break;
        scanf("%d", &c);
        Matrix a(r, c), b(r, c), d(r, c);
        for (int i = 0; i < a.row; ++i) {
            for (int j = 0; j < a.col; ++j) {
                scanf("%d", &a.matrix[i][j]);
            }
        }
        for (int k = 0; k < b.row; ++k) {
            for (int i = 0; i < b.col; ++i) {
                scanf("%d", &b.matrix[k][i]);
            }
        }
        d = MatrixSum(a, b);
        printf("%d\n", Judge(d));
    }
    return 0;
}