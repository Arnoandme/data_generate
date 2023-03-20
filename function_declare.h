#include <vector>
typedef std::vector<float>	FloatVector;  //一维
typedef std::vector<FloatVector> FloatVector2D;   //二维，用来存储矩阵
void data_generate(float *data_array,int length,int &sem);  //生成一段指定长度的数据，想法是将其用在子线程
