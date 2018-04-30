#ifndef ITEM_H_
#define ITEM_H_
#include<string>
using std::wstring;
class Item
{
  private:
    static int id_count;
    const static int kStringLength=11000;
    double price_;
    wstring title_;
    wstring detail_;
    long id_;
    bool on_shelf_;
    bool title_contain(wstring str);
    bool detail_contain(wstring str);
    wstring seller_;
  public:
    //const static Item blank;//(0,"","",-1,0);
    Item();
    Item(double price,wstring title,wstring detail,bool on_shelf,wstring seller);
    double price();
    wstring title();
    wstring detail();
    bool contain(wstring str);
    long id();
    bool on_shelf();
    void put_on_shelf();
    void put_off_shelf();
    wstring seller();
};
#endif
