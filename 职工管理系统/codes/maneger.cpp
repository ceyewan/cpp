#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = dId;
}
void Manager::show_info()
{
	cout << "职工编号：" << this->m_id
		<< " \t职工姓名：" << this->m_name
		<< " \t岗位：" << this->get_dept_name()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}
string Manager::get_dept_name()
{
	return string("经理");
}