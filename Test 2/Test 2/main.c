//
//  main.c
//  Tema 2
//
//  Created by Inga Curjos on 11/11/2020.
//
// Sa se afiseze valoarea bit-ului din fisier de pe pozitia n.
// Testari. Tratarea exceptiilor.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

FILE *fisier;

int main () {
    
    int n;
    char caracter;
    
    printf("Anunt informativ!\n\n Draga utilizator,\nTindem sa te informam ca aceasta aplicatie va functiona doar daca ai un procesor de tip MSB.\nDaca al tau este diferit, mergi si schimba-l pentru a te putea bucura de aceasta aplicatie!\nP.S It's not a bug, it's a feature!\nAll the best!\n\n");
    
    sleep(14);
    
    if((fisier = fopen("test.in","r")) != NULL) {
        printf("Fisier deschis\n");
        
        printf("Introduceti un numar: ") ; // >0
        scanf("%d", &n);
        
        int byte = n/8;
        int bit = (n-1)%8;
        
        printf("byte = %d pos = %d\n", byte, bit);
        int i = 0;
        
        while((i<byte) & ((caracter = fgetc(fisier)) != EOF)){
            i++;
        }
        if (i < byte){
            printf("Fisierul contine mai putini biti\n");
        }
        else{
            int valoarea = caracter & (int)pow(2,7-bit);
            
            if(valoarea == 0){
                printf("\nValoare bitului este 0\n");
            }
            else{
                printf("\nValoarea bitului este 1\n");
            }
        }
        
        
        if(fclose(fisier)==EOF){
            printf("Eroare la inchidere\n");
        }
        else{
            printf("Inchidere reusita\n");
        }
    }
    else{
        printf("Fisierul nu a fost deschis\n");
    }
    
    return 0;
}
