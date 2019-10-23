#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

//Poner extensión de archivo como DEPx.dat
char* TIEMPO_DE_FUNCIONAMIENTO;
double METROS_DE_PAPEL_ALUMINIO_PROCESADOS, GALONES_DE_PEGAMENTO_USADO, GALONES_DE_ACEITE_LUBRICANTE_USADO_POR_LA_MAQUINARIA, METROS_DE_PAPEL_USADO, TEMPERATURA_DE_SELLADO;
double METROS_DE_PLASTICO_USADO, GALONES_DE_AGUA_OCUPADOS, TONELADAS_DE_COPOS_DE_PAPA_UTILIZADAS, TONELADAS_DE_MAICENA_UTILIZADAS, TEMPERATURA_DE_COHESION, GALONES_DE_ACEITE_USADO;
double TONELADAS_DE_SABORIZANTE_ROCIADO, TONELADAS_DE_COPOS_DE_PAPA_UTILIZADAS, PRESION_DE_RODILLOS, METROS_DE_ALUMINIO_UTILIZADO;
int NUMERO_DE_TUBOS_PROCESADOS, NUMERO_DE_TUBOS_DE_PAPA_FINALES;

int random_integer(int sup){
	int aux_integer;
	time_t t;
	srand(time(&t));
	aux_integer=rand()%sup;
	return aux_integer;
}

char random_time_aux(int inf, int sup){
	char return_;
	int aux_integer, sum;
	sum=inf+sup;
	time_t t;
	srand(time(&t));
	aux_integer=rand()%sum;
	return_='0'+aux_integer;
	return return_;
}
char *random_time(){
	char *aux_string=(char*) malloc(sizeof(char)), *aux_string1=(char*) malloc(sizeof(char)), aux_character;
	aux_string1=aux_string;
	aux_character=random_time_aux(0,2);
	*aux_string=aux_character;
	aux_string++;
	aux_character=random_time_aux(0,9);
	*aux_string=aux_character;
	aux_string++;
	*aux_string=':';
	aux_string++;
	aux_character=random_time_aux(0,5);
	*aux_string=aux_character;
	aux_string++;
	aux_character=random_time_aux(0,9);
	*aux_string=aux_character;
	aux_string++;
	*aux_string=':';
	aux_string++;
	sleep(1);
	aux_character=random_time_aux(0,5);
	*aux_string=aux_character;
	aux_string++;
	aux_character=random_time_aux(0,9);
	*aux_string=aux_character;
	return aux_string1;
}

double random_float(int limite){
	char *aux_string=(char*) malloc(sizeof(char)), *aux_string1=(char*) malloc(sizeof(char)), aux_character;
	double return_;
	aux_string1=aux_string;
	int aux_integer, i, j;
	time_t t;
	srand(time(&t));
	for(i=0;i<2;i++){
		for(j=0;j<limite;j++){
			aux_integer=rand()%1,9;
			aux_character='0'+aux_integer;
			*aux_string=aux_character;
			aux_string++;
		}
		if(i==0){
			*aux_string='.';
			aux_string++; 
		}
	}
	return_=atof(aux_string1);
	return return_;
}

