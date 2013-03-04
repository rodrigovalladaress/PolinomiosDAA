#include "Polinomio.cc"
#include "PolinomioMultClasica.cc"
#include "PolinomioMultDivideYVenceras.cc"
#include "tiempo.cc"
class Prueba {
private:
  long long tiempo;
  long long sumaTiempos;
  int numeroPruebas;
  int tamProblema;
  
public:
  void pruebasMultClasica(void);
  void pruebasDivideYVenceras(void);
  
  Prueba(int, int);
  void setNumeroPruebas(int);
  void setTamProblema(int);
  void recalcularSumaTiempos(long long);
  void clearSumaTiempos(void);
  int getNumeroPruebas(void);
  int getTamProblema(void);
  long long getSumaTiempos(void);
  double getMediaTiempo(void);
};