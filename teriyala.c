#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my_funcs.h"

void main(void)
{
    
    FILE *k[5] = {fopen("remembering.txt", "r"), fopen("understanding.txt", "r"), fopen("applying.txt", "r"), fopen("analyzing.txt", "r"), fopen("creating.txt", "r")};
    for(int i=0;i<5;i++)
    {
        if(k[i] == NULL) {
            printf("Error opening file %d\n", i+1);
            return;
        }
    }

    
    char buffer[200];


    printf("Course Outcomes and Program Outcomes Contribution Matrix\n");

    co CO[5];
    strcpy(CO[0].c_name, "Discuss the principle and working of various radiographic equipments.");
    

    strcpy(CO[1].c_name, "Explain the tomography concept and image reconstruction techniques.");

    strcpy(CO[2].c_name, "Illustrate the concept of radio isotopic imaging techniques.");

    strcpy(CO[3].c_name, "Describe the basic principle involved in Ultrasound Imaging technique.");

    strcpy(CO[4].c_name, "Outline the basic principle and working of Magnetic resonance imaging technique.");
    
    po PO[11];
    printf("....\n");

    for(int i =0;i<5;i++)
    {
        sscanf(CO[i].c_name, "%s",CO[i].keywords );
        CO[i].keywords[0]=tolower((unsigned char)CO[i].keywords[0]);
    }
    for(int i = 0;i<5;i++){
        CO[i].x = assign_k_lvl(k, CO, i);
        // printf("CO.[%d].x: %d\n", i, CO[i].x);
    }
    printf("....\n");
    
    strcpy(PO[0].rk_lvl, "K3");
    strcpy(PO[1].rk_lvl, "K4");
    strcpy(PO[2].rk_lvl, "K5");
    strcpy(PO[3].rk_lvl, "K5");
    strcpy(PO[4].rk_lvl, "K6");
    strcpy(PO[5].rk_lvl, "K3");
    strcpy(PO[6].rk_lvl, "K2");
    strcpy(PO[7].rk_lvl, "K3");
    strcpy(PO[8].rk_lvl, "K3");
    strcpy(PO[9].rk_lvl, "K2");
    strcpy(PO[10].rk_lvl, "K3");


    for(int i=0;i<=10;i++)
    {
        PO[i].y=PO[i].rk_lvl[1] - '0';
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if((PO[j].y-CO[i].x)==0)
            PO[j].contribution[i]=3; 
            else if((PO[j].y-CO[i].x)==1)
            PO[j].contribution[i]=2;
            else if((PO[j].y-CO[i].x)==2)  
            PO[j].contribution[i]=1;
            else if((PO[j].y-CO[i].x)>=3)
            PO[j].contribution[i]=0;
    }
    }


    for(int i=0;i<5;i++)
    {
        for(int j=5;j<=10;j++)
        {
            if((PO[j].y-CO[i].x)==1)
            PO[j].contribution[i]=2;
            else
            PO[j].contribution[i]=1;
            if(j==7 || j==8)
            PO[j].contribution[i]=1;
        }
    }
    printf("\nCO-PO Contribution Matrix\n");

    printf("+------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf("| CO   | PO1 | PO2 | PO3 | PO4 | PO5 | PO6 | PO7 | PO8 | PO9 | PO10| PO11|\n");
    printf("+------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");

    for (int i = 0; i < 5; i++) {
        printf("| CO%-2d |", i + 1);

        for (int j = 0; j < 11; j++) {
            if (PO[j].contribution[i] == 0)
                printf("  -  |");
            else
                printf("  %d  |", PO[j].contribution[i]);
        }
        printf("\n");
    }

    printf("+------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");


    printf("Do you like to select any particular course?? (y/n): ");
    char choice;
    scanf("%c", &choice);
    getchar();  // to consume the newline character after scanf

    if(choice == 'y' || choice == 'Y')
    {
        printf("enter the course outcome name: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';


        for(int i=0;i<5;i++)
        {
            if(strcmp(buffer, CO[i].c_name) == 0)
            {
                print_table(i, PO);
                break;
            }
        }


        do{
            printf("Would you like to select another course outcome?? (y/n): ");
            scanf(" %c", &choice);
            getchar();

            if(choice == 'y' || choice == 'Y')
            {
                printf("enter the course outcome name: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                for(int i=0;i<5;i++)
                {
                    if(strcmp(buffer, CO[i].c_name) == 0)
                    {
                        print_table(i, PO);
                        break;
                    }
                }
            }
        } while(choice == 'y' || choice == 'Y');
        printf("Thank you!!....\n");
    }


    else{
        printf("Thank you!!....\n");
    }
        
    
    for(int i=0;i<5;i++)
    {
        fclose(k[i]);
    }
}