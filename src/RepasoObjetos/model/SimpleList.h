#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include<iostream>
#include "Node.h"
using namespace std;
template<class T>class SimpleList{
	private :
		Node<T> *start,*end;
	public :
		
		SimpleList(){
			start=end=NULL;
		}
		bool isEmpty(){
			return start==NULL;
		}
		void insertToTheStart(T date){
			Node<T> *_new=new Node<T>(date);
			if(!isEmpty()){
				_new->next=start;
				start=_new;
			}else{
				end=start=_new;
			}
		}
		void insertToTheEnd(T date){
			Node<T> *_new=new Node<T>(date);
			if(!isEmpty()){
				end->next=_new;
				end=_new;
			}else{
				end=start=_new;
			}
		}
		void show(){
			if(!isEmpty()){
				Node<T> *travel=start;
				while(travel){ // Recordar 	que NULL == False
					cout<<"["<<travel->date<<"]-->";
					travel=travel->next;
				}
				cout<<" || ";
			}else{
				cout<<"\nIt's empty\n";
			}
		}
};
#endif
