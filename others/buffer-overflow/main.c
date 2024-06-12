#include <stdio.h>
#include <string.h>

void doit(void) {
  char buf[8];

  gets(buf);
  printf("%s\n", buf);
}

int main(void) {
  printf("So... The End...\n");
  doit();
  printf("or... maybe not?\n");

  return 0;
}
