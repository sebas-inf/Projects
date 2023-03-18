#include <stdio.h>
#include <ctype.h>
#define LEN 200
/*
This program will find if str1 is a subsequence of str2
*/
/*Initializes the main function*/
int main(){
	char str1[LEN + 1];
	char str2[LEN + 1];
	/*Prompts the user to enter the first word and appends it to str1*/
	printf("Enter first word: ");
	scanf("%s", str1);
	/*Prompts the user to enter the second word and appends it to str2*/
	printf("Enter second word: ");
	scanf("%s", str2);
	/*Initializes pointers p and q*/
	char *p, *q;
	/*Sets pointers p and q to strings str1 and str2 respectively*/
	p = str1;
	q = str2;
	for(p = str1; *p != '\0'; p++){
		/*Sets the values in pointer p and pointer q to their lower case equivalent at the start of each loop*/
		*p = tolower(*p);
		*q = tolower(*q);
		/*If pointer q is at the end of the string then it will break out of the loop*/
		if(*q == '\0')
			break;
		/*This nested loop will run until the character in pointer p is equal to the character in pointer q**/
		while(*q != *p){
			/*If pointer q is not at the null value, moves pointer q to the next value in str2 and sets the value in *q to its lower case equivalent*/
			if(*q != '\0'){
				q++;
				*q = tolower(*q);
			}	
			/*If pointer q is at the null value it breaks out of the while loop*/
			if(*q == '\0')
				break;
		}
		/*If there is a value in pointer q that is equal to the value in pointer p it moves pointer q to the next value and continues the for loop*/
		q++;
	}
	/*If pointer p is at the null value it means that the loop found values in pointer q that would make it a substring of p and it will return yes*/
	if(*p == '\0') printf("YES\n");
	/*If pointer q reached the end of the string and it didn't find characters in order that would make str1 a substring of str2 then it will return no*/
	else printf("NO\n");
	return 0;
}

