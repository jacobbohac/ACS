#include "suffix_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/* Jacob Bohac 130406
 * ACS distance matrix method
 *
 * 
 *
 */
void printString(char string[]){
	int i;
	int len;
	len = strlen(string);
	for(i =0; i < len; i++)
	printf("%c", string[i]);
	printf("\n");	

}


double getSimilarity(int length[], int n, int m){
	int i=0;
        int sum=0;

	for(i=0; i<n; i++){
	   sum += length[i];
	}
	return (sum/n)/log10(m);
}

double getDistance(int length[], int n, int m){
	int i=0;
        int sum=0;

	for(i=0; i<n; i++){
	   sum += length[i];
	}
	double similarity = (sum/n)/log10(m);
	double correction = (2 * log10(n))/n;
	return (1/similarity) - correction;
}
	
double getACS(char* String_A, char* String_B){
        unsigned long position;
	/*Create the suffix tree*/
	char strb[20];
	strcpy(strb, String_A);
	int m = strlen(strb);
	SUFFIX_TREE* tree = ST_CreateTree(strb, m);
	
	/*Strings to test*/
	char str[20];
	strcpy(str, String_B);
	int l[strlen(str)];
	char  substr[strlen(str)]; 

	
	
	int i=0;
	int j=0;
        for(i=0; i<strlen(str); i++){
	  l[i] =0;
	  for(j=1; j<strlen(str)-i+1; j++){
	    strncpy(substr, &str[i], j)[j] = 0;
	    
	   printString(substr);
	    position = ST_FindSubstring(tree, substr, strlen(substr));
	    if(position != ST_ERROR){
		l[i] =j;
	    }else{
		//printf("\nString DNE\n");
		//i++;
		//j=1;
	    }
	    
	  }
	printf("%d\n", l[i]);
	}
	
	//printf(" I == %d\n", i);
	printf("Similarity = %f\n", getSimilarity(l, i, m));
	printf("Distance = %f\n", getDistance(l, i, m));
	return getDistance(l, i, m);
}

int main()
{	

	//char String_A[] = "philologist";
	//char String_B[] = "lollipop";
        
	char String_A[] = "aaaatttttttttaaaaa";
	char String_B[] = "aaaaaaaattttttttt";

	double symDist;
	symDist = (getACS(String_A, String_B) + getACS(String_B, String_A))/2;
	printf("Symmetric distance measure = %f\n", symDist);
	

	return 0;
}




 //SUFFIX_TREE* tree = ST_CreateTree(String_A, 11);
	
	//ST_PrintTree(tree);

	//tree = ST_CreateTree(String_B, 8);
	//ST_PrintTree(tree);

	//getACS(String_A, String_B);
	//getACS(String_B, String_A);


