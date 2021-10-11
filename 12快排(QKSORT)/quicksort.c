#include "quicksort.h"

//��������
int Quick_Sort(int *array, int low, int high)
{
	int i = low, j = high;
	//����һ������Ϊ��׼ֵ 
	int stand = array[i];
	
	//���е�һ�ֵ����� 
	while(i < j){
		//�����׼ֵС�����ұߵ�ֵʱ������ִ�У�j��ǰ 
		while(i < j && array[j] >= stand){
			j--;
		}
		//����ѭ�������ݽ��н��� 
		array[i] = array[j];
		
		// �����ȱ���õĻ�׼ֵ����ߵ�ֵ���бȽϣ�
		// �����׼ֵ�󣬱��ֲ��䣬i���� 
		while(i < j && array[i] <= stand){
			i++;
		}
		//����ѭ�������ݽ��н��� 
		array[j] = array[i];
	}
	
	//����ѭ��������׼ֵ���������� 
	array[i] = stand;
	
	//֮ǰ��׼ֵ��ߵ����������ٴν��п������򣨵ݹ飩 
	if(i-1 > low){
		Quick_Sort(array, low, i-1);
	}
	
	//֮ǰ��׼ֵ�ұߵ����������ٴν��п��ٲ��ң��ݹ飩
	if(i+1 < high){
		Quick_Sort(array, i+1, high);
	}
	
	return 0;
}
