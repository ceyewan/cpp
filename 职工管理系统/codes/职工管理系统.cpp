#include<iostream>
using namespace std;
#include "workerManager.h"

/*
void test()
{
    Worker* worker = NULL;
    worker = new Employee(1, "张三", 1);
    worker->show_info();
    delete worker;
    worker = new Manager(2, "李四", 2);
    worker->show_info();
    delete worker;
    worker = new Boss(3, "王五", 3);
    worker->show_info();
    delete worker;
}
*/
int main()
{
    // test();测试多态
    // return 0;
    WorkerManager wm;
    int choice = 0;
    while (true) {
        wm.show_menu();
        cout << "请输入你的选择：" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: // 退出系统
            wm.exit_system();
            break;
        case 1: // 添加职工
            wm.add_emp();
            break;
        case 2: // 显示职工
            wm.show_Emp();
            break;
        case 3: // 删除职工
            wm.delete_Emp();
            break;
        case 4: // 修改职工
            wm.mod_Emp();
            break;
        case 5: // 查找职工
            wm.find_Emp();
            break;
        case 6: // 排序职工
            wm.sort_Emp();
            break;
        case 7: // 清空文件
            wm.clean_File();
            break;
        default:
            system("cls");
            break;
        }
    }
    
    system("pause");
    return 0;
}