#include "hash.h"

//Hash1 h1(chave,tam) = (chave*1/3)%tam
//Hash2 h2(chave,tam) = [(chave + 1)%7] +1
//Em caso de colisão => HD(h1,h2,K) = [h2*k + h1 + k]%tam
int Hash1(int tam, int chave){

	return (int)((chave*1/3)%tam);
}

int Hash2(int tam, int chave){

	return ((chave+1)%7)+1;
}

int HashDupla(int tam, int h1, int h2, int k){

	return (h2*k + h1 + k)%tam;
}

HashTable *CriarTH(int tam){
	
	HashTable *aux;

	aux = malloc(sizeof(HashTable)); //Aloca a tabela
	aux->tam = tam;
	aux->qtd_col = 0;
	aux->TH = malloc(sizeof(Elemento) * tam);// Aloca espaco para os elementos

	for(int i = 0; i < tam; i++){

		aux->TH[i].estado = E_Livre; //Coloca todas as posicoes como livre

	}

	printf("\n-------> Tabela Hash de %d posicoes criada!\n\n", tam);

	return aux;
}

void InsereEmTH(HashTable *TH, int chave, int valor){

	int p, p_inicial, k;
	int h1, h2;
	k = 0;
	
	h1 = Hash1(TH->tam, chave);
	h2 = Hash2(TH->tam, chave);
	p = p_inicial = HashDupla(TH->tam,h1,h2,k);

	while(TH->TH[p].estado == E_Ocupado){

		//Se for igual a chave
		if(TH->TH[p].chave == chave){

			printf("Chave %d já se encontra na tabela!\n",chave);

			break;
		
		}else if((TH->TH[p].chave != chave) && (TH->TH[p].estado == E_Ocupado)){

			printf("Chave %d colidiu na posição %d\n",chave,p);

		}

		k++;
		TH->qtd_col++;
		p = HashDupla(TH->tam, h1, h2, k);

		if(p == p_inicial){

			printf("Tabela toda percorrida! Não foi possivel inserir a chave %d\n", chave);

			break;

		}
	}

	//Insere!
	TH->TH[p].chave = chave;
	TH->TH[p].estado = E_Ocupado;
	TH->TH[p].valor = valor;
}


void ImprimirTH(HashTable *TH){


	for(int i = 0; i < TH->tam; i++){

		char e = TH->TH[i].estado == E_Ocupado ? 'O' : (TH->TH[i].estado == E_Livre ? 'L' : 'A');

		printf("Posição %d --> Chave: %d # %c\n",i, TH->TH[i].chave, e);

	}

	printf("\nPara inserir todos os elementos nesta tabela\nHouve %d colisões\n\n", TH->qtd_col);

}


void PreencheHash(HashTable *TH){

	int chave;
	
	srand(time(0));
	for(int i = 0; i < MAX_ELEM; i++){
		
		chave = rand() % 100;

		InsereEmTH(TH, chave, chave);

		//ImprimirTH(TH);

	}

}

void ExecHashDuplaEA(){

	HashTable *TH;
	
	TH = CriarTH(41);

	PreencheHash(TH);

	printf("\n");
	ImprimirTH(TH);
}




