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
			struct timespec t1, t2;
				
			clock_gettime(CLOCK_REALTIME, &t1);
			int result = fibonacci(i);
			clock_gettime(CLOCK_REALTIME, &t2);
			
			long elapsed_time = t2.tv_nsec - t1.tv_nsec;
			FILE *fptr = fopen("fib_fast_doubling.txt", "a");
			if (fptr != NULL){
				fprintf(fptr, "%d\t%ld\n", i, elapsed_time); 	
				fclose(fptr);
 			}
		}
	
		return 0;
}
