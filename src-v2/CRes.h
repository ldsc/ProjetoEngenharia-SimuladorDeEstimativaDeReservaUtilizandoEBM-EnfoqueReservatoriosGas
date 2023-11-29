//Classe Base
//Classes Derivadas: CResGas e CResOil
#ifndef CRES_H
#define CRES_H

#include <vector>

class CRes
{
///Protected permite as classes derivadas usar os atributos declarados aqui
protected:                                           
///declarando vetor
std::vector<double> x;  //representa valores do eixo x que serao plotados no grafico   
std::vector<double> y;  //representa valores do eixo y que serao plotados no grafico 
std::vector<double> p;  //representa os valores de pressao                 
int n;

///Public permite que todas as classes possam acessar o pr�ximos m�todos
public:                                              
///Declara o m�todo virtual para que se possa ser feito o polimorfismo e assim redefinir o mesmo m�todo nas classes derivadas                        
virtual void Calc() = 0;
///metodo para pegar os valores de press�o
double P(int i)  const {return p[i];}
///metodo para pegar os valores do vetor de press�es
std::vector<double> P() const {return p;}
///metodo para pegar o valores de x
double X(int i)  const {return x[i];}
///metodo para pegar o valores do vetor das vari�veis x
std::vector<double> X() const {return x;}
///metodo para pegar o valores de y
double Y(int i)  const {return y[i];}
///metodo para pegar o valores do vetor das vari�veis y
std::vector<double> Y() const {return y;}
///metodo que pega o valor de n
int         N()       const {return n;}

///construtor default da classe
CRes() {}
};

#endif
