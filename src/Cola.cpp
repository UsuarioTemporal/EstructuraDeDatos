#include<queue.h>
using namespace Queue;
void menu();
bool opciones(int);
Nodo *primero=NULL;Nodo *ultimo=NULL;
int main (){
	cout<<"\n";
	menu();
	delete primero;
	delete ultimo;
	return 0;
}
void menu(){
	bool condition=true;
	do{
		
		cout<<"\n1. Insertar "<<endl;
		cout<<"2. Eliminar "<<endl;
		cout<<"3. Mostrar "<<endl;
		cout<<"4. Salir "<<endl;
		int op;
		cin>>op;
		condition=!opciones(op);
	}while(condition);
}

bool opciones(int op){
	switch(op){
		case 1:
			int dato;
			cin>>dato;
			push(primero,ultimo,dato);
			break;
		case 2:
			pop(primero,ultimo);
			break;
		case 3:
			show(primero);
			break;
		default : 
			return true;
	}
	return false;
}
