#include<iostream>
#include<iomanip>
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
    float in_time;
    float run_time;
    float start_time;
    float end_time;
    float T_time;
    float W_time;
};