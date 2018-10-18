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
		cout<<"3. Eliminar al inicio"<<endl;
		cout<<"4. Eliminar al final"<<endl;
		cout<<"5. Eliminar especifico"<<endl;
		cout<<"6. Mostrar "<<endl;
		cout<<"7. Limpiar "<<endl;
		cout<<"8. Salir "<<endl;
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
			deleteToStart(ultimo);
			break;
		case 4:
			deleteToEnd(ultimo);
			break;
		case 5:
			cin>>dato;
			deleteEspecific(ultimo,dato);
			break;
		case 6:
			show(ultimo);
			break;
		case 7:
			system("cls");
			break;
		default : 
			return true;
	}
	return false;
}
