<<<<<<< HEAD
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
=======
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
>>>>>>> 557d44aed67b780c7dac8b70253a2eeaa4c6b3ac
}