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
 
private:
    NodoLibro * primero;
    NodoLibro * ultimo;
    int distancia(NodoLibro *first, NodoLibro *last){
 
        int i=1;
 
        NodoLibro *ptr = first;
 
        while (ptr != last)
         {
          ptr = ptr->siguiente;
          i++;
         }
 
     return i;
 
    }
 
    void QuicksortAux(NodoLibro *first,NodoLibro *last){
 
     NodoLibro * n1,*n2;
     NodoLibro *pivote=first;
     int longitud = distancia(first,last);
     int i,j;
     if (longitud<=1)
      return;
 
     
     n1 = first;
     n2 = last;
    
         i=1;
     j=longitud;
 
    
     while (i<j){   
 
     while (!n1->compare(pivote) && i<j+1 && i<longitud){
         n1=n1->siguiente;
         i++;
     }
 
      while (n2->compare(pivote) && j>i-1 && j>1){
        n2 = n2->anterior;
        j--;
     }
 
     if (i<j)
      n1->changeLibro(n2);
     }
     
 
     pivote->changeLibro(n2);
    
     if (n2!=first)
      QuicksortAux(first,n2->anterior);
     if (n2!=last)
     QuicksortAux(n2->siguiente,last);
    
    }
 
public:
 
   
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
 
    void Quicksort(){
    if (primero!=ultimo)
     QuicksortAux(primero,ultimo);
    }
 
 
    
} ;
