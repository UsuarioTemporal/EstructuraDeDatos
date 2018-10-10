#include<tree.h>
using namespace Tree;
Nodo *raiz=NULL;
void menu();
bool opciones(int);
int main(){
	menu();
}

void menu(){
	bool condition=true;
	do{
		cout<<"\n1. Insertar"<<endl;
		
		int op;
		cout<<"\nOpcion : ";
		cin>>op;
		condition=!opciones(op);
	}while(condition);
}
bool opciones(int op){
	switch(op){
		int dato;
		case 1:
			cin>>dato;
			insertar(raiz,dato);
			return true;
	}
	return false;
}
