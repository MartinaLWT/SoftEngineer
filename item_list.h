#ifndef ITEM_LIST_H_
#define ITEM_LIST_H_
#include"list.h"
#include"item.h"
class ItemList
{
  private:
    List<Item>items_;
  public:
    List<Item> items();
    void add_item(Item var);
    Item* find_item(long id);
    List<Item> find_item(wstring str);
    //void print_item();
};
#endif
