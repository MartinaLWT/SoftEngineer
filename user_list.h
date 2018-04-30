#ifndef USER_LIST_H_
#define USER_LIST_H_
#include"list.h"
#include"user.h"
class UserList
{
  private:
    List<User>users_;
  public:
    void add_user(User var);
    User find_user(long id);
    User find_user(wstring username);
    void print_user();
};
#endif
