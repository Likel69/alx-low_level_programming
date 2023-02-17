#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/* betty style doc for function main goes there */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	
	if (n>0){
		printf("%d%s" n, "is positive");
	}
	
	else if (n == 0){
		printf("%d%s" n, "is zero %d");
	}
	
	else {
		printf("%d%s" n, "is negative %d");
	}
	
	return (0);
}
