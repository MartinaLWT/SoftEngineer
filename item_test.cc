#include<string>
#include<iostream>
#include<locale>
#include"item.h"
using std::wcin;
using std::wcout;
using std::endl;
using std::locale;

int main(void)
{
  //wstring s1;
  //wcin>>s1;
  //wcout<<s1<<endl;
  locale::global(locale(""));
  wcout.imbue(locale(""));
  Item an_item(66.6,L"你好",L"abaabaaabaaabbb",10010,true);
  wcout<<an_item.price()<<endl;
  wcout<<an_item.title()<<endl;
  wcout<<an_item.detail()<<endl;
  wcout<<an_item.contain(L"abaa")<<endl;
  wcout<<an_item.contain(L"baab")<<endl;
  wcout<<an_item.contain(L"baabb")<<endl;
  wcout<<an_item.contain(L"baaabb")<<endl;
  wcout<<"On shelf state: "<<an_item.on_shelf()<<endl;
  an_item.put_off_shelf();
  wcout<<"On shelf state: "<<an_item.on_shelf()<<endl;
  an_item.put_on_shelf();
  wcout<<"On shelf state: "<<an_item.on_shelf()<<endl;
  wcout<<"Id: "<<an_item.id()<<endl;
  return 0;
}
