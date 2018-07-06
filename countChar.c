#include<stdio.h>
#include<stdlib.h>
#define NO_OF_CHARS 256

int *counting_each_char(char *str)
{
	int *count = (int *)calloc(sizeof (int), NO_OF_CHARS);
	int i;
	for(i=0; *(str + i); i++)
		count[*(str+i)]++;
	return count;
}

int  count_char(char *str)
{
	int *count = counting_each_char(str);
	int index = -1, i;
	for(i=0; *(str + i); i++)
	{
		if(count[*(str+i)]==1) {
			index =i;
			break;
		}
	}
	free(count);
	return index;
}
int main()
{
	char str[] = "geeksforgeeks";
	int index = count_char(str);
	if(index == -1) {
		printf("Either all character are repeating or string is empty\n");
	} else {
		printf("%c is the first non repeating character\n", str[index]);
	}
	return 0;
}
