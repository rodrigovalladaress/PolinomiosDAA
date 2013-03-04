vector<int> PolinomioMultDivideYVenceras::multRec(vector<int> a, vector<int> b) {
  int n = a.size();
  if(n == 1) {
    vector<Monomio> resultado;
    Monomio monomio(a[0].getCoeficiente() * b[0].getCoeficiente(), a[0].getExponente());
    resultado.push_back(monomio);
    return resultado;
  }
  else {
    vector<int> ah;
    vector<Monomio> al;
    vector<Monomio> bh;
    vector<Monomio> bl;
    vector<Monomio> s1;
    vector<Monomio> s2;
    vector<Monomio> x1;
    vector<Monomio> x2;
    vector<Monomio> x3;
    vector<Monomio> aux;
    
    
    
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
    
    cout << "-------------------------------------" << endl;
    
    s1 = sumarVectorMonomios(ah, al);
    s2 = sumarVectorMonomios(bh, bl);
    x1 = multRec(ah, bh);
    x2 = multRec(s1, s2);
    x3 = multRec(al, bl);
    aux = restarVectorMonomios(x2, x1);
    aux = restarVectorMonomios(aux, x3);
    x1 = desplazarDerecha(x1, n);
    aux = desplazarDerecha(aux, n / 2);
    x1 = sumarVectorMonomios(x1, aux);
    x1 = sumarVectorMonomios(x1, x3);
    return x3;
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