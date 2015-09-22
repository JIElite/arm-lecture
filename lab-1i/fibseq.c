#include <stdio.h>
#include <time.h>
extern int fibonacci(int x);

int main(int argc, char **argv)
{
  	int number=0;
  	int result=0;
	
	FILE* fptr = fopen("fib_i.txt", "a");
  	scanf("%d",&number);
  	
	clock_t start = clock();
	result = fibonacci(number);
	clock_t end = clock();

	// calculate elapsed time
	double elapsed_time = (double)(end - start);
	fprintf(fptr, "%d\t%f\n", number, elapsed_time);
	fclose(fptr);


  	return 0;
}

