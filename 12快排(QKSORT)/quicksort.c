#include "quicksort.h"

//快速排序
int Quick_Sort(int *array, int low, int high)
{
	int i = low, j = high;
	//将第一个数作为基准值 
	int stand = array[i];
	
	//进行第一轮的排序 
	while(i < j){
		//如果基准值小于最右边的值时，继续执行，j往前 
		while(i < j && array[j] >= stand){
			j--;
		}
		//跳出循环，数据进行交换 
		array[i] = array[j];
		
		// 将事先保存好的基准值与左边的值进行比较，
		// 如果基准值大，保持不变，i往后 
		while(i < j && array[i] <= stand){
			i++;
		}
		//跳出循环，数据进行交换 
		array[j] = array[i];
	}
	
	//跳出循环，将基准值放入数据中 
	array[i] = stand;
	
	//之前基准值左边的所有数据再次进行快速排序（递归） 
	if(i-1 > low){
		Quick_Sort(array, low, i-1);
	}
	
	//之前基准值右边的所有数据再次进行快速查找（递归）
	if(i+1 < high){
		Quick_Sort(array, i+1, high);
	}
	
	return 0;
}
