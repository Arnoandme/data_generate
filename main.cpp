#include "matrix_data.h"
#include <thread>
#ifndef _IOSTREAM
#define _IOSTREAM
#include <iostream>
#endif
#define Matrix_Width 1280 //矩阵的列数默认为1280
#define Matrix_Height 720 //矩阵的行数默认为720
int main(){
    int test_height = 5;
    int test_width = 6;
    int mutex = 0;     //互斥量，用于控制缓冲区的访问,    这里应该使用原子类型atomic
    int element_nums = test_height*test_width;   //整个矩阵的元素数量
    FloatVector2D *vector2D = new FloatVector2D;  //矩阵
    float array[]={1,1,1,1,1,1};
    MyMatrix *mMatrix = new MyMatrix(test_height,test_width,vector2D);  //初始化矩阵对象
    float *buffer = new float[element_nums];     //此数组用来不断产生数据，即相当于模拟真实情况的缓冲区
    std::thread data_create_thread(data_generate,buffer,element_nums,std::ref(mutex));   //用带参的方式创建线程
    data_create_thread.join();
    if(mutex){  
        /*
            如果mutex为1，说明缓冲区已经满了，这时候可以将数据取出。
            这里的工作方式为：缓冲区一满一取，因此以后可以有优化的地方。
        */
        initMatrix(mMatrix,buffer,element_nums);  //将缓冲区的数据装到矩阵中
        mutex=0;
        printMatrix(mMatrix);
        std::cout<<mutiplyMatrix(mMatrix,array,6)<<std::endl;
    }
    return 0;
}
