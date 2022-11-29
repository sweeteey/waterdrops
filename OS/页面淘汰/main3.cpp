



// 对页框大小进行设置(如 k=2，或者 k=3，或者 k=4)，
// 针对 LRU 页面淘汰算法，对比 该算法针对同一批实验数据的缺页次数情况。

#include "func.cpp"

int main()
{
    cout << "请输入页码序列长度:" << endl;
    cin >> List;
    init();

    cout << "\n================LRU算法===================" << endl << endl;
    cout << "在页框数为2时--->" << endl;
    PageNum = 2;
    showList();
    LRU();
    cout << endl << "缺页总次数:" << missing << "\t缺页中断率:" << rate << endl << endl;

    cout << "在页框数为3时--->" << endl;
    PageNum = 3;
    clear();
    showList();
    LRU();
    cout << endl << "缺页总次数:" << missing << "\t缺页中断率:" << rate << endl << endl;

    cout << "在页框数为4时--->" << endl;
    PageNum = 4;
    clear();
    showList();
    LRU();
    cout << endl << "缺页总次数:" << missing << "\t缺页中断率:" << rate << endl << endl;
}