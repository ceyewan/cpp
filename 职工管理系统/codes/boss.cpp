#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = dId;
}
void Boss::show_info()
{
	cout << "ְ����ţ�" << this->m_id
		<< " \tְ��������" << this->m_name
		<< " \t��λ��" << this->get_dept_name()
		<< " \t��λְ�𣺹���˾��������" << endl;
}
string Boss::get_dept_name()
{
	return string("�ܲ�");
}
