////自定义my_memcpy函数，用于非重叠之间的内存拷贝函数
//结构体内存函数打印
////void * memcpy ( void * destination, const void * source, size_t num );
#include<stdio.h>
void* my_memcpy(void* dest, const void* src, size_t num)//void*通用类型，需要什么类型再强制转换为对于类型
{
	void* prt = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;//一个一个字节的进行交换数据
		++(char*)dest;
		++(char*)src;
	}
	//*prt = '\0';
	return prt;
}
struct Student
{
	char name[20];
	int age;
	int id;
};
int main()
{
	//char arr1[] = "abcdef";
	//char arr2[40]={0};
	/*int arr3[] = {1,2,3,4,5};
	int arr4[5] = {0};*/
	//my_memcpy(arr2, arr1, 4);
	struct Student arr3[3] = { {"zhangtian",15,1} ,{"heoehf",17,3}, {"baitian",18,2} };
	struct Student arr4[3] = {0};
	my_memcpy(arr4, arr3,sizeof(arr3));//用监视窗口看内存
	for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
	{
		printf("%s %d %d",arr4[i].name, arr4[i].age, arr4[i].id);//arr4是指针，如果单一变量采用如s.name
		printf("\n");	
	}
	//printf("%d",ret);
	//printf("%d", arr3);
	return 0;
}