#pragma once
#include<iostream>
#include<string>
using namespace std;

// 职工抽象类
class Worker
{
public:
	// 显示个人信息
	virtual void show_info() = 0;
	// 获取岗位名称
	virtual string get_dept_name() = 0;

	int m_id;// 编号
	string m_name;// 姓名
	int m_deptid;// 部门编号
};