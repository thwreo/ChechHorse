#ifndef __HORSE_C__
#define __HORSE_C__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tableC {
	int table[8][8];
	struct list *moves; 
} tableC;

typedef struct list {
	struct tableC *actual;
	struct list *next;
} list;

void copyTable(int table[8][8], int copy[8][8]) {
	for (int i = 0; i < 8; i++ )
		for (int j = 0; j < 8; j++)
			copy[i][j] = table[i][j];
}

tableC *initTable(int l, int c, tableC *start) {
	start = (tableC *)malloc(sizeof(tableC));
	int matrix[8][8] = {0};
	copyTable(matrix, start->table);
	start->moves = NULL;
	return start;
}

tableC *addMove(tableC *moment, tableC *new) {
	new = (tableC *)malloc(sizeof(tableC));
	copyTable(moment->table, new->table);
	new->moves = NULL;
	return new;
}

void allMoves(tableC *moment, int l, int c, int count) {
	moment->table[l][c] = count;

	if (l+2 < 8) {
		if (c-1 >= 0) {
			if (moment->table[l+2][c-1] == 0) {
				if (moment->moves == NULL) {
					moment->moves = (list *)malloc(sizeof(list));
					moment->moves->actual = addMove(moment, moment->moves->actual);
					moment->moves->next = NULL;
					allMoves(moment->moves->actual, l+2, c-1, count+1);	
				}
				else {
					list *aux = moment->moves;
					while (moment->moves->next)
						moment->moves = moment->moves->next;
					list *newL = (list *)malloc(sizeof(list));
					newL->actual = addMove(moment, newL->actual);
					newL->next = NULL;
					moment->moves->next = newL;
					allMoves(moment->moves->next->actual, l+2, c-1, count+1);
					moment->moves = aux;
				}
			}
		}
		if (c+1 < 8) {
			if (moment->table[l+2][c+1] == 0) {
				if (moment->moves == NULL) {
					moment->moves = (list *)malloc(sizeof(list));
					moment->moves->actual = addMove(moment, moment->moves->actual);
					moment->moves->next = NULL;
					allMoves(moment->moves->actual, l+2, c+1, count+1);	
				}
				else {
					list *aux = moment->moves;
					while (moment->moves->next)
						moment->moves = moment->moves->next;
					list *newL = (list *)malloc(sizeof(list));
					newL->actual = addMove(moment, newL->actual);
					newL->next = NULL;
					moment->moves->next = newL;
					allMoves(moment->moves->next->actual, l+2, c+1, count+1);
					moment->moves = aux;
				}
			}
		}
	}
	if (l-2 >= 0) {
		if (c-1 >= 0) {
			if (moment->table[l-2][c-1] == 0) {
				if (moment->moves == NULL) {
					moment->moves = (list *)malloc(sizeof(list));
					moment->moves->actual = addMove(moment, moment->moves->actual);
					moment->moves->next = NULL;
					allMoves(moment->moves->actual, l-2, c-1, count+1);	
				}
				else {
					list *aux = moment->moves;
					while (moment->moves->next)
						moment->moves = moment->moves->next;
					list *newL = (list *)malloc(sizeof(list));
					newL->actual = addMove(moment, newL->actual);
					newL->next = NULL;
					moment->moves->next = newL;
					allMoves(moment->moves->next->actual, l-2, c-1, count+1);
					moment->moves = aux;
				}
			}
		}
		if (c+1 < 8) {
			if (moment->table[l-2][c+1] == 0) {
				if (moment->moves == NULL) {
					moment->moves = (list *)malloc(sizeof(list));
					moment->moves->actual = addMove(moment, moment->moves->actual);
					moment->moves->next = NULL;
					allMoves(moment->moves->actual, l-2, c+1, count+1);	
				}
				else {
					list *aux = moment->moves;
					while (moment->moves->next)
						moment->moves = moment->moves->next;
					list *newL = (list *)malloc(sizeof(list));
					newL->actual = addMove(moment, newL->actual);
					newL->next = NULL;
					moment->moves->next = newL;
					allMoves(moment->moves->next->actual, l-2, c+1, count+1);
					moment->moves = aux;
				}
			}
		}
	}
	if (c+2 < 8) {
		if (l+1 < 8) {
			if (moment->table[l+1][c+2] == 0) {
				if (moment->moves == NULL) {
					moment->moves = (list *)malloc(sizeof(list));
					moment->moves->actual = addMove(moment, moment->moves->actual);
					moment->moves->next = NULL;
					allMoves(moment->moves->actual, l+1, c+2, count+1);	
				}
				else {
					list *aux = moment->moves;
					while (moment->moves->next)
						moment->moves = moment->moves->next;
					list *newL = (list *)malloc(sizeof(list));
					newL->actual = addMove(moment, newL->actual);
					newL->next = NULL;
					moment->moves->next = newL;
					allMoves(moment->moves->next->actual, l+1, c+2, count+1);
					moment->moves = aux;
				}
			}
		}
		if (l-1 >= 0) {
			if (moment->table[l-1][c+2] == 0) {
				if (moment->moves == NULL) {
					moment->moves = (list *)malloc(sizeof(list));
					moment->moves->actual = addMove(moment, moment->moves->actual);
					moment->moves->next = NULL;
					allMoves(moment->moves->actual, l-1, c+2, count+1);	
				}
				else {
					list *aux = moment->moves;
					while (moment->moves->next)
						moment->moves = moment->moves->next;
					list *newL = (list *)malloc(sizeof(list));
					newL->actual = addMove(moment, newL->actual);
					newL->next = NULL;
					moment->moves->next = newL;
					allMoves(moment->moves->next->actual, l-1, c+2, count+1);
					moment->moves = aux;
				}
			}
		}
	}
	if (c-2 >= 0) {
		if (l+1 < 8) {
			if (moment->table[l+1][c-2] == 0) {
				if (moment->moves == NULL) {
					moment->moves = (list *)malloc(sizeof(list));
					moment->moves->actual = addMove(moment, moment->moves->actual);
					moment->moves->next = NULL;
					allMoves(moment->moves->actual, l+1, c-2, count+1);	
				}
				else {
					list *aux = moment->moves;
					while (moment->moves->next)
						moment->moves = moment->moves->next;
					list *newL = (list *)malloc(sizeof(list));
					newL->actual = addMove(moment, newL->actual);
					newL->next = NULL;
					moment->moves->next = newL;
					allMoves(moment->moves->next->actual, l+1, c-2, count+1);
					moment->moves = aux;
				}
			}
		}
		if (l-1 >= 0) {
			if (moment->table[l-1][c-2] == 0) {
				if (moment->moves == NULL) {
					moment->moves = (list *)malloc(sizeof(list));
					moment->moves->actual = addMove(moment, moment->moves->actual);
					moment->moves->next = NULL;
					allMoves(moment->moves->actual, l-1, c-2, count+1);	
				}
				else {
					list *aux = moment->moves;
					while (moment->moves->next)
						moment->moves = moment->moves->next;
					list *newL = (list *)malloc(sizeof(list));
					newL->actual = addMove(moment, newL->actual);
					newL->next = NULL;
					moment->moves->next = newL;
					allMoves(moment->moves->next->actual, l-1, c-2, count+1);
					moment->moves = aux;
				}
			}
		}
	}
}

void printHorse(tableC *moment, int tab, FILE *file) {
	list *aux = moment->moves;
	while(aux) {
		for (int i = 0; i < 8; i++) {
			for (int t = 0 ; t < tab; t++) {
				fputs("\t", file);
			}
			for (int j = 0; j < 8; j++) {
				fprintf(file ,"%d ", aux->actual->table[i][j]);
			}
			fputs("\n", file);
		}
	}
}

void freeHorse(tableC *moment) {
	while (moment->moves) {
		list *aux = moment->moves;
		freeHorse(moment->moves->actual);
		moment->moves = moment->moves->next;
		free(aux->actual);
		free(aux);
	}
}

void horse(FILE *output) {
	tableC *start = NULL;

	int l, c;
	scanf("%d %d", &l, &c);

	start = initTable(l , c, start);

	allMoves(start, l, c, 1);

	for (int i = 0 ; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			fprintf(output, "%d ",start->table[i][j] );
		}
		fputs("\n", output);
	}

	printHorse(start, 1, output);

	freeHorse(start);
	free(start);
}

#endif