#include <iostream>
#include<string>

using namespace std;
#define N 20
#define PART 5 //时间片

struct PCB {
    string id;
    int status; //0:就绪 1:阻塞 2:运行
    int time; //需要时间
    int y_time; //已运行时间
    PCB* next; //同状态进程队列中下一个PCB
    PCB* all_next; //PCB总链中下一个PCB
};


//总链中PCB个数
int num;
//总链队列首指针
PCB* p_all = NULL;
//总链队列为指针
PCB* p_all_rear = NULL;

//空闲队列首指针
PCB* p_free = NULL;

//运行指针
PCB* p_run = NULL;

//就绪队列首指针
PCB* p_ready = NULL;
//就绪队列尾指针
PCB* p_ready_rear = NULL;

//0:等待I/O操作完成 1:等待分配内存 2:等待接收消息
//等待队列首指针
PCB* p_wait0 = NULL;
PCB* p_wait1 = NULL;
PCB* p_wait2 = NULL;
//等待队列尾指针
PCB* p_wait0_rear = NULL;
PCB* p_wait1_rear = NULL;
PCB* p_wait2_rear = NULL;