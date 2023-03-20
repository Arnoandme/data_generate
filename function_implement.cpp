#ifndef _IOSTREAM
#define _IOSTREAM
#include <iostream>
#endif
#include "function_declare.h"
#include "unistd.h"
#include <ctime>
#include <random>



#define DATA_MAX 1000        //定义随机数的最大值

#define DATA_MIN -1000    //定义随机数的最小值

#ifndef Matrix_Height
#define Matrix_Height 720 //矩阵的行数默认为720
#endif

#ifndef Matrix_Width
#define Matrix_Width 1280 //矩阵的列数默认为1280
#endif

void data_generate(float *data_array,int length,int &sem){       //生成指定大小的浮点数数组,sem为信号量，用于控制并发
    //do{
        if(sem){  
            while(!sem){}; //如果sem等于1的时候再进来，会覆盖前面的数据，造成问题，因此在这里需要等待
        }
        int i=0;
        std::default_random_engine e;
        std::uniform_real_distribution<float> u(DATA_MIN,DATA_MAX);
        e.seed(time(0));
        for(;i<length;++i){
            data_array[i] = u(e)+10;
        }
        sem = 1;
    //}while(1);
}


