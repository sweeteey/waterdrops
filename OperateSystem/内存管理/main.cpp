#include "func.cpp"

int main() {
    init();
    while(1) {
        cout << "*************************" << endl;
		cout << "*        1:添加作业     *" << endl;
		cout << "*        2:回收内存     *" << endl;
        cout << "*        3:显示内存     *" << endl;
		cout << "*        0:退出程序     *" << endl;
		cout << "*        请选择:        *" << endl;
        cout << "*************************" << endl;
        int Choice;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            create();
            break;
        case 2:
            callBack();
            break;
        case 3:
            showEmpty();
            showWork();
            break;
        case 0:
            cout << "感谢使用" << endl;
            exit(1);
        default:
            cout << "输入有误，请重新输入" << endl;
            break;
        }
    }
    return 0;
}