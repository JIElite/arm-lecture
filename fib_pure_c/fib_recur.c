#include<stdio.h>
#include<time.h>

int fibonacci(int number){
	int a = 0;
	int b = 1;
	
	if (number == 0) return 0;
	if (number == 1) return 1;

	return fibonacci(number-1) + fibonacci(number-2);
}

int main(){
	
		int i;

		for ( i = 0; i < 47; i++){
			
			clock_t start = clock();
			int result = fibonacci(i);
			clock_t end = clock();
			
			double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
			FILE *fptr = fopen("fib_recur.txt", "a");
			if (fptr != NULL){
				fprintf(fptr, "%d\t%f\n", i, elapsed_time); 	
				fclose(fptr);
 			}
		}
	
		return 0;
}
