#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include<string>
#include"user.h"
using std::wstring;
const int kTableLenth = 1048576;

struct Individual//设置HashTable的单独结点
{
    User *user;
    Individual *next;
};

class HashTable
{
private:
    Individual Table[kTableLenth];//顺序表
public:
    HashTable();
    void GetUser(wstring username,User *user);
    bool AddIndividual(User user);//添加新用户
    bool UserLogin(wstring username,wstring code);//用于登陆验证
};

#endif // HASHLIST_H_INCLUDED
