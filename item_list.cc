#include"list.h"
#include"item_list.h"

void ItemList::add_item(Item var)
{
  items_.add_front(var);
}

List<Item> ItemList::items()
{
  return items_;
}

Item* ItemList::find_item(long id)
{
  ListNode<Item>*pointer=items_.front();
  while(pointer!=nullptr)
  {
    if(pointer->get_content().id()==id)
      return pointer->get_pointer();
    pointer=pointer->get_next();
  }
  return new Item(0, L"", L"", 0,L"system");
}

List<Item> ItemList::find_item(wstring str)
{
  List<Item>ret;
  ListNode<Item>*pointer=items_.front();
  while(pointer!=nullptr)
  {
    //std::wcout<<"hello"<<std::endl;
    if(pointer->get_content().contain(str))
      ret.add_front(pointer->get_content());
    pointer = pointer->get_next();
  }
  return ret;
}
/*
void ItemList::print_item()
{
  ListNode<Item>*pointer=items_.front();
  while(pointer!=nullptr)
  {
    cout << endl;
    cout << "Id: " << pointer->get_content().id() << endl;
    cout << "Title: " << pointer->get_content().title() << endl;
    cout << "Price: " << pointer->get_content().price() << endl;
    pointer = pointer->get_next();
  }
}
*/
