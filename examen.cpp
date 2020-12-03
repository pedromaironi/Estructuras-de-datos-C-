/*
UNIVERSIDAD TECNOLÓGICA DE PUEBLA
PROGRAMA PARA ORDENAR NUMEROS EN FORMA
ASCENDENTE O DESCENDENTE, POR MEDIO
DEL MÉTODO DE LA BURBUJA
BORLAND C++
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <cstring.h>

int main (int argc, char *argv[])
{
        int numeros[9]; // Diez numeros
        int i,j,temp;
        char opc;
    do{
        clrscr();
        printf("\n1. Ordenar Numeros Forma Ascendente  ");
        printf("\n2. Ordenar Numeros Forma Descendente ");
        printf("\n\nDigite Opcion :");
        opc=getch();
        switch (opc)
              {
                case '1':
                      for(i=0; i<10;i++)
                      {
                       printf("\nnumero[%d] = ",i+1);scanf("%d",&numeros[i]);
                      }
                      printf("\nNumeros Ordenados Forma Ascendente ");
                       for (i=0;i<10;i++)   // Metdodo Burbuja
                       {
                         for(j=i+1;j<10;j++)
                         {
                          if(numeros[j]<numeros[i])
                           {
                             temp=numeros[j];
                             numeros[j]=numeros[i];
                             numeros[i]=numeros[j];
                             numeros[i]=temp;
                           }
                         }
                       }
                       for(i=0;i<10;i++)
                       {
                         printf("\n %d",numeros[i]);
                       }

                break;
                case '2':
                      for(i=0; i<10;i++)
                      {
                       printf("\nnumero[%d] = ",i+1);scanf("%d",&numeros[i]);
                      }
                      printf("\nNumeros Ordenados Forma Descendente ");
                       for (i=0;i<10;i++)                 // Metdodo Burbuja
                       {
                         for(j=i+1;j<10;j++)
                         {
                          if(numeros[j]>numeros[i])
                           {
                             temp=numeros[j];
                             numeros[j]=numeros[i];
                             numeros[i]=numeros[j];
                             numeros[i]=temp;
                           }
                         }
                       }
                       for(i=0;i<10;i++)
                       {
                         printf("\n %d",numeros[i]);
                       }
                break;
              }

         do {
               printf("\nDesea Ordenar mas Numeros ? y/n ");
               opc=getch();clrscr();

         }while (toupper(opc)!='Y' && toupper(opc)!='N');

      }while(toupper(opc)=='Y' );
        return 0;
}//main


