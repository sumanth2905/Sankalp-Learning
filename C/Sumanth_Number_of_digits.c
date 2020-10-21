#include<stdio.h>
int main(){
	int num, val, count = 0;
	printf("Enter a number: ");
	scanf("%d",&num);
	val = num;		  #copy of the number for printing at the end
	while(num != 0){
		num = num / 10;
		count = count + 1;
	}
	printf("The number of digits in %d is %d",val,count);
	return 0;
}
