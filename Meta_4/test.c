#include <stdio.h>
int x;

int twice(int z) {
    x = !z;
    //putchar(2*z + 'A');
    return 2*z;
}

int main(void) {
  putchar((0 || twice(13)>0 || twice(25)>0) + 'A');
  return 0;
}

/*
  %aux = zext i1 %13 to i32
  %14 = icmp ne i32 %aux, 1
  %15 = or i1 %9, %14
  */