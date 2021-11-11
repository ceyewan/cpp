# include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = dId;
}
void Employee::show_info()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->get_dept_name() 
		<< "\t岗位职责：完成经理交给的任务" << endl;
}
string Employee::get_dept_name()
{
	return string("员工");
}