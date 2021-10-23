#include<string.h>
#include<stdio.h>
#include<stdlib.h>

extern void mysort(char line[111][111],int n);
extern void csort(char line[111][111],int n, int no);
extern void small(char line[111][111],int n);
extern void new(char line[111][111], int count);
extern void rev(char line[111][111],int count);
extern void check(char line [111][111],int num);
extern int dupcheck(char uniq[111][111],int num,char s[]);
extern void nodupfill(char line[111][111],char uniq[111][111],int count);
extern void weeksort(char file[111][111],int count);
extern void monthsort(char file[111][111],int count);


int main(int argc,char* argv[]) {

	char line[111][111];	// array to store contents of the file
	char uniq[111][111];	// array to be used for "duplicate" function
	char fname[20];		// array to store file name
	FILE *fptr = NULL; 
	int i = 0;
	int j,count =0;		// count to store number of lines.....i and j for loops
	char c;			// char used to count no of lines
	
	if(argv[1]==NULL){	// error handling if file name is not menioned
		printf("\n ~Please enter file name alongside ( ~~ sort filename.txt ~~ )\n ");
		exit(1);
	}
	
    fptr = fopen(argv[1], "r");		// opening the mentioned file
	if(fptr==NULL) {		// error msg for if the file doesnt exits
		printf("~~File not found~~\n");
		exit(1);
		}
    while(fgets(line[i],111, fptr))	 // storing file contents in array
	{       
	
	line[i][strlen(line[i]) - 1] = '\0';
        i++;
 	}
	
	fseek(fptr,0,SEEK_SET);		// resetting pointer to count no of lines	
	
	for (c = getc(fptr); c != EOF; c = getc(fptr)) {	//counting number of lines and storing in "count"
        	if (c == '\n') 
			count = count + 1; 
	}	

	printf("\nFile has been read\n");
	
	int p = 1;
	
	check(line,count);		// checking if file is already sorted
	
	printf("\nWould you like to try the additional options? (press '1' if yes or '0' if no)\n");
	scanf(" %d",&p);

	while(p!=0 && p!=1) {
		printf("\n~invalid choice~\n");	
		printf("\nWould you like to try the additional options? (press '1' if yes or '0' if no)\n");
		scanf(" %c",&p);
	}

	

	while(p) {
	_Bool f = 1;
	
	while(f) {
	printf("\n\n");
	printf("Type C for checking if the file is already sorted or not \n");
	printf("Type S for normal sort\n");
	printf("Type I for case insensitive sort\n");
	printf("Type O for saving output into another file\n");
	printf("Type R for reverse sort\n");
	printf("Type K for column based sort\n");
	printf("Type U for Removing duplicate lines from the file\n");
	printf("Type W for week sort\n");
	printf("Type M for Month sort\n");
	printf("Type Q to Quit \n");

	int d;
	char x;
	printf("\n\nEnter choice - ");
	scanf(" %c",&x);

	switch(x) {
		case 's' : case 'S':
			mysort(line,count);		// calling normal sort
				for(i=0;i<count;i++)		// printing sorted contents
					printf("%s\n",line[i]);
				printf("\n");
				break;
		case 'o' : case 'O' :
			new(line,count++);	
			for(i=0;i<count;i++)
					printf("%s\n",line[i]);
				printf("\n");
				break;


		case 'r' : case 'R' :
			rev(line,count);
				printf("\n");
				break;


		case 'k' : case 'K' :
			printf("Pls choose which word to sort based on\n(ie 1 for first, 2 for second...)");
			scanf(" %d",&d);
			csort(line,count,d);
			for(i=0;i<count;i++)
					printf("%s\n",line[i]);
				printf("\n");
				break;


		case 'c' : case 'C' :
			check(line,count);
			break;


		case 'u' : case 'U':
			nodupfill(line,uniq,count);
			for(i=0;i<count;i++)
				printf("\n%s",uniq[i]);
				break;


		case 'w' : case 'W' :
			weeksort(line,count);
			break;


		case 'q' : case 'Q' :
			f = 0;
			fclose(fptr);
			break;


		case 'i' : case 'I' :
			small(line,count);
			mysort(line,count);
			for(i=0;i<count;i++)
					printf("%s\n",line[i]);
				printf("\n");
				break;


		case 'm' : case 'M' :
			monthsort(line,count);
			break;


		default :
			printf("~Invalid chioce~");
			printf("\n");
			break;
		}		
	}
	}

return 0;
}