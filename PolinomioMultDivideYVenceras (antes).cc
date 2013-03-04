#include "PolinomioMultDivideYVenceras.h"

typedef PolinomioMultDivideYVenceras PolinomioMDV;

void PolinomioMultDivideYVenceras::mult(Polinomio& pol) {
  Polinomio p;
  
  vector<Monomio> a = getTodosTerminos();
  vector<Monomio> b = pol.getTodosTerminos();
  
  cout << "antesmult" << endl;
  
  
  
  a = multRec(a, b);
  
  cout << "final_a = ";
    for(unsigned i = 0; i < a.size(); i ++)
      cout << a[i] << " ";
    cout << endl;
  
  setTodosTerminos(a);
  
  
  
}

vector<Monomio> PolinomioMultDivideYVenceras::multRec(vector<Monomio> a, vector<Monomio> b) {
  
  
  cout << "nueva multRec ---------------------" << endl;
  
  cout << "a = ";
    for(unsigned i = 0; i < a.size(); i ++)
      cout << a[i] << " ";
    cout << endl;
    
    cout << "b = ";
    for(unsigned i = 0; i < b.size(); i ++)
      cout << b[i] << " ";
    cout << endl;
  
  
  int n = a.size();
  if(b.size() > n)
    n = b.size();
  if(n == 1) {
    vector<Monomio> resultado;
    Monomio monomio(a[0].getCoeficiente() * b[0].getCoeficiente(), a[0].getExponente());
    resultado.push_back(monomio);
    
    cout << "n = 1" << endl;
    
    return resultado;
  }
  else {
    vector<Monomio> ah;
    vector<Monomio> al;
    vector<Monomio> bh;
    vector<Monomio> bl;
    vector<Monomio> s1;
    vector<Monomio> s2;
    vector<Monomio> x1;
    vector<Monomio> x2;
    vector<Monomio> x3;
    vector<Monomio> aux;
    vector<Monomio> x;
    ah = parteAlta(a);
    al = parteBaja(a);
    bh = parteAlta(b);
    bl = parteBaja(b);
    
    cout << "ah = ";
    for(unsigned i = 0; i < ah.size(); i ++)
      cout << ah[i] << " ";
    cout << endl;
    
    cout << "al = ";
    for(unsigned i = 0; i < al.size(); i ++)
      cout << al[i] << " ";
    cout << endl;
    
    cout << "bh = ";
    for(unsigned i = 0; i < bh.size(); i ++)
      cout << bh[i] << " ";
    cout << endl;
    
    cout << "bl = ";
    for(unsigned i = 0; i < bl.size(); i ++)
      cout << bl[i] << " ";
    cout << endl;
    
    s1 = sumarVectorMonomios(ah, al);
    s2 = sumarVectorMonomios(bh, bl);
    
    
    cout << "s1 = ";
    for(unsigned i = 0; i < s1.size(); i ++)
      cout << s1[i] << " ";
    cout << endl;
    cout << "s2 = ";
    for(unsigned i = 0; i < s2.size(); i ++)
      cout << s2[i] << " ";
    cout << endl;
    
    cout << "-------------------------------------" << endl;
    
    x1 = multRec(ah, bh);
    x2 = multRec(s1, s2);
    x3 = multRec(al, bl);
    
    cout << "x1 = ";
    for(unsigned i = 0; i < x1.size(); i ++)
      cout << x1[i] << " ";
    cout << endl;
    cout << "x2= ";
    for(unsigned i = 0; i < x2.size(); i ++)
      cout << x2[i] << " ";
    cout << endl;
    cout << "x3 = ";
    for(unsigned i = 0; i < x3.size(); i ++)
      cout << x3[i] << " ";
    cout << endl;
    
    
    aux = restarVectorMonomios(x2, x1);
    aux = restarVectorMonomios(aux, x3);
    
    cout << "aux = ";
    for(unsigned i = 0; i < aux.size(); i ++)
      cout << aux[i] << " ";
    cout << endl;
    
    
    x1 = desplazarDerecha(x1, n);
    
    cout << "x1_desp = ";
    for(unsigned i = 0; i < x1.size(); i ++)
      cout << x1[i] << " ";
    cout << endl;
    
    
    aux = desplazarDerecha(aux, n / 2);
    
    cout << "aux_desp = ";
    for(unsigned i = 0; i < aux.size(); i ++)
      cout << aux[i] << " ";
    cout << endl;
    
    
    x = sumarVectorMonomios(x1, aux);
    x = sumarVectorMonomios(x, x3);
    return x;
  }
}

vector<Monomio> PolinomioMultDivideYVenceras::parteAlta(vector<Monomio> p) {
  p = desplazarIzquierda(p, p.size() / 2);
  return p;
}

