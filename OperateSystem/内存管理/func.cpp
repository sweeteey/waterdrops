#include "head.cpp"

void delete_sp(Space *&list, Space *sp); //从list中删除sp
void add_sp(Space *&list, Space *sp);    //向list尾加入sp
void init();                            //初始化
void firstSuit();                       //首次适应排序
void bestSuit();                        //最佳适应排序
void worstSuit();                       //最坏适应排序
void showEmpty();                       //打印empty
void showWork();                        //打印work
void create();                          //创建新作业
void upNeighbor(Space *&sp);             //空闲队列中有上邻
void downNeighbor(Space *&sp);           //空闲队列中有下邻
void callBack();                        //回收已有程序

//初始化
// empty起始地址为内存首地址，长度为sum
// work为null
void init()
{
    empty = new Space;
    empty->begin = 0;
    empty->length = sum;
    empty->next = NULL;
}

//首次适应
void firstSuit()
{
    if (empty == NULL)
    {
        cout << "无剩余空间，分配失败" << endl;
        return;
    }
    //按照从begin从小到大排序
    Space *temp1 = empty;
    Space *temp2 = empty;
    while (temp1->next != NULL)
    {
        while (temp2->next != NULL)
        {
            if (temp2->begin > temp2->next->begin)
            {
                int temp_begin = temp2->begin;
                int temp_len = temp2->length;

                temp2->begin = temp2->next->begin;
                temp2->length = temp2->next->length;
                temp2->next->begin = temp_begin;
                temp2->next->length = temp_len;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

//最佳适应
void bestSuit()
{
    if (empty == NULL)
    {
        cout << "无剩余空间，分配失败" << endl;
        return;
    }
    //按照从length从小到大排序
    Space *temp1 = empty;
    Space *temp2 = empty;
    while (temp1->next != NULL)
    {
        while (temp2->next != NULL)
        {
            if (temp2->length > temp2->next->length)
            {
                int temp_begin = temp2->begin;
                int temp_len = temp2->length;

                temp2->begin = temp2->next->begin;
                temp2->length = temp2->next->length;
                temp2->next->begin = temp_begin;
                temp2->next->length = temp_len;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

//最坏适应
void worstSuit()
{
    if (empty == NULL)
    {
        cout << "无剩余空间，分配失败" << endl;
        return;
    }
    //按照从length从大到小排序
    Space *temp1 = empty;
    Space *temp2 = empty;
    while (temp1->next != NULL)
    {
        while (temp2->next != NULL)
        {
            if (temp2->length < temp2->next->length)
            {
                int temp_begin = temp2->begin;
                int temp_len = temp2->length;

                temp2->begin = temp2->next->begin;
                temp2->length = temp2->next->length;
                temp2->next->begin = temp_begin;
                temp2->next->length = temp_len;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

//打印empty表
void showEmpty()
{
    cout << endl
         << endl
         << "*********empty***********"
         << endl;

    if (empty == NULL)
    {
        cout << "无可申请空间!" << endl;
    }
    else
    {
        Space *temp = empty;
        cout << "begin"
             << "\t"
             << "length"
             << "\t"
             << "状态" << endl;
        while (temp != NULL)
        {
            cout << temp->begin << "\t" << temp->length << "\t"
                 << "未分配" << endl;
            temp = temp->next;
        }
    }
    cout << "*********empty***********" << endl;
}

//打印work表
void showWork()
{
    cout << endl
         << endl
         << "*********work************"
         << endl;

    if (work == NULL)
    {
        cout << "无已用内存" << endl;
    }
    else
    {
        Space *temp = work;
        cout << "作业名"
             << "\t"
             << "begin"
             << "\t"
             << "length" << endl;
        while (temp != NULL)
        {
            cout << temp->name << "\t" << temp->begin << "\t" << temp->length << endl;
            temp = temp->next;
        }
    }
    cout << "*********work************" << endl
         << endl;
}

//从list中删除sp
void delete_sp(Space *&list, Space *sp)
{
    Space *temp = list;
    Space *pretemp = list;
    while (temp != NULL)
    {
        if (temp == sp)
        {
            //若sp为list首结点
            if (temp == list)
            {
                list = list->next;
                temp->next = NULL;
                delete temp;
            }
            else
            {
                while (pretemp->next != temp)
                {
                    pretemp = pretemp->next;
                }
                // sp为list尾结点
                if (temp->next == NULL)
                {
                    pretemp->next = NULL;
                    delete temp;
                }
                // sp在list中间位置
                else
                {
                    pretemp->next = temp->next;
                    temp->next = NULL;
                    delete temp;
                }
            }
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "删除失败" << endl;
}

//向list尾加入sp
void add_sp(Space *&list, Space *sp)
{
    if (list == NULL)
    {
        list = sp;
    }
    else
    {
        Space *l = list;
        while (l->next != NULL)
        {
            l = l->next;
        }
        l->next = sp;
    }
}

//添加新的作业
void create()
{
    if (empty == NULL)
    {
        cout << "内存空间已满，不可再添加" << endl;
        return;
    }

    //按照需要的策略对empty进行排序
    int choice;
    cout << "请选择分配策略：(1.首次适应策略 2.最佳适应策略 3.最坏适应策略)" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        firstSuit();
        break;
        ;
    case 2:
        bestSuit();
        break;
    case 3:
        worstSuit();
        break;
    default:
        cout<<"没有该选项"<<endl;
        return;
    }

    //输入作业
    int length;
    string name;
    cout << "请输入要添加的作业的名称、长度" << endl;
    cin >> name;
    cin >> length;
    if (length > sum - alreadyUse)
    {
        cout<<"name = "<<name<<" length = "<<length<<endl;
        cout << "当前剩余内存空间不足，拒绝添加新作业" << endl;
        return;
    }

    //寻找合适的位置
    Space *temp = empty;
    while (temp != NULL)
    {
        //该内存块空间够
        // new一个新结点，插入work
        //但是node.length要根据阈值来确定
        if (temp->length >= length)
        {
            Space *node = new Space;
            node->name = name;
            node->begin = temp->begin;
            node->next = NULL;
            //差值小于阈值,整个分配给该作业
            if (temp->length - length < threshold)
            {
                //已用空间增加
                alreadyUse += temp->length;
                //长度为整个内存块长度
                node->length = temp->length;

                //将node加入work
                add_sp(work, node);
                //从empty中删除temp
                delete_sp(empty, temp);
            }
            //差值大于阈值,node.length=length
            else
            {
                alreadyUse += length;
                node->length = length;
                temp->begin = temp->begin + length;
                temp->length = temp->length - length;
                add_sp(work, node);
            }
            cout << node->name << "添加成功, begin = " << node->begin <<
             ", length = " << node->length << endl;
            return;
        }
        else
            temp = temp->next;
    }
    cout << "添加失败，没有足够的空间块" << endl;
    return;
}

//上邻
void upNeighbor(Space *&sp)
{
    Space *temp = empty;
    while (temp != NULL)
    {
        // temp与sp上邻
        if (temp->begin + temp->length == sp->begin)
        {
            sp->begin = temp->begin;
            sp->length = sp->length + temp->length;
            delete_sp(empty, temp);
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
}

//下邻
void downNeighbor(Space *&sp)
{
    Space *temp = empty;
    while (temp != NULL)
    {
        // temp与sp下邻
        if (sp->begin + sp->length == temp->begin)
        {
            sp->length = sp->length + temp->length;
            delete_sp(empty, temp);
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
}

//回收已有程序
void callBack()
{
    string name;
    Space *temp = work;
    Space *node = new Space; //用来存放回收的空间

    showWork();
    cout << "请输入将要回收的作业名:" << endl;
    cin >> name;

    while (temp != NULL)
    {
        //找到目标程序
        if (temp->name == name)
        {
            alreadyUse -= temp->length;
            node->begin = temp->begin;
            node->length = temp->length;
            //从work中删除temp
            delete_sp(work, temp);
            //回收要考虑：上邻、下邻、上下邻、不相邻
            upNeighbor(node);
            downNeighbor(node);
            add_sp(empty, node);
            cout << "成功回收" << name << endl;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "未查询到要回收的作业" << endl;
}