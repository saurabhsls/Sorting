#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void mysort(char line[111][111],int n) {
	char temp[111];
	int i,j;
	for(i=0;i<n;i++) {
    		for(j=i+1;j<n;j++) {
        		if(strcmp(line[i],line[j])>0)
			{
            			strcpy(temp,line[i]);
            			strcpy(line[i],line[j]);
            			strcpy(line[j],temp);
        		}
		}
	}
}

void csort(char line[111][111],int n, int no) {
	char temp[111];
	int i,j,k;
	int l1,l2;
	int count;
	for(i=0;i<n;i++)  { 
		for(j=i+1;j<n;j++){
			l1 = 0;
			l2 = 0;
			count = 0;
			for(k=0;line[i][k]!='\0';k++) {
				if(line[i][k]==' ')
					count++;
				
				if(count==(no-1))
					break;
				
				++l1;
			}
			count = 0;
			for(k=0;line[j][k]!='\0';k++) {
				if(line[j][k]==' ')
					count++;
				
				if(count==(no-1))
					break;
				
				++l2;
			}
        		if(strcmp(line[i]+l1,line[j]+l2)>0)
			{
            			strcpy(temp,line[i]);
            			strcpy(line[i],line[j]);
            			strcpy(line[j],temp);
        		}
		}
	}
}

void small(char line[111][111],int n) {
	
	int i,j;	
	
	for(i=0;i<n;i++) 
	{	
		for(j=0;line[i][j]!=' ';j++)
		{
			if(line[i][j]>='A' && line[i][j]<='Z') 
			{
			line[i][j] = line[i][j] + 32;
			}
		}
	}
}

void new(char line[111][111], int count) {
	char sentence[100];
	FILE *fp = fopen("Destination.txt","w");
	int i;
	for(i=0;i<count;i++)   {
		fprintf(fp,"%s\n",line[i]);
	}
	fclose(fp);
}

void rev(char line[111][111],int count) {
	int i;
	for(i=(count-1);i>=0;i--) {
		printf("\n%s",line[i]);
	}

}

void check(char line [111][111],int num)  {
	char c[111][111];
	int i,j;
	int flag = 0;
	for(i=0;i<num;i++) {
		for(j=0;j<num;j++)  {
				c[i][j] = line[i][j];
		}
	}
	mysort(c,num);
	
	for(i=0;i<num;i++) {
			if(strcmp(line[i],c[i]))  // returns 1 if not equal
				flag =1;
				break;
		}
	if(flag==1)
		printf("~~File is not sorted~~");
	else
		printf("~~File is sorted~~");
}

int dupcheck(char uniq[111][111],int num,char s[]) {  //returns 1 if equal
	int i;
	for(i=0;i<num;i++) {
			if( !( strcmp(uniq[i],s) ) )
				return 1;
	}
	return 0;
}

void nodupfill(char line[111][111],char uniq[111][111],int count) {
	int i;
	for(i=0;i<count;i++)  {
	if( (dupcheck(uniq,count,line[i]) )==0 ) //ie if elem no exist as it returns 1 if elem exists
		strcpy(uniq[i],line[i]);			
	}

}


void weeksort(char file[111][111],int count) {
	char w[111][111] = {"Mon","mon","MON","monday","Monday","MONDAY",
				"Tue","TUE","tue","tuesday","Tuesday","TUESDAY",
				"Wed","WED","wed","wednesday","WEDNESDAY","Wednesday",
				"thu","THU","Thu","thursday","THURSDAY","Thursday",
				"fri","FRI","Fri","friday","Friday","FRIDAY",
				"sat","Sat","SAT","Saturday","SATURDAY","saturday",
				"sun","Sun","SUN","sunday","Sunday","SUNDAY"};
	int i,f=1;
	for(i=0;i<7;i++) {
		if(file[0]!=w[i]) {
			printf("\n ~File has other words than days pls try again~\n");
			f = 0;  
			break;
		}			
	}	
	
	while(f) {
	int temp[111];
	int j;
	for(i=0;i<count;i++){
		for(j=0;j<7;j++){
			char f[5];
			char we[5];
			strcpy(f,file[i]);
			strcpy(we,w[j]);
			if(!(strcmp(f,we))){
				temp[i]=j;
			}
		}
	}
	
	int a;
        for (i = 0; i < count; ++i) 
        {
            for (j = i + 1; j < count; ++j)
            {
                if (temp[i] > temp[j]) 
                {
                   a =  temp[i];
                   temp[i] = temp[j];
                    temp[j] = a;
                }
            }
        }
 
	for(i=0;i<7;i++) {
		for(j=0;j<count;j++) {
			if(temp[j]==i)
				printf("%s ",w[temp[j]]);
		}
	}
	}
}


void monthsort(char file[111][111],int count) {
	char w[111][111] = {"january","January","JANUARY","jan","Jan","JAN",
				"february","February","FEBRUARY","feb","Feb","FEB",
				"march","March","MARCH","mar","Mar","MAR",
				"april","April","APRIL","apr","April","APRIL",
				"may","May","MAY",
				"june","June","JUNE","jun","Jun","JUN",
				"july","July","JULY","jul","Jul","JUL",
				"august","August","AUGUST","aug","Aug","AUG",
				"september","September","SEPTEMBER","sept","Sept","SEPT",
				"october","October","OCTOBER","oct","Oct","OCT",
				"november","November","NOVEMBER","nov","Nov","NOV",
				"december","December","DECEMBER","dec","Dec","DEC",}; //j
	int i;
	for(i=0;i<12;i++) {
		if(file[0]!=w[i]) {
			printf("File has other words than Months");
			exit(1);
		}			
	}	

	int temp[111];
	int j;
	for(i=0;i<count;i++){
		for(j=0;j<7;j++){
			char f[5];
			char we[5];
			strcpy(f,file[i]);
			strcpy(we,w[j]);
			if(!(strcmp(f,we))){
				temp[i]=j;
			}
		}
	}
	
	int a;
        for (i = 0; i < count; ++i) 
        {
            for (j = i + 1; j < count; ++j)
            {
                if (temp[i] > temp[j]) 
                {
                   a =  temp[i];
                   temp[i] = temp[j];
                    temp[j] = a;
                }
            }
        }
 
	for(i=0;i<7;i++) {
		for(j=0;j<count;j++) {
			if(temp[j]==i)
				printf("%s ",w[temp[j]]);
		}
	}
}