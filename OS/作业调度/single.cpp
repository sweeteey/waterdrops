/**
 * 单道环境
 * 输入n个作业的进入时间和估计运行时间(min)
 * 输出开始时间、结束时间、周转时间、带权周转时间
 * */

#include "func.cpp"

/******先来先服务调度算法*********/
void FCFS(Job job[], int n)
{
    double end_temp = 0.00; //标记当前作业结束时间
    for (int i = 0; i < n; i++)
    {
        order[i] = i;
        //开始时间
        //若还未进入输入井，则开始时间 为 进入时间
        //否则，开始时间为上一个作业结束时间
        if (job[i].in_time > end_temp)
            job[i].start_time = job[i].in_time;
        else
            job[i].start_time = end_temp;
        //结束时间，周转时间，带权周转时间
        end_temp = GetEndTime(job[i]);
    }
}

/******短作业优先调度算法*********/
void SJF(Job job[], int n)
{
    //最先到达的作业最先运行
    order[0] = 0;
    job[0].start_time = job[0].in_time;
    double end_temp = GetEndTime(job[0]);

    //第一层for循环，循环n-1次表示需要运行剩下的n-1个作业
    for (int i = 1; i < n; i++)
    {
        double min=9999;
        //第二层for循环，从job[1...n-1]中找出下一个运行的作业
        for (int j = 1; j < n; j++)
        {
            //若作业不在输入井中，说明后面的作业都不在其中
                //break
            if (job[j].in_time > end_temp)
                break;
            //若作业在输入井中，满足：
            //1. in_time <= end_temp
            //2. end_time == 0
                //if(min>job[j].run_time)
                //则min=job[j].run_time,order[i]=j
            else if (job[j].in_time <= end_temp && job[j].end_time==0)
            {
                if(min>job[j].run_time) {
                    min = job[j].run_time;
                    order[i] = j;
                }
            }
        }
        //if(order[i]==0),输入井中无作业
            //运行接下来的job
        if (order[i]==0) {
            int number = order[i-1]+1;
            order[i] = number;
            job[number].start_time = job[number].in_time;
            end_temp = GetEndTime(job[number]);
        }
        else {
            job[order[i]].start_time = end_temp;
            end_temp = GetEndTime(job[order[i]]);
        }
    }
}

/******最高响应比优先调度算法*********/
void HRRN(Job job[], int n) {
    //最先到达的作业最先运行
    order[0] = 0;
    job[0].start_time = job[0].in_time;
    double end_temp = GetEndTime(job[0]);

    //第一层for循环，循环n-1次表示需要运行剩下的n-1个作业
    for (int i=1; i<n; i++) {
        double start;
        double high = 0;
        //第二层for循环，计算job[1...n-1]的响应比:
        for (int j=1; j<n; j++) {
            //若已完成
                //continue;
            if (job[j].end_time != 0)
                continue;
            //若未完成
                //if (high < GetR(job[j]))
                //high = GetR(job[j]),order[i]=j
            else {
                //不在输入井中，start=job.in_time
                //在输入井中，start=end_temp
                start = (job[j].in_time > end_temp) ? job[j].in_time : end_temp;
                // cout<<job[j].id<<"响应比为"<<GetR(job[j], start)<<endl;
                if (high < GetR(job[j], start)) {
                    high = GetR(job[j], start);
                    order[i] = j;
                }
            }
            
        }
        job[order[i]].start_time = start;
        end_temp = GetEndTime(job[order[i]]);
    }
}


// int main()
// {
//     // cout.setf(ios::fixed);; //显示小数点后面的0
//     // cout.precision(2);              //使用定点计数法，显示小数点后面位数精度

//     //测试
//     Job job[3] = {
//         {"job1", 8.00, 30},
//         {"job2", 8.30, 20},
//         {"job3", 8.10, 60}};
//     SortByInTime(job, 3);
//     // for(int i=0; i<3; i++) {
//     //     order[i] = i;
//     // }
//     // Show(job, 3);
//     // cout<<"F_to_M()\t"<<F_to_M(1.2)<<endl;
//     // cout<<"M_to_F()\t"<<M_to_F(80)<<endl;
//     cout<<"先来先服务调度算法"<<endl;
//     FCFS(job, 3);
//     Show(job, 3);

//     Clear(job, 3);

//     cout<<endl<<"短作业优先调度算法"<<endl;
//     SJF(job, 3);
//     Show(job, 3);

//     Clear(job, 3);

//     cout<<endl<<"最高响应比优先调度算法"<<endl;
//     HRRN(job, 3);
//     Show(job, 3);
// }

int main() {
    Job *job = init(n);
    SortByInTime(job, n);

    cout<<endl<<"====================="<<endl;
    cout<<"FCFS调度算法:"<<endl;
    FCFS(job, n);
    Show(job, n);
    cout<<endl;
    Clear(job, n);

    cout<<"SJF调度算法:"<<endl;
    SJF(job, n);
    Show(job, n);
    cout<<endl;
    Clear(job, n);

    cout<<"HRRN调度算法:"<<endl;
    HRRN(job, n);
    Show(job, n);
}