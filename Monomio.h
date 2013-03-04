#ifndef MONOMIO_H_
#define MONOMIO_H_

using std::ostream;
using std::string;
using std::ostringstream;
using std::abs;

class Monomio {
  static const char VARIABLE_POR_DEFECTO = 'x';
private:
  char variable;
  int coeficiente;
  int exponente;
public:
  Monomio();
  Monomio(int, int);
  Monomio(int);
  Monomio(int, int, char);
  
  inline int evaluar(int) const;
  
  /* Getter y setter */
  inline int getCoeficiente() const;
  inline int getExponente() const;
  inline char getVariable() const;
  inline void setCoeficiente(int);
  inline void setExponente(int);
  inline void setVariable(int);
  
  /* Multiplicación (método abstracto) */
  virtual Monomio mult(const Monomio& m);  
  
  /* Operadores */
  friend ostream& operator<<(ostream& out, const Monomio& m);
  friend Monomio operator+(const Monomio& x, const Monomio& y);
  friend Monomio operator-(const Monomio& x, const Monomio& y);
  friend Monomio operator*(const Monomio& x, const Monomio& y);
  Monomio& operator+=(const Monomio& p);
};

#endif