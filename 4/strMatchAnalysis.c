#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void strMatch(int* str, int* pat, int strlen, int patlen){
	int i,j;
	for(i=0;i<strlen-patlen;i++){
		j=0;
		while(++count && pat[j]==str[i+j] && j<patlen){
			j++;
		}
		if (j==patlen) return;
	}
}

void main(){
	int n,i;
	int *str;
	
	FILE *b, *w, *a;
	system("rm a.txt b.txt w.txt");
	b = fopen("b.txt","a");
	w = fopen("w.txt","a");
	a = fopen("a.txt","a");
	
	for(n=10;n<1000;n+=10){
		str = (int*)calloc(n,sizeof(int));
		
		int pat[] = {0,0,0,0};
		
		//Best Case
		count=0;
		strMatch(str,pat,n,4);
		fprintf(b,"%d\t%d\n", n, count);
		
		//Worst Case
		count=0;
		pat[3]=1;
		strMatch(str,pat,n,4);
		fprintf(w,"%d\t%d\n", n, count);
		
		//Average Case
		count=0;
		pat[1] = pat[2] = 1;
		pat[3]=0;
		str[(n-1)/2] = str[(n-1)/2 + 1] = 1;
		strMatch(str,pat,n,4);
		fprintf(a,"%d\t%d\n", n, count);
		
	}
	
	fclose(b); fclose(a); fclose(w);
}
