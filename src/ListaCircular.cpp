#include<circlesimplelist.h>
using namespace CircleSimpleList;
Nodo *ultimo=NULL;
void menu();
bool opciones(int);
int main(){
	menu();
	return 0;
}
void menu(){
	bool condition=true;
	do{
		cout<<"\n1. Insertar al final"<<endl;
		cout<<"2. Insertar al inicio"<<endl;
		cout<<"3. Eliminar especifico"<<endl;
		cout<<"4. Mostrar "<<endl;
		cout<<"5. Limpiar "<<endl;
		cout<<"6. Salir "<<endl;
		int op;
		cin>>op;
		condition=!opciones(op);
	}while(condition);
}
bool opciones(int op){
	switch(op){
		int dato;
		case 1:
			cin>>dato;
			insertToEnd(ultimo,dato);
			break;
		case 2:
			cin>>dato;
			insertToStart(ultimo,dato);
			break;
		case 3:
			cin>>dato;
			deleteEspecific(ultimo,dato);
			break;
		case 4:
			show(ultimo);
			break;
		case 5:
			system("cls");
			break;
		default : 
			return true;
	}
	return false;
}
