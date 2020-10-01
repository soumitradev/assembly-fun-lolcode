#ifndef LOLLIB_H
#define LOLLIB_H

#include "../cpu/types.h"

void fflush(int x);
void printf(char x[], char y[]);
float* malloc(u32 size);
long _func_ksleep_();
long _func_cls_();
char* _func_getmsg_(char *in);
char* _func_get_();
char *MSG;
float _op_add(int X, int Y);
#endif