//Lo dela boleta

#include <stdio.h>

typedef struct{
	int cantidad,codigo,precio,total;
}producto;

int main(){
	int f1,f2,aux,continuar,descuento,descuento2,DW;
	producto leche,pan,jugo,flan,yogurt,cereal,aceite,harina;
	
	DW=1;
	do{
		f1=0;
		continuar=0;
		
		leche.codigo=1;
		pan.codigo=2;
		jugo.codigo=3;
		flan.codigo=4;
		yogurt.codigo=5;
		cereal.codigo=6;
		aceite.codigo=7;
		harina.codigo=8;
		
		leche.cantidad=0;
		pan.cantidad=0;
		jugo.cantidad=0;
		flan.cantidad=0;
		yogurt.cantidad=0;
		cereal.cantidad=0;
		aceite.cantidad=0;
		harina.cantidad=0;
		
		leche.precio=700;
		pan.precio=1200;
		jugo.precio=1000;
		flan.precio=350;
		yogurt.precio=1250;
		cereal.precio=1220;
		aceite.precio=1090;
		harina.precio=520;
		
		//Inicio de los datos
		printf("La leche(1) cuesta 700, el kilo de pan(2) cuesta 1200, el jugo(3) cuesta 1000 y el flan(4) cuesta 350. \n");
		printf("El yogurt(5) cuesta 1250, el cereal(6) cuesta 1220, el aceite(7) cuesta 1090 y la harina(8) cuesta 520. \n");
		printf("Promocion: 2x1 en Leche.\n");
		system("pause");
		system("cls");
		
		while(f1<1){
			printf ("Inserte codigo: ");
			fflush(stdin);
			scanf ("%i",&aux);
			switch (aux){
				case 1:{
					leche.cantidad++;
					break;
				}
				case 2:{
					pan.cantidad++;
					break;
				}
				case 3:{
					jugo.cantidad++;
					break;
				}
				case 4:{
					flan.cantidad++;
					break;
				}
				case 5:{
					yogurt.cantidad++;
					break;
				}
				case 6:{
					cereal.cantidad++;
					break;
				}
				case 7:{
					aceite.cantidad++;
					break;
				}
				case 8:{
					harina.cantidad++;
					break;
				}
				default:{
					printf ("El numero dado no existe. \n");
					break;
				}
			}
			printf("Dar otro codigo(1 si, 2 no): ");
			scanf("%i",&continuar);
			if(continuar==2){
				f1++;
			}else if (continuar>2){
				printf("No diste 1 o 2.");
			system ("pause");
			}
			system("cls");
		}
			
		//Descuento
		int total;
		
		descuento = leche.cantidad/2;
		leche.total = leche.precio * leche.cantidad;
		descuento2 = leche.precio * descuento;
		leche.total = leche.total - descuento2;
		pan.total = pan.precio * pan.cantidad;
		jugo.total = jugo.precio * jugo.cantidad;
		flan.total = flan.precio * flan.cantidad;
		yogurt.total = yogurt.precio * yogurt.cantidad;
		cereal.total = cereal.precio * cereal.cantidad;
		aceite.total = aceite.precio * aceite.cantidad;
		harina.total = harina.precio * harina.cantidad;
		
		total = leche.total + pan.total;
		total = total + jugo.total;
		total = total + flan.total;
		total = total + yogurt.total;
		total = total + cereal.total;
		total = total + aceite.total;
		total = total + harina.total;
		
		//Pago
		int EFECTIVO,vuelto;
		
		printf("(%i)\nCuanto paga? ",total);
		scanf("%i",&EFECTIVO);
		
		vuelto = EFECTIVO - total;
		//Boleta
		system("cls");
		printf("Recuerda que hay descuento.\n");
		Sleep(1000);
		printf("Producto | Cantidad | Precio (Precio total) | Codigo.\n");
		Sleep(1000);
		if ( leche.cantidad > 0 ){
			printf("Leche | %i | 700 (%i) | 1.\n",leche.cantidad,leche.total);
			Sleep(1000);
		}
		if ( pan.cantidad > 0 ){
			printf("Kilo de Pan | %i | 1200 (%i) | 2.\n",pan.cantidad,pan.total);
			Sleep(1000);
		}
		if ( jugo.cantidad > 0 ){
			printf("Jugo | %i | 1000 (%i) | 3.\n",jugo.cantidad,jugo.total);
			Sleep(1000);
		}
		if ( flan.cantidad > 0 ){
			printf("Flan | %i | 350 (%i) | 4.\n",flan.cantidad,flan.total);
			Sleep(1000);
		}
		if ( yogurt.cantidad > 0 ){
			printf("Yogurt | %i | 1250 (%i) | 5.\n",yogurt.cantidad,yogurt.total);
			Sleep(1000);
		}
		if ( cereal.cantidad > 0 ){
			printf("Cereal | %i | 1220 (%i) | 6.\n",cereal.cantidad,cereal.total);
			Sleep(1000);
		}
		if ( aceite.cantidad > 0 ){
			printf("Aceite | %i | 1090 (%i) | 7.\n",aceite.cantidad,aceite.total);
			Sleep(1000);
		}
		if ( harina.cantidad > 0 ){
			printf("Harina | %i | 520 (%i) | 8.\n",harina.cantidad,harina.total);
			Sleep(1000);
		}
		printf("Descuento: %i. \n",descuento2);
		Sleep(1000);
		printf("Total: %i. \n",total);
		Sleep(1000);
		printf("Efectivo: %i. \n",EFECTIVO);
		Sleep(1000);
		printf("Vuelto: %i. \n",vuelto);
		Sleep(1000);
		system("pause");
		system("cls");
		printf("Cerrar(1) o no cerrar(otro numero): ");
		scanf("%i",&DW);
		system("cls");
	}while(DW==1);
	system("pause");
	return 0;
}
