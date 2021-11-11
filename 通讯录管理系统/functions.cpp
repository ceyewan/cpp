# include "通讯录管理系统.h"

void show_mean()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}

void add_person(address_books* users)
{
    if (users->m_size == MAX) {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    users->person_array[users->m_size].m_name = name;
    int sex = 0;
FLAG:
    cout << "请输入性别：" << endl;
    cout << "1、男\n2、女" << endl;
    cin >> sex;
    if (sex == 1 || sex == 2)
        users->person_array[users->m_size].m_sex = sex;
    else
        goto FLAG;
    cout << "请输入年龄：" << endl;
    int age = 0;
    cin >> age;
    users->person_array[users->m_size].m_age = age;
    cout << "请输入联系电话：" << endl;
    string phone = "";
    cin >> phone;
    users->person_array[users->m_size].m_phone = phone;
    cout << "请输入家庭住址：" << endl;
    string address;
    cin >> address;
    users->person_array[users->m_size].m_address = address;
    users->m_size++;
    cout << "添加成功" << endl;
    system("pause");
    system("cls");
}

void show_person(address_books* users)
{
    if (users->m_size == 0) {
        cout << "当前记录为空" << endl;
        return;
    }
    for (int i = 0; i < users->m_size; i++) {
        cout << "姓名：" << users->person_array[i].m_name << endl;
        cout << "性别：" << (users->person_array[i].m_sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << users->person_array[i].m_age << "\t";
        cout << "电话：" << users->person_array[i].m_phone << "\t";
        cout << "住址：" << users->person_array[i].m_address << endl;
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
    cout << "请输入你需要删除的人的姓名：" << endl;
    cin >> name;
    int judge = is_exist(users, name);
    if (judge == -1)
        cout << "找不到这个人" << endl;
    else {
        for (int i = judge; i < users->m_size; i++) {
            users->person_array[i] = users->person_array[i + 1];
        }
        users->m_size--;
        cout << "删除成功" << endl;
    }
    system("pause");
    system("cls");
}

void search_person(address_books* users)
{
    cout << "请输入需要查找的人的姓名" << endl;
    string name;
    cin >> name;
    int judge = is_exist(users, name);
    if (judge == -1)
        cout << "查无此人" << endl;
    else {
        cout << "姓名：" << users->person_array[judge].m_name << "\t";
        cout << "性别：" << users->person_array[judge].m_sex << "\t";
        cout << "年龄：" << users->person_array[judge].m_age << "\t";
        cout << "电话：" << users->person_array[judge].m_phone << "\t";
        cout << "住址：" << users->person_array[judge].m_address << endl;
    }
    system("pause");
    system("cls");
}

void modify_person(address_books* users)
{
    cout << "请输入需要修改的人的姓名" << endl;
    string name;
    cin >> name;
    int judge = is_exist(users, name);
    if (judge == -1) {
        cout << "查无此人" << endl;
        return;
    }
    cout << "请输入修改后的姓名：" << endl;
    cin >> name;
    users->person_array[judge].m_name = name;
    int sex = 0;
FLAG:
    cout << "请输入性别：" << endl;
    cout << "1、男\n2、女" << endl;
    cin >> sex;
    if (sex == 1 || sex == 2)
        users->person_array[users->m_size].m_sex = sex;
    else
        goto FLAG;
    cout << "请输入年龄：" << endl;
    int age = 0;
    cin >> age;
    users->person_array[users->m_size].m_age = age;
    cout << "请输入联系电话：" << endl;
    string phone = "";
    cin >> phone;
    users->person_array[users->m_size].m_phone = phone;
    cout << "请输入家庭住址：" << endl;
    string address;
    cin >> address;
    users->person_array[users->m_size].m_address = address;
    cout << "修改成功" << endl;
    system("pause");
    system("cls");
}

void clean_person(address_books* users)
{
    users->m_size = 0;
    cout << "清空成功" << endl;
    system("pause");
    system("cls");
}