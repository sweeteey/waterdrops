/*****创建、撤销、时间片到(时间片轮转调度算法)、挂起、激活*****/
#include "head.cpp"

void get_free(); //构造容量为N的空闲PCB队列
void dispatch(); //采用FIFO调度算法
void init();     //初始化
void create();   //创建
void kill();     //撤销,在进程处于运行状态下进行的
void time_control(); //时间片到
void susp(int x); //挂起,在进程处于运行状态下进行的
void wakeup(int x); //激活,阻塞队首移到就绪队列
void show();


void get_free()
{
    //空闲PCB队列首指针
    p_free = new PCB();

    //标识指针
    PCB *temp = p_free;
    temp->all_next = NULL;

    PCB *p;
    for (int i = 1; i < N; i++)
    {
        p = new PCB();
        temp->all_next = p;
        temp = p;
        temp->all_next = NULL;
    }
}

void dispatch() {
    //就绪队列首进入运行队列
    //就绪队列空
    if(p_ready == NULL) {
        cout<<"没有可以运行的进程"<<endl;
        return;
    }
    //就绪队列只有一个进程
    else if(p_ready == p_ready_rear) {
        //插入运行队列
        p_run = p_ready;
        p_ready = p_ready_rear = NULL;
        p_run->next = NULL;
    }
    else {
        p_run = p_ready;
        p_ready = p_ready->next;
        p_run->next = NULL;
    }

    p_run->status = 2;
}

void init()
{
    get_free();
    //等待队列
    p_wait0 = p_wait0_rear = NULL;
    p_wait1 = p_wait1_rear = NULL;
    p_wait2 = p_wait2_rear = NULL;

    //将初始化的进程插入 就绪队列 和 总链
    cout << "输入PCB的个数(个数少于" << N << "个):" << endl;
    cin >> num;
    while (num > N)
    {
        cout << "输入PCB的个数不得大于" << N << "个)" << endl;
        cout << "请重新输入PCB的个数:" << endl;
        cin >> num;
    }
    cout << "请分别输入PCB的ID、预计运行时间:" << endl;

    //从空闲队列取一个到总链
    p_all = p_all_rear = p_free;
    p_free = p_free->all_next;
    p_all_rear->all_next = NULL;

    cin >> p_all->id;
    cin >> p_all->time;
    p_all->y_time = 0;
    p_all->status = 0;

    //放入就绪队列中
    p_ready = p_ready_rear = p_all;
    p_ready_rear->next = NULL;

    //首指针以后的操作
    for (int i = 1; i < num; i++)
    {
        PCB *p = p_free;
        p_free = p_free->all_next;
        p->all_next = NULL;
        p->next = NULL;

        cin >> p->id;
        cin >> p->time;
        p->y_time = 0;
        p->status = 0;

        //放入总链
        p_all_rear->all_next = p;
        p_all_rear = p_all_rear->all_next;
        //放入就绪队列
        p_ready_rear->next = p;
        p_ready_rear = p_ready_rear->next;
    }

    dispatch();
}

void create()
{
    // PCB表已满
    if (num == N)
    {
        cout << "PCB池已满,创建失败" << endl;
        return;
    }

    int tag = 0;
    string ID;
    PCB *p = p_all;

    cout << "请输入ID:" << endl;
    cin >> ID;

    // ID不能重复
    while (p != NULL)
    {
        if (p->id == ID)
        {
            tag = 1;
            break;
        }
        p = p->all_next;
    }

    if (tag == 1)
    {
        cout << "ID名重复,创建失败" << endl;
        return;
    }
    else if (tag == 0)
    {
        num++; // PCB个数加一

        //从空闲队列中取一个
        PCB *newp = p_free;
        p_free = p_free->all_next;
        newp->all_next = NULL;
        newp->next = NULL;

        cout << "请输入预计运行时间:" << endl;
        cin >> newp->time;
        newp->id = ID;
        newp->status = 0;
        newp->y_time = 0;

        //插入到总链
        p_all_rear->all_next = newp;
        p_all_rear = p_all_rear->all_next;

        //插入到就绪队列
        p_ready_rear->next = newp;
        p_ready_rear = p_ready_rear->next;

        cout << "创建新进程成功" << endl;
    }
}

