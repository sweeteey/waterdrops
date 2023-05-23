



// 是否可以构造一批实验数据，使得 FIFO 页面淘汰算法会产生 Belady 现象，
// 即:当分配 给进程的物理页面数增加时，缺页次数反而增加，给出你所构造出的这些数据
#include "func.cpp"

int main()
{
    List = 12;
    //arr[] : 1,2,3,4,1,2,5,1,2,3,4,5
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    arr[3]=4;
    arr[4]=1;
    arr[5]=2;
    arr[6]=5;
    arr[7]=1;
    arr[8]=2;
    arr[9]=3;
    arr[10]=4;
    arr[11]=5;

    cout << "\n================Belady异常===================" << endl << endl;
    cout << "在页框数为3时--->" << endl;
    PageNum = 3;
    clear();
    showList();
    FIFO();
    cout << endl << "缺页总次数:" << missing << "\t缺页中断率:" << rate << endl << endl;
    double r1 = rate;

    cout << "在页框数为4时--->" << endl;
    PageNum = 4;
    clear();
    showList();
    FIFO();
    cout << endl << "缺页总次数:" << missing << "\t缺页中断率:" << rate << endl << endl;
    double r2 = rate;

    cout<<"页框数为3时缺页率为"<<r1<<"\n页框数为4时缺页率为"<<r2<<endl;
    if (r1<r2) {
        cout<<"发生了Belady异常"<<endl;
    }
    else {
        cout<<"未发生Belady异常"<<endl;
    }
    
}