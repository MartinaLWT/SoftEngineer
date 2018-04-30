#include <iostream>
#include"user.h"
#include"hashtable.h"
using namespace std;

User got=User(L"Empty",L"Empty"),login;
wstring name,code;
HashTable Table;
int main()
{
    locale::global(locale(""));
    wcin.imbue(locale(""));
    wcout.imbue(locale(""));
    wcout<<"Please enter your name"<<endl;
    wcin>>name;
    wcout<<"Please enter your code"<<endl;
    wcin>>code;
    login = User(name, code);
    Table.AddIndividual(login);
    wcout<<L"用户名："<<name<<L"；密码："<<code<<endl;
    wcout<<login.GetName()<<" "<<login.GetCode()<<" "<<login.id()<<endl;
    login = User(name, code);
    wcout<<login.id()<<endl;
    login = User(name, code);
    wcout<<login.id()<<endl;
    login = User(name, code);
    wcout<<login.id()<<endl;
    wcout<<ElfHash(login.GetName())<<endl;
    Table.GetUser(ElfHash(login.GetName()),login.GetName(),&got);
//    Table.GetUser(login.ElfHash(),login.GetName(),got);
    wcout<<L"Here we've got "<<got.GetName()<<" and "<<got.GetCode()<<endl;
    return 0;
}
