/**
 * 单道环境
 * 输入n个作业的进入时间和估计运行时间(min)
 * 输出开始时间、结束时间、周转时间、带权周转时间
 * */

#include "func.cpp"

/******先来先服务调度算法*********/
void FCFS(Job job[], int n) {
    float end_temp = 0.00; //标记当前作业结束时间
    for (int i=0; i<n; i++) {
        order[i] = i;
        //开始时间
        //若还未进入输入井，则开始时间 为 进入时间
        //否则，开始时间为上一个作业结束时间
        if (job[i].in_time > end_temp)
            job[i].start_time = job[i].in_time;
        else
            job[i].start_time = end_temp;
        //结束时间
        end_temp = GetEndTime(job[i]);
        //周转时间
        GetTTime(job[i]);
        //带权周转时间
        GetWTime(job[i]);
    }
}

/******短作业优先调度算法*********/
void SJF(Job job[], int n);

int main()
{
    // cout.setf(ios::fixed);; //显示小数点后面的0
    // cout.precision(2);              //使用定点计数法，显示小数点后面位数精度

    //测试
    Job job[3] = {
        {"job1", 8.00, 10},
        {"job2", 8.30, 20},
        {"job3", 8.10, 60}};
    SortByInTime(job, 3);
    // for(int i=0; i<3; i++) {
    //     order[i] = i;
    // }
    // Show(job, 3);
    // cout<<"F_to_M()\t"<<F_to_M(1.2)<<endl;
    // cout<<"M_to_F()\t"<<M_to_F(80)<<endl;
    FCFS(job, 3);
    Show(job, 3);

}