#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEM 20


typedef enum Estado{
	
	E_Livre,
	E_Ocupado,

}Estado;

typedef struct Elemento{

	int chave;
	int valor;
	Estado estado;
	
}Elemento;

typedef struct HashTable{

	int qtd_col;
	int tam;
	Elemento *TH;

}HashTable;

HashTable *CriarTH(int tam);

int Hash1(int tam, int chave);
int Hash2(int tam, int chave);
int HashDupla(int tam, int h1, int h2, int k);

void InsereEmTH(HashTable *TH, int chave, int valor); 
void PreencheHash(HashTable *TH);
void ImprimirTH(HashTable *TH);
void ExecHashDuplaEA();


