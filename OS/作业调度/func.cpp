#include "head.cpp"


// double表示的时间转化为标准形式输出
void ShowD(double d) {
    double minute = (int)round(d*100)%100;
    // double minute = (int)(d * 100) % 100;
    double hour = d - minute / 100;
    cout<<hour<<":"<<setfill('0')<<setw(2)<<minute;
}
//输出job[]
void Show(Job job[], int n)
{
    cout <<"作业编号 进入时间 运行时间 开始时间 结束时间 周转时间 带权周转时间"<<endl;

    for (int i = 0; i < n; i++)
    {
        cout << job[i].id << "     ";
        ShowD(job[i].in_time);
        cout<< "     ";
        cout << job[i].run_time << "       ";
        ShowD(job[i].start_time);
        cout<< "     ";
        ShowD(job[i].end_time);
        cout<< "     ";
        cout << job[i].T_time << "       ";
        cout << job[i].W_time << endl;
    }
}



//job[]和order[]格式化
void Clear(Job job[],int n) {
    memset(order, 0, sizeof(order));
    for (int i=0; i<n; i++) {
        job[i].status = 0; //double¸
        job[i].remain = job[i].run_time; //double
        job[i].start_time = 0;
        job[i].end_time = 0;
        job[i].T_time = 0;
        job[i].W_time = 0;
    }
}

// double表示的时间转换为minute
double D_to_M(double d)
{
    // double minute = (int)(d * 100) % 100;
    double minute = (int)round(d * 100) % 100;
    double hour = d - minute / 100;
    return hour * 60 + minute;
}

// minute转换为double表示的时间
double M_to_D(double m)
{
    // double minute = (int)m % 60;
    double minute = (int)round(m) % 60;
    double hour = (m - minute) / 60;
    return hour + minute / 100;
}

/*******求结束时间,周转时间,带权周转时间**********/
double GetEndTime(Job &j)
{
    //结束时间
    j.end_time = M_to_D(j.run_time + D_to_M(j.start_time));
    //周转时间
    j.T_time = D_to_M(j.end_time) - D_to_M(j.in_time);
    //带权周转时间
    j.W_time = j.T_time / j.run_time;
    return j.end_time;
}



/***********求响应比************/
double GetR(Job j, double start) {
    double waittime = D_to_M(start) - D_to_M(j.in_time);
    return 1+waittime/j.run_time;
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



/*********输入作业**********/
Job* init(int n) {
    cout<<"请依次输入每个作业的编号、进入时间、运行时间,每输入完一个作业的信息请回车"<<endl;
    cout<<"其中 进入时间以小数形式输入,例如8:30输入为8.30"<<endl;
    
    for (int i=0; i<n; i++) {
        cin>>job[i].id;
        cin>>job[i].in_time;
        cin>>job[i].run_time;
        job[i].remain = job[i].run_time; //double
    }
    return job;
}