#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void insertionSort(int* arr, int n){
	int i,j,cur;
	for(i=1;i<n;i++){
		cur=arr[i];
		j=i-1;
		while(++count && arr[j]>arr[i] && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=cur;
	}
}

void main(){
	int n,i;
	int *arr;
	
	FILE *b,*w,*a;
	system("rm a.txt b.txt w.txt");
	b = fopen("b.txt","a");
	w = fopen("w.txt","a");
	a = fopen("a.txt","a");
	
	for(n=10;n<1000;n+=10){
		arr = (int*)malloc(n*sizeof(int));
		
		//Best Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = (i==0) ? rand()%100 : arr[i-1]+rand()%10;
		}
		insertionSort(arr,n);
		fprintf(b,"%d\t%d\n",n,count);
		
		//Worst Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = 2*n - i;
		}
		insertionSort(arr,n);
		fprintf(w,"%d\t%d\n",n,count);
		
		//Average Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		insertionSort(arr,n);
		fprintf(a,"%d\t%d\n",n,count);
	}
	
	fclose(b); fclose(a); fclose(w);
}
