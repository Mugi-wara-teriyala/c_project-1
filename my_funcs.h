#ifndef MY_FUNCS_H
#define MY_FUNCS_H

typedef struct {
    char c_name[200];
    char k_lvl[3];
    char keywords[20];
    int x;
} co;

typedef struct {
    char rk_lvl[3];
    int contribution[11];   // you are looping till 11
    int y;
} po;

void print_table(int i ,po *PO);

#endif