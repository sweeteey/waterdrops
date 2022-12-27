#include "head.cpp"

void Delete_NULL(string fileName); // 删除空行
void Show_UFD();                   // 打印UFD
void Show_AFD();                   // 打印AFD
void Init_AFD();                   // 初始化AFD
bool Init_MFD();                   // 初始化主文件目录
bool Init_UFD(string name);        // 初始化用户name的文件，得到pUFD
bool User_Check();                 // 登录，验证用户身份
bool Create_UFD();                 // 用户创建一个文件
bool Delete_UFD();                 // 用户删除一个文件
bool Open();                       // 用户打开一个文件
bool Close();                      // 用户关闭一个文件
bool Read();                       // 用户读取一个文件
bool Write();                      // 用户写入一个文件

void Show_UFD()
{
    UFD *p = pUFD->next;
    if (!p)
    {
        cout << "用户" << User_Name << "未创建文件" << endl;
        return;
    }
    cout << "文件名\t\t最大长度\t起始地址\t文件长度\t是否可读\t是否可写\t是否可执行" << endl;
    while (p)
    {
        cout << p->fileName << "\t" << p->maxLength << "\t\t" << p->begin << "\t\t" << p->length << "\t\t";
        // 可读
        if (p->read == 1)
            cout << "true"
                 << "\t\t";
        else
            cout << "false"
                 << "\t\t";
        // 可写
        if (p->write == 1)
            cout << "true"
                 << "\t\t";
        else
            cout << "false"
                 << "\t\t";
        // 可执行
        if (p->execute == 1)
            cout << "true"
                 << "\n";
        else
            cout << "false"
                 << "\n";
        p = p->next;
    }
}

void Show_AFD()
{
    AFD *p = pAFD->next;
    if (!p)
    {
        cout << "用户" << User_Name << "未打开文件" << endl;
        return;
    }

    cout << "文件名\t\t最大长度\t起始地址\t文件长度\t是否可读\t是否可写\t是否可执行\t写指针位置" << endl;
    while (p)
    {
        cout << p->fileName << "\t" << p->maxLength << "\t\t" << p->begin << "\t\t" << p->length << "\t\t";
        // 可读
        if (p->read == 1)
            cout << "true"
                 << "\t\t";
        else
            cout << "false"
                 << "\t\t";
        // 可写
        if (p->write == 1)
            cout << "true"
                 << "\t\t";
        else
            cout << "false"
                 << "\t\t";
        // 可执行
        if (p->execute == 1)
            cout << "true"
                 << "\t\t";
        else
            cout << "false"
                 << "\t\t";
        // 写指针位置
        cout << p->pointer << endl;
        p = p->next;
    }
}

bool Init_MFD()
{
    pMFD = new MFD;
    MFD *p = pMFD;

    ifstream file("MFD.txt"); // 文件的输入流对象

    // 未创建，打开错误
    if (!file)
    {
        cerr << "错误:无法打开MFD" << endl;
        p->mfdNext = NULL;
        p->ufdNext = NULL;
        return false;
    }

    // 打开文件
    // cout << "userName" << endl;
    while (!file.eof()) // 未到达文件尾
    {
        Current_Users++; // 当前用户个数加一
        p->mfdNext = new MFD;
        p = p->mfdNext;
        // 读入用户名和密码
        file >> p->userName >> p->password;
        p->mfdNext = NULL;
        p->ufdNext = NULL;
        // cout << p->userName << endl;
        // cout << "\t\t" << p->password << endl;
    }
    cout << endl;
    // 关闭文件
    file.close();
    return true;
}

bool Init_UFD(string name)
{
    // 初始化AFD
    pAFD = new AFD;
    pAFD->next = NULL;
    pUFD = new UFD;
    UFD *p = pUFD;
    ifstream file(name);

    // 未创建，打开错误
    if (!file)
    {
        cerr << "错误:无法打开文件" << endl;
        p->next = NULL;
        return false;
    }

    int M_index = 0; // 标识是否找到了该用户在MFD上的位置

    // 在MFD中找到该用户
    MFD *mp = pMFD->mfdNext;
    while (mp != NULL && M_index == 0)
    {
        // 在MFD中找到该用户
        if (mp->userName == name)
        {
            mp->ufdNext = p;
            M_index = 1;
            break;
        }
        else
        {
            mp = mp->mfdNext;
        }
    }

    while (!file.eof())
    {
        Current_Files++; // 当前用户的文件数+1
        p->next = new UFD;
        p = p->next;

        // 文件中信息存入链表
        file >> p->fileName >> p->maxLength >> p->begin >> p->length >> p->read >> p->write >> p->execute;
        MAX_End += p->maxLength;
        // cout << p->fileName << " " << p->maxLength << " " << p->begin << " " << p->length << " " << p->read << " " << p->write << " " << p->execute << endl;
    }
    cout << "MAX_End = " << MAX_End << endl
         << endl;
    Show_UFD();
    p->next = NULL;
    file.close();
    return true;
}

