
void print_number_table(short row, short col) {
	for (int k = 1; k <= col; k++) printf("**");
	printf("*\n");
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) printf("|%d", rand() % 10);
		printf("|\n");
		if (i != row) {
			printf("|");
			for (int k = 1; k < col; k++) printf("-+");
			printf("-|\n");
		}
		else {
			for (int k = 1; k < 2 * (col + 1); k++) printf("*");
		}
	}
	printf("\n");
	printf("done");
}

void write_nils_to_head_file(const char* full_name, int N) {
	FILE *myfile;
	myfile = fopen(full_name, "w");
	for (int i = 1; i <= N; i++) fprintf(myfile, "%2x", 0x00);
	fclose(myfile);
	printf("done\n");
}

void write_ones_to_tail_file(const char* full_name, int N) {
	FILE *myfile;
	myfile = fopen(full_name, "a");
	for (int i = 1; i <= N; i++) fprintf(myfile, "%2x", 0xff);
	fclose(myfile);
	printf("done\n");
}

int read_i_string_from_file(const char* full_name, int i, char* out_str, int max_size) {
	FILE *myfile;
	char str;
	myfile = fopen(full_name, "r");
	for (int j = 1; j <= i; j++) {
		str = fgetc(myfile);
		while (str != '\n') {
			if (str == EOF) return 0;
			str = fgetc(myfile);
		}
	}
	out_str[0] = fgetc(myfile);
	for (int i = 1; i < max_size; i++) {
		out_str[i] = fgetc(myfile);
		if (out_str[i] == '\n') {
			out_str[i] = '\0';
			return i;
		}
	}
	out_str[max_size] = '\0';
	printf("done\n");
	return max_size;
}

void TEST_memcpy_and_memset(void) {
	int* int_arr;
	double* dbl_arr;
	char* char_arr;
	char* buf;
	int_arr = (int*)malloc(40 * sizeof(int));
	dbl_arr = (double*)malloc(20 * sizeof(double));
	char_arr = (char*)malloc(80 * sizeof(char));
	buf = (char*)malloc(80 * sizeof(char));
	memset(char_arr, 0x01, 80);
	memset(dbl_arr, 0x00, 20 * sizeof(double));
	for (int i = 0; i <= 40; i++) int_arr[i] = 1;
	for (int i = 0; i <= 9; i++) printf("%d ", int_arr[i]);
	printf("\n");
	for (int i = 0; i <= 9; i++) printf("%c ", char_arr[i]);
	printf("\n");
	for (int i = 0; i <= 9; i++) printf("%f ", dbl_arr[i]);
	printf("\n \n");
	memcpy(buf, char_arr, 80);
	memcpy(char_arr, int_arr, 80);
	memcpy(int_arr, dbl_arr, 80);
	memcpy(dbl_arr, buf, 80);
	for (int i = 0; i <= 9; i++) printf("%d ", int_arr[i]);
	printf("\n");
	for (int i = 0; i <= 9; i++) printf("%c ", char_arr[i]);
	printf("\n");
	for (int i = 0; i <= 9; i++) printf("%f ", dbl_arr[i]);
	printf("\n");
	printf("done\n");
}

void test_read_i_string_from_file(void) {
	char* testbuf = (char*)malloc(30 * sizeof(char));
	read_i_string_from_file("ctask", 3, testbuf, 30);
	printf("%s\n", testbuf);
	free(testbuf);
	testbuf = (char*)malloc(3 * sizeof(char));
	read_i_string_from_file("ctask", 3, testbuf, 3);
	printf("%s\n", testbuf);
	read_i_string_from_file("ctask", 20, testbuf, 3);
	printf("%s\n", testbuf);
	free(testbuf);
	printf("done\n");
}
