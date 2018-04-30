#include"list.h"
#include"user_list.h"

void UserList::add_user(User var)
{
  users_.add_front(var);
}

User UserList::find_user(long id)
{
  ListNode<User>*pointer=users_.front();
  while(pointer!=nullptr)
  {
    if(pointer->get_content().id() == id)
      return pointer->get_content();
    pointer=pointer->get_next();
  }
  return User("", "", -1);
}

User UserList::find_user(wstring username)
{
  ListNode<User>*pointer=users_.front();
  while(pointer!=nullptr)
  {
    if(pointer->get_content().username() == username)
      return pointer->get_content();
    pointer = pointer->get_next();
  }
  return User( "", "", -1);
}

void UserList::print_user()
{
  ListNode<User>*pointer=users_.front();
  while(pointer!=nullptr)
  {
    cout << endl;
    cout << "Id: " << pointer->get_content().id() << endl;
    cout << "Username: " << pointer->get_content().username() << endl;
    cout << "Password: " << pointer->get_content().password() << endl;
    pointer = pointer->get_next();
  }
}
