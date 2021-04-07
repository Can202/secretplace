/*SecretPlace v1.5*/
#include <stdio.h>
int loop(char v[10][20],int *AV);
void mod(char v[10][20],char *move,int *pX,int *pY,int *PV,int *j,int *g,int *AYUD,int *V);
void LS(int *l,int *k);
int probar(char v[10][20],int *V,int l,int k,int pY,int pX);
void uptade();
void draw(char v[10][20],int *V);
void intro(char v[10][20],int pY,int pX,int *V);
int main(){
	char v[10][20];
	int s,OV,N,g;
	int AV;
	OV=1;
	N=0;
	AV=3;
	s=3;
	printf("Eres nivel %i.\n",N);
	system("pause");
	system("cls");
	do{
		g=loop(v,&AV);
		s=4;
		system("cls");
		if(g==3){
			N++;
			if(AV<100){
				AV+=3;
			}
			printf("Eres nivel %i.\n",N);
		}
		else{
			printf("Fuiste nivel %i, pero ahora ",N);
			N=0;
			AV=3;
			printf("eres nivel %i.\n",N);
		}
		system("pause");
		system("cls");
		if(N==100){
			printf("Felicidades llegaste al nivel 100, es el mejor nivel, presumelo, Empezaras de cero.");
			N=0;
			system("pause");
		}
		while(s==4){
			system("cls");
			printf("2 y despues intro para continuar.\n3 y despues intro para salir.\n");
			fflush(stdin);
			scanf("%i",&s);
			if(s==2){
				OV=2;
				if(g!=3){
					s=3;
				}
			}
			else if(s==3){
				OV=3;
			}
			else{
				s=4;
			}
			system("cls");
		}
	}while(OV==2);
	system("pause");
	return 0;
}
int loop(char v[10][20],int *AV){
	int g,pY,pX,j;
	int PV,V;
	int l,k;
	int AYUD;
	char move;
	V=*AV;
	g=0;
	pY=7;
	pX=9;
	intro(v,pY,pX,&V);
	LS(&l,&k);
	do{
		draw(v,&V);
		PV=0;
		move=getch();
		mod(v,&move,&pX,&pY,&PV,&j,&g,&AYUD,&V);
		if(AYUD==1){
			g=probar(v,&V,l,k,pY,pX);
		}
		if(V<=0){
			g=2;
		}
	}while(g==0);
	draw(v,&V);
	if(g==1){
		printf("Abandonaste la partida.\n");
	}
	else if(g==2){
		printf("Perdiste.\n");
	}
	else if(g==3){
		printf("Ganaste.\n");
	}
	*AV=V;
	system("pause");
	return g;
}
void mod(char v[10][20],char *move,int *pX,int *pY,int *PV,int *j,int *g,int *AYUD,int *V){
	int D;
	if(*move=='a'||*move=='A'){
			if(*pX>3){
				v[*pY][*pX]=' ';
				v[*pY][*pX+1]=' ';
				*pX-=6;
				*PV=1;
			}
		}
		if(*move=='d'||*move=='D'){
			if(*pX<15){
				v[*pY][*pX]=' ';
				v[*pY][*pX+1]=' ';
				*pX+=6;
				*PV=1;
			}
		}
		else if(*move=='w'||*move=='W'){
			if(*pX==9){
				if(*pY>1){
					v[*pY][*pX]=' ';
					v[*pY][*pX+1]=' ';
					v[*pY+1][*pX]=' ';
					v[*pY+1][*pX+1]=' ';
					*pY-=2;
					*PV=1;
				}
			}
		}
		else if(*move=='s'||*move=='S'){
			if(*pX==9){
				if(*pY<7){
					v[*pY][*pX]=' ';
					v[*pY][*pX+1]=' ';
					v[*pY+1][*pX]=' ';
					v[*pY+1][*pX+1]=' ';
					*pY+=2;
					*PV=1;
				}
			}
		}
		for(D=9;D<=10;D++){
			v[*pY+1][D]='-';
		}
		v[*pY][*pX]='c';
		v[*pY][*pX+1]=':';
		if(*PV==1){
			*AYUD=1;
		}
		else{
			*AYUD=0;
		}
		if(*move=='f'||*move=='F'){
			*g=1;
		}
		uptade();
		if(*V==0){
			*g=2;
		}
}
void LS(int *l,int *k){
	srand(time(NULL));
	int i;
	i=rand()%7;
	switch(i){
		case 0:{
			*l=1;
			*k=3;
			break;
		}
		case 1:{
			*l=3;
			*k=3;
			break;
		}
		case 2:{
			*l=5;
			*k=3;
			break;
		}
		case 3:{
			*l=7;
			*k=3;
			break;
		}
		case 4:{
			*l=1;
			*k=15;
			break;
		}
		case 5:{
			*l=3;
			*k=15;
			break;
		}
		case 6:{
			*l=5;
			*k=15;
			break;
		}
		case 7:{
			*l=7;
			*k=15;
			break;
		}
	}
}
int probar(char v[10][20],int *V,int l,int k,int pY,int pX){
	if(v[1][9]==' '&&v[3][9]==' '&&v[5][9]==' '&&v[7][9]==' '){
		if(v[l][k]=='c'){
			return 3;
		}
		else{
			*V-=1;
		}
	}
	return 0;
}
void uptade(){
	system("cls");
}
void draw(char v[10][20],int *V){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
			printf("%c",v[i][j]);
		}
		printf("\n");
	}
	printf("VIDAS %i.\nControles:\nW para subir.\nS para bajar.\nA Izquierda.\nD Derecha.\nF Abandonar.\nInstrucciones:\nEncontrar el lugar secreto el\ncual es elegido al azar.\nPrueba tu suerte eligiedo 3 lugares\nporque cada vez que lleges a un\nlugar incorrecto perderas una vida.\nDe Manuel Gonzalez.\n",*V);
}
void intro(char v[10][20],int pY,int pX,int *V){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
			if(i==0||i==9){
				v[i][j]='-';
			}
			else if(j==0||j==19){
				v[i][j]='|';
			}
			else{
				v[i][j]=' ';
			}
		}
	}
	for(j=9;j<=10;j++){
		v[pY+1][j]='-';
	}
	for(i=8;i>=2;i-=2){
		for(j=1;j<=5;j++){
			v[i][j]='=';
		}
		for(j=14;j<=18;j++){
			v[i][j]='=';
		}
	}
	v[pY][pX]='c';
	v[pY][pX+1]=':';
}
