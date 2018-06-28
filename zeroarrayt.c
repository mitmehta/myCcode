#include<stdio.h>

void zeroAddEnd(int arr[], int size)
{
int count = 0;
int i;
for(i = 0; i < size; i++) {
if(arr[i] != 0)
arr[count++] = arr[i];
}
while(count < size)
arr[count++] = 0;
}

void printArray(int arr[], int size)
{
int i;
for(i = 0; i < size; i++)
printf("%d\t", arr[i]);
}

int main()
{
int arr[] = {1, 3, 0, 4, 8, 0, 7, 0, 6, 0};
int size = sizeof(arr) / sizeof(arr[0]);
printArray(arr, size);
printf("\n\n");
zeroAddEnd(arr, size);
printArray(arr, size);
printf("\n");
}
