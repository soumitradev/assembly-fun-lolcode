#include "./kernel.h"

#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "../lib/lollib.h"
#include "../lib/strlib.h"

void kmain() {
  // Initialise interrupts
  isr_install();
  irq_install();

  // Clear screen and show prompt
  clr_scr();
  print("BruhOS\n", 0x02);
  print("| Release: v0.0.2a (LOLCODE flavor)\n", 0);
  print("| Release Date: 1st October 2020\n", 0);
  print("| Architecture: i386\n", 0);
  print("| Resolution: 80x25\n", 0);
  print(">", 0);
}
// Handle commands
void user_input(char *input) {
  if (strcmp(input, "KILL") == 0) {
    print("I'm ded.\n", 0);
    asm volatile("hlt");
  } else if (strcmp(substr(input, 0, 3), "MOO") == 0) {
    MSG = substr(input, 4, strlen(input));
    print("\n", 0);
    print("\n", 0);
    main();
  } else if (strcmp(input, "PANIC") == 0) {
    panic();
  } else if (strcmp(input, "SLEEP") == 0) {
    _func_ksleep_();
  } else {
    // Command not found
    // main();
    print("COMMAND ", 0);
    print(input, 0);
    print(" NOT FOUND! ", 0);
  }
  print("\n>", 0);
}