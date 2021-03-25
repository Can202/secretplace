//multiplos xD
#include <stdio.h>
int main (){
	int n,aux,n2,a;
	printf("Di un numero: ");
	scanf("%i",&n);
	n2 = n;
	printf("Cuantos Multiplos: ");
	scanf("%i",&a);
	printf("%i, ",n);
	for(aux = 1; aux < a; aux++){
		n = n + n2;
		printf("%i, ",n);
	}
	printf("etc. \n\n\n\n\n\n\n\n");
	system("pause");
	system("cls");
	return 0;
}
