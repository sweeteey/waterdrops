/**
 * 多道环境
 * 输入n个作业的进入时间、估计运行时间、所需资源
 * 输出开始时间、结束时间、周转时间、带权周转时间
 * */
#include "func.cpp"
#include <queue>

const int num = 2; //环境道数
int remain_num;    //剩余环境道数

const double block = 5; //时间片
double timeblock;       //时间标志

int D_end; //剩余作业数

queue<int> ready; //就绪队列
queue<int> run;   //运行队列


//SJF和HRRN需要用到优先队列，这里定义其排序方法
struct SJF_cmp {
    bool operator() (int i, int j) {
        return job[i].run_time > job[j].run_time;
    }
}; //SJF中，run_time小的优先
struct HRRN_cmp {
    bool operator() (int i, int j) {
        return GetR(job[i], timeblock) < GetR(job[j], timeblock);
    }
}; //HRRN中，响应比大的优先

priority_queue<int, vector<int>, SJF_cmp> SJF_ready; //SJF就绪队列
priority_queue<int, vector<int>, SJF_cmp> SJF_in; //SJF输入井

priority_queue<int, vector<int>, HRRN_cmp> HRRN_ready; //HRRN就绪队列
priority_queue<int, vector<int>, HRRN_cmp> HRRN_in; //HRRN输入井


double D_GetEndTime(Job &j); //获取周转时间,带权周转时间
int IsReady(Job j); //判断是否能入就绪队列
void Timecontrol(Job job[]); //时间片到后的快照
void Dispatch(Job job[]); //调度run和ready

void D_FCFS(Job job[], int n);
void D_SJF(Job job[], int n);
void D_HRRN(Job job[], int n);



//多道环境下作业 进入内存(in_time)、结束时间(end_time)根据timeblock来确定
// GetEndTime需要重写
/*******周转时间,带权周转时间**********/
double D_GetEndTime(Job &j)
{
    //周转时间
    j.T_time = D_to_M(j.end_time) - D_to_M(j.in_time);
    //带权周转时间
    j.W_time = j.T_time / j.run_time;
    return j.end_time;
}

/*******判断是否能够进入就绪队列**********/
// status 状态 0--外存 1--就绪队列 2--运行队列 3--运行完
// 1.在输入井中 in_time == timeblock
// 2.尚未入就绪队列 status == 0
// 3.系统有剩余道数 remain_num > 0
int IsReady(Job j)
{
    // cout<<"正在检测"<<j.id<<endl;
    if (j.in_time <= timeblock && j.status == 0 && remain_num > 0)
        return 1;
    // else if(j.in_time > timeblock) {
    //     cout<<j.id<<"还未进入输入井"<<endl;
    // }
    // else if(j.status == 1) {
    //     cout<<j.id<<"已经进入就绪队列"<<endl;
    // }
    // else if(j.status == 2) {
    //     cout<<j.id<<"已经进入运行队列"<<endl;
    // }
    // else if(j.status == 3) {
    //     cout<<j.id<<"已经运行完"<<endl;
    // }
    // else if (remain_num <= 0){
    //     cout<<"没有资源了"<<endl;
    // }
    // else {
    //     cout<<"error"<<endl;
    // }
    return 0;
}

/*******时间片到**********/
//若作业运行完:
// 1.D_end--
// 2.status = 3
// 3.end_time = timeblock
// 4.计算周转时间,带权周转时间
// 5.run.pop()
// 6.回收资源 remain_num
//若作业未运行完：
//下一个时间片到
void Timecontrol(Job job[])
{
    if (job[run.front()].remain < 0)
        exit(1);

    timeblock = M_to_D(D_to_M(timeblock) + block);

    job[run.front()].remain -= block;

    //若时间片到时，作业运行完
    if (job[run.front()].remain == 0)
    {
        cout << "job" << run.front() << "运行完..." << endl;
        D_end--;
        job[run.front()].status = 3;
        job[run.front()].end_time = timeblock;
        D_GetEndTime(job[run.front()]);
        run.pop();
        remain_num++;
    }
}

