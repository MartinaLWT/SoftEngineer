#include"item_list.h"
#include"item.h"

int main(void)
{
  ItemList list1;
  list1.add_item(Item(6.1, "Item1", "The deails of Item1", 1, 1));
  list1.add_item(Item(6.2, "Item2", "The deails ofs Item2", 2, 0));
  list1.add_item(Item(6.3, "Item3", "The deails ofs Item3", 3, 0));
  list1.add_item(Item(6.4, "Item4", "The deails of Item4", 4, 1));
  list1.add_item(Item(6.4, "Item4", "The deails ofs Item4", 5, 1));
  list1.print_item();

  Item found = list1.find_item(3);
  cout << endl << "Result of Item find_item(long str)" << endl;
  cout << "Id: " << found.id() << endl;
  cout << "Title: " << found.title() << endl;
  cout << "Detail: " << found.detail() <<endl;
  cout << "Price: " << found.price() << endl;
  cout << "State: " << found.on_shelf() << endl;
  cout << endl;

  List<Item>found2 = list1.find_item("ofs");
  ListNode<Item>*pointer = found2.front();
  cout << "Result of ItemList find_item(long str)" << endl;
  while(pointer != nullptr)
  {
    Item found = pointer->get_content();
    cout << "Id: " << found.id() << endl;
    cout << "Title: " << found.title() << endl;
    cout << "Detail: " << found.detail() <<endl;
    cout << "Price: " << found.price() << endl;
    cout << "State: " << found.on_shelf() << endl;
    pointer = pointer->get_next();
    cout << endl;
  }
  return 0;
}
