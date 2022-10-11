// for givin elements {1, 2, 3, ..., n}
// generate all arrays and combinations of character sets

#include <iostream>
using namespace std;

int x[] = {1, 2, 3, 4};
int temp[4];
int n = 3;

void backtrack_com(int t);  //combination
void backtrack_arr(int t);  //array
void output(int x[]);
void swap(int &x, int &y);

int main() {
    cout<<"combinations: "<<endl;
    backtrack_com(0);

    cout<<"arrays: "<<endl;
    backtrack_arr(0);

    return 0;
}


void backtrack_com(int t) {
    if(t>n) 
        output(x);
    else
        for(int i=0; i<=1; i++) {
            temp[t] = i;
            backtrack_com(t+1);
        }
}


void backtrack_arr(int t) {
    if(t>n) output(x);
    else {
        for(int i=t; i<=n; i++) {
            swap(x[t], x[i]);
            backtrack_arr(t+1);
            swap(x[t],x[i]);
        }
    }
}

void output(int x[]) {
    for(int i=0; i <= n; i++) {
        if(temp[i] == 1)
            cout<<x[i]<<" ";
    }
    cout<<endl;
}

void swap(int &x, int &y) {
    int a = x;
    x = y;
    y = a;
}