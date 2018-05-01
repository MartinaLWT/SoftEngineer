#ifndef LIST_H_
#define LIST_H_
#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class ListNode//������
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
		T* get_pointer()//���ؽ��ָ��
		{
		    return &content;
		}
		T get_content()//���ؽ������
		{
			return content;
		}
		void set_next(ListNode *next)//���ý��ָ����һ���
		{
			this->next=next;
		}
		ListNode* get_next()//���ؽ��ָ�����һ����ָ��
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
		void add_front(T var)//�����½���������ͷ
		{
			head=new ListNode<T>(var,head);
		}
		bool empty()
		{
			return head==nullptr;
		}
		void del_front()//ɾ����һ�����
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
    ListNode<T> *front()//����ͷ���
    {
      return head;
    }
};
#endif
