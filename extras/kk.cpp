#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(){
	int a=12;
	char buffer[10];
	char *intStr = itoa(12,buffer,10);
	string s=string(intStr);
	cout<<s;
	return 0;
}
