#include <stdio.h>

int main(){
	int num;
	printf("Enter the number of elements:");
	scanf("%d",&num);
	
	printf("enter %d numbers :\n",num);
	
	for(int i=0;i<num;i++){
		int input;
		scanf("%d",&input);
		
		if(input%2==0){
			printf("%d is Even number\n",input);
		}
		else{
			printf("%d is Odd Number\n",input);
		}
	}
	return 0;
}