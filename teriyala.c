<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include "my_funcs.h"

void main(void)
{
    FILE *k5,*k1,*k3,*k4,*k2,*k6;
    k1 = fopen("understanding.txt", "r");
    if(k1 == NULL) {
        printf("Error opening file understanding.txt\n");
        return;
    }
    k2 = fopen("remembering.txt", "r");
    if(k2 == NULL) {
        printf("Error opening file remembering.txt\n");
        return;
    }  
    k3 = fopen("applying.txt", "r");
    if(k3 == NULL) {
        printf("Error opening file applying.txt\n");
        return;
    }
    k4 = fopen("analyzing.txt", "r");
    if(k4 == NULL) {
        printf("Error opening file analyzing.txt\n");
        return;
    }
    k5 = fopen("create.txt", "r");
    if(k5 == NULL) {
        printf("Error opening file create.txt\n");
        return;
    }
    k6 = fopen("evaluating.txt", "r");
    if(k6 == NULL) {
        printf("Error opening file evaluating.txt\n");
        return;
    }


    printf("Course Outcomes and Program Outcomes Contribution Matrix\n");

    co CO[5];
    strcpy(CO[0].c_name, "Discuss the principle and working of various radiographic equipments.");
    strcpy(CO[0].k_lvl, "K2");
    

    strcpy(CO[1].c_name, "Explain the tomography concept and image reconstruction techniques.");
    strcpy(CO[1].k_lvl, "K2");

    strcpy(CO[2].c_name, "Illustrate the concept of radio isotopic imaging techniques.");
    strcpy(CO[2].k_lvl, "K2");

    strcpy(CO[3].c_name, "Describe the basic principle involved in Ultrasound Imaging technique.");
    strcpy(CO[3].k_lvl, "K2");

    strcpy(CO[4].c_name, "Outline the basic principle and working of Magnetic resonance imaging technique.");
    strcpy(CO[4].k_lvl, "K2");
    po PO[11];

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

    char buffer[200];
    char buffer1[200];

    // while(fgets(buffer, sizeof(buffer), k1) != NULL){
    //     buffer[strcspn(buffer, "\n")] = '\0';
    //     for(int i=0;i<5;i++)
    // }

    for(int i =0;i<5;i++)
    {
        CO[i].x = CO[i].k_lvl[1] - '0';
    }

    for(int i=0;i<=10;i++)
    {
        PO[i].y=PO[i].rk_lvl[1] - '0';
    }

     for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if((PO[j].y-CO[j].x)==0)
            {
                //if()
                PO[j].contribution[i]=3;

            }
            else if((PO[j].y-CO[i].x)==1)
            PO[j].contribution[i]=2;
            else if((PO[j].y-CO[j].x)==2)  
            PO[j].contribution[i]=1;
            else if((PO[j].y-CO[j].x)>=3)
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
        
    
=======
#include <stdio.h>
#include <string.h>
#include "my_funcs.h"

void main(void)
{
    FILE *k5,*k1,*k3,*k4,*k2,*k6;
    k1 = fopen("understanding.txt", "r");
    if(k1 == NULL) {
        printf("Error opening file understanding.txt\n");
        return;
    }
    k2 = fopen("remembering.txt", "r");
    if(k2 == NULL) {
        printf("Error opening file remembering.txt\n");
        return;
    }  
    k3 = fopen("applying.txt", "r");
    if(k3 == NULL) {
        printf("Error opening file applying.txt\n");
        return;
    }
    k4 = fopen("analyzing.txt", "r");
    if(k4 == NULL) {
        printf("Error opening file analyzing.txt\n");
        return;
    }
    k5 = fopen("create.txt", "r");
    if(k5 == NULL) {
        printf("Error opening file create.txt\n");
        return;
    }
    k6 = fopen("evaluating.txt", "r");
    if(k6 == NULL) {
        printf("Error opening file evaluating.txt\n");
        return;
    }


    printf("Course Outcomes and Program Outcomes Contribution Matrix\n");

    co CO[5];
    strcpy(CO[0].c_name, "Discuss the principle and working of various radiographic equipments.");
    strcpy(CO[0].k_lvl, "K2");
    

    strcpy(CO[1].c_name, "Explain the tomography concept and image reconstruction techniques.");
    strcpy(CO[1].k_lvl, "K2");

    strcpy(CO[2].c_name, "Illustrate the concept of radio isotopic imaging techniques.");
    strcpy(CO[2].k_lvl, "K2");

    strcpy(CO[3].c_name, "Describe the basic principle involved in Ultrasound Imaging technique.");
    strcpy(CO[3].k_lvl, "K2");

    strcpy(CO[4].c_name, "Outline the basic principle and working of Magnetic resonance imaging technique.");
    strcpy(CO[4].k_lvl, "K2");
    po PO[11];

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

    char buffer[200];

    // while(fgets(buffer, sizeof(buffer), k1) != NULL){
    //     buffer[strcspn(buffer, "\n")] = '\0';
    //     for(int i=0;i<5;i++)
    // }

    for(int i =0;i<5;i++)
    {
        CO[i].x = CO[i].k_lvl[1] - '0';
    }

    for(int i=0;i<=10;i++)
    {
        PO[i].y=PO[i].rk_lvl[1] - '0';
    }

     for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if((PO[j].y-CO[j].x)==0)
            {
                //if()
                PO[j].contribution[i]=3;

            }
            else if((PO[j].y-CO[i].x)==1)
            PO[j].contribution[i]=2;
            else if((PO[j].y-CO[j].x)==2)  
            PO[j].contribution[i]=1;
            else if((PO[j].y-CO[j].x)>=3)
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
        
    
>>>>>>> 557d44aed67b780c7dac8b70253a2eeaa4c6b3ac
}