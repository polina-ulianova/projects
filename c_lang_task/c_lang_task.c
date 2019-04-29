
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "c_lang_task.h"

int main() {
	int N2, N3, col, row;
	printf("Vvedite dannye dla 1 zadaniya ");
	scanf("%d%d", &col, &row);
	print_number_table(col, row);
	printf("Vvedite dannye dla 2 zadaniya ");
	scanf("%d", &N2);
	write_nils_to_head_file("task23", N2);
	printf("Vvedite dannye dla 3 zadaniya ");
	scanf("%d", &N3);
	write_ones_to_tail_file("task23", N3);
	TEST_memcpy_and_memset();
	TEST_read_i_string_from_file();
	system("pause");
	return 0;
}