bool User_Check()
{
    string userName;
    string password;
    MFD *mp = pMFD->mfdNext;

    cout << "请输入用户名:" << endl;
    cin >> userName;
    cout << "请输入密码:" << endl;
    cin >> password;

    while (mp)
    {
        if (mp->userName == userName && mp->password == password)
        {
            char *temp = (char *)userName.data();
            strcat(temp, ".txt");
            Init_UFD(temp);
            User_Name = temp; // 记住该用户名
            cout << "登录成功！" << endl;
            return true;
        }
        else
            mp = mp->mfdNext;
    }
    cout << "用户名或密码错误，登录失败！" << endl;
    return false;
}

bool Create_UFD()
{
    if (Current_Files == 10)
    {
        cout << "该用户保存的文件已经到上限，请删掉部分文件再创建！" << endl;
        return false;
    }

    UFD *p = pUFD->next;
    string fileName;
    int maxLength;
    char choice;
    int read;
    int write;
    int execute;

    // 文件名不能重复
    cout << "请输入文件名" << endl;
    cin >> fileName;
    while (p)
    {
        if (p->fileName == fileName)
        {
            cout << "该文件名已存在，创建失败!" << endl;
            return false;
        }
        if (p->next == NULL)
            break;
        p = p->next;
    }

    cout << "请输入文件最大容量" << endl;
    cin >> maxLength;

    // 是否可读
    while (1)
    {
        cout << "文件是否可读<y/n>" << endl;
        cin >> choice;
        if (choice == 'y')
        {
            read = 1;
            break;
        }
        else if (choice == 'n')
        {
            read = 0;
            break;
        }
        else
        {
            cout << "您的输入有误，请重新选择" << endl;
        }
    }
    // 是否可写
    while (1)
    {
        cout << "文件是否可写<y/n>" << endl;
        cin >> choice;
        if (choice == 'y')
        {
            write = 1;
            break;
        }
        else if (choice == 'n')
        {
            write = 0;
            break;
        }
        else
        {
            cout << "您的输入有误，请重新选择" << endl;
        }
    }
    // 是否可执行
    while (1)
    {
        cout << "文件是否可执行<y/n>" << endl;
        cin >> choice;
        if (choice == 'y')
        {
            execute = 1;
            break;
        }
        else if (choice == 'n')
        {
            execute = 0;
            break;
        }
        else
        {
            cout << "您的输入有误，请重新选择" << endl;
        }
    }

    // 修改UFD
    //  char *temp = (char *)User_Name.data();
    //  strcat(temp, ".txt");
    ofstream file(User_Name, ofstream::app); // 如果没有文件，那么打开失败；如果有文件，那么定位到文件尾
    if (!file)
    {
        cout << User_Name << "的UFD打开失败,创建文件失败" << endl;
        return false;
    }
    string line = "\n" + fileName + "\t" + to_string(maxLength) + "\t" + to_string(MAX_End) + "\t" + to_string(0) + "\t" + to_string(read) + "\t" + to_string(write) + "\t" + to_string(execute);
    file << line;
    file.close();

    // Show_UFD();
    p->next = new UFD;
    p = p->next;
    p->fileName = fileName;
    p->maxLength = maxLength;
    p->begin = MAX_End;
    p->length = 0;
    p->read = read;
    p->write = write;
    p->execute = execute;
    p->next = NULL;
    // Show_UFD();
    MAX_End += p->maxLength;
    Current_Files++; // 用户文件数加一
    cout << "创建成功" << endl;

    // 创建文件
    ofstream fo(fileName, ios::app);

    return true;
}

