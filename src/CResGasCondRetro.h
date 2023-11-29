///Classe herdeira de CResGas para Reservatorio de Gas Condensado Retrogrado

#ifndef CRESGASCONDRETRO_H
#define CRESGASCONDRETRO_H

#include <cmath>
#include <iostream>
#include <vector>
#include "CResGas.h"

///Heranca Simples
class CResGasCondRetro: public CResGas
{
///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
///Declara os vetores que armazenam os valores para z de duas fases, saturacao de liquido condensado dentro do reservatorio, numero de mols de gas
//por volume unitario de fluido no reservatorio e numero de mols de liquido por volume unitario de fluido no reservatorio
       std::vector<double> z2f, sl, n1, n2;
///Declara a variável que representa o fator volume de formacao inicial do gas, temperatura do gas no reservatorio
//densidade do condensado no reservatorio, massa molecular do condensado no reservatorio
       double bgi, temp, dl, ml;
       
///Torna publico os proximos metodos
public:
///Declara o metodo calculo (polimorfismo)
void Calc();
///Declara o metodo para pegar os valores de z de duas fases
double Z2f(int i) const {return z2f[i];}
///Declara o metodo para pegar os valores de saturacao de liquido condensado dentro do reservatorio
double Sl(int i) const {return sl[i];}
///Declara o metodo para pegar os valores do numero de mols de gas por volume unitario de fluido no reservatorio
double N1(int i) const {return n1[i];}
///Declara o metodo para pegar os valores do numero de mols de liquido por volume unitario de fluido no reservatorio
double N2(int i) const {return n2[i];}
///Declara o metodo para pegar o valor inicial do fator volume de formacao
double Bgi() const {return bgi;}
///Declara o metodo para pegar o valor da temperatura no reservatorio
double Temp() const {return temp;}
///Declara o metodo para pegar a densidade do condensado no reservatorio
double Dl() const {return dl;}
///Declara o metodo para pegar a massa molecular do condensado no reservatorio
double Ml() const {return ml;}


///Construtor default da classe
CResGasCondRetro();
      
};
#endif
