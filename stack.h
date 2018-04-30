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
    void push(T var)//��������ҳ
    {
        content.add_front(var);
        stacksize++;
    }
    T pop()//������ҳ
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
    T top()//��ǰ��ҳ
    {
        return content.front()->get_content();
    }
    /*
    ListNode* showpage()//��ǰ����ҳ
    {
        return content.head;
    }
    */
};
#endif // STACK_H_
