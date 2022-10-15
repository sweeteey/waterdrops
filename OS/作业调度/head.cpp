#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

#define NUM 20

//存放作业运行次序
int order[NUM];


/***
 * id 作业编号
 * in_time 进入时间
 * run_time 运行时间
 * start_time 开始时间
 * end_time 结束时间
 * T_time 周转时间
 * W_time 带权周转时间
 * */
struct Job {
    string id;
    double in_time;
    double run_time;
    double start_time;
    double end_time;
    double T_time;
    double W_time;
};