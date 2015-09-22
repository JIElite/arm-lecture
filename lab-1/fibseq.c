#include <stdio.h>
#include <time.h>

extern int fibonacci(int x);

int main(int argc, char **argv)
{
  int number = 0;
  int result = 0;

  scanf("%d",&number);
  
  	clock_t start = clock();
  	result = fibonacci(number);
	clock_t end = clock();
	
	FILE *fptr = fopen("fib.txt", "a");
	if (fptr != NULL){
		double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
		fprintf(fptr, "%d\t%f\n", number, elapsed_time);
		fclose(fptr);
	}

  	printf("The fibonacci sequence at %d is: %d\n", number, result);
	
	return 0;
}

