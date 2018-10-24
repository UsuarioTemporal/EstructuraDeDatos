#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template<class T>class Node{
	public:
		T date;
		Node *next=NULL,*previous=NULL;
		Node(T date){
			this->date=date;
		}
};
#endif
