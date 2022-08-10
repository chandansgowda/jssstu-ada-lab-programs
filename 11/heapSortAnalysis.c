#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int *arr, int n, int i){
	int largest = i;
	int left = 2*i +1;
	int right = 2*i +2;
	
	count++;
	
	if (left<n && arr[left]>arr[largest])
		largest = left;
	if (right<n && arr[right]>arr[largest])
		largest = right;
		
	if (largest!=i){
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapSort(int* arr, int n){
	for(int i=n/2-1; i>=0; i--){
		heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
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
			arr[i] = 1;
		}
		heapSort(arr,n);
		fprintf(b,"%d\t%d\n",n,count);
		
		//Worst Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = (i==0) ? rand()%100 : arr[i-1]+rand()%10;
		}
		heapSort(arr,n);
		fprintf(w,"%d\t%d\n",n,count);
		
		//Average Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		heapSort(arr,n);
		fprintf(a,"%d\t%d\n",n,count);
	}
	
	fclose(b); fclose(a); fclose(w);
}
