#ifndef POLINOMIOMULTCLASICA_H_
#define POLINOMIOMULTCLASICA_H_

class PolinomioMultClasica : public Polinomio {
public:
  /* Multiplicación */
  void mult(Polinomio&);
  PolinomioMultClasica(void);
  
  PolinomioMultClasica(int);
  PolinomioMultClasica(int coef[], const int tam);
  ~PolinomioMultClasica(void);
};

#endif