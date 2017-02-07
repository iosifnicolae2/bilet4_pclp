#include<stdio.h>
void citire(int &n, int *&tab) {
	int i;
	printf("Introdu dimensiunea tabloului");
	scanf("%d", &n);
	tab = new int[n];
	for (i = 0; i < n; i++) {
		printf("tab[%d]=", i);
		scanf("%d", tab+i);
	}

}
int cautare(int *tab,int nr_comp, int val) {

	for (int i = 0; i < nr_comp; i++) {
		if (val == tab[i])
			return 1;

	}
	return 0;
}
void concatenare(int *t1, int *t2, int *&t3, int nr1, int nr2, int *nr3) {
	int i;
	t3 = new int[nr1 + nr2];
	for (i = 0; i < nr1; i++) {
		t3[i] = t1[i];
	}
	for (i = 0; i < nr2; i++) {
		t3[nr1 + i] = t2[i];
	}
	*nr3 = nr1 + nr2;
}

void afisare(int *tab, int nr_comp) {
	int i;
	for (i = 0; i < nr_comp; i++) {
        //Am mutat if-ul mai sus ca sa puna spatiu corect..
        if (i % 5 == 0)
            printf("\n");
		printf("%d ", tab[i]);
	}
}


int main()
{
	int *a, *b, *c;
	int na, nb,*nc;
	a = new int[1];
	b = new int[1];
	c = new int[1];


	na = 0;
	nb = 0;
	nc = new int;

	int nr=0;
	citire(na, a);
	citire(nb, b);
	for (int i = 0; i < na; i++) {

		if (cautare(b, nb, a[i]) == 1)
			printf("%d a fost gasit in b\n",a[i]);
		nr++;
	}
	printf("Numarul de elemente prezente in b din a: %d\n", nr);
	concatenare(a, b, c, na, nb, nc);

	afisare(c,*nc);


    return 0;
}