#pragma once
#include<iostream>
#include<string>
using namespace std;

// ְ��������
class Worker
{
public:
	// ��ʾ������Ϣ
	virtual void show_info() = 0;
	// ��ȡ��λ����
	virtual string get_dept_name() = 0;

	int m_id;// ���
	string m_name;// ����
	int m_deptid;// ���ű��
};