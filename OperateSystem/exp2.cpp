#include <iostream>
#include<string>
using namespace std;

#define LEN 100

int len1, len2, len3;

int BF(char str[], char sub_str[]);
char* InsertStr(char str[], char insert_str[], int lo);


int main() {
    // string str;
    // string sub_str("student");
    // string insert_str("a ");

    //输入 "I am student"
    // cout<<"请输入字符串:"<<endl;
    // getline(cin, str);

    //寻找待插入位置
    // int lo = str.find(sub_str);

    //插入
    // str.insert(lo, insert_str);

    //输出
    // cout<<"输出为:\n"<<str<<endl;
    // return 0;

    char str[LEN];
    char sub_str[]="student", insert_str[]="a ";
    len2 = strlen(sub_str);
    len3 = strlen(insert_str);

    //输入
    cout<<"请输入一个字符串:"<<endl;
    cin.get(str,LEN);
    len1 = strlen(str);

    //寻找待插入位置
    int lo = BF(str, sub_str);

    //插入
    InsertStr(str, insert_str, lo);

    //输出
    cout<<"输出为:\n"<<str<<endl;
    return 0;
}

int BF(char str[], char sub_str[]){
    int i,j,temp;

    for(i=0;i<=len1-len2;i++){
        temp = i;
        j = 0;
        while(j<len2){
            if(str[temp] == sub_str[j]){
                temp ++;
                j++;
            }
            else break;
        }
        if(j == len2){
            return i;
        }
    }
    return -1;
}

char* InsertStr(char str[], char insert_str[], int lo){
    //后续字符串后移
    for(int i = len1;i >= lo; i--){
        str[i+len3] = str[i];
    }
    //插入
    int temp = lo;
    for(int j = 0; j < len3; j++){
        str[temp] = insert_str[j];
        temp++;
    }
    return str;
}