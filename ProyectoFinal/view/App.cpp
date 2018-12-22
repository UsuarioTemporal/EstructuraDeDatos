#include "../model/Menu.h"
#include <locale.h>
int main(){
	setlocale(LC_ALL,"");
	Menu *menu=new Menu();
	menu->initComponents();
	delete(menu);
}
