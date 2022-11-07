#include "func.cpp"

int main() {
    init();
    int a, x;
    while(1) {
        cout<<"=========菜单========="<<endl;
        cout<<"(1) 创建"<<endl;
        cout<<"(2) 撤销"<<endl;
        cout<<"(3) 时间片到"<<endl;
        cout<<"(4) 挂起"<<endl;
        cout<<"(5) 激活"<<endl;
        cout<<"(6) 显示"<<endl;
        cout<<"(0) 退出"<<endl;
        cout<<"=========菜单========="<<endl;

        cout<<endl<<"请输入您的操作:"<<endl;
        cin>>a;
        switch(a) {
            case 1: create(); break;
            case 2: kill(); break;
            case 3: time_control(); break;
            case 4: 
                cout<<"请选择挂起原因,其中"<<endl;
                cout<<"0:等待I/O操作完成"<<endl<<"1:等待分配内存"<<endl<<"2:等待接收消息"<<endl;
                cin>>x;
                susp(x);
                break;
            case 5:
                cout<<"请选择等待的时间,其中"<<endl;
                cout<<"0:I/O操作完成"<<endl<<"1:分配内存"<<endl<<"2:接收消息"<<endl;
                cin>>x;
                wakeup(x);
                break;
            case 6: show(); break;
            case 0: 
                cout<<"感谢您的使用，再见"<<endl;
                exit(0);
                break;
            default:
                cout<<"不存在该操作"<<endl;
                break;
        }
    }
    return 0;
}