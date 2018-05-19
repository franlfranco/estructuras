#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include <conio.h>
#include "malloc.h"
const int columna=30;

typedef struct{
   int  matricula;
   char nombre[30];
   char sexo;
}alumno;

void cargar_matricula(alumno a[],int pos){
   printf("Ingrese Numero de matricula\n");
   fflush(stdin);
   scanf("%d",&a[pos].matricula);
}

void cargar_nombre(alumno a[],int pos){
   printf("Ingrese Nombre del alumno\n");
   fflush(stdin);
   scanf("%s",a[pos].nombre);
}

void cargar_sexo(alumno a[],int pos){
   char control='n';
   while(control=='n'){
      printf("Ingrese Sexo m/f\n");
      fflush(stdin);
      scanf("%c",&a[pos].sexo);
      if(a[pos].sexo=='m' || a[pos].sexo=='f'){
         control='s';
      }else{
         printf("Ingreso mal el sexo\n");
      }
   }
}

int cargar(alumno a[]){
   char control='s';
   int i=0;
   while(control=='s'&&i<columna){
      cargar_matricula(a,i);
      cargar_nombre(a,i);
      cargar_sexo(a,i);
      printf("Si quiere cargar otro alumno oprime 's'\n");
      fflush(stdin);
      scanf("%c",&control);
      i++;
   }
   return i;
}

int busca_matricula(alumno a[],int validos,int n){
   // Si encuentra el dato devuelve la posiccion, sino devuelve -1.
   int pos=-1;
   int i=0;
   while(i<validos && pos==-1){
      if(a[i].matricula==n){
         pos=i;
      }
      i++;
   }
   return pos;
}

void show(alumno a[],int validos){
   for(int i=0;i<validos;i++){
      printf("Nombre :       %s\n",a[i].nombre);
      printf("La matricula : %d\n",a[i].matricula);
      printf("Sexo :         %c\n",a[i].sexo);
      printf("\n");
   }
}

void encontrar_nombre(alumno a[],int validos,int b){
   int pos=busca_matricula(a,validos,b);
   if (pos!=-1){
      printf("Se encontro la matricula:%d\n",a[pos].matricula);
      printf("Nombre :       %s\n",a[pos].nombre);
      printf("Sexo :         %c\n",a[pos].sexo);
      printf("\n");
   }else{
      printf("La matricula %d, no se encuentra registrada\n",b);
   }
}

int posicion_menor(alumno a[],int cant,int desde){
    int pos=desde;
    for (int i=desde;i<cant;i++){
      if(strcmp(a[pos].nombre,a[i].nombre)>0){
         pos=i;
      }
    }
    return pos;
}

void ordenar_x_nombre(alumno a[],int cant){ //Punto 11 parte 1
    int pos,mat;
    char s;
    char aux[20];
    for (int i=0;i<cant;i++){
      pos=posicion_menor(a,cant,i);
      strcpy(aux,a[i].nombre);
      strcpy(a[i].nombre,a[pos].nombre);
      strcpy(a[pos].nombre,aux);
      mat=a[i].matricula;
      a[i].matricula=a[pos].matricula;
      a[pos].matricula=mat;
      s=a[i].sexo;
      a[i].sexo=a[pos].sexo;
      a[pos].sexo=s;
    }
}

int posicion_menor_matricula(alumno a[],int cant,int desde){
    int pos=desde;
    for (int i=desde;i<cant;i++){
      if((a[pos].matricula>a[i].matricula)){
         pos=i;
      }
    }
    return pos;
}

void ordenar_x_matricula(alumno a[],int cant){ //Punto 11 parte 1
    int pos,mat;
    char s;
    char aux[20];
    for (int i=0;i<cant;i++){
      pos=posicion_menor_matricula(a,cant,i);
      strcpy(aux,a[i].nombre);
      strcpy(a[i].nombre,a[pos].nombre);
      strcpy(a[pos].nombre,aux);
      mat=a[i].matricula;
      a[i].matricula=a[pos].matricula;
      a[pos].matricula=mat;
      s=a[i].sexo;
      a[i].sexo=a[pos].sexo;
      a[pos].sexo=s;
    }
}

int main() {
   alumno a[20];
   int validos=0,mat=0;
   //cargar
   validos=cargar(a);
   //buscar matricula n
   printf("Ingrese la matricula a buscar\n");
   scanf("%d",&mat);
   encontrar_nombre(a,validos,mat);
   // Ordena alfabeticamente los alumnos.
   ordenar_x_nombre(a,validos);
   printf("Alumnos en orden por nombre\n");
   show(a,validos);
   // Ordena por matricula
   ordenar_x_matricula(a,validos);
   printf("Alumnos en orden por matricula\n");
   show(a,validos);
   return 0;
}
