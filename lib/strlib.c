#include "./strlib.h"

#include "./lollib.h"

// K&R implementation of itoa, fails on base > 10.
void int_to_char(int n, char *str, int base) {
  int i, sign;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    str[i++] = n % base + '0';
  } while ((n /= base) > 0);

  if (sign < 0) str[i++] = '-';

  str[i] = '\0';

  rev_str(str);
}

// Write our own idk if this is faster or not str rev.
void rev_str(char *s) {
  int i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    s[i] ^= s[j];
    s[j] ^= s[i];
    s[i] ^= s[j];
  }
}

// Write our crappy strlen that fails at normal unicode bytes.
int strlen(char *str) {
  char *s;
  for (s = str; *s; s++) {
  }
  return (s - str);
}

// Append char to str
void append(char *str, char new) {
  int len = strlen(str);
  str[len] = new;
  str[len + 1] = '\0';
}

// Remove last char from str
void backspace(char *str) { str[strlen(str) - 1] = '\0'; }

// Return < 0 if s1 < s2, 0 if equal and > 0 if s1 > s2. Also K&R implementation
int strcmp(char *s1, char *s2) {
  int i;
  for (i = 0; s1[i] == s2[i]; i++) {
    if (s1[i] == '\0') return 0;
  }
  return s1[i] - s2[i];
}

char *substr(const char *src, int m, int n) {
  // get length of the destination string
  int len = n - m;

  // allocate (len + 1) chars for destination (+1 for extra null character)
  char *dest = (char *)malloc(sizeof(char) * (len + 1));

  // extracts characters between m'th and n'th index from source string
  // and copy them into the destination string
  for (int i = m; i < n && (strcmp(*(src + i), '\0') != 0); i++) {
    *dest = *(src + i);
    dest++;
  }

  // null-terminate the destination string
  *dest = '\0';

  // return the destination string
  return dest - len;
}