/**
Having fun with multidimensinal arrays.
*/

#include <stdio.h>


/**
TODO: Dada uma matriz inteira Maxb, imprima o número de linhas e colunas 
nulas (apenas com valores zerados, matematicamente falando)
da matriz.
*/

#define ROWS_QTT 4
#define COLS_QTT 5

int main(){

	/*
	Dada uma matriz Amxm, imprima quantas vezes se repete cada valor.
	Should be a function like writeRepeatedValuesQtts(args).
	*/
	int matrix[ROWS_QTT][COLS_QTT] = {
		{2, 3, 18, 9, 8},
		{1, 15, 2, 9, 6},
		{3, 5, 100, 99, 77},
		{12, 10, 3, 7, 18}
	};

	int i, j, k;
	char hasFoundRepeteadValue; /* it's a flag! */

	int repetitions[ROWS_QTT * COLS_QTT][2]; /* r[0]: repeated number, r[1]: its repeated times */
	int repetitionsSize = 0; /* if C doesnt have dinamic sizes, I'll create my own */

	for (i = 0; i < ROWS_QTT; i++){
		for (j = 0; j < COLS_QTT; j++){

			hasFoundRepeteadValue = 0;


			/* has this value been stored previously?... */
			for (k = 0; k < repetitionsSize; k++){
				if (repetitions[k][0] == matrix[i][j]){
					/* ... yes! raise our flag and increase the repeated times quantity for this founded number */
					hasFoundRepeteadValue = 1;
					repetitions[k][1]++;
					break;
				}
			}

			if (!hasFoundRepeteadValue){
				/* ... no! so it's a new value, store it at a new position and increase the position quantity */ 
				repetitions[repetitionsSize][0] = matrix[i][j];
				repetitions[repetitionsSize][1] = 1;
				repetitionsSize++;
			}

		}

	}

	for(i = 0; i < repetitionsSize; i++){
		if (repetitions[i][1] > 1)
			printf("%d se repetiu %d vezes.\n", repetitions[i][0], repetitions[i][1]);
	}

    return 0;

}