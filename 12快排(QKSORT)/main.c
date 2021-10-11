#include "quicksort.h"

int main()
{
	int array[N] = {1, 3, 5, 10, 23, 8, 7, 6, 2, 0};
	int i = 0;
	
	printf("≈≈–Ú«∞:");
	for(i=0; i<N; i++){
		printf("%d ",array[i]);
	}
	putchar(10);
	
	//øÏ≈≈ 
	Quick_Sort(array, 0, N-1);
	
	printf("≈≈–Ú∫Û:");
	for(i=0; i<N; i++){
		printf("%d ",array[i]);
	}
	putchar(10);
	
	return 0;
}
