///Classe herdeira de CResGas para Reservatorio de Gas Seco Sob Influxo de Agua

#ifndef CRESGASSECOINF_H
#define CRESGASSECOINF_H

#include <cmath>
#include <iostream>
#include "CResGas.h"

///Heranca Simples
class CResGasSecoInf: public CResGas
{
///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
///Declara os vetores que armazenam os valores de fator volume-formacao do gas e influxo de agua  
       std::vector<double> bg, we;
///Declara a variável que representa o fator volume-formacao inicial do gas
       double bgi;
       
///Torna publico os proximos metodos
public:
///Declara o metodo calculo (polimorfismo)
void Calc();
///Declara o metodo para pegar os valores do fator volume-formacao do gas
double Bg(int i) const {return bg[i];}
///Declara o metodo para pegar os valores de influxo de agua
double We(int i) const {return we[i];}
///Declara o metodo para pegar o valor inicial do fator volume-formacao
double Bgi() const {return bgi;}

///Construtor default da classe
CResGasSecoInf();
      
};
#endif
