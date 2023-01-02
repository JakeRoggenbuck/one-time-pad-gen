#include "termcolor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS 5
#define COLS 5

void help() { printf("Usage: otpg [rows]\n\n"); }

void panic() {
    help();
    exit(1);
}

void error(char *msg) {
    cprint("ERROR: ", FG_RED);
    printf(msg);
    panic();
}

void warn(char *msg) {
    cprint("WARN: ", FG_YELLOW);
    printf(msg);
}

void generate(int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLS; ++j) {
            for (int k = 0; k < WORDS; ++k) {
                int v = rand() % 26;
                printf("%c ", (char)(v + 65));
            }
            printf(" ");
        }
        printf("\n");
    }
}

int get_seed() {
	int val;
	FILE *fp;

	fp = fopen("/dev/urandom", "rb");
	fread(&val, sizeof(int), 1, fp);
	fclose(fp);

	return val;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		error("Too few arguments.\n");
	}

	if (argc > 2) {
		error("Too many arguments.\n");
	}

	int rows = atoi(argv[1]);

	int seed = get_seed();
	srand(time(NULL) * seed);

	generate(rows);

	return 0;
}
