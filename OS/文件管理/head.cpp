// 设计一个 10 个用户的文件系统，每次用户可保存 10 个文件，一次运行用户可以打开 5 个文件
// 并需要对文件设置保护措施
// Create、Open、Read、Write、Close、Delete
// 用户通过菜单方式方式实现对自己文件的管理。

#include <iostream>
#include <string>
#include <fstream>
#include<stdio.h>
#define User_NUMBER 10
#define USER_FILE 10
#define OPEN_FILE 5
#define MAX 512
using namespace std;

struct UFD
{
    string fileName;
    int maxLength; // 最大长度
    int begin;     // 起始位置
    int length;    // 长度
    int read;      // 读保护码，1为可读
    int write;     // 写保护码，1为可写
    int execute;   // 执行保护码，1为可执行
    UFD *next;
};

struct MFD
{
    string userName;
    string password;
    UFD *ufdNext;
    MFD *mfdNext;
};

struct AFD
{
    string fileName;
    int maxLength;
    int begin;
    int length;
    int read;    // 读保护码，1为可读
    int write;   // 写保护码，1为可写
    int execute; // 执行保护码，1为可执行
    int pointer; // 读写指针
    AFD *next;
};

int Current_Users = 0; // 当前用户个数
int Current_Files = 0; // 当前用户的文件
int Current_Opens = 0; // 当前用户打开的文件数
int MAX_End = 0;       // 该用户所用的内存量

UFD *pUFD = NULL; // 带头结点单链表，每次只能登录一个用户，因此只需要一个pUFD
MFD *pMFD = NULL; // 带头结点单链表
AFD *pAFD = NULL; // 带头结点单链表

string User_Name;