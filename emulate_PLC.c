/*Solo queda que en la función void make_doc(int check_function, int check_data, int data_integer, double data_float, char* string_data)
de la línea #109 cambiar la extensión de los archivos, para que en lugar de crear .txt, cree .dat, además en la variable global total_items
se define la cantidad de items a crear para cada uno de los documentos*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

char* tiempo_de_funcionamiento;
double metros_de_papel_aluminio_procesados, galones_depegamento_usado, galones_de_aceite_lubricante_usado_por_la_maquinaria, metros_de_papel_usado, temperatura_de_sellado;
double metros_de_plastico_usado, galones_de_agua_ocupados, toneladas_de_copos_de_papa_utilizadas, toneladas_de_maicena_utilizadas, temperatura_de_cohesion, galones_de_aceite_usado;
double toneladas_de_saborizante_rociado, presion_de_rodillos, metros_de_aluminio_utilizado;
int numero_de_tubos_procesados, numero_de_tubos_de_papa_finales, total_items=10000;

#define BILLION  1000000000L

long random_nseconds(){
	long nseconds;
	struct timespec start, stop;

	if(clock_gettime(CLOCK_REALTIME, &start)==-1){
		perror("clock gettime");
		exit(EXIT_FAILURE);
	}
	if(clock_gettime(CLOCK_REALTIME, &stop)==-1){
		perror("clock gettime");
		exit(EXIT_FAILURE);
	}
	nseconds=stop.tv_nsec-start.tv_nsec/BILLION;
	return nseconds;
}

int random_integer(int sup){
	int aux_integer;
	long nano_seconds;
	nano_seconds=random_nseconds();
	srand(nano_seconds);
	aux_integer=rand()%sup;
	return aux_integer;
}


char random_time_aux(int inf, int sup){
	char return_;
	int aux_integer, sum;
	long nano_seconds;
	sum=inf+sup;
	nano_seconds=random_nseconds();
	srand(nano_seconds);
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
	aux_character=random_time_aux(0,5);
	*aux_string=aux_character;
	aux_string++;
	aux_character=random_time_aux(0,9);
	*aux_string=aux_character;
	aux_string++;
	*aux_string='\0';
	return aux_string1;
}

double random_float(int limite){
	char *aux_string=(char*) malloc(sizeof(char)), *aux_string1=(char*) malloc(sizeof(char)), aux_character;
	double return_;
	aux_string1=aux_string;
	int aux_integer, i, j;
	long nano_seconds;
	nano_seconds=random_nseconds();
	srand(nano_seconds);
	for(i=0;i<2;i++){
		for(j=0;j<limite;j++){
			aux_integer=rand()%9;
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
			fichero3=fopen("DEP3.txt","a");
			if(fichero3==NULL){fputs("File error\n", stderr); exit(1);}
			fputs(string_data,fichero3);
			fputs("  ",fichero3);
			fclose(fichero3);
			break;
			case 2:
			fichero3=fopen("DEP3.txt","a");
			if(fichero3==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux3,"%.2f",data_float);
			fputs(string_aux3,fichero3);
			fputs("  ",fichero3);
			fclose(fichero3);
			break;
			case 3:
			fichero3=fopen("DEP3.txt","a");
			if(fichero3==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux3,"%.2f",data_float);
			fputs(string_aux3,fichero3);
			fputs("  ",fichero3);
			fclose(fichero3);
			break;
			case 4:
			fichero3=fopen("DEP3.txt","a");
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
			fichero4=fopen("DEP4.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 2:
			fichero4=fopen("DEP4.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 3:
			fichero4=fopen("DEP4.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 4:
			fichero4=fopen("DEP4.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 5:
			fichero4=fopen("DEP4.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 6:
			fichero4=fopen("DEP4.txt","a");
			if(fichero4==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux4,"%.2f",data_float);
			fputs(string_aux4,fichero4);
			fputs("  ",fichero4);
			fclose(fichero4);
			break;
			case 7:
			fichero4=fopen("DEP4.txt","a");
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
			fichero5=fopen("DEP5.txt","a");
			if(fichero5==NULL){fputs("File error\n", stderr); exit(1);}
			sprintf(string_aux5,"%.2f",data_float);
			fputs(string_aux5,fichero5);
			fputs("  ",fichero5);
			fclose(fichero5);
			break;
			case 2:
			fichero5=fopen("DEP5.txt","a");
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
	pthread_mutex_t mutex_first_function;
	int total_items_first, counter_items_first;
	pthread_mutex_unlock(&mutex_first_function);
	total_items_first=total_items;
	pthread_mutex_lock(&mutex_first_function);
	while(counter_items_first<total_items_first){
		pthread_mutex_unlock(&mutex_first_function);
		tiempo_de_funcionamiento=random_time();
		make_doc(1,1,0,0.0,tiempo_de_funcionamiento);
		metros_de_papel_aluminio_procesados=random_float(3);
		make_doc(1,2,0,metros_de_papel_aluminio_procesados,NULL);
		galones_depegamento_usado=random_float(2);
		make_doc(1,3,0,galones_depegamento_usado,NULL);
		galones_de_aceite_lubricante_usado_por_la_maquinaria=random_float(2);
		make_doc(1,4,0,galones_de_aceite_lubricante_usado_por_la_maquinaria,NULL);
		counter_items_first=counter_items_first+1;
		pthread_mutex_lock(&mutex_first_function);
	}
}

void* second_function(){
	pthread_mutex_t mutex_second_function;
	int total_items_second, counter_items_second;
	pthread_mutex_unlock(&mutex_second_function);
	total_items_second=total_items;
	pthread_mutex_lock(&mutex_second_function);
	while(counter_items_second<total_items_second){
		pthread_mutex_unlock(&mutex_second_function);
		tiempo_de_funcionamiento=random_time();
		make_doc(2,1,0,0.0,tiempo_de_funcionamiento);
		metros_de_papel_usado=random_float(4);
		make_doc(2,2,0,metros_de_papel_usado,NULL);
		numero_de_tubos_procesados=random_integer(2500);
		make_doc(2,3,numero_de_tubos_procesados,0.0,NULL);
		counter_items_second=counter_items_second+1;
		pthread_mutex_lock(&mutex_second_function);
	}
}

void* third_function(){
	pthread_mutex_t mutex_third_function;
	int total_items_third, counter_items_third;
	pthread_mutex_unlock(&mutex_third_function);
	total_items_third=total_items;
	pthread_mutex_lock(&mutex_third_function);
	while(counter_items_third<total_items_third){
		pthread_mutex_unlock(&mutex_third_function);
		tiempo_de_funcionamiento=random_time();
		make_doc(3,1,0,0.0,tiempo_de_funcionamiento);
		metros_de_papel_usado=random_float(4);
		make_doc(3,2,0,metros_de_papel_usado,NULL);
		temperatura_de_sellado=random_float(2);
		make_doc(3,3,0,temperatura_de_sellado,NULL);
		metros_de_plastico_usado=random_float(4);
		make_doc(3,4,0,metros_de_plastico_usado,NULL);
		counter_items_third=counter_items_third+1;
		pthread_mutex_lock(&mutex_third_function);
	}
}

void* fourth_function(){
	pthread_mutex_t mutex_fourth_function;
	int total_items_fourth, counter_items_fourth;
	pthread_mutex_unlock(&mutex_fourth_function);
	total_items_fourth=total_items;
	pthread_mutex_lock(&mutex_fourth_function);
	while(counter_items_fourth<total_items_fourth){
		pthread_mutex_unlock(&mutex_fourth_function);
		galones_de_agua_ocupados=random_float(3);
		make_doc(4,1,0,galones_de_agua_ocupados,NULL);
		toneladas_de_copos_de_papa_utilizadas=random_float(2);
		make_doc(4,2,0,toneladas_de_copos_de_papa_utilizadas,NULL);
		toneladas_de_maicena_utilizadas=random_float(2);
		make_doc(4,3,0,toneladas_de_maicena_utilizadas,NULL);
		presion_de_rodillos=random_float(2);
		make_doc(4,4,0,presion_de_rodillos,NULL);
		temperatura_de_cohesion=random_float(2);
		make_doc(4,5,0,temperatura_de_cohesion,NULL);
		galones_de_aceite_usado=random_float(3);
		make_doc(4,6,0,galones_de_aceite_usado,NULL);
		toneladas_de_saborizante_rociado=random_float(2);
		make_doc(4,7,0,toneladas_de_saborizante_rociado,NULL);
		counter_items_fourth=counter_items_fourth+1;
		pthread_mutex_lock(&mutex_fourth_function);
	}
}

void* fifth_function(){
	pthread_mutex_t mutex_fifth_function;
	int total_items_fifth, counter_items_fifth;
	pthread_mutex_unlock(&mutex_fifth_function);
	total_items_fifth=total_items;
	pthread_mutex_lock(&mutex_fifth_function);
	while(counter_items_fifth<total_items_fifth){
		pthread_mutex_unlock(&mutex_fifth_function);
		metros_de_aluminio_utilizado=random_float(3);
		make_doc(5,1,0,metros_de_aluminio_utilizado,NULL);
		numero_de_tubos_de_papa_finales=random_integer(5000);
		make_doc(5,2,numero_de_tubos_de_papa_finales,0.0,NULL);
		counter_items_fifth=counter_items_fifth+1;
		pthread_mutex_lock(&mutex_fifth_function);
	}
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
}

int main(int argc, char const *argv[]){
	launcher();
	return 0;
}