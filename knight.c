#include <stdio.h>


void printTable(int table[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (table[i][j] >= 10)
				printf("%d  ",table[i][j] );
			else
				printf("%d   ",table[i][j] );
		}	
		printf("\n");
	}
	printf("\n");
}

void knight(int table[8][8],int v[65], int lc[8], int cc[8], int count, int l, int c) {
	if (count < 64) {
		table[l][c] = count;
		//printf("%d\n",count );
		//printf("%d\n",v[count] );
		//printTable(table);
		int k = 0;
		while (v[count] < 8 && k == 0) {
			if (0 <= l+lc[v[count]] && 8 > l+lc[v[count]] && 0 <= c+cc[v[count]] && 8 > c+cc[v[count]]) {
				if (table[l+lc[v[count]]][c+cc[v[count]]] == 0) {
					k = 1;
				}
			}
			if (k == 0) {
				v[count] = v[count] + 1;
			}
		}
		//printf("%d\n",v[count] );
		//printf("%d\n",k );
		//printf("\n");
		if (k == 1) {
			count = count + 1;
			knight(table, v, lc, cc, count, l+lc[v[count-1]], c+cc[v[count-1]]);
		}
		else {
			v[count] = 0;
			table[l][c] = 0;
			count = count - 1;
			v[count] = v[count] + 1;
			knight(table, v, lc, cc, count, l-lc[v[count]-1], c-cc[v[count]-1]);
		}
	}
	else {
		table[l][c] = count;
	}
}


int main() {
	int table[8][8] = {0};
	int v[65] = {0};
	int lc[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
	int cc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
	int l, c;
	int count = 1;

	scanf("%d %d", &l, &c);
	
	//for (int i = 0; i < 64; i++)
	//	printf("%d ",v[i] );
	knight(table, v, lc, cc, count, l, c);
	
	//printTable(table);
	
	return 0;
}