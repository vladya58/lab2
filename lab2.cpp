#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<time.h>
#include<string.h>
void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}

}

void qs(int* items, int left, int right) //вызовфункции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;


	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);

}


/* сравнениедвухцелых */
int comp(const void* i, const void* j) {

	return(int)i - (int)j;
}
void mas(int n, double** ar, int b) {


	//srand(time(NULL));
	int* a1, * a2, * a3, * a4, * a5;
	int m = 0;
	double t;

	a1 = (int*)malloc(n * sizeof(int));
	a2 = (int*)malloc(n * sizeof(int));
	a3 = (int*)malloc(n * sizeof(int));
	a4 = (int*)malloc(n * sizeof(int));
	a5 = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) { //случайныйнаборзначений
		a1[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++) { //возрастающая последовательность чисел
		a2[i] = i;
	}
	for (int i = n; i > 0; i--) {//убывающаяпоследовательностьчисел
		a3[i] = i;
	}
	for (int i = 0; i < n; i++) { //первая половина которого возроставет, а вторая убывает
		if (i < n / 2) {
			a4[i] = i;
			//printf("%d\n", a4[i]);
		}
		else {
			a4[i] = i - m;
			m = m + 2;
			//printf("%d\n", a4[i]);

		}
	}
	//СортировкаШелла
	memcpy(a5, a1, n);
	time_t start = clock();
	shell(a5, n);
	time_t stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 3][0] = t;
	printf("Время выполнения сортировки Шелла со случайным набором значений массива %fl\n", t);
	//fprintf(f1, "Сортировка Шелла:\n");
	//fprintf(f1, "1) %fl\n", t);

	memcpy(a5, a2, n);
	start = clock();
	shell(a5, n);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 3][1] = t;
	printf("Время выполнения сортировки Шелла c возрастающей последовательностью чисел %fl\n", t);
	//fprintf(f1, "2) %fl\n", t);

	memcpy(a5, a3, n);
	start = clock();
	shell(a5, n);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 3][2] = t;
	printf("Время выполнения сортировки Шелла c убывающей последовательностью чисел %fl\n", t);
	//fprintf(f1, "3) %fl\n", t);
	memcpy(a5, a4, n);
	start = clock();
	shell(a5, n);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 3][3] = t;
	printf("Время выполнения сортировки Шелла первая половина которого возроставет, а вторая убывает %fl\n", t);
	//fprintf(f1, "4) %fl\n", t);
	printf("***********\n");

	// Быстрая сортировка
	//fprintf(f1, "Быстрая сортировка:\n");
	memcpy(a5, a1, n);
	start = clock();
	qs(a5, 0, n - 1);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 2][0] = t;

	printf("Время выполнения быстрой сортировки со случайным набором значений массива %fl\n", t);
	//fprintf(f1, "1) %fl\n", t);
	memcpy(a5, a2, n);
	start = clock();
	qs(a5, 0, n - 1);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 2][1] = t;

	printf("Время выполнения быстрой сортировки c возрастающей последовательностью чисел %fl\n", t);
	//fprintf(f1, "2) %fl\n", t);
	memcpy(a5, a3, n);
	start = clock();
	qs(a5, 0, n - 1);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 2][2] = t;
	printf("Время выполнения быстрой сортировки c убывающей последовательностью чисел %fl\n", t);
	//fprintf(f1, "3) %fl\n", t);
	memcpy(a5, a4, n);
	start = clock();
	qs(a5, 0, n - 1);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 2][3] = t;
	printf("Время выполнения быстрой сортировки первая половина которого возроставет, а вторая убывает %fl\n", t);
	//fprintf(f1, "4) %fl\n", t);


	//стандартной функции qsort
	printf("***********\n");
	//fprintf(f1, "Стандартной функции qsort\n");
	memcpy(a5, a1, n);
	start = clock();
	qsort(a5, n, sizeof(int), comp);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 1][0] = t;
	printf("Время выполнения стандартной функции qsort со случайным набором значений массива %fl\n", t);
	//fprintf(f1, "1) %fl\n", t);
	memcpy(a5, a2, n);
	start = clock();
	qsort(a5, n, sizeof(int), comp);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 1][1] = t;

	printf("Время выполнения стандартной функции qsort c возрастающей последовательностью чисел %fl\n", t);
	//fprintf(f1, "2) %fl\n", t);
	memcpy(a5, a3, n);
	start = clock();
	qsort(a5, n, sizeof(int), comp);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 1][2] = t;
	printf("Время выполнения стандартной функции qsort c убывающей последовательностью чисел %fl\n", t);
	//fprintf(f1, "3) %fl\n", t);
	memcpy(a5, a4, n);
	start = clock();
	qsort(a5, n, sizeof(int), comp);
	stop = clock();
	t = (stop - start) / 1000.0;
	ar[b - 1][3] = t;
	printf("Время выполнения стандартной функции qsort первая половина которого возроставет, а вторая убывает %fl\n", t);
	//fprintf(f1, "4) %fl\n", t);
}


int main() {
	system("chcp 1251");
	system("cls");
	FILE* f1;
	int n = 0, arr, m = 4, c, b = 0, z = 0, j = 0, g = 0;
	double** a;
	double** bb;
	int* aa;
	double v;
	char f[] = "REZ.txt";
	f1 = fopen(f, "w");
	printf("Кол-во:");
	scanf_s("%d", &arr);
	c = arr * 3;
	g = 12;
	a = (double**)malloc(c * sizeof(double*));
	bb = (double**)malloc(g * sizeof(double*));
	aa = (int*)malloc(arr * sizeof(int*));
	for (int i = 0; i < c; i++) {
		a[i] = (double*)malloc(m * sizeof(double));
	}
	for (int i = 0; i < g; i++) {
		bb[i] = (double*)malloc(arr * sizeof(double));
	}

	for (int i = 0; i < arr; i++) {
		b = b + 3;
		printf("Введите размер массива\n");
		scanf_s("%d", &n);
		aa[i] = n;
		mas(n, a, b);


	}
	for (int i = 0; i < arr; i++) {
		fprintf(f1, "    %d", aa[i]);
	}
	fprintf(f1, "%\n");
	for (int i = 0; i < arr; i++) {
		for (int k = 0; k < g; k++) {

			bb[k][i] = a[z][j];

			if (j < m) {
				j++;
			}
			else {
				j = 0;
				if (z != c - 1) {
					z++;
				}
			}
			if (j == 4) {
				j = 0;
				if (z != c - 1) {
					z++;
				}
			}

		}
	}

	for (int i = 0; i < g; i++) {
		for (int k = 0; k < arr; k++) {

			fprintf(f1, "    %lf", bb[i][k]);
		}
		fprintf(f1, "%\n");
	}



}
