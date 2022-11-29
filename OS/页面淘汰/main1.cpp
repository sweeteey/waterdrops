

#include "func.cpp"
// 针对一个页框，设计实验数据，
// 以 OPT算法为参考，分别实现 FIFO 页面淘汰算法和 LRU 页面淘汰算法，
// 并对比这两类算法针对同一批实验数据的缺页次数情况。
int main()
{
    cout << "请输入页框数：" << endl;
    cin >> PageNum;
    cout << "请输入页码序列长度" << endl;
    cin >> List;
    init();

    cout << endl << "--------------理想页面置换算法(OPT)---------------" << endl;
    clear();
    showList();
    OPT();
    cout << endl << "缺页总次数:" << missing << "\t缺页中断率:" << rate << endl;

    cout << endl << "--------------先进先出淘汰算法(FIFO)---------------" << endl;
    clear();
    showList();
    FIFO();
    cout << endl << "缺页总次数:" << missing << "\t缺页中断率:" << rate << endl;

    cout << endl << "--------------最近最久未使用淘汰算法(LRU)---------------" << endl;
    clear();
    showList();
    LRU();
    cout << endl << "缺页总次数:" << missing << "\t缺页中断率:" << rate << endl;

    return 0;
}