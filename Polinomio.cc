#include "Polinomio.h"
Polinomio::Polinomio(int numeroTerminos) {
  int coeficiente;
  /* Se crean n = EXPONENTE_MAXIMO monomios de coeficiente aleatorio entre 
   * 0 y COEFICIENTE_MAXIMO */
  for(int i = 0; i < numeroTerminos; i++) {
    coeficiente = rand() % COEFICIENTE_MAXIMO;
    if(rand() % 2)
      coeficiente = -coeficiente;
    crearMonomio(coeficiente, i);
  }
}

Polinomio::Polinomio(void) {
  int coeficiente;
  /* Se crean n = EXPONENTE_MAXIMO monomios de coeficiente aleatorio entre 
   * 0 y COEFICIENTE_MAXIMO */
  for(int i = 0; i < EXPONENTE_MAXIMO; i++) {
    coeficiente = rand() % COEFICIENTE_MAXIMO;
    if(rand() % 2)
      coeficiente = -coeficiente;
    crearMonomio(coeficiente, i);
  }
}

Polinomio::Polinomio(int coef[], const int tam) {
  for(int i = 0; i < tam; i++)
    crearMonomio(coef[i], i);
}

Polinomio::Polinomio(Polinomio& pol) {
  clearTerminos();
  setTodosTerminos(pol.getTodosTerminos());
}

Polinomio::~Polinomio(void) {
  clearTerminos();
}

/* Imprimir */

ostream& operator<<(ostream &out, Polinomio& p) {
  for(int i = (int)p.getNumeroTerminos() - 1; i >= 0; i--) {
    out << p.getTermino(i); 
    if(p.getTermino(i).getCoeficiente() != 0)
      out << ' ';
  }
  return out;
}

/* Getters y setters */

void Polinomio::crearMonomio(int coeficiente, int exponente) {
  Monomio monomio(coeficiente, exponente);
  addTermino(monomio);
}

void Polinomio::addTermino(Monomio monomio) {
  terminos.push_back(monomio);
}

void Polinomio::setTermino(int i, Monomio p) {
  terminos[i] = p;
}

void Polinomio::borrarUltimoTermino(void) {
  terminos.pop_back();
}

void Polinomio::setTodosTerminos(vector<Monomio> monomios) {
  clearTerminos();
  for(unsigned i = 0; i < monomios.size(); i++)
    addTermino(monomios[i]);
}

Monomio Polinomio::getTermino(int i) {
  if(i < (int)getNumeroTerminos())
    return terminos[i];
  else {
    Monomio zero(0, i);
    return zero;
  }
}

const vector<Monomio>& Polinomio::getTodosTerminos(void) {
  return terminos;
}

unsigned Polinomio::getNumeroTerminos(void) {
  return terminos.size();
}

void Polinomio::clearTerminos(void) {
  terminos.clear();
}