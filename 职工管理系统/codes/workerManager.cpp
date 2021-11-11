# include "workerManager.h"
/*ְ���������ʵ��*/
WorkerManager::WorkerManager()
{
    /*���캯��*/
    //  �ļ��������ļ�
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    // �ļ������ڣ�û�д�
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // �ļ����ڣ�����Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ�գ�" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // ˵����Ϊ��
    this->m_FileIsEmpty = false;
    // ͳ�Ƶõ�ְ������
    int num = this->get_empnum();
    cout << "ְ������Ϊ�� " << num << endl;
    this->m_EmpNum = num;
    // ����ְ�����������飬��this->m_EmpNum��Workerָ���ָ������
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    // ��ʼ��ְ��
    init_emp();
    // ���Դ���
    /*for (int i = 0; i < m_EmpNum; i++) {
        cout << "ְ���ţ� " << this->m_EmpArray[i]->m_id
            << "\tְ�������� " << this->m_EmpArray[i]->m_name
            << "\t���ű�ţ� " << this->m_EmpArray[i]->m_deptid << endl;
    }*/
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
    }
}
// ��ʾ�˵�
void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}
// �˳�ϵͳ
void WorkerManager::exit_system()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}
// ����ְ��
void WorkerManager::add_emp()
{
    cout << "����������ְ��������" << endl;
    int add_num = 0;
    cin >> add_num;
    if (add_num > 0) {
        // �¿ռ�Ĵ�С
        int new_size = this->m_EmpNum + add_num;
        // �����¿ռ�
        Worker **new_space = new Worker*[new_size];
        // ����ԭ�ռ������
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                new_space[i] = this->m_EmpArray[i];
            }
        }
        // ����������
        for (int i = 0; i < add_num; i++) {
            int id;
            string name;
            int dselect;
            cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
            cin >> id;
            cout << "������� " << i + 1 << " ����ְ��������" << endl;
            cin >> name;
            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> dselect;
            Worker* worker = NULL;
            switch (dselect) {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            new_space[this->m_EmpNum + i] = worker;
        }
        // �ͷ�ԭ�ռ�
        delete[] this->m_EmpArray;
        // �¿ռ�ָ��
        this->m_EmpArray = new_space;
        // �µ�Ա������
        this->m_EmpNum = new_size;
        // ����ְ����Ϊ�ձ�־
        this->m_FileIsEmpty = false;
        // ��ʾ��Ϣ
        cout << "��ӳɹ�" << add_num << "����ְԱ" << endl;
        // ���浽�ļ���
        this->save();
    }
    else {
        cout << "��������" << endl;
    }
    system("pause");
    system("cls");// ����
}
// ְ����Ϣд���ļ�
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_id << " "
            << this->m_EmpArray[i]->m_name << " "
            << this->m_EmpArray[i]->m_deptid << endl;
    }
    ofs.close();
}
// ��ȡ�ļ����õ������ļ���ְ��������
int WorkerManager::get_empnum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    ifs.close();

    return num;
}
// ��ʼ��ְ������ȡ�ļ�������ֺ�
void WorkerManager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker* worker = NULL;
        if (dId == 1) {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2) {
            worker = new Manager(id, name, dId);
        }
        else {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index++] = worker;
    }
}
// ��ʾ���е�ְ����Ϣ
void WorkerManager::show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else {
        for (int i = 0; i < m_EmpNum; i++) {
            // ���ö�̬���ýӿ�
            this->m_EmpArray[i]->show_info();
        }
    }
    system("pause");
    system("cls");
}
// ɾ��ְ��
void WorkerManager::delete_Emp()
{
    if (this->m_FileIsEmpty)
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    else {
        // ����ְ�����ɾ��
        cout << "��������Ҫɾ����ְ���ţ�" << endl;
        int id = 0;
        cin >> id;
        // ���ڣ���ɾ��������Ķ�ǰ��һλ
        int index = this->IsExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_EmpNum - 1; i++)
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            this->m_EmpNum--;
            // д���ļ�
            this->save();
            cout << "ɾ���ɹ�" << endl;
        }
        else {
            cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
        }
        system("pause");
        system("cls");
    }
}
// ����id�Ƿ����
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_id == id) {
            index = i;
            break;
        }
    }
    return index;
}
// �޸�ְ����ɾ�����������롣����ֱ�Ӹģ���Ϊ������Ա���ĳɾ����಻һ��
void WorkerManager::mod_Emp()
{
    if (this->m_FileIsEmpty)
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    else {
        cout << "�������޸ĵ�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if (ret != -1) {
            delete this->m_EmpArray[ret];
            int newid = 0;
            string newname = "";
            int dselect = 0;
            cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
            cin >> newid;
            cout << "�������������� " << endl;
            cin >> newname;
            cout << "�������λ�� " << endl;
            cout << "1����ͨԱ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> dselect;
            Worker* worker = NULL;
            switch (dselect)
            {
            case 1:
                worker = new Employee(newid, newname, dselect);
                break;
            case 2:
                worker = new Manager(newid, newname, dselect);
                break;
            case 3:
                worker = new Boss(newid, newname, dselect);
                break;
            default:
                break;
            }
            this->m_EmpArray[ret] = worker;
            cout << "�޸ĳɹ�" << endl;
            this->save();
        }
        else {
            cout << "�޸�ʧ�ܣ� ���޴���" << endl;
        }
        system("pause");
        system("cls");
    }
}
// ����ְ��
void WorkerManager::find_Emp()
{
    if (this->m_FileIsEmpty)
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    else {
        cout << "��������ҵķ�ʽ�� " << endl;
        cout << "1����ְ����Ų���" << endl;
        cout << "2������������" << endl;
        int select = 0;
        cin >> select;
        if (select == 1) {
            int id;
            cout << "��������ҵ�ְ����ţ�" << endl;
            cin >> id;
            int ret = IsExist(id);
            if (ret != -1) {
                cout << "���ҳɹ�����Ϣ���£�" << endl;
                // ���ö�̬���ýӿ�
                this->m_EmpArray[ret]->show_info();
            }
            else
                cout << "���޴���" << endl;
        }
        else if (select == 2) {
            string name;
            cout << "��������ҵ�ְ��������" << endl;
            cin >> name;
            int ret = -1;
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i]->m_name == name) {
                    ret = i;
                    cout << "���ҳɹ�����Ϣ���£�" << endl;
                    // ���ö�̬���ýӿ�
                    this->m_EmpArray[ret]->show_info();
                }
            }
            if (ret == -1)
                cout << "���޴���" << endl;
        }
        else
            cout << "����ѡ������" << endl;
    }
    system("pause");
    system("cls");
}
// ����ְ��
void WorkerManager::sort_Emp()
{
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ������ʽ�� " << endl;
        cout << "1����ְ���Ž�������" << endl;
        cout << "2����ְ���Ž��н���" << endl;

        int select = 0;
        cin >> select;

        // ð�ݣ���Ҳ��֪�����ܶ���֮�Ǹ�������
        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)
            {
                if (select == 1) //����
                {
                    if (m_EmpArray[minOrMax]->m_id > m_EmpArray[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }
                else  //����
                {
                    if (m_EmpArray[minOrMax]->m_id < m_EmpArray[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }
            }
            // ����
            if (i != minOrMax)
            {
                Worker* temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }

        }

        cout << "����ɹ�,�������Ϊ��" << endl;
        // д���ļ�
        this->save();
        // ��ʾ�����Ľ��
        this->show_Emp();
    }
}
// ����ļ��������ͷ��ڴ�
void WorkerManager::clean_File()
{
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //��ģʽ ios::trunc �������ɾ���ļ������´���
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "��ճɹ���" << endl;
    }

    system("pause");
    system("cls");
}