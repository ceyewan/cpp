# include "ͨѶ¼����ϵͳ.h"

struct address_books users;

int main()
{
    users.m_size = 0;
    int select = 0;
    while (true) {
        show_mean();
        cout << "��������ţ�" << endl;
        cin >> select;
        switch (select) {
        case 1:
            add_person(&users);
            break;
        case 2:
            show_person(&users);
            break;
        case 3:
            delete_person(&users);
            break;
        case 4:
            search_person(&users);
            break;
        case 5:
            modify_person(&users);
            break;
        case 6:
            clean_person(&users);
            break;
        case 0:
            goto EXIT;
            break;
        default:
            break;
        }
    }
EXIT:
    return 0;
}