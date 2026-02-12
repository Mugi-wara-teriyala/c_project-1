#include <stdio.h>
#include <string.h>

typedef struct {
    char c_name[200];
    char k_lvl[3];
    int x;
} co;



typedef struct {
    char rk_lvl[3];
    int contribution[5];
    int y;
} po;




int main(void)
{

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
    po PO[5];

    strcpy(PO[0].rk_lvl, "K3");
    strcpy(PO[1].rk_lvl, "K4");
    strcpy(PO[2].rk_lvl, "K5");
    strcpy(PO[3].rk_lvl, "K5");
    strcpy(PO[4].rk_lvl, "K6");

    for(int i =0;i<5;i++)
    {
        CO[i].x = CO[i].k_lvl[1] - '0';
    }

    for(int i=0;i<5;i++)
    {
        PO[i].y=PO[i].rk_lvl[1] - '0';
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if((PO[j].y-CO[j].x)==0)
            PO[j].contribution[i]=3;
            else if((PO[j].y-CO[i].x)==1)
            PO[j].contribution[i]=2;
            else if((PO[j].y-CO[j].x)==2)  
            PO[j].contribution[i]=1;
            else if((PO[j].y-CO[j].x)>=3)
            PO[j].contribution[i]=0;
    }
    }


printf("+-----+-----+-----+-----+-----+-----+\n");
printf("| CO  | PO1 | PO2 | PO3 | PO4 | PO5 |\n");
printf("+-----+-----+-----+-----+-----+-----+\n");

for (int i = 0; i < 5; i++) {
    printf("| CO%d |", i + 1);
    for (int j = 0; j < 5; j++) {
        printf(" %2d  |", PO[j].contribution[i]);
    }
    printf("\n");
}

printf("+-----+-----+-----+-----+-----+-----+\n");

      return 0;
}