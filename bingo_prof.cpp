#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

const int NumLinhasCartao      = 5;
const int NumColunasCartao      = 5;
const int Numcolunaspainel     = 20;
const int Intervaloentrebolas  = 500000;
const int msgpause             =2000000;


int sorteados           = 0;
int numerosSorteado     = 0;
int anterior            = 0;


int numerodebolas, tiposorteio, numerodecartoes;

string red      ="\u001b[31m";
string blue     ="\u001b[34m";
string rgreen   ="\u001b[32m";
string reset    ="\u001b[0m";
string bold     ="\u001b[1m";



typedef struct {
    int numero;
    bool sorteado;
} bingoPanel;

bingoPanel bingo[] = {};
