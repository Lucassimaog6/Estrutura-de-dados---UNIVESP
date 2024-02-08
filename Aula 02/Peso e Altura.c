#include <stdio.h>
#define alturaMaxima 225 

int main() {
	typedef struct {
		int peso;
		int altura;
	} PesoAltura;

	PesoAltura pessoa;
	pessoa.peso = 80;
	pessoa.altura = 180;

	printf("Peso %i, Altura %i\n", pessoa.peso, pessoa.altura);

	if (pessoa.altura > alturaMaxima) printf("Altuma maior q o limite permitido\n");
	else printf("Altura normal\n");
	
	return 0;
}