bool Open()
{
    if (Current_Opens == 5)
    {
        cout << "该用户打开的文件已经到上限，请关闭部分文件再打开！" << endl;
        return false;
    }

    string fileName;
    UFD *pu = pUFD->next;
    AFD *pa = pAFD->next;
    string line;

    cout << "请输入要打开的文件名" << endl;
    cin >> fileName;

    // cout<<"1"<<endl;
    int isNULL = 0;
    // cout<<"1"<<endl;
    if (pa == NULL) // AFD为空
    {
        pa = pAFD;
        isNULL = 1;
    }
    else
    {
        while (pa) // 在AFD中寻找
        {
            if (fileName == pa->fileName) // 一打开，retur true
            {
                cout << "文件" << fileName << "已经打开！" << endl;
                return true;
            }
            if (pa->next == NULL)
                break;
            pa = pa->next;
        }
    }

    while (pu) // 在UFD中找到该文件并加入AFD中
    {
        if (pu->fileName == fileName) // 找到文件
        {
            int pointer;
            if (pu->write == 0) // 不可写
                pointer = 0;
            else
                pointer = pu->length;

            // 写入AFD文件中
            ofstream file("AFD.txt", ofstream::app); // 如果没有文件，那么打开失败；如果有文件，那么定位到文件尾
            if (!file)
            {
                cout << User_Name << "的AFD打开失败, 打开文件失败" << endl;
                return false;
            }
            if (isNULL == 0)
                line = "\n" + fileName + "\t" + to_string(pu->maxLength) + "\t" + to_string(pu->begin) + "\t" + to_string(pu->length) + "\t" + to_string(pu->read) + "\t" + to_string(pu->write) + "\t" + to_string(pu->execute) + "\t" + to_string(pointer);
            else
                line = fileName + "\t" + to_string(pu->maxLength) + "\t" + to_string(pu->begin) + "\t" + to_string(pu->length) + "\t" + to_string(pu->read) + "\t" + to_string(pu->write) + "\t" + to_string(pu->execute) + "\t" + to_string(pointer);
            file << line;
            file.close();

            // 写入AFD链中
            pa->next = (AFD *)new AFD;
            pa = pa->next;
            pa->fileName = fileName;
            // cout << pa->fileName << "   pa" << endl;
            // cout << pAFD->next->fileName << "   pAFD" << endl;
            pa->maxLength = pu->maxLength;
            pa->begin = pu->begin;
            pa->length = pu->length;
            pa->read = pu->read;
            pa->write = pu->write;
            pa->execute = pu->execute;
            pa->pointer = pointer;
            pa->next = NULL;
            Show_AFD();
            // cout<<pAFD->next->fileName<<"Ffff"<<endl;
            Current_Opens++; // 当前打开文件数加一
            cout << "文件打开成功！" << endl;
            return true;
        }
        pu = pu->next;
    }
    cout << "要打开的文件不存在，请检查是否文件名输入错误！" << endl;
    return false;
}

bool Delete_UFD()
{
    string fileName;
    UFD *pu = pUFD->next;
    AFD *pa = pAFD->next;

    cout << "请输入要删除的文件名" << endl;
    cin >> fileName;

    // 文件已经打开，则不能进行删除操作
    while (pa)
    {
        if (fileName == pa->fileName)
        {
            cout << "该文件已被打开，请先关闭，再进行删除操作" << endl;
            return false;
        }
    }

    // 从UFD中找到并删除
    int index = 0; // 标记是否在UFD中找到
    int i = 0;
    string line[USER_FILE];
    line[0] = "#"; // 标记删除后UDF是否为空
    while (pu)
    {
        // cout<<"pu->fileName = "<<pu->fileName<<endl;
        // cout<<"fileName = "<<fileName<<endl;
        if (pu->fileName == fileName)
        {
            index = 1; // 找到
            // 从UFD链表中删除文件
            UFD *front = pUFD;
            while (front->next != pu)
                front = front->next;
            front->next = pu->next;
            delete pu;
            pu = front->next;
            if (pu == NULL)
                break;
        }
        else
        {
            line[i] = pu->fileName + "\t" + to_string(pu->maxLength) + "\t" + to_string(pu->begin) + "\t" + to_string(pu->length) + "\t" + to_string(pu->read) + "\t" + to_string(pu->write) + "\t" + to_string(pu->execute) + "\n";
            // cout << line[i] << endl;
            pu = pu->next;
            i++;
        }
    }

    if (index == 0) // 未找到file
    {
        cout << "没有该文件，删除失败！" << endl;
        return false;
    }
    else // 找到了file
    {
        ofstream file(User_Name, ofstream::ate); // 如果没有文件，那么打开失败；如果有文件，则清空文件内容
        if (line[0] != "#")                      // 删除后UFD不空
        {
            for (i = 0; i < Current_Files - 1; i++)
            {
                file << line[i];
            }
        }
        Current_Files--;
        file.close();
        Delete_NULL(User_Name);
        cout << "删除成功！" << endl;

        // 删除文件
        char *fn = (char *)fileName.data();
        remove(fn);
        return true;
    }
}

