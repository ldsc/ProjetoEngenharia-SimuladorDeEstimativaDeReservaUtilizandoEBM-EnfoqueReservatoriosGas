///Classe Derivada de CRes
///Possui os dados iniciais de Reservatorio de Gas
///Classes Derivadas: CGasSecoPres, CResGasSecoInf, CResGasSecoInfPotAquifer, CResGasSecoInfSchilthuis,CResGasCondNaoRetro e CResGasCondRetro

#ifndef CRESGAS_H
#define CRESGAS_H

#include <iostream>
#include <cmath>
#include <vector>
#include "CRes.h"

///Heranca Simples
class CResGas: public CRes
{
///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
///Declara o vetor que armazena o volume de gas produzido                        
std::vector<double> gp;
///Declara o vetor que armazena o fator de compressibilidade do gas
std::vector<double> z;
///Torna publico os proximos metodos
public:
///Declara o metodo calculo (polimorfismo)
virtual void Calc();
///Declara o metodo para pegar os valores de gas produzido
double Gp(int i) const {return gp[i];}
///Declara o metodo para pegar os valores do fator de compressibilidade
double Z(int i)  const {return z[i];}

///Construtor default da classe
CResGas();
};

#endif
