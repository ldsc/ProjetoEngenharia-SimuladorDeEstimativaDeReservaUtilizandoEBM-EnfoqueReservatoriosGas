///Classe herdeira de CResGas para Reservatorio com o modelo de influxo Pot Aquifer

#ifndef CRESGASSECOINFPOTAQUIFER_H
#define CRESGASSECOINFPOTAQUIFER_H
#include <cmath>
#include<vector>
#include <iostream>
#include "CResGas.h"


///Heranca Simples
class CResGasSecoInfPotAquifer: public CResGas
{
      ///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
	  //Declara a variavel que representa o valor do influxo e do fator volume formacao do gas
          std::vector<double> we, bg;
          //Declara a variavel que representa o fator volume formacao inicial do gas
          double bgi;
	  //Declara a variavel que representa a porosidade do aquifero
          double fi;
          //Declara a variavel que representa a altura do aquifero
          double h;
          //Declara a variavel que representa o raio do aquifero
          double re;
          //Declara a variavel que representa o raio do reservatorio
          double ro;
          //Declara a variavel que representa a compressibilidade da água
          double cw;
          //Declara a variavel que representa a compressibilidade  dos poros
          double cf;
          //Declara a variavel que representa a diferenca de pressao delta p
          std::vector<double> deltap;

          
          ///Torna publico os proximos metodos
public:
	///Declara o metodo calculo (polimorfismo)
		void Calc();
       
       ///Declara o metodo para pegar os valores da porosidade do aquifero
	   double Fi () const {return fi;}

	 ///Declara o metodo para pegar os valores da porosidade do aquifero
	   double Bgi () const {return bgi;}
	
	///Declara o metodo para pegar o valor da altura do aquifero
	   double H () const {return h;}
	   
       ///Declara o metodo para pegar os valores do raio do aquifero
       double Re () const {return re;}
       
       ///Declara o metodo para pegar os valores do raio do reservatorio
       double Ro () const {return ro;}
       
       ///Declara o metodo para pegar os valores da compressibilidade da agua
       double Cw () const {return cw;}
       
       ///Declara o metodo para pegar os valores da compressibilidade dos poros
       double Cf () const {return cf;}
       
       ///Declara o metodo para pegar os valores do deltap
       double Deltap (int i) const {return deltap[i];}
       
       ///Declara o metodo para pegar os valores do influxo
      double We (int i) const {return we[i];}

	///Declara o metodo para pegar os valores do fator volume formacao do gas
       double Bg (int i) const {return bg[i];}
      
///Construtor default da classe
CResGasSecoInfPotAquifer();

};

#endif
          
          
