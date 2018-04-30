#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include<string>
#include"user.h"
using std::wstring;
const int kTableLenth = 1048576;

struct Individual
{
    User *user;
    Individual *next;
};

class HashTable
{
private:
    Individual Table[kTableLenth];
public:
    HashTable();
    void GetUser(wstring username,User *user);
    bool AddIndividual(User user);
    bool UserLogin(wstring username,wstring code);
    //void PrintUser(int address)
    //{
    //    cout<<Table[address].user.GetName()<<endl;
    //}
};

#endif // HASHLIST_H_INCLUDED
