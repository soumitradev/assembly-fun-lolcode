#ifndef SCREEN_H
#define SCREEN_H

#define VIDEO_ADDR (unsigned char *)0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0xf4
#define WHITE_ON_RED 0x4f

#define REG_SCR_CTRL 0x3d4
#define REG_SCR_DAT 0x3d5

void panic();
void clr_scr();
void flood(char chr, char attr);
void print(char *str, char attr);
void set_cursor(int col, int row);
void set_cursor_offset(int offset);
void print_at(char *str, int col, int row, char attr);
void print_at_offset(char *str, int offset, char attr);
void print_at_offset_l(char *str, long offset, char attr);
void backspace_handler();

int get_cursor_offset();
int get_offset_col(int offset);
int get_offset_row(int offset);
int get_offset(int col, int row);
int print_char(char chr, int col, int row, char attr);
void print_char_at(char chr, int col, int row, char attr);

#endif
