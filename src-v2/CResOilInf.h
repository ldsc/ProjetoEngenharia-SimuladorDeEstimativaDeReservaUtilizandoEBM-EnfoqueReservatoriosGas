///Classe herdeira de CResGas para Reservatorio de Oleo Sob Influxo de Agua

#ifndef CRESOILINF_H
#define CRESOILINF_H

#include <cmath>
#include <iostream>
#include "CResOil.h"


///Herança Simples
class CResOilInf: public CResOil
{
///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
///Declara os vetores que armazenaram os valores de rp, rs, bg e we
       std::vector<double> we;
       std::vector<double> rp, rs, bg;
///declara os atributos que armazenaram os valores correspondentes a m, bgi, rsi
       double m, bgi, rsi;

///Torna puplico os proximos metodos       
public:
///Declara o metodo calculo (polimorfismo)
void Calc();
///Declara o metodo para pegar os valores de m
double M() const {return m;}
///Declara o metodo para pegar os valores de fotor volume de formacao do gas inicial
double Bgi() const {return bgi;}
///Declara o metodo para pegar os valores de rasao de solubilidade inicial
double Rsi() const {return rsi;}
///Declara o metodo para pegar os valores do volume do influxo dagua
double We(int i) const {return we[i];}
///Declara o metodo para pegar os valores de rp
double Rp(int i) const {return rp[i];}
///Declara o metodo para pegar os valores de rasao de solubilidade
double Rs(int i)  const {return rs[i];}
///Declara o metodo para pegar os valores de bg
double Bg(int i)  const {return bg[i];}

///Construtor default da classe
CResOilInf();
};
#endif
