int main(void){
  	int a , b, c;
  	a = (a = a || (b && !c)) || (c = b);
    return a;
}