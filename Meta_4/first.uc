int n1=10;

void print_int(int value) {
   if(value != 0) {
      print_int(value/10);
      putchar((value%10) + '0');
   }
}

void func(int n1){
	while( n1 = n1 -1){
      print_int(n1);
    }	
    n1 = 10;
    while( n1 = n1 -1){
      print_int(n1);
    }
}

int main(void)
{
	func(20);
    return 0;
}