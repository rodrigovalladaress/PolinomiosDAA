#include "Monomio.h"
Monomio::Monomio(void) {
  setCoeficiente(0);
  setExponente(1);
  setVariable(VARIABLE_POR_DEFECTO);
}

Monomio::Monomio(int coef, int exp) {
  setCoeficiente(coef);
  setExponente(exp);
  setVariable(VARIABLE_POR_DEFECTO);
}

Monomio::Monomio(int coef) {
  setCoeficiente(coef);
  setExponente(0);
  setVariable(VARIABLE_POR_DEFECTO);
}

Monomio::Monomio(int coef, int exp, char var) {
  setCoeficiente(coef);
  setExponente(exp);
  setVariable(var);
}

int Monomio::evaluar(int valor) const {
  return getCoeficiente() * pow(valor, getExponente());
}

int Monomio::getCoeficiente() const {
  return coeficiente;
}

int Monomio::getExponente() const {
  return exponente;
}

char Monomio::getVariable(void) const {
  return variable;
}

void Monomio::setCoeficiente(int coef) {
  coeficiente = coef;
}

void Monomio::setExponente(int exp) {
  exponente = exp;
}

void Monomio::setVariable(int var) {
  variable = var;
}

Monomio Monomio::mult(const Monomio& m) {
  Monomio resultado;
  return resultado;
}

ostream& operator<<(ostream & out, const Monomio& m) {
  string exponenteString;
  ostringstream convertir;
  if(m.getCoeficiente() != 0) {
    if(m.getCoeficiente() < 0) {
      out << "- ";
      out << abs(m.getCoeficiente());
    }
    else
      out << "+ " << m.getCoeficiente();
    if(m.getExponente() != 0) {
      out << m.getVariable();
      convertir << m.getExponente();
      exponenteString = convertir.str();
      for(unsigned i = 0; i < exponenteString.size(); i++) {
	switch(exponenteString.at(i)) {
	  case '0': if(exponenteString.size() > 1) out << "⁰"; break;
	  case '1': if(exponenteString.size() > 1) out << "¹"; break;
	  case '2': out << "²"; break;
	  case '3': out << "³"; break;
	  case '4': out << "⁴"; break;
	  case '5': out << "⁵"; break;
	  case '6': out << "⁶"; break;
	  case '7': out << "⁷"; break;
	  case '8': out << "⁸"; break;
	  case '9': out << "⁹"; break;
	}
      }
    }
  }
  return out;
}

Monomio operator+(const Monomio& x, const Monomio& y) {
  Monomio resultado;
  resultado.setCoeficiente(x.getCoeficiente() + y.getCoeficiente());
  resultado.setExponente(x.getExponente());
  resultado.setVariable(x.getVariable());
  return resultado;
}

Monomio operator-(const Monomio& x, const Monomio& y) {
  Monomio resultado;
  resultado.setCoeficiente(x.getCoeficiente() - y.getCoeficiente());
  resultado.setExponente(x.getExponente());
  resultado.setVariable(x.getVariable());
  return resultado;
}

Monomio operator*(const Monomio& x, const Monomio& y) {
  Monomio resultado;
  resultado.setCoeficiente(x.getCoeficiente() * y.getCoeficiente());
  resultado.setExponente(x.getExponente() + y.getExponente());
  resultado.setVariable(x.getVariable());
  return resultado;
}

Monomio& Monomio::operator+=(const Monomio& p) {
  setCoeficiente(getCoeficiente() + p.getCoeficiente());
  return *this;
}