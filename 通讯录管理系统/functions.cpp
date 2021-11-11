# include "ͨѶ¼����ϵͳ.h"

void show_mean()
{
    cout << "***************************" << endl;
    cout << "*****  1�������ϵ��  *****" << endl;
    cout << "*****  2����ʾ��ϵ��  *****" << endl;
    cout << "*****  3��ɾ����ϵ��  *****" << endl;
    cout << "*****  4��������ϵ��  *****" << endl;
    cout << "*****  5���޸���ϵ��  *****" << endl;
    cout << "*****  6�������ϵ��  *****" << endl;
    cout << "*****  0���˳�ͨѶ¼  *****" << endl;
    cout << "***************************" << endl;
}

void add_person(address_books* users)
{
    if (users->m_size == MAX) {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    }
    string name;
    cout << "������������" << endl;
    cin >> name;
    users->person_array[users->m_size].m_name = name;
    int sex = 0;
FLAG:
    cout << "�������Ա�" << endl;
    cout << "1����\n2��Ů" << endl;
    cin >> sex;
    if (sex == 1 || sex == 2)
        users->person_array[users->m_size].m_sex = sex;
    else
        goto FLAG;
    cout << "���������䣺" << endl;
    int age = 0;
    cin >> age;
    users->person_array[users->m_size].m_age = age;
    cout << "��������ϵ�绰��" << endl;
    string phone = "";
    cin >> phone;
    users->person_array[users->m_size].m_phone = phone;
    cout << "�������ͥסַ��" << endl;
    string address;
    cin >> address;
    users->person_array[users->m_size].m_address = address;
    users->m_size++;
    cout << "��ӳɹ�" << endl;
    system("pause");
    system("cls");
}

void show_person(address_books* users)
{
    if (users->m_size == 0) {
        cout << "��ǰ��¼Ϊ��" << endl;
        return;
    }
    for (int i = 0; i < users->m_size; i++) {
        cout << "������" << users->person_array[i].m_name << endl;
        cout << "�Ա�" << (users->person_array[i].m_sex == 1 ? "��" : "Ů") << "\t";
        cout << "���䣺" << users->person_array[i].m_age << "\t";
        cout << "�绰��" << users->person_array[i].m_phone << "\t";
        cout << "סַ��" << users->person_array[i].m_address << endl;
    }
    system("pause");
    system("cls");
}

int is_exist(address_books* users, string name)
{
    for (int i = 0; i < users->m_size; i++)
        if (users->person_array[i].m_name == name)
            return i;
    return -1;
}

void delete_person(address_books* users)
{
    string name;
    cout << "����������Ҫɾ�����˵�������" << endl;
    cin >> name;
    int judge = is_exist(users, name);
    if (judge == -1)
        cout << "�Ҳ��������" << endl;
    else {
        for (int i = judge; i < users->m_size; i++) {
            users->person_array[i] = users->person_array[i + 1];
        }
        users->m_size--;
        cout << "ɾ���ɹ�" << endl;
    }
    system("pause");
    system("cls");
}

void search_person(address_books* users)
{
    cout << "��������Ҫ���ҵ��˵�����" << endl;
    string name;
    cin >> name;
    int judge = is_exist(users, name);
    if (judge == -1)
        cout << "���޴���" << endl;
    else {
        cout << "������" << users->person_array[judge].m_name << "\t";
        cout << "�Ա�" << users->person_array[judge].m_sex << "\t";
        cout << "���䣺" << users->person_array[judge].m_age << "\t";
        cout << "�绰��" << users->person_array[judge].m_phone << "\t";
        cout << "סַ��" << users->person_array[judge].m_address << endl;
    }
    system("pause");
    system("cls");
}

void modify_person(address_books* users)
{
    cout << "��������Ҫ�޸ĵ��˵�����" << endl;
    string name;
    cin >> name;
    int judge = is_exist(users, name);
    if (judge == -1) {
        cout << "���޴���" << endl;
        return;
    }
    cout << "�������޸ĺ��������" << endl;
    cin >> name;
    users->person_array[judge].m_name = name;
    int sex = 0;
FLAG:
    cout << "�������Ա�" << endl;
    cout << "1����\n2��Ů" << endl;
    cin >> sex;
    if (sex == 1 || sex == 2)
        users->person_array[users->m_size].m_sex = sex;
    else
        goto FLAG;
    cout << "���������䣺" << endl;
    int age = 0;
    cin >> age;
    users->person_array[users->m_size].m_age = age;
    cout << "��������ϵ�绰��" << endl;
    string phone = "";
    cin >> phone;
    users->person_array[users->m_size].m_phone = phone;
    cout << "�������ͥסַ��" << endl;
    string address;
    cin >> address;
    users->person_array[users->m_size].m_address = address;
    cout << "�޸ĳɹ�" << endl;
    system("pause");
    system("cls");
}

void clean_person(address_books* users)
{
    users->m_size = 0;
    cout << "��ճɹ�" << endl;
    system("pause");
    system("cls");
}