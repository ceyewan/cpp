/*������*/
#pragma once
#include<iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
    WorkerManager();
    // չʾĿ¼
    void show_menu();
    // �˳�ϵͳ
    void exit_system();
    // ����ְ��
    void add_emp();
    // �����ļ�
    void save();
    // ͳ������
    int get_empnum();
    // ��ʼ��ְ��
    void init_emp();
    // ��ʾְ��
    void show_Emp();
    // ɾ��ְ��
    void delete_Emp();
    // �ж�ְ���Ƿ���ڣ� ����λ��
    int IsExist(int id);
    // �޸�ְ��
    void mod_Emp();
    // ����ְ��
    void find_Emp();
    // ����ְ��
    void sort_Emp();
    // ����ļ�
    void clean_File();
    ~WorkerManager();
public:
    int m_EmpNum;// ����
    Worker** m_EmpArray;// Ա�������ָ��
    bool m_FileIsEmpty;
};
