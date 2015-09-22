#include<stdio.h>
#include<time.h>

int fibonacci(int number){
	int a = 0;
	int b = 1;

	if (number == 0) return 0;
	if (number == 1) return 1;
	if (number == 2) return 1; 	
	
	int result = 0;
	if ( (number % 2) == 0){ 
		int k = number >> 1;
		int tmp1 = fibonacci(k);
		int tmp2 = fibonacci(k+1);
		return tmp1*((tmp2 << 1) - tmp1);
	}
	else{
		int k = (number - 1) >> 1;
		int tmp1 = fibonacci(k+1);
		int tmp2 = fibonacci(k);
		return tmp1*tmp1 + tmp2*tmp2;
	}

}

int main(){
	
		int i;

		for ( i = 0; i < 47; i++){
			
			clock_t start = clock();
			int result = fibonacci(i);
			clock_t end = clock();
			
			double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
			FILE *fptr = fopen("fib_fast_doubling.txt", "a");
			if (fptr != NULL){
				fprintf(fptr, "%d\t%f\n", i, elapsed_time); 	
				fclose(fptr);
 			}
		}
	
		return 0;
}
