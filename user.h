#ifndef USER_H_
#define USER_H_
#include<iostream>
#include<string>
#include"item.h"
#include"list.h"
#include"deal.h"
using std::wstring;
typedef unsigned hash_value;

class User
{
private:
    static int id_counter;
    wstring username;
    wstring code;
    int id_;
    List<Item>sale_items_;
    List<Deal>sell_deals_;
    List<Deal>buy_deals_;
public:
    User();
    User(wstring username);
    User(wstring username,wstring code);
    void ChangeName(wstring name);
    void ChangeCode(wstring code);
    wstring GetName();
    wstring GetCode();
    //hash_value  ElfHash();
    int id();
    List<Item>& sale_items();
    List<Deal>& sell_deals();
    List<Deal>& buy_deals();
};

hash_value ElfHash(wstring str);

#endif // CODEMATCH_H_INCLUDED