void kill()
{
    //找到总链中该进程位置
    PCB *p = p_all;
    while (p != NULL)
    {
        if (p_run->id == p->id)
        {
            //总链只有一个PCB
            if (p_all == p_all_rear)
            {
                delete p_all;
                p_all = p_all_rear = NULL;
            }
            else
            {
                //队首
                if (p_all == p)
                {
                    p_all = p_all->all_next;
                    delete p;
                }
                //队尾
                else if (p_all_rear == p)
                {
                    PCB *temp = p_all;
                    //找到队尾上一个PCB
                    while (temp->all_next != p)
                    {
                        temp = temp->all_next;
                    }

                    p_all_rear = temp;
                    p_all_rear->all_next = NULL;
                    delete p;
                }
                //中间
                else
                {
                    PCB *temp = p_all;
                    //找到p的上一个PCB
                    while (temp->all_next != p)
                    {
                        temp = temp->all_next;
                    }

                    temp->all_next = p->all_next;
                    delete p;
                }
            }
            //空出来的插入空闲队列
            PCB *temp = new PCB();
            temp->all_next = p_free;
            p_free = temp;

            // PCB个数减一
            num--;

            cout << "撤销成功" << endl;
            dispatch();
            return;
        }
        p = p->all_next;
    }
    cout << "撤销失败" << endl;
}

void time_control() {
    //剩余未完成的时间
    int w_time = p_run->time - p_run->y_time;

    //时间片够,运行结束,申请撤销
    if (w_time <= PART) {
        kill();
    }
    //时间片不够,插入就绪队列尾
    else {
        p_run->y_time += PART;
        p_run->status = 0;
        p_ready_rear->next = p_run;
        p_ready_rear = p_ready_rear->next;
        p_ready_rear->next = NULL;

        dispatch();
    }
}

// 0:等待I/O操作完成
// 1:等待分配内存
// 2:等待接收消息
void susp(int x)
{
    switch (x)
    {
    case 0:
        //变为阻塞状态
        p_run->status = 1;
        if (p_wait0 == NULL)
        {
            p_wait0 = p_wait0_rear = p_run;
            p_wait0_rear->next = NULL;
        }
        else
        {
            p_wait0_rear->next = p_run;
            p_wait0_rear = p_wait0_rear->next;
            p_wait0_rear->next = NULL;
        }
        cout<<"挂起成功"<<endl;
        dispatch();
        break;

    case 1:
        //变为阻塞状态
        p_run->status = 1;
        if (p_wait1 == NULL)
        {
            p_wait1 = p_wait1_rear = p_run;
            p_wait1_rear->next = NULL;
        }
        else
        {
            p_wait1_rear->next = p_run;
            p_wait1_rear = p_wait1_rear->next;
            p_wait1_rear->next = NULL;
        }
        cout<<"挂起成功"<<endl;
        dispatch();
        break;
    case 2:
        //变为阻塞状态
        p_run->status = 1;
        if (p_wait2 == NULL)
        {
            p_wait2 = p_wait2_rear = p_run;
            p_wait2_rear->next = NULL;
        }
        else
        {
            p_wait2_rear->next = p_run;
            p_wait2_rear = p_wait2_rear->next;
            p_wait2_rear->next = NULL;
        }
        cout<<"挂起成功"<<endl;
        dispatch();
        break;
    default:
        cout << "不存在这种阻塞原因" << endl;
        break;
    }
}

