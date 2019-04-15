#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

template<typename T>
class Single_List
{
	typedef struct Node_tag{
		T m_data;
		Node_tag* p_mNext;
		Node_tag(T data):m_data(data),p_mNext(nullptr){
		}
	}node_t;

	node_t* p_mHead;
	size_t m_length;
	void copy_list(const Single_List & other){
		node_t* other_head = other.p_mHead;

		assert(other_head != nullptr);
		init_list(other_head->m_data);
		node_t* tempnode = p_mHead;
		other_head = other_head->p_mNext;
		while(other_head!= nullptr){
			tempnode->p_mNext=new node_t(other_head->m_data);
			tempnode= tempnode->p_mNext;
			other_head = other_head->p_mNext;
		}
		m_length = other.m_length;
	}
	void clear_list(){
		node_t* temp = p_mHead;
		do{
			p_mHead = p_mHead->p_mNext;
			delete temp;
			temp = p_mHead;
		}while(temp!=nullptr);
		m_length = 0;
	}
	bool is_empty()const{
		return (m_length == 0);
	}
public:
	Single_List(void){
		p_mHead = nullptr;
		m_length = 0;
	}
	Single_List(T data){
		p_mHead = new node_t(data);
		m_length = 1;
	}
	Single_List(const Single_List& other){
		if(other.is_empty()){
			return;
		}
		copy_list(other);
	}
	Single_List& operator =(const Single_List & other){
		if(this!=&other){
			//Clear the Existing list
			clear_list();
			//Copy the list
			copy_list(other);
		}
		return *this;
	}
	void init_list(T data){
		node_t* newnode = new node_t(data);
		p_mHead = newnode;
		m_length = 1;
	}
	void insert_node(T data, size_t index){		
		assert(index <= m_length);
		node_t* newnode = new node_t(data);
		if(is_empty()){
			init_list(data);
			return;
		}else if(index == m_length){
			node_t* temp = p_mHead;
			while(temp->p_mNext!=nullptr){
				temp = temp->p_mNext;
			}
			temp->p_mNext= newnode;
		}else if(index < m_length){
			node_t* temp = p_mHead;
			node_t* prevnode = nullptr;
			for(int i =0 ;i < index; i++){
				prevnode = temp;
				temp = temp->p_mNext;
			}
			if(prevnode != nullptr){
				/*prevnode->next = newnode;
				newnode->next = temp;*/
				newnode->p_mNext = temp->p_mNext;
				temp->p_mNext = newnode;

			}
		}
		++m_length;

	}
	size_t get_length()const{
		return m_length;
	}
	~Single_List(void){
		clear_list();
	}
	void reverse_list(){
		node_t * current;
		node_t* prev = nullptr;
		node_t* next = nullptr;
		current = p_mHead;
		while (current!=nullptr)
		{
			next = current->p_mNext;
			current->p_mNext = prev;
			prev = current;
			current = next;
		}
		p_mHead = prev;
	}

	class Iterator{
		node_t* m_pnode;
	public:
		Iterator(){
		}

		Iterator(node_t* ptr):m_pnode(ptr){
		}

		Iterator& operator++(){
			m_pnode= m_pnode->p_mNext;
			return *this;
		}
		T& operator*(){
			return m_pnode->m_data;
		}

		T* operator->(){
			return m_pnode->m_data;
		}
		bool operator==(const Iterator& other)const{
			return(m_pnode==other.m_pnode);
		}
		bool operator!=(const Iterator& other)const{
			return(m_pnode!=other.m_pnode);
		}

	};

	Iterator begin(){
		return Iterator(p_mHead);
	}
	Iterator end(){
		return Iterator(nullptr);
	}
	void print_list(){
		node_t* temp = p_mHead;
		while(temp!=nullptr){
			std::cout<<temp->m_data<<endl;
			temp = temp->p_mNext;
		}
	}
};

void ListOps(void);

