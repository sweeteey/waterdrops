// 词法分析
#include <iostream>
#include <string>
#include <fstream>
#define _KEY_WORDEND "waiting for your expanding"
using namespace std;

struct WORD {
    int typenum; //单词种别
    char* word;
};

string buffer = ""; //单词缓冲区
string token = "";  //输入缓冲区
char ch;            //当前读入字符
int p_input; //输入缓冲区指针
int p_token; //单词缓冲区指针

int main()
{
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        cout << "open file failed!" << endl;
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        buffer += ch;
    }

    return 0;
}