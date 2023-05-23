//string matching (BF)

#include <iostream>
#include <string.h>
using namespace std;

int BF(char str[], char sub_str[]);

int main() {
    char str[] = "abcabcacb";
    char sub_str[] = "abcac";
    cout<<"the matching position is "<<BF(str, sub_str)<<endl;
}


//return the matching position(starting by 0)
int BF(char str[], char sub_str[]) {
    int len1 = strlen(str);
    int len2 = strlen(sub_str);
    int i, j, temp;
    //for (i in str) {
    //  temp = i;
    //  match(str[temp++], sub_str[j++]) {
    //    if not, break;
    //  }
    //}

    for (i = 0; i < len1-len2+1; i++) {
        temp = i;
        j = 0;
        while (j < len2) {
            if (str[temp] == sub_str[j]) {
                temp++;
                j++;
            }
            else break;
        }  //matching
        if (j == len2) {
            return i;
        }  //successfully
    }
    cout<<"match failed!"<<endl;
    return -1;
}