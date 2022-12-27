#include "func.cpp"

int main()
{
    Init_MFD();
    cout << "请登录：" << endl;
    if (!User_Check())
        return 0;
    while (1)
    {
        cout << "\n***************************************" << endl;
        cout << "*              1.创建文件             *\n";
        cout << "*              2.删除文件             *\n";
        cout << "*              3.打开文件             *\n";
        cout << "*              4.关闭文件             *\n";
        cout << "*              5.读取文件             *\n";
        cout << "*              6.写入文件             *\n";
        cout << "*              7.显示所有文件         *\n";
        cout << "*              8.显示打开文件         *\n";
        cout << "*              0.退出系统             *\n";
        cout << "***************************************\n"<<endl;
        char choice;
        cout << "请输入您的操作" << endl;
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case '0':
            cout << "感谢您的使用！" << endl;
            exit(1);
        case '1':
            Create_UFD();
            break;
        case '2':
            Delete_UFD();
            break;
        case '3':
            Open();
            break;
        case '4':
            Close();
            break;
        case '5':
            Read();
            break;
        case '6':
            Write();
            break;
        case '7':
            Show_UFD();
            break;
        case '8':
            Show_AFD();
            break;
        default:
            cout << "没有该操作，请重新输入" << endl;
            break;
        }
    }
    return 0;
}