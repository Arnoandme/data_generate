#include "matrix_data.h"
#ifndef _IOSTREAM
#define _IOSTREAM
#include <iostream>
#endif
#include <iomanip>
#define MULTIPLY_MATRIX_ERROR -1.0
#define INVERSE_MATRIX_ERROR -2
MyMatrix::MyMatrix(){};             //空的构造函数
MyMatrix::MyMatrix(int n,int m,FloatVector2D *data)     
{   //带全部参数的构造函数
    this->n = n;     
	this->m = m;
    matrix = data;
}
MyMatrix::~MyMatrix(){};   //析构函数
void initMatrix(MyMatrix *matrix_instance,float *originData,int length){  //该函数用于从一维数组originData中初始化矩阵,默认length长度无限
    int height = matrix_instance->n;   //获取矩阵的行数
	int width = matrix_instance->m;   //获取矩阵的列数
    int matrix_size = height*width;   //矩阵的元素数量
    matrix_instance->matrix->resize(matrix_size);
	for(int i = 0; i < height; ++i)
	{
		(*matrix_instance->matrix)[i].resize(width);  //设置每行的长度
	}
 
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			(*matrix_instance->matrix)[i][j] = originData[i * height + j];
		}
	}
}
void printMatrix(MyMatrix *matrix_instance){                       //输出方阵的值
    FloatVector2D *temp = matrix_instance->matrix;
    int height = matrix_instance->n;   //获取矩阵的行
	int width = matrix_instance->m;  //获取矩阵的列
	std::cout<<"矩阵的行是"<<height<<std::endl;
	std::cout<<"矩阵的列是"<<width<<std::endl;
    for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			std::cout<<std::setprecision(2)<<std::setiosflags(std::ios::fixed)<<std::setw(5)<<(*temp)[i][j]<<" ";
		}
        std::cout<<std::endl;
	}
}
void getReverseMatrix(MyMatrix *origin_matrix,MyMatrix *reverse_matrix,int *flag){
    /*求矩阵的逆的函数，只有方阵才能求*/
	int height = origin_matrix->n;
	int width = origin_matrix->m;
	if(height!=width){
		*flag = INVERSE_MATRIX_ERROR;
		return ;
	}
	/*
		尚未实现
	*/

}
void mutiplyNum(MyMatrix *origin_matrix,const float num){//矩阵的数乘
	FloatVector2D *vector2D = origin_matrix->matrix;  
	int height = origin_matrix->n;
	int width = origin_matrix->m;
	for(int i=0;i<height;++i){
		for(int j=0;j<width;j++)
		(*vector2D)[i][j]*=num;
	}
}  
float mutiplyMatrix(MyMatrix *origin_matrix,float *array,int n){//一个矩阵与一个列向量相乘，得到一个向量，再把向量内的各分量相加，返回它们相加后的值
	float ans = 0.0;
	int height = origin_matrix->n;
	int width = origin_matrix->m;
	if(width!=n){
		return MULTIPLY_MATRIX_ERROR;   //无法相乘
	}
	FloatVector2D *vector2D = origin_matrix->matrix;
	for(int i=0;i<height;i++){
		float sum = 0;
		for(int j=0,q=0;j<width;++j,++q){
			sum+=(*vector2D)[i][j]*(array[q]);
		}
		ans+=sum;
	}
	return ans;
}
void getTMatrix(MyMatrix *origin_matrix){  //获取矩阵的转置  ,此函数有问题
	FloatVector2D *vector2D = origin_matrix->matrix;
	int height = origin_matrix->n;
	int width = origin_matrix->m;
	FloatVector2D *temp_vector;
	temp_vector->resize(height*width);
	for(int i = 0; i < width; ++i)
	{
		(*temp_vector)[i].resize(height);  //设置每行的长度
	}
	for(int i=0;i<height;++i){
		for(int j=0;j<width;++j){
			(*temp_vector)[j][i]=(*vector2D)[i][j];
		}
	}
	origin_matrix->matrix = temp_vector;
	delete vector2D;
	origin_matrix->n = width;
	origin_matrix->m = height;
}


