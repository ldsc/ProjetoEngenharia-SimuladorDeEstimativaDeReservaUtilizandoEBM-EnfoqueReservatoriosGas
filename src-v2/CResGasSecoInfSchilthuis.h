///Classe herdeira de CResGas para Reservatorio com o modelo de influxo Schilthuis

#ifndef CRESGASSECOINFSCHILTHUIS_H
#define CRESGASSECOINFSCHILTHUIS_H
#include <cmath>
#include <iostream>
#include <vector>
#include "CResGas.h"


///Heranca Simples
class CResGasSecoInfSchilthuis: public CResGas
{
      ///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
	  //Declara a variavel que representa o valor do influxo e do fator volume formacao do gas
          std::vector<double> we, bg;
          //Declara a variavel que representa a diferenca de pressao delta p
          std::vector<double> deltap;
          //Declara a variavel que representa o fator volume formacao inicial do gas
          double bgi;
          //Declara a variavel que representa a constante de influxo
          double j;
          //Declara a variavel que representa os valores de t1 e t2 = limites fixos de integracao
          double t1, t2;
          
          ///Torna publico os proximos metodos
public:
      
	///Declara o metodo calculo (polimorfismo)
		void Calc();

	///Declara o metodo para pegar o valor do fator volume formacao inicial do gas
	   double Bgi () const {return bgi;}
	   

	///Declara o metodo para pegar o valor da constante de influxo
	   double J () const {return j;}
	   

	///Declara o metodo para pegar o valor do limite fixo de integracao t1
	   double T1 () const {return t1;}
	   

	///Declara o metodo para pegar o valor do limite fixo de integracao t2
	   double T2 () const {return t2;}
	   
       
    ///Declara o metodo para pegar os valores do deltap
       double Deltap (int i) const {return deltap[i];}
       
       ///Declara o metodo para pegar os valores do influxo
      double We (int i) const {return we[i];}

	///Declara o metodo para pegar os valores do fator volume formacao do gas
       double Bg (int i) const {return bg[i];}
       
     
       
///Construtor default da classe
CResGasSecoInfSchilthuis();

};

#endif
          
         
