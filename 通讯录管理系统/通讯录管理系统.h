# include<iostream>
# include<string>
# define MAX 1000
using namespace std;

struct person {
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_address;
};

struct address_books {
    struct person person_array[MAX];
    int m_size;
};

void show_mean();
void add_person(address_books* users);
void show_person(address_books* users);
int is_exist(address_books* users, string name);
void delete_person(address_books* users);
void search_person(address_books* users);
void modify_person(address_books* users);
void clean_person(address_books* users);