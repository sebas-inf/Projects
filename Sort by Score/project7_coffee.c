#include <stdio.h>
#include <string.h>
#define LEN 150

/*
Sebastian Infante Murguia U04743487
This program will take in a file with the summarized data for arabica coffee beans. It will then read the file and ignore the commas when appending the 5 arguments. If it is able to append the five arguments to the struct list then it will add 1 to count.
Then the struct list will be sent to a selection sort function, in the function the scores of each coffee will be compared and then organized in descending order. Then the sorted struct list will be sent to a loop in which the items in the sorted struct 
list will be printed onto the sorted file. Then the files will be closed and a message with the output file name will be returned.
*/

/*Coffee struct*/
struct coffee{
	char country[LEN + 1];
	char region[LEN + 1];
	char owner[LEN + 1];
	char variety[LEN + 1];
	double score;
};

/*Initialization of selection_sort function*/
void selection_sort(struct coffee list[], int n);

int main(){
	
	/*Initialization of variables*/
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
	
	/*Opens the files to be read and written*/
	rFile = fopen(input, "r");
	wFile = fopen(output, "w");
	
	/*If the file to be read or to be written does not exist it ends the program*/
	if((rFile == NULL) || (wFile == NULL)){
		printf("Error opening file\n");
		return 1;
	}
	
	/*Reads file given until it reaches its end or an error occurs*/
	while(!feof(rFile) && !ferror(rFile)){
		
		/*If the expected amount of elements are appended then it will increase count by one*/
		if(fscanf(rFile, "%[^,],%[^,],%[^,],%[^,],%lf\n", coffee_a[i].country, coffee_a[i].region, coffee_a[i].owner, coffee_a[i].variety, &coffee_a[i].score) == 5)
			count++;
		/*Moves i to next value for the struct list*/
		i++;

	}
	
	/*Sorts the coffee list in order of scores*/
	selection_sort(coffee_a, count);

	/*Writes the sorted coffee list into sorted file*/
	for(i = 0; i < count; i++)
		fprintf(wFile, "%s, %s, %s, %s, %.2lf\n", coffee_a[i].country, coffee_a[i].region, coffee_a[i].owner, coffee_a[i].variety, coffee_a[i].score);
	
	/*Prints the name of the sorted file returned*/
	printf("Output file name: \n%s\n", output);
		
	/*Closes file read*/
	fclose(rFile);
	
	/*Closes file written*/
	fclose(wFile);

	return 0;
}

/*Will sort the coffee list by scores in descending order*/
void selection_sort(struct coffee coffee_a[], int n){
	
	/*Initializes variables for function*/
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












































