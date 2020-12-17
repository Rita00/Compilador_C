int fibonnaci(int n){
	if ( n<=1 ){
		return n;
	}
	else
		return fibonnaci( n-1 ) + fibonnaci ( n-2);

}

int fatorial( int n ){
	if ( n<=1 ){
		return 1;
	}
	else
		return n * fatorial( n-1 );
}

int gcd (int a, int b) 
{
	int r; // remainder
	while (b > 0) 
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}


int bigmod ( int a, int p, int m )
{
	int c;
    if ( p == 0 )return 1; // If power is 0, then a ^ 0 = 1 for any value of a, And 1 Mod m=1 for any value of m, So return 1
 
    if ( p % 2 ) // If power is odd, Split it : a ^ 5 =( a )* (a ^ 4) --> left and right child respectively.
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m; 
    }
    else //If power is even then split it equally and return the result...
    {
        c = bigmod ( a, p / 2, m ); 
        return ( (c%m) * (c%m) ) % m;
    }
}

int primes(int n)
{
   int i = 3, count, c;
 
   if ( n >= 1 )
   {
   		putchar('2');
   		putchar(' ');
   }
 
   count = 2 ; 
   while(count <= n  )
   {
      c = 2 ; 
      
      while(c <= i - 1  && i%c != 0 ) 
      {
        	c = c + 1 ;
      }

      if ( c == i )
      {
         putchar(i+48);
         putchar(',');
         count = count+1;
      }
      i= i+1;
   }
 
   return 0;
}


int main(void){	
	
	int a = 10;

	putchar( fatorial( a-5 ) );
	putchar('\n');

	putchar( fibonnaci( a ) );
	putchar('\n');
	

	putchar( bigmod( 151, 5, 200 ) + 48 );
	putchar('\n');
	
	putchar( gcd(10,5) + bigmod( 151, 5, 200 ) +  fatorial( a-5 )  + fibonnaci( a ) + 48);
	putchar('\n');


	putchar( primes( 5 ) );
	putchar('\n');


	int or = 10 || fibonnaci(4);

	putchar(or+48);
}