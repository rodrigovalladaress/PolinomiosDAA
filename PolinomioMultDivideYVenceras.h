#ifndef POLINOMIOMULTDIVIDEYVENCERAS_H_
#define POLINOMIOMULTDIVIDEYVENCERAS_H_

class PolinomioMultDivideYVenceras : public Polinomio {
public:
  
  typedef PolinomioMultDivideYVenceras PolinomioMDV;
  
  /* Multiplicación */
  void mult(Polinomio&);
  vector<Monomio> multRec(vector<Monomio> &, vector<Monomio>&);
  vector<Monomio> parteAlta(vector<Monomio>); 
  vector<Monomio> parteBaja(vector<Monomio>);
  vector<Monomio> desplazarIzquierda(vector<Monomio>, int);
  void desplazarDerecha(vector<Monomio>&, int);
  
  /* Suma y resta */
  vector<Monomio> sumarVectorMonomios(vector<Monomio>&, vector<Monomio>&);
  vector<Monomio> restarVectorMonomios(vector<Monomio>&, vector<Monomio>&);
  
  PolinomioMultDivideYVenceras(void);
  PolinomioMultDivideYVenceras(int coef[], const int tam);
  PolinomioMultDivideYVenceras(int);
  PolinomioMultDivideYVenceras(Polinomio);
  ~PolinomioMultDivideYVenceras(void);
};

#endif