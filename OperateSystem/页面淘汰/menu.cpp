// 要求一
// 以 OPT算法为参考，分别实现 FIFO 页面淘汰算法和 LRU 页面淘汰算法，
// 并对比这两类算法针对同一批实验数据的缺页次数情况。

// 要求二
// 对页框大小进行设置(如 k=2，或者 k=3，或者 k=4)，
// 针对 FIFO 页面淘汰算法，对比 该算法针对同一批实验数据的缺页次数情况。

// 要求三
// 对页框大小进行设置(如 k=2，或者 k=3，或者 k=4)，
// 针对 LRU 页面淘汰算法，对比 该算法针对同一批实验数据的缺页次数情况。

#include "func.cpp"

int main()
{
    //设置页码序列
    List = 20;
    cout << "初始时页码序列长度为 20" << endl;
    init();

    while (1)
    {
        char ch;
        cout << endl
             << "***********菜单*************" << endl;
        cout << "*       1.OPT算法          *" << endl;
        cout << "*       2.FIFO算法         *" << endl;
        cout << "*       3.LRU算法          *" << endl;
        cout << "*       4.刷新序列         *" << endl;
        cout << "*       0.退出             *" << endl;
        cout << "***********菜单*************" << endl
             << endl;
        cout << "请输入您的选择:";
        cin >> ch;

        switch (ch)
        {
        case '1':
            cout << "\n请输入页框数:";
            cin >> PageNum;
            cout << "在页框数为" << PageNum << "时--->" << endl;
            showList();
            OPT();
            cout << "\n缺页总次数:" << missing << "\t缺页中断率:" << rate << endl << endl;
            clear();
            break;
        case '2':
            cout << "\n请输入页框数:";
            cin >> PageNum;
            cout << "在页框数为" << PageNum << "时--->" << endl;
            showList();
            FIFO();
            cout << "\n缺页总次数:" << missing << "\t缺页中断率:" << rate << endl << endl;
            clear();
            break;
        case '3':
            cout << "\n请输入页框数:";
            cin >> PageNum;
            cout << "在页框数为" << PageNum << "时--->" << endl;
            showList();
            LRU();
            cout << "\n缺页总次数:" << missing << "\t缺页中断率:" << rate << endl << endl;
            clear();
            break;
        case '4':
            cout << "\n请输入新的序列长度:";
            cin >> List;
            init();
            break;
        case '0':
            cout << "\n感谢您的使用"<<endl;
            exit(0);
        default:
            cout<<"\n没有该选项,请重新输入"<<endl;
            break;
        }
    }
}