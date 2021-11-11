# include "workerManager.h"
/*职工操作类的实现*/
WorkerManager::WorkerManager()
{
    /*构造函数*/
    //  文件流，打开文件
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    // 文件不存在，没有打开
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 文件存在，但是为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空！" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 说明不为空
    this->m_FileIsEmpty = false;
    // 统计得到职工数量
    int num = this->get_empnum();
    cout << "职工个数为： " << num << endl;
    this->m_EmpNum = num;
    // 根据职工数创建数组，有this->m_EmpNum个Worker指针的指针数组
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    // 初始化职工
    init_emp();
    // 测试代码
    /*for (int i = 0; i < m_EmpNum; i++) {
        cout << "职工号： " << this->m_EmpArray[i]->m_id
            << "\t职工姓名： " << this->m_EmpArray[i]->m_name
            << "\t部门编号： " << this->m_EmpArray[i]->m_deptid << endl;
    }*/
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
    }
}
// 显示菜单
void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}
// 退出系统
void WorkerManager::exit_system()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
// 新增职工
void WorkerManager::add_emp()
{
    cout << "请输入增加职工数量：" << endl;
    int add_num = 0;
    cin >> add_num;
    if (add_num > 0) {
        // 新空间的大小
        int new_size = this->m_EmpNum + add_num;
        // 开辟新空间
        Worker **new_space = new Worker*[new_size];
        // 拷贝原空间的内容
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                new_space[i] = this->m_EmpArray[i];
            }
        }
        // 输入新数据
        for (int i = 0; i < add_num; i++) {
            int id;
            string name;
            int dselect;
            cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
            cin >> id;
            cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;
            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dselect;
            Worker* worker = NULL;
            switch (dselect) {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            new_space[this->m_EmpNum + i] = worker;
        }
        // 释放原空间
        delete[] this->m_EmpArray;
        // 新空间指向
        this->m_EmpArray = new_space;
        // 新的员工个数
        this->m_EmpNum = new_size;
        // 更新职工不为空标志
        this->m_FileIsEmpty = false;
        // 提示信息
        cout << "添加成功" << add_num << "名新职员" << endl;
        // 保存到文件中
        this->save();
    }
    else {
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");// 清屏
}
// 职工信息写入文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_id << " "
            << this->m_EmpArray[i]->m_name << " "
            << this->m_EmpArray[i]->m_deptid << endl;
    }
    ofs.close();
}
// 读取文件，得到现有文件中职工的数量
int WorkerManager::get_empnum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    ifs.close();

    return num;
}
// 初始化职工，读取文件，按类分好
void WorkerManager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker* worker = NULL;
        if (dId == 1) {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2) {
            worker = new Manager(id, name, dId);
        }
        else {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index++] = worker;
    }
}
// 显示所有的职工信息
void WorkerManager::show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else {
        for (int i = 0; i < m_EmpNum; i++) {
            // 利用多态调用接口
            this->m_EmpArray[i]->show_info();
        }
    }
    system("pause");
    system("cls");
}
// 删除职工
void WorkerManager::delete_Emp()
{
    if (this->m_FileIsEmpty)
        cout << "文件不存在或记录为空" << endl;
    else {
        // 按照职工编号删除
        cout << "请输入想要删除的职工号：" << endl;
        int id = 0;
        cin >> id;
        // 存在，就删除，后面的都前移一位
        int index = this->IsExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_EmpNum - 1; i++)
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            this->m_EmpNum--;
            // 写入文件
            this->save();
            cout << "删除成功" << endl;
        }
        else {
            cout << "删除失败，未找到该职工" << endl;
        }
        system("pause");
        system("cls");
    }
}
// 查找id是否存在
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_id == id) {
            index = i;
            break;
        }
    }
    return index;
}
// 修改职工，删除后重新输入。不能直接改，因为可能是员工改成经理，类不一样
void WorkerManager::mod_Emp()
{
    if (this->m_FileIsEmpty)
        cout << "文件不存在或记录为空" << endl;
    else {
        cout << "请输入修改的职工的编号：" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if (ret != -1) {
            delete this->m_EmpArray[ret];
            int newid = 0;
            string newname = "";
            int dselect = 0;
            cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
            cin >> newid;
            cout << "请输入新姓名： " << endl;
            cin >> newname;
            cout << "请输入岗位： " << endl;
            cout << "1、普通员工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dselect;
            Worker* worker = NULL;
            switch (dselect)
            {
            case 1:
                worker = new Employee(newid, newname, dselect);
                break;
            case 2:
                worker = new Manager(newid, newname, dselect);
                break;
            case 3:
                worker = new Boss(newid, newname, dselect);
                break;
            default:
                break;
            }
            this->m_EmpArray[ret] = worker;
            cout << "修改成功" << endl;
            this->save();
        }
        else {
            cout << "修改失败， 查无此人" << endl;
        }
        system("pause");
        system("cls");
    }
}
// 查找职工
void WorkerManager::find_Emp()
{
    if (this->m_FileIsEmpty)
        cout << "文件不存在或者记录为空" << endl;
    else {
        cout << "请输入查找的方式： " << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;
        int select = 0;
        cin >> select;
        if (select == 1) {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;
            int ret = IsExist(id);
            if (ret != -1) {
                cout << "查找成功！信息如下：" << endl;
                // 利用多态调用接口
                this->m_EmpArray[ret]->show_info();
            }
            else
                cout << "查无此人" << endl;
        }
        else if (select == 2) {
            string name;
            cout << "请输入查找的职工姓名：" << endl;
            cin >> name;
            int ret = -1;
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i]->m_name == name) {
                    ret = i;
                    cout << "查找成功！信息如下：" << endl;
                    // 利用多态调用接口
                    this->m_EmpArray[ret]->show_info();
                }
            }
            if (ret == -1)
                cout << "查无此人" << endl;
        }
        else
            cout << "输入选项有误" << endl;
    }
    system("pause");
    system("cls");
}
// 排序职工
void WorkerManager::sort_Emp()
{
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;

        int select = 0;
        cin >> select;

        // 冒泡？我也不知道，总而言之是个简单排序法
        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)
            {
                if (select == 1) //升序
                {
                    if (m_EmpArray[minOrMax]->m_id > m_EmpArray[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }
                else  //降序
                {
                    if (m_EmpArray[minOrMax]->m_id < m_EmpArray[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }
            }
            // 交换
            if (i != minOrMax)
            {
                Worker* temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }

        }

        cout << "排序成功,排序后结果为：" << endl;
        // 写入文件
        this->save();
        // 显示排序后的结果
        this->show_Emp();
    }
}
// 清空文件，包括释放内存
void WorkerManager::clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }

    system("pause");
    system("cls");
}