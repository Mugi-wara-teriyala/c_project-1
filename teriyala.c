#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my_funcs.h"
#include <windows.h>

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
        // CO 1
        if(CO[0].x == 1)
        {
            Sleep(500);
            printf("CO-1\n");
            printf("You can introduce examples showing how engineering projects affect society, environment, and public safety.\n");
            Sleep(500);
            printf("You can also include questions testing awareness of sustainability and environmental impact in engineering systems.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[0]=2;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[0]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
                PO[5].contribution[0]=1;
            }
        }

        else if(CO[0].x == 3)
        {
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[5].contribution[0]=3;
        }

        else if(CO[0].x == 2)
        {
            Sleep(500);
            printf("CO-1\n");
            Sleep(500);
            printf("You can discuss case studies where engineering solutions influenced environmental sustainability or societal welfare.\n");
            Sleep(500);
            printf("You can explain how engineering decisions affect economy, safety, and environmental sustainability.");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[0]=3;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[0]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
                PO[5].contribution[0]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO6. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }
    // CO 2

    if(CO[1].x == 1)
        {
            Sleep(500);
            printf("CO-2\n");
            printf("You can introduce fundamental concepts of sustainable engineering and environmental responsibility.\n");
            Sleep(500);
            printf("Include short examples of engineering systems designed to reduce environmental impact.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[1]=2;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[1]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
                PO[5].contribution[1]=1;
            }
        }

        else if(CO[1].x == 3)
        {   
            printf("CO-2\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[5].contribution[1]=3;
        }

        else if(CO[1].x == 2)
        {   
            Sleep(500);
            printf("CO-2\n");
            Sleep(500);
            printf("Explain the relationship between engineering decisions and environmental sustainability.\n");
            Sleep(500);
            printf("you can discuss case studies highlighting societal and safety implications of engineering solutions.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[1]=3;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[1]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
                PO[5].contribution[1]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO6. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }

    // Co 3
    if(CO[2].x == 1)
        {
            Sleep(500);
            printf("CO-3\n");
            printf("You can introduce basic knowledge of environmental and societal responsibilities of engineers.");
            Sleep(500);
            printf("You can include examples of engineering projects affecting public health and safety.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[2]=2;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[2]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
                PO[5].contribution[2]=1;
            }
        }

        else if(CO[2].x == 3)
        {   
            printf("CO-3\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[5].contribution[2]=3;
        }

        else if(CO[2].x == 2)
        {   
            Sleep(500);
            printf("CO-3\n");
            Sleep(500);
            printf("Explain the impact of engineering solutions on culture, environment, and society..\n");
            Sleep(500);
            printf("You can use real-world engineering case studies related to sustainability and environmental protection.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[2]=3;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[2]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
                PO[5].contribution[2]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO6. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }
    //CO 4

    if(CO[3].x == 1)
        {
            Sleep(500);
            printf("CO-4\n");
            printf("You can introduce fundamental concepts of environmental sustainability in engineering practice.\n");
            Sleep(500);
            printf("Provide examples of engineering projects impacting economic and environmental sustainability.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[3]=2;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[3]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
                PO[5].contribution[3]=1;
            }
        }

        else if(CO[3].x == 3)
        {   
            printf("CO-4\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[5].contribution[3]=3;
        }

        else if(CO[3].x == 2)
        {   
            Sleep(500);
            printf("CO-4\n");
            Sleep(500);
            printf("You can explain how engineering solutions affect societal welfare and environmental safety.\n");
            Sleep(500);
            printf("Discuss engineering case studies involving environmental and legal considerations.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[3]=3;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[3]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
                PO[5].contribution[3]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO6. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
            PO[5].contribution[3]=3;
        }

    //CO 5

    if(CO[4].x == 1)
        {
            Sleep(500);
            printf("CO-5\n");
            printf("Introduce concepts of sustainable development and environmental responsibility in engineering practice.\n");
            Sleep(500);
            printf("Include examples of engineering practices that promote environmental sustainability.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[4]=2;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[4]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
                PO[5].contribution[4]=1;
            }
        }

        else if(CO[4].x == 3)
        {   
            printf("CO-5\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[5].contribution[4]=3;
        }

        else if(CO[4].x == 2)
        {   
            Sleep(500);
            printf("CO-5\n");
            Sleep(500);
            printf("Explain how engineering projects impact environment, society, and public safety.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[5].contribution[4]=3;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[5].contribution[4]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO6.\n");
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO6. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }

    //...................................................................
    printf("This is for PO7\nPO7 is about engineering ethics, responsibility, inclusivity, and legal compliance.\n");
    // CO 1
        if(CO[0].x == 1)
        {
            Sleep(500);
            printf("CO-1\n");
            printf("Include short questions in exams on professional codes of ethics and responsibilities of engineers.");
            Sleep(500);
            printf("You can also introduce examples of ethical engineering failures during lectures.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[0]=2;
                printf("Great! The course's contribution to PO7 has been improved to %d.\n", PO[6].contribution[0]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[0]=1;
            }
        }

        else if(CO[0].x == 3)
        {
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[6].contribution[0]=3;
        }

        else if(CO[0].x == 2)
        {
            Sleep(500);
            printf("CO-2\n");
            Sleep(500);
            printf("You can conduct classroom discussions on ethical responsibilities in engineering design and public safety.\n");
            Sleep(500);
            printf("You can provide case studies explaining ethical issues in engineering practice.");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[0]=3;
                printf("Great! The course's contribution to PO7 has been improved to %d.\n", PO[6].contribution[0]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[0]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO7. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }
    // CO 2

    if(CO[1].x == 1)
        {
            Sleep(500);
            printf("CO-2\n");
            printf("You can include basic questions about ethical responsibilities in engineering professions.");
            Sleep(500);
            printf("You can also Introduce short examples of ethical standards followed in engineering industries..\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[1]=2;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[6].contribution[1]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[1]=1;
            }
        }

        else if(CO[1].x == 3)
        {   
            printf("CO-2\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[6].contribution[1]=3;
        }

        else if(CO[1].x == 2)
        {   
            Sleep(500);
            printf("CO-2\n");
            Sleep(500);
            printf("Explain ethical implications of engineering decisions affecting society and environment.\n");
            Sleep(500);
            printf("Use case studies to help students understand ethical considerations in engineering projects.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[1]=3;
                printf("Great! The course's contribution to PO6 has been improved to %d.\n", PO[6].contribution[1]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[1]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO7. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }

    // Co 3
    if(CO[2].x == 1)
        {
            Sleep(500);
            printf("CO-3\n");
            printf("You can include questions testing knowledge of engineering ethics and professional conduct.\n");
            Sleep(500);
            printf("Introduce examples of ethical violations in engineering projects.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[2]=2;
                printf("Great! The course's contribution to PO7 has been improved to %d.\n",PO[6].contribution[2]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[2]=1;
            }
        }

        else if(CO[1].x == 3)
        {   
            printf("CO-3\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[6].contribution[2]=3;
        }

        else if(CO[0].x == 2)
        {   
            Sleep(500);
            printf("CO-3\n");
            Sleep(500);
            printf("Explain ethical responsibilities related to safety, inclusivity, and professional practice.\n");
            Sleep(500);
            printf("Discuss engineering case studies involving ethical dilemmas.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[2]=3;
                printf("Great! The course's contribution to PO7 has been improved to %d.\n", PO[6].contribution[2]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[2]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO7. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }
    //CO 4

    if(CO[3].x == 1)
        {
            Sleep(500);
            printf("CO-4\n");
            printf("Include definitions and principles of professional engineering ethics in course materials.");
            Sleep(500);
            printf("Provide examples of ethical guidelines followed by engineering organizations.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[3]=2;
                printf("Great! The course's contribution to PO7 has been improved to %d.\n", PO[6].contribution[3]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[3]=1;
            }
        }

        else if(CO[3].x == 3)
        {   
            printf("CO-4\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[6].contribution[3]=3;
        }

        else if(CO[3].x == 2)
        {   
            Sleep(500);
            printf("CO-4\n");
            Sleep(500);
            printf("Explain the importance of ethics in engineering decision-making and public welfare.\n");
            Sleep(500);
            printf("Use real engineering examples to illustrate ethical responsibilities.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[3]=3;
                printf("Great! The course's contribution to PO7 has been improved to %d.\n", PO[6].contribution[3]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[3]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO7. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }

    //CO 5

    if(CO[4].x == 1)
        {
            Sleep(500);
            printf("CO-5\n");
            printf("Introduce basic concepts of engineering ethics and professional conduct.\n");
            Sleep(500);
            printf("Include questions on ethical standards followed by engineers globally.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[4]=2;
                printf("Great! The course's contribution to PO7 has been improved to %d.\n", PO[6].contribution[4]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[4]=1;
            }
        }

        else if(CO[4].x == 3)
        {   
            printf("CO-5\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[6].contribution[4]=3;
        }

        else if(CO[4].x == 2)
        {   
            Sleep(500);
            printf("CO-5\n");
            Sleep(500);
            printf("Explain ethical implications of engineering decisions affecting society and environment.\n");
            Sleep(500);
            printf("Use case studies to help students understand ethical responsibilities.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[6].contribution[4]=3;
                printf("Great! The course's contribution to PO7 has been improved to %d.\n", PO[6].contribution[4]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO7.\n");
                PO[6].contribution[4]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO7. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }

    
    //...........................................................
    printf("This is for PO&\nPO8 is about engineering ethics, responsibility, inclusivity, and legal compliance.\n");
    // CO 1
        if(CO[0].x == 1)
        {
            Sleep(500);
            printf("CO-1\n");
            printf("Include short questions in exams on professional codes of ethics and responsibilities of engineers.\n");
            Sleep(500);
            printf("You can also introduce examples of ethical engineering failures during lectures.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[0]=2;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[0]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
                PO[7].contribution[0]=1;
            }
        }

        else if(CO[0].x == 3)
        {
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[7].contribution[0]=3;
        }

        else if(CO[0].x == 2)
        {
            Sleep(500);
            printf("CO-1\n");
            Sleep(500);
            printf("You can conduct classroom discussions on ethical responsibilities in engineering design and public safety.\n");
            Sleep(500);
            printf("You can provide case studies explaining ethical issues in engineering practice.");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[0]=3;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[0]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
                PO[7].contribution[0]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO8. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }
    // CO 2

    if(CO[1].x == 1)
        {
            Sleep(500);
            printf("CO-2\n");
            printf("You can include basic questions about ethical responsibilities in engineering professions.");
            Sleep(500);
            printf("You can also Introduce short examples of ethical standards followed in engineering industries..\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[1]=2;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[1]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
                PO[7].contribution[1]=1;
            }
        }

        else if(CO[1].x == 3)
        {   
            printf("CO-2\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[7].contribution[1]=3;
        }

        else if(CO[1].x == 2)
        {   
            Sleep(500);
            printf("CO-2\n");
            Sleep(500);
            printf("Explain ethical implications of engineering decisions affecting society and environment.\n");
            Sleep(500);
            printf("Use case studies to help students understand ethical considerations in engineering projects.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[1]=3;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[1]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
                PO[7].contribution[1]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO8. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }

    // Co 3
    if(CO[2].x == 1)
        {
            Sleep(500);
            printf("CO-3\n");
            printf("You can include questions testing knowledge of engineering ethics and professional conduct.");
            Sleep(500);
            printf("Introduce examples of ethical violations in engineering projects.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[2]=2;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[2]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
                PO[7].contribution[2]=1;
            }
        }

        else if(CO[2].x == 3)
        {   
            printf("CO-3\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[7].contribution[2]=3;
        }

        else if(CO[2].x == 2)
        {   
            Sleep(500);
            printf("CO-3\n");
            Sleep(500);
            printf("Explain ethical responsibilities related to safety, inclusivity, and professional practice.\n");
            Sleep(500);
            printf("Discuss engineering case studies involving ethical dilemmas.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[2]=3;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[2]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
                PO[7].contribution[2]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO8. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }
    //CO 4

    if(CO[3].x == 1)
        {
            Sleep(500);
            printf("CO-4\n");
            printf("Include definitions and principles of professional engineering ethics in course materials.");
            Sleep(500);
            printf("Provide examples of ethical guidelines followed by engineering organizations.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[3]=2;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[3]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
                PO[7].contribution[3]=1;
            }
        }

        else if(CO[3].x == 3)
        {   
            printf("CO-4\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[7].contribution[3]=3;
        }

        else if(CO[3].x == 2)
        {   
            Sleep(500);
            printf("CO-4\n");
            Sleep(500);
            printf("Explain the importance of ethics in engineering decision-making and public welfare.\n");
            Sleep(500);
            printf("Use real engineering examples to illustrate ethical responsibilities.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[3]=3;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[3]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
                PO[7].contribution[3]=2;
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO8. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
            PO[7].contribution[3]=3;
        }

    //CO 5

    if(CO[4].x == 1)
        {
            Sleep(500);
            printf("CO-5\n");
            printf("Introduce basic concepts of engineering ethics and professional conduct.\n");
            Sleep(500);
            printf("Include questions on ethical standards followed by engineers globally.\n");
            Sleep(500);
            printf("Implementing these suggestions can enhance the course's contribution from 1 ->2.\n");
            
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[4]=2;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[4]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
                PO[7].contribution[4]=1;
            }
        }

        else if(CO[4].x == 3)
        {   
            printf("CO-5\n");
            Sleep(500);
            printf("This CO already has good contributioni and no furthur improvements needed\n");
            PO[7].contribution[4]=3;
        }

        else if(CO[4].x == 2)
        {   
            Sleep(500);
            printf("CO-5\n");
            Sleep(500);
            printf("Explain ethical implications of engineering decisions affecting society and environment.\n");
            Sleep(500);
            printf("Use case studies to help students understand ethical responsibilities.\n");
            printf("Implementing these suggestions can enhance the course's contribution from 2 ->3.\n");
            printf("Would you like to implement these suggestions?? (y/n): ");
            scanf("%s", choice);
            getchar();
            if(strcmp(choice, "y") == 0)
            {
                PO[7].contribution[4]=3;
                printf("Great! The course's contribution to PO8 has been improved to %d.\n", PO[7].contribution[4]);
            }
            else{
                printf("No problem! You can consider implementing these suggestions in the future to enhance the course's contribution to PO8.\n");
            }
        }
        else
        {
            printf("The course already has a strong contribution to PO8. You can consider maintaining this level by regularly updating content and incorporating current societal and ethical issues related to imaging technology.\n");
        }
    //...............................................................................................











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
    }


    for(int i=0;i<5;i++)
    {
        fclose(k[i]);
    }
}
}