vector<Monomio> PolinomioMultDivideYVenceras::parteBaja(vector<Monomio> p) {
  for(unsigned i = 0; i < p.size() / 2; i++)
    p.pop_back();
  return p;
}

vector<Monomio> PolinomioMultDivideYVenceras::desplazarIzquierda(vector<Monomio> p, int n) {
  int numeroTerminos = p.size();
  for(int i = numeroTerminos - 1; i >= n; i--) { //comprobar si lo hace bien
    p[i - n] = p[i];
    p[i - n].setExponente(i - n);
    p.pop_back();
  }
  return p;
}

vector<Monomio> PolinomioMultDivideYVenceras::desplazarDerecha(vector<Monomio> p, int n) {
  
  int numeroTerminos = p.size() + n;
  
  cout << "desplazarDerecha antes = ";
  for(int i = 0; i < p.size(); i++)
    cout << p[i] << " ";
  cout << endl;
  
  Monomio zero(0, 1);
  vector<Monomio> resultado;
  for(int i = 0; i < numeroTerminos; i++) {
    resultado.push_back(zero);
    resultado[i].setExponente(i);
  }
  
  for(int i = p.size() - 1; i >= 0; i--) {
    resultado[i + n] = p[i];
    resultado[i + n].setExponente(i + n);
  }
  
  cout << "desplazarDerecha despues = ";
  for(int i = 0; i < resultado.size(); i++)
    cout << resultado[i] << " ";
  cout << endl;
  
  return resultado;
}

PolinomioMDV operator+(PolinomioMDV& x, PolinomioMDV& y) {
  unsigned numeroTerminos = x.getNumeroTerminos();
  PolinomioMDV suma(0);
  if(y.getNumeroTerminos() > numeroTerminos)
    numeroTerminos = y.getNumeroTerminos();
  for(unsigned i = 0; i < numeroTerminos; i++)
    suma.setTermino(i, x.getTermino(i) + y.getTermino(i));
  return suma;
}

PolinomioMDV operator-(PolinomioMDV& x, PolinomioMDV& y) {
  unsigned numeroTerminos = x.getNumeroTerminos();
  PolinomioMDV resta(0);
  if(y.getNumeroTerminos() > numeroTerminos)
    numeroTerminos = y.getNumeroTerminos();
  for(unsigned i = 0; i < numeroTerminos; i++)
    resta.setTermino(i, x.getTermino(i) - y.getTermino(i));
  return resta;
}

vector<Monomio> PolinomioMultDivideYVenceras::sumarVectorMonomios(vector<Monomio>& x, vector<Monomio>& y) {
  unsigned numeroTerminos = x.size();
  vector<Monomio> suma;
  if(y.size() > numeroTerminos)
    numeroTerminos = y.size();
  for(unsigned i = 0; i < numeroTerminos; i++) {
    if((i < x.size())&&(i < y.size()))
      suma.push_back(x[i] + y[i]);
    else if((i < x.size())&&(i >= y.size()))
      suma.push_back(x[i]);
    else if((i >= x.size())&&(i < y.size()))
      suma.push_back(y[i]);
  }
  return suma;
}

vector<Monomio> PolinomioMultDivideYVenceras::restarVectorMonomios(vector<Monomio>& x, vector<Monomio>& y) {
  unsigned numeroTerminos = x.size();
  vector<Monomio> resta;
  if(y.size() > numeroTerminos)
    numeroTerminos = y.size();
  for(unsigned i = 0; i < numeroTerminos; i++) {
    if((i < x.size())&&(i < y.size()))
      resta.push_back(x[i] - y[i]);
    else if((i < x.size())&&(i >= y.size()))
      resta.push_back(x[i]);
    else if((i >= x.size())&&(i < y.size())) {
      Monomio zero(0, i);
      resta.push_back(zero - y[i]);
    }
  }
  return resta;
}

void PolinomioMultDivideYVenceras::setTodosTerminos(vector<Monomio>& p) {
  clearTerminos();
  for(unsigned i = 0; i < p.size(); i++)
    addTermino(p[i]);
}

PolinomioMultDivideYVenceras::PolinomioMultDivideYVenceras(void) : Polinomio() {}

PolinomioMultDivideYVenceras::PolinomioMultDivideYVenceras(int coef[], const int tam) : Polinomio(coef, tam) {}

PolinomioMultDivideYVenceras::PolinomioMultDivideYVenceras(int numero) : Polinomio(numero) {}

PolinomioMultDivideYVenceras::PolinomioMultDivideYVenceras(Polinomio pol) : Polinomio(pol) {}

PolinomioMultDivideYVenceras::~PolinomioMultDivideYVenceras(void) {
  clearTerminos();
}