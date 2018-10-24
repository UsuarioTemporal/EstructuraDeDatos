#include <iostream>
#include <string>
enum genero { teatro,ensayo,novela };
using namespace std;
 
 
/*    CLASE LIBRO  */
class libro
{
public:
    int codigo;
    string titulo;
    int anho;
    int autor;
    string editorial;
    genero _Genero;
 
    libro(int c,string t, int ano, int a, string edi,genero g)
    {
        codigo = c;
        titulo = t;
        anho = ano;
        autor = a;
        editorial = edi;
        _Genero = g;
    }
    void printlibro()
    {
        cout<<"codigo: " << codigo << " Titulo: " << titulo << endl;
    }
};
 
/*    CLASE NODOLIBRO  */
class NodoLibro
{
public:
    libro * lib;
    NodoLibro * anterior;
    NodoLibro * siguiente;
    NodoLibro(libro * l)
    {
        lib = l;
        anterior = NULL;
        siguiente = NULL;
    }
    bool compare(const NodoLibro * l)
    {
        if (lib->codigo > l->lib->codigo)
            return true;
        return false;
    }
    
    void changeLibro(NodoLibro * l)
    {
        libro * temp = lib;
        lib = l->lib;
        l->lib =temp;
    }
};
 
/*    CLASE LISTA  */
 
class Lista
{
public:
    NodoLibro * primero;
    NodoLibro * ultimo;
    Lista()
    {
        primero = ultimo = NULL;
    }
    ~Lista()
    {
        NodoLibro * temp = primero, * temp2;
        while (temp != NULL) {
            temp2 = temp->siguiente;
            delete temp;
            temp = temp2;
        }
    }
    void Append(libro * l)
    {
        NodoLibro * n = new NodoLibro(l);
        if (ultimo  == NULL )
            primero = ultimo = n;
        else{
            n->siguiente = NULL;
            ultimo->siguiente = n;
            n->anterior = ultimo;
            ultimo = n;
        }
    } 
    libro * Remove ()
    {
        NodoLibro * n = ultimo;
        libro * l = ultimo->lib;
        if (ultimo == primero)
            ultimo = primero = NULL;
        else{
            ultimo = ultimo->anterior;
            ultimo->siguiente = NULL;
        }
        delete n;
        return l;
        
    }
    
    void printlista()
    {
        NodoLibro * temp = primero;
        while (temp != NULL){
            temp->lib->printlibro();
            temp = temp->siguiente;
        }
    }
    
    void OrdenarLista()
    {
        NodoLibro * n1,*n2;
        for (n1 = ultimo; n1 != primero ; n1 = n1->anterior)
            for (n2 = primero; n2 != n1 ; n2 = n2->siguiente)
            {
                if (n2->compare(n2->siguiente))
                    n2->changeLibro(n2->siguiente);
                    
            }
    }
} ;
 
int main ()
{
    libro * l1 = new libro(1,"mi mundo",2000,4,"edu",teatro);
    libro * l2 = new libro(3,"hello world",2000,4,"edu",teatro);
    libro * l3 = new libro(2,"a la madona",2000,4,"edu",teatro);
    Lista * c = new Lista();
    c->Append(l1);
    c->Append(l2);
    c->Append(l3);
 
    c->printlista();
    cout<<"----------------------------------------------------"<<endl;
    c->OrdenarLista();
    c->printlista();
    delete c;
    cout<<"chauuuu" << endl;
    return 0;
}
