#ifndef _NAME_H
#define _NAME_H
#include "function_declare.h"   
#endif
class MyMatrix
{
    private:
        int n;            //矩阵的行数
        int m;           //矩阵的列数
        FloatVector2D *matrix;    //矩阵
    public:
        MyMatrix();
        MyMatrix(int n,int m,FloatVector2D *data);
        ~MyMatrix();
        friend void printMatrix(MyMatrix *matrix);   //打印矩阵
        friend void initMatrix(MyMatrix *matrix,float *originData,int length);  //初始化矩阵
        friend void getReverseMatrix(MyMatrix *origin_matrix,MyMatrix *reverse_matrix,int *flag);  //求逆矩阵，要求是方阵且不为0时才能实现
        friend void mutiplyNum(MyMatrix *origin_matrix,const float num);  //矩阵的数乘
        friend float mutiplyMatrix(MyMatrix *origin_matrix,float *array,int n);   //将矩阵与一个向量相乘
        friend void getTMatrix(MyMatrix *origin_matrix);  //获取矩阵的转置
};