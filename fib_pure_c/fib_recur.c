#include<stdio.h>
#include<time.h>


int fib(int n, int x, int y){
	
	if (0 == n) return 0;
	if (1 == n) return 1;

	return fib(n-1, y, x+y);

}

int main(){
	
		int i;

		for ( i = 0; i < 47; i++){
			
			struct timespec t1, t2;
			clock_gettime(CLOCK_REALTIME, &t1);
			int result = fib(i, 0, 1);
			clock_gettime(CLOCK_REALTIME, &t2);

			long elapsed_time = t2.tv_nsec - t1.tv_nsec;
	
			FILE *fptr = fopen("fib_recur.txt", "a");
			if (fptr != NULL){
				fprintf(fptr, "%d\t%ld\n", i, elapsed_time); 	
				fclose(fptr);
 			}
		}
	
		return 0;
}
