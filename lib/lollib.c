#include "./lollib.h"
#include "../drivers/screen.h"

// Write our own epic (unoptimised 😳) memcpy
void fflush(int x) {
}
void printf(char x[], char y[]) {
    print(y, 0);
}
