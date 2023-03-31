#include <stdio.h>
#include <string.h>
#define LEN 150

/*
This program will take in a file with summarazed data that has 5 arguments, 4 strings separated by comma, and a double for with the score the last argument. It will
then organize the files by the score of the data in descending order.
*/

/*Coffee struct*/
struct coffee{
	char country[LEN + 1];
	char region[LEN + 1];
	char owner[LEN + 1];
	char variety[LEN + 1];
	double score;
};

void selection_sort(struct coffee list[], int n);

int main(){
	
	char input[LEN + 1];
	char output[LEN + 1] = "sorted_";
	FILE *rFile, *wFile;
	int i = 0, count = 0;
	struct coffee coffee_a[101];
	
	/*Prompts the use for the name of the file to be read*/
	printf("Enter the file name: ");
	scanf("%s", input);

	/*Sets the name of output to sorted_ the name of the file to read*/
	strcat(output, input);
	
	rFile = fopen(input, "r");
	wFile = fopen(output, "w");
	
	if((rFile == NULL) || (wFile == NULL)){
		printf("Error opening file\n");
		return 1;
	}
	
	while(!feof(rFile) && !ferror(rFile)){
		
		if(fscanf(rFile, "%[^,],%[^,],%[^,],%[^,],%lf\n", coffee_a[i].country, coffee_a[i].region, coffee_a[i].owner, coffee_a[i].variety, &coffee_a[i].score) == 5)
			count++;
		i++;

	}
	
	/*Sorts the coffee list in order of scores*/
	selection_sort(coffee_a, count);

	/*Writes the sorted coffee list into sorted file*/
	for(i = 0; i < count; i++)
		fprintf(wFile, "%s, %s, %s, %s, %.2lf\n", coffee_a[i].country, coffee_a[i].region, coffee_a[i].owner, coffee_a[i].variety, coffee_a[i].score);
	
	/*Prints the name of the sorted file returned*/
	printf("Output file name: \n%s\n", output);
		
	fclose(rFile);
	
	fclose(wFile);

	return 0;
}

/*Will sort the coffee list by scores in descending order*/
void selection_sort(struct coffee coffee_a[], int n){
	
	int i, smallest = 0;
	struct coffee temp;
	
	/*Return when all elements have been iterated over*/
	if(n == 1)
		return;
	
	/*Finds the coffee with the lowest score and sets the index of it to smallest*/
	for( i = 1; i < n; i++){
		if(coffee_a[i].score < coffee_a[smallest].score)
			smallest = i;
	}
	
	/*Swaps the position of the coffee with the lowest score and the last coffee on the current list*/
	if(smallest < n - 1){
		temp = coffee_a[n - 1];
		coffee_a[n - 1] = coffee_a[smallest];
		coffee_a[smallest] = temp;
	}
	
	/*Recursive call of selection_sort*/
	selection_sort(coffee_a, n - 1);
	
}












































