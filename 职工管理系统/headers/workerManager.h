/*操作类*/
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
    // 展示目录
    void show_menu();
    // 退出系统
    void exit_system();
    // 增加职工
    void add_emp();
    // 保存文件
    void save();
    // 统计人数
    int get_empnum();
    // 初始化职工
    void init_emp();
    // 显示职工
    void show_Emp();
    // 删除职工
    void delete_Emp();
    // 判断职工是否存在， 返回位置
    int IsExist(int id);
    // 修改职工
    void mod_Emp();
    // 查找职工
    void find_Emp();
    // 排序职工
    void sort_Emp();
    // 清空文件
    void clean_File();
    ~WorkerManager();
public:
    int m_EmpNum;// 人数
    Worker** m_EmpArray;// 员工数组的指针
    bool m_FileIsEmpty;
};
