#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = dId;
}
void Manager::show_info()
{
	cout << "ְ����ţ�" << this->m_id
		<< " \tְ��������" << this->m_name
		<< " \t��λ��" << this->get_dept_name()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}
string Manager::get_dept_name()
{
	return string("����");
}