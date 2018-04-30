#ifndef LIST_H_
#define LIST_H_
#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class ListNode
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
		T* get_pointer()
		{
		    return &content;
		}
		T get_content()
		{
			return content;
		}
		void set_next(ListNode *next)
		{
			this->next=next;
		}
		ListNode* get_next()
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
		void add_front(T var)
		{
			head=new ListNode<T>(var,head);
		}
		bool empty()
		{
			return head==nullptr;
		}
		void del_front()
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
    ListNode<T> *front()
    {
      return head;
    }
};
#endif