bool Close()
{
    string fileName;
    AFD *pa = pAFD->next;

    cout << "请输入要关闭的文件名" << endl;
    cin >> fileName;

    // 从AFD中找到并删除
    int one = 0;
    int index = 0;  // 标记是否在AFD中找到
    int isRear = 0; // 是否到末尾
    int i = 0;
    string line[OPEN_FILE];
    line[0] = "#"; // 标记删除后ADF是否为空

    if (pa->fileName == fileName) //只有一个
    {
        index = 1;
        AFD *front = pAFD;
        while (front->next != pa)
            front = front->next;
        front->next = pa->next;
        delete pa;
        pa = front->next;
        one = 1;
    }
    else{
        while (pa)
        {
            if (pa->fileName == fileName)
            {
                index = 1; // 找到

                // 从AFD链表中删除文件
                AFD *front = pAFD;
                while (front->next != pa)
                    front = front->next;
                front->next = pa->next;
                delete pa;
                pa = front->next;
                if (!pa) // 删除后空
                {
                    isRear = 1; // 末尾
                    break;
                }
            }
            else
            {
                line[i] = pa->fileName + "\t" + to_string(pa->maxLength) + "\t" + to_string(pa->begin) + "\t" + to_string(pa->length) + "\t" + to_string(pa->read) + "\t" + to_string(pa->write) + "\t" + to_string(pa->execute) + to_string(pa->pointer) + "\n";
                i++;
            }
            pa = pa->next;
        }
    }

    if (index == 0) // 未找到file
    {
        cout << "该文件未被打开，关闭失败！" << endl;
        return false;
    }
    else // 找到了file
    {
        if (one)
        {
            ofstream file("AFD.txt", ofstream::ate);
            file.close();
            cout << "关闭成功！" << endl;
            return true;
        }
        ofstream file("AFD.txt", ofstream::ate); // 如果没有文件，那么打开失败；如果有文件，则清空文件内容
        if (line[0] != "#")                      // 删除AFD不空
        {
            for (i = 0; i < Current_Files - 1; i++)
            {
                file << line[i];
            }
        }
        Current_Opens--;
        file.close();
        string sname = "AFD.txt";
        Delete_NULL(sname);
        cout << "关闭成功！" << endl;
        return true;
    }
}

// 读文件系统调用的一般格式为:
// read(文件名,(文件内位置),要读的长度,内存目的地址)
bool Read()
{
    char c[MAX]; // 存放文件信息
    string fileName;
    int rLen; // 读取的长度
    AFD *pa = pAFD->next;

    cout << "请输入要读取的文件名" << endl;
    cin >> fileName;
    cout << "请输入要读取的长度" << endl;
    cin >> rLen;

    while (pa)
    {
        if (fileName == pa->fileName) // 找到文件
        {
            if (pa->read == 0) // 不可读
            {
                cout << "该文件为不可读文件！" << endl;
                return false;
            }
            if (rLen > pa->length)
                rLen = pa->length;
            cout << "文件" << fileName << "长度为" << rLen << "的内容为:" << endl;
            fstream file(fileName);
            file.read(c, rLen);
            for (int i = 0; i < rLen; i++)
                cout << c[i];
            cout << endl;
            return true;
        }
        pa = pa->next;
    }
    cout << "该文件未打开，读取失败！" << endl;
    return false;
}

bool Write()
{
    string s;
    string fileName;
    int wLen; // 写入的长度
    AFD *pa = pAFD->next;

    cout << "请输入要写入的文件名" << endl;
    cin >> fileName;
    cout << "请输入要写入的长度" << endl;
    cin >> wLen;

    while (pa)
    {
        if (fileName == pa->fileName) // 找到文件
        {
            if (pa->write == 0) // 不可写
            {
                cout << "该文件为不可写文件！" << endl;
                return false;
            }
            if (pa->pointer + wLen > pa->maxLength) // 溢出
            {
                cout << "写入的数据大小超过文件的分配容量, 写入失败！" << endl;
                return false;
            }
            cout << "请输入写入的内容" << endl;
            cin >> s;
            ofstream file(fileName, ios::app);
            file << s;
            cout << endl;
            return true;
        }
        pa = pa->next;
    }
    cout << "该文件未打开，写入失败！" << endl;
    return false;
}

void Delete_NULL(string fileName)
{
    string s[User_NUMBER];
    string line;
    int k = 0;
    ifstream f(fileName);
    while (getline(f, line))
    {
        s[k] = line;
        k++;
    }
    // cout<<k<<endl;
    // for (int i=0; i<k; i++)
    //     cout<<s[i]<<endl;
    f.close();

    ofstream file(fileName, ofstream::ate);
    for (int i = 0; i < k - 1; i++)
    {
        string s1 = s[i] + '\n';
        file << s1;
    }
    file << s[k - 1];
    file.close();
}