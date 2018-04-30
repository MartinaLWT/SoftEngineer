#include"hashtable.h"
//#include<iostream>
HashTable::HashTable()
{
  //User blank(L"Empty", L"Empty");
  int circle;
  for(circle=0;circle<kTableLenth;circle++)
  {
    //Table[circle].user.ChangeName(L"Empty");
    //Table[circle].user.ChangeCode(L"Empty");
    Table[circle].user = nullptr;
    Table[circle].next = nullptr;
    //std::cout<<circle<<std::endl;
  }
}


void HashTable::GetUser(wstring username,User *user)
{
    unsigned address = ElfHash(username);
  Individual *finding;
  finding = &Table[address];
  while(user == nullptr || (username!=Table[address].user->GetName()))
  {
    if(finding->next!=nullptr)
      finding = finding->next;
    else
      return;
  }
  if(user != nullptr)
  {
    user->ChangeName(finding->user->GetName());
    user->ChangeCode(finding->user->GetCode());
  }
}


bool HashTable::AddIndividual(User user)
{
  unsigned address = ElfHash(user.GetName());
  Individual *find_next;//,new_apply;
  //address = ElfHash(user.GetName());
  if(Table[address].user == nullptr)//.GetName()==L"Empty")
  {
    //Table[address].user.ChangeName(user.GetName());
    //Table[address].user.ChangeCode(user.GetCode());
    Table[address].user = new User(user);
    Table[address].next = nullptr;
    return true;
  }
  else
  {
    find_next = &Table[address];
    while(find_next!=nullptr)
    {
        if(find_next->user->GetName() == user.GetName())
            return false;
        find_next = find_next->next;
    }
    find_next->next = new Individual();
    find_next = find_next->next;    //new_apply.user.ChangeName(user.GetName());
    //new_apply.user.ChangeCode(user.GetCode());
    find_next->user = new User(user);
    find_next->next = nullptr;
    return true;
  }
  //return false;
}


bool HashTable::UserLogin(wstring username,wstring code)
{
    unsigned address = ElfHash(username);
    Individual *finding;
    finding = &Table[address];
    if(finding->user == nullptr)
        return false;
    while(username!=finding->user->GetName())
    {
        if(finding->next!=nullptr)
            finding = finding->next;
        else
            return false;
  }
  if(username==finding->user->GetName() && code==finding->user->GetCode())
    return true;
  else
    return false;
}
