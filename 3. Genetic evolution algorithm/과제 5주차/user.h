#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define sel_array 4
#define base_array 8
#define length 10
#define random() (float)rand()/RAND_MAX //ox7fff

void make_array(int(*arr)[10]);
void score_array(int(*arr)[10], int *score, int st);
void print_array(int(*arr)[10], int st);
void select_array(int(*arr)[10], int *score, int st);
void copy_array(int(*arr)[10], int j,int i);
void cross_array(int(*arr)[10]);
