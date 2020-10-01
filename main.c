#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

int main(int argc, char *argv[]) {
	if (argc == 2) {
		FILE *output = fopen(argv[1], "w");

		horse(output);

		fclose(output);
	}

	return 0;
}