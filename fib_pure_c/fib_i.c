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
	
		int i;

		for ( i = 0; i < 47; i++){
			
			clock_t start = clock();
			int result = fibonacci(i);
			clock_t end = clock();
			
			double elapsed_time = (double)(end - start);
			FILE *fptr = fopen("fib_i.txt", "a");
			fprintf(stdout, "%d\t%f\t%d\n", i, elapsed_time, fibonacci(i)); 	
			/*
			if (fptr != NULL){
				fprintf(fptr, "%d\t%f\n", i, elapsed_time); 	
				fclose(fptr);
 			}
			*/
		}
	
		return 0;
}
