#include "PolinomioMultClasica.h"
void PolinomioMultClasica::mult(Polinomio& pol) {
  vector<Monomio> monomios;
  Monomio* aux;
  int numeroTerminosMultiplicando;
  int numeroTerminosMultiplicador;
  int numeroTerminosResultado;
  Polinomio* p;
  Polinomio* q;
  /*   p
   * X q
   * ____
   *   r  */
  if(getNumeroTerminos() <= pol.getNumeroTerminos()) {
    p = &pol;
    q = this;
  }
  else {
    p = this;
    q = &pol;
  }
  numeroTerminosMultiplicador = q->getNumeroTerminos();
  numeroTerminosMultiplicando = p->getNumeroTerminos();
  numeroTerminosResultado = numeroTerminosMultiplicador + numeroTerminosMultiplicando -1;
  for(int i = 0; i < numeroTerminosResultado; i++) {
    aux = new Monomio(0, i);
    monomios.push_back(*aux);
  } 
  /* Multiplicación */
  for(int i = 0; i < numeroTerminosMultiplicador; i++)
    for(int j = 0; j < numeroTerminosMultiplicando; j++)
      monomios[i + j] += (p->getTermino(j) * q->getTermino(i));
  clearTerminos();
  setTodosTerminos(monomios);
  monomios.clear();
}

PolinomioMultClasica::PolinomioMultClasica(void) : Polinomio() {}

PolinomioMultClasica::PolinomioMultClasica(int numeroTerminos) : Polinomio(numeroTerminos) {
  
}

PolinomioMultClasica::PolinomioMultClasica(int coef[], const int tam) : Polinomio(coef, tam) {}

PolinomioMultClasica::~PolinomioMultClasica(void) {
  clearTerminos();
}