void wakeup(int x) {
    switch (x)
    {
    case 0:
        if (p_wait0 == NULL) {
            cout<<"没有可被唤醒的进程"<<endl;
        }
        //只有一个阻塞进程
        else if (p_wait0 == p_wait0_rear) {
            //插入就绪队列尾
            p_ready_rear->next = p_wait0;
            p_ready_rear = p_ready_rear->next;
            p_ready_rear->next = NULL;

            p_wait0 = p_wait0_rear = NULL;
        }
        //有多个阻塞进程
        else
        {
            p_ready_rear->next = p_wait0;
            p_wait0 = p_wait0->next;
            p_ready_rear = p_ready_rear->next;
            p_ready_rear->next = NULL;            
        }
        p_ready_rear->status = 0;
        break;

    case 1:
        if (p_wait1 == NULL) {
            cout<<"没有可被唤醒的进程"<<endl;
        }
        //只有一个阻塞进程
        else if (p_wait1 == p_wait1_rear) {
            //插入就绪队列尾
            p_ready_rear->next = p_wait1;
            p_ready_rear = p_ready_rear->next;
            p_ready_rear->next = NULL;

            p_wait1 = p_wait1_rear = NULL;
        }
        //有多个阻塞进程
        else
        {
            p_ready_rear->next = p_wait1;
            p_wait1 = p_wait1->next;
            p_ready_rear = p_ready_rear->next;
            p_ready_rear->next = NULL;            
        }
        p_ready_rear->status = 0;
        break;

    case 2:
        if (p_wait2 == NULL) {
            cout<<"没有可被唤醒的进程"<<endl;
        }
        //只有一个阻塞进程
        else if (p_wait2 == p_wait2_rear) {
            //插入就绪队列尾
            p_ready_rear->next = p_wait2;
            p_ready_rear = p_ready_rear->next;
            p_ready_rear->next = NULL;

            p_wait2 = p_wait2_rear = NULL;
        }
        //有多个阻塞进程
        else
        {
            p_ready_rear->next = p_wait2;
            p_wait2 = p_wait2->next;
            p_ready_rear = p_ready_rear->next;
            p_ready_rear->next = NULL;            
        }
        p_ready_rear->status = 0;
        break;
    default:
        cout << "不存在这种阻塞原因" << endl;
        break;
    }
}

void show() {
    cout<<endl<<"===================================================="<<endl;
    if (p_run) {
        cout<<"运行队列:"<<endl;
        cout<<"id   状态   预计运行时间  已运行时间"<<endl;
        cout<<p_run->id<<"   运行中  "<<p_run->time<<"            "<<p_run->y_time<<endl;
        cout<<endl;
    }

    if (p_ready) {
        cout<<"就绪队列:"<<endl;
        cout<<"id   状态   预计运行时间  已运行时间"<<endl;
        PCB* p = p_ready;
        while(p != NULL) {
            cout<<p->id<<"   就绪中  "<<p->time<<"            "<<p->y_time<<endl;
            p = p->next;
        }
        cout<<endl;
    }

    if (p_wait0) {
        cout<<"等待I/O操作完成的阻塞队列:"<<endl;
        cout<<"id   状态   预计运行时间  已运行时间"<<endl;
        PCB* p = p_wait0;
        while(p != NULL) {
            cout<<p->id<<"   阻塞中  "<<p->time<<"            "<<p->y_time<<endl;
            p = p->next;
        }
        cout<<endl;
    }

    if (p_wait1) {
        cout<<"等待分配内存的阻塞队列:"<<endl;
        cout<<"id   状态   预计运行时间  已运行时间"<<endl;
        PCB* p = p_wait1;
        while(p != NULL) {
            cout<<p->id<<"   阻塞中  "<<p->time<<"            "<<p->y_time<<endl;
            p = p->next;
        }
        cout<<endl;
    }

    if (p_wait2) {
        cout<<"等待接收消息的阻塞队列:"<<endl;
        cout<<"id   状态   预计运行时间  已运行时间"<<endl;
        PCB* p = p_wait2;
        while(p != NULL) {
            cout<<p->id<<"   阻塞中  "<<p->time<<"            "<<p->y_time<<endl;
            p = p->next;
        }
    }
    cout<<"===================================================="<<endl<<endl;
}