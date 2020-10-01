#include "./lollib.h"

#include "../drivers/keyboard.h"
#include "../drivers/screen.h"
#include "./strlib.h"

// Write our own epic (unoptimised 😳) memcpy
void fflush(int x) {}
void printf(char x[], char y[]) {
  // if (strcmp("%s \n", x) == 0) {
  //   // print(y, 0);
  // } else if (strcmp("%ld \n", x) == 0) {
  //   char buf[10];
  //   int_to_char(y, buf, 10);
  //   print(buf, 0);
  // }
  print(y, 0);
}

float _op_add(int X, int Y){
  return X+Y;
}

extern u32 end;
u32 free_mem = (u32)&end;

float* malloc(u32 size) {
  int align = 0;
  u32* phys_addr = 0;
  if (free_mem == 0) free_mem = 0x10002;
  if (align == 1 && (free_mem & 0x00000FFF)) {
    free_mem &= 0xFFFFF000;
    free_mem += 0x1000;
  }
  if (phys_addr) *phys_addr = free_mem;

  u32 ret = free_mem;
  free_mem += size;
  return ret;
}

long _func_ksleep_() {
  int i = 0;
  for (i = 0; i < 1000000000; i++) {
  }
}
long _func_cls_() { clr_scr(); }