#ifndef CREGLIN_H
#define CREGLIN_H

#include "CRes.h"

class CRegLin
{

///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
///declara o atributo "a" que corresponde ao coeficiente linear da reta	
       double a;
///Declara o atributo "b" que corresponde ao coeficiente angular da reta
       double b;
      
      double media, maximo, minimo;
///Public permite que todas as classes possam acessar o próximos métodos
public:
///Declara a regressao Linear feita pelo Metodo dos Mínimos Quadrados 
       void Reg(CRes*);
///Declara o metodo para pegar o valor de "a"       
       double A()       const {return a;}
///Declara o metodo para pegar o valor de "b"       
       double B()       const {return b;}
       
    //   double Media() const {return media;}
    
///Construtor default que inicializa a e b com valores iguais a zero
       CRegLin(): a(0.0), b(0.0) {}


 /*.........................................................*/       
       /*
       void Est(Cres*);
       double Media() const {return media;}
       double Maximo () const {return maximo;}
       double Minimo() const {return minimo;}
       */                                      

};


#endif
