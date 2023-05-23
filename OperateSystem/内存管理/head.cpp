#include <iostream>
#include <string>

using namespace std;

struct Space
{
    string name;
    int begin;  //首地址
    int length; //长度
    Space *next;
};

int threshold = 2;  //阈值为2
int sum = 200;      //内存总长度
int alreadyUse = 0; //已使用的内存长度

Space *empty = NULL; //空闲块队列
Space *work = NULL;  //已使用内存块队列