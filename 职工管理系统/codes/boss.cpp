#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = dId;
}
void Boss::show_info()
{
	cout << "职工编号：" << this->m_id
		<< " \t职工姓名：" << this->m_name
		<< " \t岗位：" << this->get_dept_name()
		<< " \t岗位职责：管理公司所有事务" << endl;
}
string Boss::get_dept_name()
{
	return string("总裁");
}
