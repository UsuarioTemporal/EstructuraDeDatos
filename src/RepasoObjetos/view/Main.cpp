#include<iostream>
#include "../model/SimpleList.h"
using namespace std;
SimpleList<int> numberList=SimpleList<int>();
SimpleList<string> stringList=SimpleList<string>();
int main(){
	numberList.insertToTheEnd(4);
	numberList.insertToTheEnd(5);
	numberList.insertToTheEnd(6);
	numberList.insertToTheEnd(7);
	numberList.show();
	cout<<"\n";
	
	stringList.insertToTheStart("Hola");
	stringList.insertToTheStart("como");
	stringList.insertToTheStart("estas");
	stringList.insertToTheStart("amigo");
	stringList.show();
}
