#ifndef LIST_H_
#define LIST_H_
#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class ListNode//链表结点
{
	private:
		T content;
		ListNode *next;
	public:
		ListNode()
		{
			next=nullptr;
		}
		ListNode(T content):content(content)
		{
			next=nullptr;
		}
		ListNode(T content, ListNode *next):content(content),next(next)
		{}
		T* get_pointer()//返回结点指针
		{
		    return &content;
		}
		T get_content()//返回结点内容
		{
			return content;
		}
		void set_next(ListNode *next)//设置结点指向下一结点
		{
			this->next=next;
		}
		ListNode* get_next()//返回结点指向的下一结点的指针
		{
			return next;
		}
};

template<typename T>
class List
{
	private:
		ListNode<T> *head;
	public:
		List()
		{
			head=nullptr;
		}
		void add_front(T var)//增加新结点在链表的头
		{
			head=new ListNode<T>(var,head);
		}
		bool empty()
		{
			return head==nullptr;
		}
		void del_front()//删除第一个结点
		{
			if(empty())
				return;
			ListNode<T> *node_to_delete=head;
			head=head->get_next();
			delete node_to_delete;
		}
		void print()
		{
			ListNode<T> *it=head;
			if(it==nullptr)
				cout<<"It's empty.";
			while(it!=nullptr)
			{
				cout<<it->get_content();
				it=it->get_next();
			}
			cout<<endl<<endl;
		}
    ListNode<T> *front()//返回头结点
    {
      return head;
    }
};
#endif
