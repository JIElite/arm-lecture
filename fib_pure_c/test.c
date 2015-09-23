#include<stdio.h>
#include<time.h>

int fibonacci(int number){
	int a = 0;
	int b = 1;
	
	if (number == 0) return 0;
	if (number == 1) return 1;
	
	int result = 0;
	int i;
	for ( i = 1; i < number; i++){
		result = a;
		a = b;
		result = result + a;
		b = result;
	}
	
	return result;
}

int main(){
	
		int num = 0;
		scanf("%d", &num);
		int result = fibonacci(num);
		
		printf("%d\n", result);
		return 0;
}
