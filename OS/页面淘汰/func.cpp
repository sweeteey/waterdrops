

// FIFO，设置queue<int> F_queue
// 1.在内存中，continue
// 2.size<PageNum，页框未满，push()
// 3.size==PageNum, 页框已满，pop()，push()

// LRU，设置queue<int> L_queue
// 1.在内存中，erase(),push()
// 2.size<PageNum，页框未满，push()
// 3.size==PageNum, 页框已满，pop()，push()

// OPT，设置queue<int> O_queue
// 1.在内存中，continue
// 2.size<PageNum，页框未满，push()
// 3.size==PageNum, 页框已满，找出nextNo最大的erase(),push()

#include <iostream>
#include <queue>
using namespace std;
#define MAX 100

queue<int> page_queue;
int arr[MAX]; //访问序列
int List;     //访问序列长度
int PageNum;  //页框数

int missing = 0; //缺页次数
double rate;     //缺页中断率

void init();       //初始化，生成随机访问序列arr[]
void clear();      // page_queue清空，missing重置
void showList();   //打印访问序列
void showQ(int i); //访问arr[i]时，打印内存空间中的页码

int inArr(int a);               //判断页码a是否在内存中
void erase(int a);              //将页码a从page_queue中删除
int getNextNo(int page, int i); //返回页码在arr[]中下一次出现的位置，参数i标识当前arr[]的位置
int getMaxNext(int i);          //找到page_queue中nextNo最大的，并返回页码数

void FIFO();
void LRU();
void OPT();

void init()
{
    //生成随机数序列
    srand((unsigned int)(time(NULL)));
    for (int i = 0; i < List; i++)
    {
        arr[i] = rand() % 20;
        cout << arr[i] << " ";
        // cout << "arr["<<i<<"] = "<<arr[i]<<endl;
    }
    cout << endl;
}

void clear()
{
    // missing重置
    missing = 0;
    // page_queue清空，pop()直到队列空
    while (!page_queue.empty())
    {
        page_queue.pop();
    }
}

void showList()
{
    //每十个换行
    cout << endl
         << "================页面访问序列=====================" << endl;
    for (int i = 0; i < List; i++)
    {
        printf("%4d", arr[i]);
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
        if (i == List-1)
        {
            cout << endl;
        }
    }
    cout << "=================================================" << endl;
}

void showQ(int i)
{
    printf("访问%3d ----> 内存中的页码有 [", arr[i]);
    queue<int> q_index = page_queue;
    int n = PageNum;
    while (n != 0)
    {
        //不为空，则打印页码
        if (!q_index.empty())
        {
            printf("%3d", q_index.front());
            q_index.pop();
        }
        //为空，打印空格
        else
        {
            printf("   ");
        }
        n--;
    }
    printf("]");
}

int inArr(int a)
{
    queue<int> q_index = page_queue;
    while (!q_index.empty())
    {
        //在内存中找到a
        if (q_index.front() == a)
        {
            return 1;
        }
        q_index.pop();
    }
    return 0;
}

void erase(int a)
{
    // cout<<"要移除的页码是"<<a<<endl;
    queue<int> q_index;
    while (!page_queue.empty())
    {
        if (page_queue.front() != a)
        {
            //从page_queue队首入q_index队尾
            q_index.push(page_queue.front());
        }
        page_queue.pop();
    }
    page_queue = q_index;
}

int getNextNo(int page, int i)
{
    for (int n = i + 1; n < List; n++)
    {
        if (page == arr[n])
        {
            // cout<<page<<"下一次出现的位置是"<<n<<endl;
            return n;
        }
    }
    // cout<<page<<"不再出现"<<endl;
    return -1;
}

int getMaxNext(int i)
{
    queue<int> q_index = page_queue;
    int furthest = getNextNo(q_index.front(), i);
    int page = q_index.front();
    //若furthest==-1，说明该页码不再出现
    while (!q_index.empty() && furthest != -1)
    {
        q_index.pop();
        int temp = getNextNo(q_index.front(), i);
        if (temp > furthest || temp == -1)
        {
            furthest = temp;
            page = q_index.front();
        }
    }

    return page;
}

// FIFO，设置queue<int> F_queue
// 1.在内存中，continue
// 2.size<PageNum，页框未满，push()
// 3.size==PageNum, 页框已满，pop()，push()
void FIFO()
{
    for (int i = 0; i < List; i++)
    {
        //若在内存中，continue
        if (inArr(arr[i]))
        {
            showQ(i);
            printf("\n");
        }
        //若不在内存中，缺页
        else
        {
            missing++; //缺页次数+1
            // size<PageNum，页框未满，push()
            if (page_queue.size() < PageNum)
            {
                page_queue.push(arr[i]);
            }
            // size==PageNum, 页框已满，pop()，push()
            else if (page_queue.size() == PageNum)
            {
                page_queue.pop();
                page_queue.push(arr[i]);
            }
            showQ(i);
            printf(" ---缺页中断--- \n");
        }
    }
    rate = (double)missing / (double)List;
}

// LRU，设置queue<int> L_queue
// 1.在内存中，erase(),push()
// 2.size<PageNum，页框未满，push()
// 3.size==PageNum, 页框已满，pop()，push()
void LRU()
{
    for (int i = 0; i < List; i++)
    {
        //若在内存中，erase(),push()
        if (inArr(arr[i]))
        {
            erase(arr[i]);
            page_queue.push(arr[i]);
            showQ(i);
            printf("\n");
        }
        //若不在内存中，缺页
        else
        {
            missing++; //缺页次数+1
            // size<PageNum，页框未满，push()
            if (page_queue.size() < PageNum)
            {
                page_queue.push(arr[i]);
            }
            // size==PageNum, 页框已满，pop()，push()
            else if (page_queue.size() == PageNum)
            {
                page_queue.pop();
                page_queue.push(arr[i]);
            }
            showQ(i);
            printf(" ---缺页中断--- \n");
        }
    }
    rate = (double)missing / (double)List;   
}


// OPT，设置queue<int> O_queue
// 1.在内存中，continue
// 2.size<PageNum，页框未满，push()
// 3.size==PageNum, 页框已满，找出nextNo最大的erase(),push()
void OPT()
{
    // cout<<"此时OPT的页框数为"<<PageNum<<endl;
    for (int i = 0; i < List; i++)
    {
        //若在内存中，erase(),push()
        if (inArr(arr[i]))
        {
            showQ(i);
            printf("\n");
        }
        //若不在内存中，缺页
        else
        {
            missing++; //缺页次数+1
            // size<PageNum，页框未满，push()
            if (page_queue.size() < PageNum)
            {
                page_queue.push(arr[i]);
            }
            // size==PageNum, 页框已满，找出nextNo最大的erase(),push()
            else if (page_queue.size() == PageNum)
            {
                // cout<<"页框满"<<endl;
                erase(getMaxNext(i));
                page_queue.push(arr[i]);
            }
            showQ(i);
            printf(" ---缺页中断--- \n");
        }
    }
    rate = (double)missing / (double)List; 
}