#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

// ������
class Manager :public Worker
{
public:
	Manager(int id, string name, int dId);
	virtual void show_info();
	virtual string get_dept_name();
};