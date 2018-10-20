// CCadena.h: Fichero de cabecera de definición de cadenas
// C con Clase: Marzo de 2002

#ifndef CCADENA
#define CCADENA
#include <cstring>
using namespace std;

class Cadena {
  public:
   Cadena(char *cad) {
      cadena = new char[strlen(cad)+1];
      strcpy(cadena, cad);
   }
   Cadena() : cadena(NULL) {}
   Cadena(const Cadena &c) : cadena(NULL) {*this = c;}
   ~Cadena() { if(cadena) delete[] cadena; }
   Cadena &operator=(const Cadena &c) {
      if(this != &c) {
         if(cadena) delete[] cadena;
         if(c.cadena) {
            cadena = new char[strlen(c.cadena)+1];
            strcpy(cadena, c.cadena);
         }
         else cadena = NULL;
      }
      return *this;
   }
   bool operator==(const Cadena &c) const {
      return !strcmp(cadena, c.cadena);
   }
   bool operator!=(const Cadena &c) const {
      return strcmp(cadena, c.cadena);
   }
   bool operator<(const Cadena &c) const {
      return strcmp(cadena, c.cadena) < 0;
   }
   bool operator>(const Cadena &c) const {
      return strcmp(cadena, c.cadena) > 0;
   }
   bool operator<=(const Cadena &c) const {
      return strcmp(cadena, c.cadena) <= 0;
   }
   bool operator>=(const Cadena &c) const {
      return strcmp(cadena, c.cadena) >= 0;
   }

   const char* Lee() const {return cadena;}
   
  private:
   char *cadena;
};

ostream& operator<<(ostream &os, const Cadena& cad) {
   os << cad.Lee();
   return os;
}
#endif