void make_doc(int check_function, int check_data, int data_integer, double data_float, char* string_data){
	FILE *fichero1, *fichero2, *fichero3, *fichero4, *fichero5;
	char string_aux1[15], string_aux2[15], string_aux3[15], string_aux4[15], string_aux5[15];
	switch(check_function){
		case 1: 
		switch(check_data){
			case 1:
			fichero1=fopen("DEP1.txt","a");
			if(fichero1==NULL){fputs("File error\n", stderr); exit(1);}
			fputs(string_data,fichero1);
			fputs("  ",fichero1);
			fclose(fichero1);
			break;
			case 2:
			fichero1=fopen("DEP1.txt","a");
			if(fichero1==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux1,"%.2f",data_float);
			fputs(string_aux1,fichero1);
			fputs("  ",fichero1);
			fclose(fichero1);
			break;
			case 3:
			fichero1=fopen("DEP1.txt","a");
			if(fichero1==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux1,"%.2f",data_float);
			fputs(string_aux1,fichero1);
			fputs("  ",fichero1);
			fclose(fichero1);
			break;
			case 4:
			fichero1=fopen("DEP1.txt","a");
			if(fichero1==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux1,"%.2f",data_float);
			fputs(string_aux1,fichero1);
			fputs("\n",fichero1);
			fclose(fichero1);
			break;
		}
		break;
		case 2:
		switch(check_data){
			case 1:
			fichero2=fopen("DEP2.txt","a");
			if(fichero2==NULL){fputs("File error\n", stderr); exit(1);}
			fputs(string_data,fichero2);
			fputs("  ",fichero2);
			fclose(fichero2);
			break;
			case 2:
			fichero2=fopen("DEP2.txt","a");
			if(fichero2==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux2,"%.2f",data_float);
			fputs(string_aux2,fichero2);
			fputs("  ",fichero2);
			fclose(fichero2);
			break;
			case 3:
			fichero2=fopen("DEP2.txt","a");
			if(fichero2==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux2,"%d",data_integer);
			fputs(string_aux2,fichero2);
			fputs("\n",fichero2);
			fclose(fichero2);
			break;
		}
		break;
		case 3:
		switch(check_data){
			case 1:
			fichero3=fopen("DEP2.txt","a");
			if(fichero3==NULL){fputs("File error\n", stderr); exit(1);}
			fputs(string_data,fichero3);
			fputs("  ",fichero3);
			fclose(fichero3);
			break;
			case 2:
			fichero3=fopen("DEP2.txt","a");
			if(fichero3==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux3,"%.2f",data_float);
			fputs(string_aux3,fichero3);
			fputs("  ",fichero3);
			fclose(fichero3);
			break;
			case 3:
			fichero3=fopen("DEP2.txt","a");
			if(fichero3==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux3,"%.2f",data_float);
			fputs(string_aux3,fichero3);
			fputs("  ",fichero3);
			fclose(fichero3);
			break;
			case 4:
			fichero3=fopen("DEP2.txt","a");
			if(fichero3==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux3,"%.2f",data_float);
			fputs(string_aux3,fichero3);
			fputs("\n",fichero3);
			fclose(fichero3);
			break;
		}
		break;
		case 4:
		switch(check_data){
			case 1:
			fichero4=fopen("DEP3.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 2:
			fichero4=fopen("DEP3.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 3:
			fichero4=fopen("DEP3.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 4:
			fichero4=fopen("DEP3.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 5:
			fichero4=fopen("DEP3.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 6:
			fichero4=fopen("DEP3.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 7:
			fichero4=fopen("DEP3.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("\n",fichero4);
			fclose(fichero4);
			break;
		}
		break;
		case 5:
		switch(check_data){
			case 1:
			fichero5=fopen("DEP3.txt","a");
			if(fichero5==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux5,"%.2f",data_float);
			fputs(string_aux5,fichero5);
			fputs("  ",fichero5);
			fclose(fichero5);
			break;
			case 2:
			fichero5=fopen("DEP3.txt","a");
			if(fichero5==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux5,"%d",data_integer);
			fputs(string_aux5,fichero5);
			fputs("\n",fichero5);
			fclose(fichero5);
			break;
		}
		break;
	}
}

void* first_function(){
	//while(){
		TIEMPO_DE_FUNCIONAMIENTO=random_time();
		make_doc(1,1,NULL,NULL,TIEMPO_DE_FUNCIONAMIENTO);
		METROS_DE_PAPEL_ALUMINIO_PROCESADOS=random_float(3);
		make_doc(1,2,NULL,METROS_DE_PAPEL_ALUMINIO_PROCESADOS,NULL);
		GALONES_DE_PEGAMENTO_USADO=random_float(2);
		make_doc(1,3,NULL,GALONES_DE_PEGAMENTO_USADO,NULL);
		GALONES_DE_ACEITE_LUBRICANTE_USADO_POR_LA_MAQUINARIA=random_float(2);
		make_doc(1,4,NULL,GALONES_DE_ACEITE_LUBRICANTE_USADO_POR_LA_MAQUINARIA,NULL);
	//}
}

void* second_function(){
	TIEMPO_DE_FUNCIONAMIENTO=random_time();
	make_doc(2,1,NULL,NULL,TIEMPO_DE_FUNCIONAMIENTO);
	METROS_DE_PAPEL_USADO=random_float(4);
	make_doc(2,2,NULL,METROS_DE_PAPEL_USADO,NULL);
	NUMERO_DE_TUBOS_PROCESADOS=random_integer(2500);
	make_doc();
	//printf("%i\n",NUMERO_DE_TUBOS_PROCESADOS);
}

void* third_function(){
	TIEMPO_DE_FUNCIONAMIENTO=random_time();
	METROS_DE_PAPEL_USADO=random_float(4);
	TEMPERATURA_DE_SELLADO=random_float(2);
	METROS_DE_PLASTICO_USADO=random_float(4);
}

void* fourth_function(){
	GALONES_DE_AGUA_OCUPADOS=random_float(3);
	TONELADAS_DE_COPOS_DE_PAPA_UTILIZADAS=random_float(2);
	TONELADAS_DE_MAICENA_UTILIZADAS=random_float(2);
	PRESION_DE_RODILLOS=random_float(2);
	TEMPERATURA_DE_COHESION=random_float(2);
	GALONES_DE_ACEITE_USADO=random_float(3);
	TONELADAS_DE_SABORIZANTE_ROCIADO=random_float(2);
}

void* fifth_function(){
	METROS_DE_ALUMINIO_UTILIZADO=random_float(3);
	NUMERO_DE_TUBOS_DE_PAPA_FINALES=random_integer(5000);
}

void launcher(){
	pthread_t hilos[5];
	pthread_create(&hilos[0], NULL, (void*)first_function, NULL);
	pthread_create(&hilos[1], NULL, (void*)second_function,NULL);
	pthread_create(&hilos[2], NULL, (void*)third_function, NULL);
	pthread_create(&hilos[3], NULL, (void*)fourth_function, NULL);
	pthread_create(&hilos[4], NULL, (void*)fifth_function, NULL);
	pthread_join(hilos[0], NULL);
	pthread_join(hilos[1], NULL);
	pthread_join(hilos[2], NULL);
	pthread_join(hilos[3], NULL);
	pthread_join(hilos[4], NULL);
	/*first_function();
	second_function();
	third_function();
	fourth_function();
	fifth_function();*/	
}

int main(int argc, char const *argv[]){
	launcher();
	return 0;
}