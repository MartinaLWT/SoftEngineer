#ifndef STACK_H_
#define STACK_H_
#include"list.h"

template<typename T> class Stack
{
private:
    List<T> content;
    int stacksize;
public:
    Stack(){}
    int getSize()
    {
        return stacksize;
    }
    void push(T var)//进入新网页
    {
        content.add_front(var);
        stacksize++;
    }
    T pop()//返回网页
    {
        T toreturn;
        toreturn = content.front()->get_content();
        content.del_front();
        stacksize--;
        return toreturn;
        /*if(size==0)
            return;
        content.del_front();
        size--;
        return;*/
    }
    T top()//当前网页
    {
        return content.front()->get_content();
    }
    /*
    ListNode* showpage()//当前的网页
    {
        return content.head;
    }
    */
};
#endif // STACK_H_
