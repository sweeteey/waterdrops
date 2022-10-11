//string matching (KMP)

#include <iostream>
#include <string.h>
#define N 50
using namespace std;

void get_next(char s[], int next[]);
int KMP(char str[], char sub_str[]);

int main() {
    char str[] = "ababaababcb";
    char sub_str[] = "ababc";
    cout<<"the matching position is "<<KMP(str, sub_str)<<endl;
    return 0;
}

//get next[]
void get_next(char s[], int next[]) {
    int i, j;
    int len;
    next[0] = -1;

    for(j=1; s[j]!='\0'; j++) {
        for(len=j-1; len>=1; len--) {
            for(i=0; i<len; i++)
                if(s[i] != s[j-len+i])
                    break;
            
            if(i==len) {
                next[j] = len;
                break;
            }
        }

        if(len<1)
            next[j] = 0;
    }
}

int KMP(char str[], char sub_str[]) {
    int i=0, j=0;
    int next[N];
    get_next(sub_str, next);

    while(str[i]!='\0' && sub_str[j]!='\0') {
        if(str[i] == sub_str[j]) {
            i++;
            j++;
        }

        else {
            j = next[j];
            if (j == -1) {
                i++;
                j++;
            }
        }
    }

    if (sub_str[j] == '\0')
        return (i-strlen(sub_str)+1);
    else return -1;
}