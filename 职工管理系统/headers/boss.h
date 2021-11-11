#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

// ¿œ∞Â¿‡
class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);
	virtual void show_info();
	virtual string get_dept_name();
};
