#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void merge(int *arr, int l, int m, int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int arr1[n1], arr2[n2];
	
	for(i=0;i<n1;i++)
		arr1[i] = arr[l+i];
	for (i=0;i<n2;i++)
		arr2[i] = arr[m+i+1];
		
	i=0; j=0; k=l;
		
	while(i<n1 && j<n2){
		count++;
		if (arr1[i] <= arr2[j])
			arr[k++] = arr1[i++];
		else 
			arr[k++] = arr2[j++];
	}
	
	while(i<n1)
		arr[k++] = arr1[i++];
	while(j<n2)
		arr[k++] = arr2[j++];
}


void mergeSort(int *arr, int l, int r){
	if (l<r){
		int mid = (l+r)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}


void worstMerge(int *arr, int l, int m, int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int arr1[n1], arr2[n2];
	
	for(i=0;i<n1;i++)
		arr1[i] = arr[l+i];
	for (i=0;i<n2;i++)
		arr2[i] = arr[m+i+1];
		
	i=0; j=0; k=l;
		
	while(i<n1 && j<n2){
		count++;
		if (arr1[i] > arr2[j])
			arr[k++] = arr1[i++];
		else 
			arr[k++] = arr2[j++];
	}
	
	while(i<n1)
		arr[k++] = arr1[i++];
	while(j<n2)
		arr[k++] = arr2[j++];
}


void worstCaseGenerate(int *arr, int l, int r){
	if (l<r){
		int mid = (l+r)/2;
		worstCaseGenerate(arr,l,mid);
		worstCaseGenerate(arr,mid+1,r);
		worstMerge(arr,l,mid,r);
	}
}


void main(){
	int n,i,j;
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
		mergeSort(arr,0,n-1);
		fprintf(b,"%d\t%d\n",n,count);
		
		//Worst Case
		worstCaseGenerate(arr,0,n-1); //to generate worst case input
		mergeSort(arr,0,n-1);
		fprintf(w,"%d\t%d\n",n,count);
		
		//Average Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		mergeSort(arr,0,n-1);
		fprintf(a,"%d\t%d\n",n,count);
	}
	
	fclose(b); fclose(a); fclose(w);
}
