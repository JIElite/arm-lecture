#include<stdio.h>

int fib(int n, int x, int y){
	if (0 == n) return x;
	if (1 == n) return y;	
	return fib(n-1, y, x+y);
}


int main(){
	for (int i = 0; i < 47; i++) {
		printf("%d\t%d\n", i, fib(i, 0, 1));
	}
	return 0;
}
