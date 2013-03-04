#ifndef POLINOMIO_H_
#define POLINOMIO_H_
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "Monomio.cc"
#include "tratamientocadenas.cpp"

using std::string;
using std::ostringstream;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::vector;
using std::remove;
using std::streamsize;

class Polinomio {
public:
  static const int COEFICIENTE_MAXIMO = 5000;
  static const int EXPONENTE_MAXIMO = 10;
private:
  int grado;
  vector<Monomio> terminos;
public:
  
  /* Multiplicación */
  virtual void mult(Polinomio&) {}

  /* Constructores y destructor */
  Polinomio(void); //Polinomio al azar
  Polinomio(int coef[], const int tam);
  Polinomio(int); //Polinomio al azar eligiendo el número de términos
  Polinomio(Polinomio&);
  virtual ~Polinomio(void);
  
  /* Imprimir */
  friend ostream& operator<<(ostream &out, Polinomio& p);
  
  /* Getters y setters */
  void crearMonomio(int, int);
  void addTermino(Monomio);
  void setTermino(int, Monomio);
  void borrarUltimoTermino(void);
  void setTodosTerminos(vector<Monomio>);
  Monomio getTermino(int);
  const vector<Monomio>& getTodosTerminos(void);
  unsigned getNumeroTerminos(void);
  void clearTerminos(void);
};

#endif