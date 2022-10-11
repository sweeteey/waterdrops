#include "main.cpp"

// float表示的时间转化为标准形式输出
void ShowF(float f) {
    float minute = (int)(f * 100) % 100;
    float hour = f - minute / 100;
    cout<<hour<<":"<<setfill('0')<<setw(2)<<minute;
}
//输出job[]
void Show(Job job[], int n)
{
    cout <<"作业编号 进入时间 运行时间 开始时间 结束时间 周转时间 带权周转时间"<<endl;

    for (int i = 0; i < n; i++)
    {
        cout << job[order[i]].id << "     ";
        ShowF(job[order[i]].in_time);
        cout<< "     ";
        cout << job[order[i]].run_time << "       ";
        ShowF(job[order[i]].start_time);
        cout<< "     ";
        ShowF(job[order[i]].end_time);
        cout<< "     ";
        cout << job[order[i]].T_time << "       ";
        cout << job[order[i]].W_time << endl;
    }
}

// float表示的时间转换为minute
float F_to_M(float f)
{
    float minute = (int)(f * 100) % 100;
    float hour = f - minute / 100;
    return hour * 60 + minute;
}

// minute转换为float表示的时间
float M_to_F(float m)
{
    float minute = (int)m % 60;
    float hour = (m - minute) / 60;
    return hour + minute / 100;
}

/*******求结束时间**********/
float GetEndTime(Job &j)
{
    j.end_time = M_to_F(j.run_time + F_to_M(j.start_time));
    return j.end_time;
}

/*******求周转时间**********/
float GetTTime(Job &j)
{
    j.T_time = F_to_M(j.end_time) - F_to_M(j.in_time);
    return j.T_time;
}

/******求带权周转时间*********/
float GetWTime(Job &j)
{
    j.W_time = j.T_time / j.run_time;
    return j.W_time;
}

/*******按照到达时间进行排序******/
/*******选择冒泡排序******/
Job *SortByInTime(Job job[], int n)
{
    int end = n;
    while (end)
    {
        int flag = 0; //记录是否有交换
        for (int i = 1; i < end; i++)
        {
            if (job[i - 1].in_time > job[i].in_time)
            {
                Job temp = job[i];
                job[i] = job[i - 1];
                job[i - 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
        end--;
    }
    return job;
}