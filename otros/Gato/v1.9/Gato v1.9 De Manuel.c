//Tre en raya para 2 jugadores
#include <stdio.h>
#include <windows.h>
int main(){
	char a1,a2,a3,a4,a5,a6,a7,a8,a9,X,O;
	int b1,b2,b3,b4,b5,b6,b7,b8,b9,g;
	g=0;
	X='0';
	O='0';
	a1='1';
	a2='2';
	a3='3';
	a4='4';
	a5='5';
	a6='6';
	a7='7';
	a8='8';
	a9='9';
	b1=0;
	b2=0;
	b3=0;
	b4=0;
	b5=0;
	b6=0;
	b7=0;
	b8=0;
			fflush(stdin);
	b9=0;
	system("pause");
	system("cls");
	while(g==0){
		printf("|%c|%c|%c|\n",a1,a2,a3);
		printf("|%c|%c|%c|\n",a4,a5,a6);
		printf("|%c|%c|%c|\n",a7,a8,a9);
		printf("Tu turno X: \n");
		fflush(stdin);
		scanf("%c",&X);
		printf("Tu turno O: \n");
		fflush(stdin);
		scanf("%c",&O);
		system("cls");
		if(X==a1){
			if(b1==0){
				a1='x';
				b1=1;
			}
		}
		else if(X==a2){
			if(b2==0){
				a2='x';
				b2=2;
			}
		}
		else if(X==a3){
			if(b3==0){
				a3='x';
				b3=2;
			}
		}
		else if(X==a4){
			if(b4==0){
				a4='x';
				b4=2;
			}
		}
		else if(X==a5){
			if(b5==0){
				a5='x';
				b5=2;
			}
		}
		else if(X==a6){
			if(b6==0){
				a6='x';
				b6=2;
			}
		}
		else if(X==a7){
			if(b7==0){
				a7='x';
				b7=2;
			}
		}
		else if(X==a8){
			if(b8==0){
				a8='x';
				b8=2;
			}
		}
		else if(X==a9){
			if(b9==0){
				a9='x';
				b9=2;
			}
		}
		if(O==a1){
			if(b1==0){
				a1='o';
				b1=1;
			}
		}
		else if(O==a2){
			if(b2==0){
				a2='o';
				b2=2;
			}
		}
		else if(O==a3){
			if(b3==0){
				a3='o';
				b3=2;
			}
		}
		else if(O==a4){
			if(b4==0){
				a4='o';
				b4=2;
			}
		}
		else if(O==a5){
			if(b5==0){
				a5='o';
				b5=2;
			}
		}
		else if(O==a6){
			if(b6==0){
				a6='o';
				b6=2;
			}
		}
		else if(O==a7){
			if(b7==0){
				a7='o';
				b7=2;
			}
		}
		else if(O==a8){
			if(b8==0){
				a8='o';
				b8=2;
			}
		}
		else if(O==a9){
			if(b9==0){
				a9='o';
				b9=2;
			}
		}
		if(a1=='x'&&a2=='x'&&a3=='x'){
			printf("Gano X.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a3=='x'&&a6=='x'&&a9=='x'){
			printf("Gano X.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a7=='x'&&a8=='x'&&a9=='x'){
			printf("Gano X.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a1=='x'&&a4=='x'&&a7=='x'){
			printf("Gano X.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a1=='x'&&a5=='x'&&a9=='x'){
			printf("Gano X.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a3=='x'&&a5=='x'&&a7=='x'){
			printf("Gano X.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a2=='x'&&a5=='x'&&a8=='x'){
			printf("Gano X.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a4=='x'&&a5=='x'&&a6=='x'){
			printf("Gano X.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a1=='o'&&a2=='o'&&a3=='o'){
			printf("Gano O.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a3=='o'&&a6=='o'&&a9=='o'){
			printf("Gano O.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a7=='o'&&a8=='o'&&a9=='o'){
			printf("Gano O.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a1=='o'&&a4=='o'&&a7=='o'){
			printf("Gano O.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a1=='o'&&a5=='o'&&a9=='o'){
			printf("Gano O.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a2=='o'&&a5=='o'&&a8=='o'){
			printf("Gano O.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a4=='o'&&a5=='o'&&a6=='o'){
			printf("Gano O.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
		else if(a1!='1' && a2!='2' && a3!='3' && a4!='4' && a5!='5' && a6!='6' && a7!='7' && a8!='8' && a9!='9'){
			printf("Empate.\n");
			g=1;
			printf("|%c|%c|%c|\n\r",a1,a2,a3);
			printf("|%c|%c|%c|\n\r",a4,a5,a6);
			printf("|%c|%c|%c|\n\r",a7,a8,a9);
		}
	}
	system ("pause");
	return 0;
}
