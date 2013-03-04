#include "Prueba.h"
void Prueba::pruebasMultClasica(void) {
  clearSumaTiempos();
  for(int i = 0; i < getNumeroPruebas(); i++) {
    PolinomioMultClasica pol1(getTamProblema());
    PolinomioMultClasica pol2(getTamProblema());
    cronomilisec(1);
    pol1.mult(pol2);
    recalcularSumaTiempos(cronomilisec(0));
  }
}

void Prueba::pruebasDivideYVenceras(void) {
  clearSumaTiempos();
  for(int i = 0; i < getNumeroPruebas(); i++) {
    PolinomioMDV pol1(getTamProblema());
    PolinomioMDV pol2(getTamProblema());
    cronomilisec(1);
    pol1.mult(pol2);
    recalcularSumaTiempos(cronomilisec(0));
  }
}

Prueba::Prueba(int numPruebas, int tamProblema) {
  srand(time(NULL));
  clearSumaTiempos();
  setNumeroPruebas(numPruebas);
  setTamProblema(tamProblema);
}

void Prueba::setNumeroPruebas(int nPruebas) {
  numeroPruebas = nPruebas;
}

void Prueba::setTamProblema(int tProblema) {
  tamProblema = tProblema;
}

void Prueba::recalcularSumaTiempos(long long tiempo) {
  sumaTiempos += tiempo; 
}

void Prueba::clearSumaTiempos(void) {
  sumaTiempos = 0;
}

int Prueba::getNumeroPruebas(void) {
  return numeroPruebas;
}

int Prueba::getTamProblema(void) {
  return tamProblema;
}

long long Prueba::getSumaTiempos(void) {
  return sumaTiempos;
}

double Prueba::getMediaTiempo(void) {
  return (double)getSumaTiempos() / (double)getNumeroPruebas();
}