#include<iostream>
using namespace std;
#include "workerManager.h"

/*
void test()
{
    Worker* worker = NULL;
    worker = new Employee(1, "����", 1);
    worker->show_info();
    delete worker;
    worker = new Manager(2, "����", 2);
    worker->show_info();
    delete worker;
    worker = new Boss(3, "����", 3);
    worker->show_info();
    delete worker;
}
*/
int main()
{
    // test();���Զ�̬
    // return 0;
    WorkerManager wm;
    int choice = 0;
    while (true) {
        wm.show_menu();
        cout << "���������ѡ��" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: // �˳�ϵͳ
            wm.exit_system();
            break;
        case 1: // ���ְ��
            wm.add_emp();
            break;
        case 2: // ��ʾְ��
            wm.show_Emp();
            break;
        case 3: // ɾ��ְ��
            wm.delete_Emp();
            break;
        case 4: // �޸�ְ��
            wm.mod_Emp();
            break;
        case 5: // ����ְ��
            wm.find_Emp();
            break;
        case 6: // ����ְ��
            wm.sort_Emp();
            break;
        case 7: // ����ļ�
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