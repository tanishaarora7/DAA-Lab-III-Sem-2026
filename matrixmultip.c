practical 03
MATRIX MULTIPLICATION 
TANISHA ARORA 25070521116

#include<stdio.h>
//TANISHA ARORA 25070521116
int main(){
	int m, n, n1, p;
	scanf("%d %d",&m,&n);
	int a[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d",&n1, &p);
	if(n != n1){
		printf("Invalid input");
		return 0;
	}
	int b[n1][p];
	for(int i=0;i<n1;i++){
		for(int j=0;j<p;j++){
			scanf("%d", &b[i][j]);
		}
	}
	int result[m][p];
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			result[i][j] = 0;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			for(int k=0;k<n;k++){
				result[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}