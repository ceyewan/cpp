#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

// ‘±π§¿‡
class Employee :public Worker
{
public:
	Employee(int id, string name, int dId);
	virtual void show_info();
	virtual string get_dept_name();
};