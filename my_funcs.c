#include "my_funcs.h"
#include <stdio.h>
#include <string.h>
void print_table(int i , po *PO)
{
printf("The selected course outcome is:  CO%d\n", i+1);
                printf("+------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
                printf("| CO   | PO1 | PO2 | PO3 | PO4 | PO5 | PO6 | PO7 | PO8 | PO9 | PO10| PO11|\n");
                printf("+------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
                    
                printf("| CO%-2d |", i + 1);

                    for (int j = 0; j < 11; j++) {
                        if (PO[j].contribution[i] == 0)
                            printf("  -  |");
                        else
                            printf("  %d  |", PO[j].contribution[i]);
                        }
                    printf("\n");
                printf("+------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
}

int assign_k_lvl(FILE *k[],co *CO,int j)
{
    char buffer[25];
    for(int i =0; i<5;i++){

        while(fgets(buffer, sizeof(buffer), k[i]) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        if(strcmp(buffer,CO[j].keywords)==0){
            // printf("CO.[%d].keywords: %s........\n", j, CO[j].keywords);
            rewind(k[i]);
            return i+1;
        }
        
        }rewind(k[i]);
        printf("CO.[%d].keywords: %s\n", j, CO[j].keywords);
    }
    return 0;
}