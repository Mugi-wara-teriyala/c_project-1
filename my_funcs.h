#ifndef MY_FUNCS_H
#define MY_FUNCS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char c_name[200];
    char k_lvl[3];
    char keywords[25];
    int x;
} co;

typedef struct {
    char rk_lvl[3];
    int contribution[11];   // you are looping till 11
    int y;
} po;

void print_table(int i ,po *PO);
int assign_k_lvl(FILE *k[],co *CO,int j);

#endif