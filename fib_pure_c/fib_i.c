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
			struct timespec t1, t2;
			
			clock_gettime(CLOCK_REALTIME, &t1);
			int result = fibonacci(i);
			clock_gettime(CLOCK_REALTIME, &t2);
			
			long elapsed_time = t2.tv_nsec - t1.tv_nsec;
			FILE *fptr = fopen("fib_i.txt", "a");
			
			//fprintf(fptr, "%d\t%ld\t%d\n", i, elapsed_time, fibonacci(i)); 	
			if (fptr != NULL){
				fprintf(fptr, "%d\t%ld\n", i, elapsed_time); 	
				fclose(fptr);
 			}
		}
	
		return 0;
}