/*******调度程序**********/
// run空，ready首入run，时间片到
// 若run空且ready空，下一时间片
// run不空，时间片到
void Dispatch(Job job[])
{
    if (run.empty())
    {
        if (!ready.empty())
        {
            cout << "就绪队列队首job" << ready.front() << "入运行队列..." << endl;
            //将ready队首推入run
            run.push(ready.front());
            //运行的作业status=2
            job[run.front()].status = 2;
            //删除ready队首
            ready.pop();

            //下一个时间片
            Timecontrol(job);
        }
        else
        {
            timeblock = M_to_D(D_to_M(timeblock) + block);
        }
    }
    else
        Timecontrol(job);
}

/******先来先服务调度算法*********/
//初始时间timeblock设置为第一个作业进入时间，即为job[0].in_time
//剩余道数 remain_num = num
//未完成的作业数D_end = n
void D_FCFS(Job job[], int n)
{
    timeblock = job[0].in_time;
    remain_num = num;
    D_end = n;

    //作业未全部完成，则时间片一直轮转
    //遍历作业，查看：是否有作业进入输入井，若进入输入井则查看是否能进入ready
    //调度程序
    //时间片到
    while (D_end)
    {
        for (int i = 0; i < n; i++)
        {
            //入ready：
            // 1.start_time = timebleck
            // 2.status = 1
            // 3.remain_num--;
            // 4.ready.push()
            if (IsReady(job[i]))
            {
                job[i].start_time = timeblock;
                job[i].status = 1;
                remain_num--;
                ready.push(i);
                cout << "job" << i << "入就绪队列" << endl;
            }
        }
        Dispatch(job);
    }
}

/******短作业优先调度算法*********/
void D_SJF(Job job[], int n)
{
    timeblock = job[0].in_time;
    remain_num = num;
    D_end = n;


    while (D_end)
    {
        //遍历作业，查看：是否有作业进入输入井
        for (int i = 0; i<n; i++) {
            if (job[i].in_time <= timeblock && job[i].status == 0) {
                SJF_in.push(i);
            }
        }
        //进入输入井
        while (remain_num > 0) {
            int temp = SJF_in.top();
            SJF_in.pop();
            SJF_ready.push(temp);
            job[temp].start_time = timeblock;
            job[temp].status = 1;
            remain_num--;
            cout<<job[temp].id<<"入就绪队列" << endl;
        }
        Dispatch(job);
    }
}

/******最高响应比优先调度算法*********/
void D_HRRN(Job job[], int n)
{
    timeblock = job[0].in_time;
    remain_num = num;
    D_end = n;


    while (D_end)
    {
        //遍历作业，查看：是否有作业进入输入井
        for (int i = 0; i<n; i++) {
            if (job[i].in_time <= timeblock && job[i].status == 0) {
                HRRN_in.push(i);
            }
        }
        //进入输入井
        while (remain_num > 0) {
            int temp = HRRN_in.top();
            HRRN_in.pop();
            HRRN_ready.push(temp);
            job[temp].start_time = timeblock;
            job[temp].status = 1;
            remain_num--;
            cout<<job[temp].id<<"入就绪队列" << endl;
        }
        Dispatch(job);
    }
}


int main()
{
    //Job *job = init(n);
    //SortByInTime(job, n);

    job[0].id = "job0";
    job[0].in_time = 10.00;
    job[0].run_time = job[0].remain = 30;

    job[1].id = "job1";
    job[1].in_time = 10.05;
    job[1].run_time = job[1].remain = 20;

    job[2].id = "job2";
    job[2].in_time = 10.10;
    job[2].run_time = job[2].remain = 5;

    job[3].id = "job3";
    job[3].in_time = 10.20;
    job[3].run_time = job[3].remain = 10;

    cout<<endl<<"====================="<<endl;
    cout<<"FCFS调度算法:"<<endl;
    D_FCFS(job, n);
    Show(job, n);
    cout<<endl;
    Clear(job, n);

    cout<<"SJF调度算法:"<<endl;
    D_SJF(job, n);
    Show(job, n);
    cout<<endl;
    Clear(job, n);

    cout<<"HRRN调度算法:"<<endl;
    D_HRRN(job, n);
    Show(job, n);

}