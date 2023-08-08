#include <stdio.h>

void mm(int a[][3],int b[][2],int c[][2],int m,int n,int p){
	for(int i=0;i<m;i++){
		for(int j=0;i<p;j++){
			c[i][j]=0;
			for(int k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}

int main(){
	int a[][3]={{1,2,3},{4,5,6}};
	int b[][2]={{7,8},{9,10},{11,12}};
	int c[2][2];
	
	int m=2,n=3,p=2;
	
	mm(a,b,c,m,n,p);
	
	printf("Resultant Matrix:\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			printf("%d",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}