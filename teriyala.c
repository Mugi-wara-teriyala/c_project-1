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


    strcpy(CO[0].Co, "CO1");
    strcpy(CO[1].Co, "CO2");
    strcpy(CO[2].Co, "CO3");
    strcpy(CO[3].Co, "CO4");
    strcpy(CO[4].Co, "CO5");
    
    po PO[11];

    for(int i =0;i<5;i++)
    {
        sscanf(CO[i].c_name, "%s",CO[i].keywords );
        CO[i].keywords[0]=tolower((unsigned char)CO[i].keywords[0]);
    }
    for(int i = 0;i<5;i++){
        CO[i].x = assign_k_lvl(k, CO, i);
        
    }
    
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
            PO[j].contribution[i]=0;
            // if((PO[j].y-CO[i].x)==1)
            // PO[j].contribution[i]=2;
            // else
            // PO[j].contribution[i]=1;
            // // if(j==7 || j==8)
            // // PO[j].contribution[i]=1;
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
    printf("Would you like to take some suggestions to improve the course contribution?? (y/n): ");
    char choice[4];
    int a[5]={0};
    scanf("%s", choice);
    getchar();  // to consume the newline character after scanf
    if(strcmp(choice, "y") == 0)
    {

        printf("This is for PO6\nPO6 is about analyzing and evaluating societal, environmental, economic, health, safety, and legal impacts of engineering solutions.\n");
        for(int i=0;i<5;i++)
        {
        if(CO[i].x == 1)
        {
            printf("You can explain the health and safety implications of each technique. This allows Now student connects technique with radiation risk, safety protocols.");
            printf("You can also insist students to identify environmental and regulatory concerns related to imaging equipment disposal.This includes\n1) Waste management\n2) Legal compliance\n3) Sustainability");
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                CO[i].x++;
                printf("Great! The course's contribution to PO1 has been improved to %d.\n", CO[i].x);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
            }
        }

        // else if(CO[i].x == 3)
        // {
        //     printf("Evaluate sustainability aspects of imaging system design.\n");
        //     printf("This includes \n1) Energy consumption\n2) Equipment lifecycle\n3) Green engineering");
        //     printf("Implementing these suggestions can enhance the course's contribution from 3 ->.\n");
        //     printf("Would you like to implement these suggestions?? (y/n): ");
        //     scanf("%s", choice);
        //     getchar();
        //     if(strcmp(choice, "y") == 0)
        //     {
        //         CO[i].x++;
        //         printf("Great! The course's contribution to PO1 has been improved to %d.\n", CO[i].x);
        //     }
        //     else{
        //         printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
        //     }
        // }

        else if(CO[i].x == 2)
        {
            printf("Discuss societal and ethical considerations in MRI usage.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                CO[i].x++;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", CO[i].x);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO6. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }
    }
    

//     printf("Does this course require students to analyze or evaluate real-life societal or environmental cases related to imaging systems?\n ");
//     for(int i=0;i<5;i++)
//     {
//         printf("CO %d:  ", i+1);
//         scanf("%s",choice);
//         getchar();
//         if(strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0 || strcmp(choice, "yes") == 0 || strcmp(choice, "YES") == 0 || strcmp(choice, "Yes") == 0)
//         {
//             a[i]++;
//         } 
//     }
//     printf("Does the course discuss how imaging technology affects public healthcare access?:\n");
//     for(int i=0;i<5;i++)
//     {
//         printf("CO %d:  ", i+1);
//         scanf("%s",choice);
//         getchar();
//         if(strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0 || strcmp(choice, "yes") == 0 || strcmp(choice, "YES") == 0 || strcmp(choice, "Yes") == 0)
//         {
//             a[i]++;
//         } 
//     }
//     




    






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

    /*printf("Do you like to select any particular course?? (y/n): ");
    
    scanf("%s", choice);
    getchar();  // to consume the newline character after scanf
    while(strcmp(choice, "y") != 0 && strcmp(choice, "Y") != 0 && strcmp(choice, "yes") != 0 && strcmp(choice, "YES") != 0 && strcmp(choice, "Yes") != 0 && strcmp(choice, "n") != 0 && strcmp(choice, "N") != 0 && strcmp(choice, "no") != 0 && strcmp(choice, "NO") != 0 && strcmp(choice, "No") != 0)
    {
        printf("Please enter a valid input (y/n): ");
        scanf("%s", choice);
        getchar();
    }

    if(strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0 || strcmp(choice, "yes") == 0 || strcmp(choice, "YES") == 0 || strcmp(choice, "Yes") == 0)
    {
        printf("enter the course outcome name or the CO number (e.g., CO1): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';


        for(int i=0;i<5;i++)
        {
            if(strcmp(buffer, CO[i].c_name) == 0 || strcmp(buffer, CO[i].Co) == 0)
            {
                print_table(i, PO);
                break;
            }
        }


        do{
            printf("Would you like to select another course outcome?? (y/n): ");
            scanf(" %s", choice);
            getchar();

            if(strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0 || strcmp(choice, "yes") == 0 || strcmp(choice, "YES") == 0 || strcmp(choice, "Yes") == 0)
            {
                printf("enter the course outcome name or the CO number (e.g., CO1): ");
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
        } while(strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0 || strcmp(choice, "yes") == 0 || strcmp(choice, "YES") == 0 || strcmp(choice, "Yes") == 0 );
        printf("Thank you!!....\n");
    }


    else{
        printf("Thank you!!....\n");
    }*/
        
    
    for(int i=0;i<5;i++)
    {
        fclose(k[i]);
    }
}