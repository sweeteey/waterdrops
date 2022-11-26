// G[E]:
//     E->TG
//     G->+TG|ε
//     T->FS
//     S->*FS|ε
//     F->(E)|i
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
//变量定义
string s, str, stackStr;//s：输入串、str：中间变量、stackStr : 模拟栈
int i;
string ch;//当前分析字符
vector<string> v;//字符串类型的向量(文法+分析栈)
//函数声明
void E();                   //E-->TG
void G();                   //G-->+TG|ε
void T();                   //T-->FS
void S();                   //S-->*FS|ε
void F();                   //F-->(E)|i
void err();					//提示错误信息
int check();//验证是否已经到栈底
void push(string pre, string value);//将字符串存入输出栈

int main() {
    cout << "===================================================" << endl;
    cout << "=== 递归下降分析 ===" << endl;
    cout << "===================================================" << endl;
    cout << "===请输入字符串 (以#号结束）===" << endl;
    while (cin >> s) //输入要分析的字符串
    {
        v.clear();
        i = 0;
        stackStr = "E#";//初始化栈
        E();
        if (check())
        {
            cout << "=====>\t\t 输入串分析正确！ " << endl;
            cout << "推导过程如下： " << endl;
            cout << "文法\t\t分析栈\t\t当前分析字符\n";
            cout << "E      \t\tE#\t\t" << s[0] << endl;//初始栈的内容
            int i;
            for (i = 0; i < v.size(); i++)
            {
                cout << v[i].substr(0, v[i].find_first_of(",", 0)) << "\t";
                cout << setiosflags(ios::right) << setw(10) << v[i].substr(v[i].find_first_of(",", 0) + 1) << "\t\t";
                cout << ch[i] << endl;
            }
        }
        else
            cout << "==>\t 输入串不符合该文法 " << endl;
    }
    
    return 0;
}


/**
 * 函数功能：提示错误信息
 */
void err()
{
    cout << "ERROR" << endl;
    exit(0);
}
/**
 * 函数功能：将字符串存入输出栈
 */
void push(string pre, string value)
{
    ch += s[i];
    int idx = stackStr.find_first_of(pre[0], 0);//从头开始找到pre开始的位置
    if (value != "ε")//不是空字时
    {
        string value1;
        value1 = value;
        if (value[0] == '+')value1 = "TG";
        if (value[0] == '*')value1 = "FS";
        if (value[0] == '(')value1 = "E";
        if (value[0] == 'i')value1 = "";
        stackStr.replace(idx, 1, value1);//将第一个pre的位置替换为value
    }
    else
    {
        stackStr.erase(idx, 1);//删除从该位置开始的1个字符
    }
    v.push_back((pre + value + "," + stackStr));//将对应的表达式和栈的内容存加入在向量v尾部
}
/**
 * 函数功能：验证是否已经到栈底
 */
int check()
{
    if (i >= s.size()) {
        return 1;
    }
    else if (s[i] == '#')
    {
        ch += '#';
        return 1;
    }
    return 0;
}
/**
 * 函数功能：E-->TG
 */
void E()
{
    push("E-->", "TG");
    T();
    G();
}
/**
 * 函数功能：G-->+TG|ε
 */
void G() {
    if (s[i] == '+')
    {
        str = s[i];
        str += "TG";
        i++;
        push("G-->", str);
        T();
        G();
    }
    else
    {
        push("G-->", "ε");
    }
}
/**
 * 函数功能：T-->FS
 */
void T()
{
    push("T-->", "FS");
    F();
    S();
}
/**
 * 函数功能：S-->*FS|ε
 */
void S() {
    if (s[i] == '*')
    {
        str = s[i];
        str += "FS";
        i++;
        push("S-->", str);
        F();
        S();
    }
    else
    {
        push("S-->", "ε");
    }
}
/**
 * 函数功能：F-->(E)|i
 */
void F() {
    if (s[i] == '(')
    {
        i++;
        push("F-->", "(E)");
        E();
        if (s[i] == ')')
        {
            i++;
        }
        else
        {
            err();
        }
    }
    else if (s[i] == 'i')
    {
        i++;
        push("F-->", "i");
    }
    else
    {
        err();
    }
}