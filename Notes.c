#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dir.h>
#include<string.h>

int choice, option;

void home_page();
int menu(int);
char *file_path;
char ext [20] = ".txt";
char *string_cat;


int new_note();
int list(int);
int show();

int main (){
home_page();	
return 0;
}

// menu
int menu (int choice) {
	int a,b,c,p ;
	option = choice;
	switch (option){
		case 1: 
				a= new_note();
				if (a==2)
				home_page();
				break;
		case 2: 
				b= list(p);
		        if (b==2)
				home_page();
				break;
		case 3: 
				c= show();
			    if (c==2)
				home_page();
				break;
		case 4:
				exit(0);
		default :
				printf ("select the correct option\n");
				home_page();
				break;
		}
	}

// Home page
void home_page(){
	
	printf ("\n------------------------\n");
	printf (" :: Notes ::\n");
	printf ("Select the option\n");
	printf ("1) New \n"
			"2) List \n"
			"3) Show \n"
			"4) Exit\n");
	printf ("\n------------------------\n");
	scanf("%d", &choice);
	menu(choice);
	
}

// New note
int new_note(){
	
	FILE *fptr;
	char file_name[50];
	char path[200]= "C:/TO_DO/";
	
	char ch;
	int back;
	printf (" Enter the File Name\n");
	scanf("%s", file_name);
	
	mkdir (path);

	string_cat = strcat(path, file_name);
	
	file_path = strcat(string_cat, ext);
	
	printf ("\n File is created at  :%s\n", file_path );
	
	fptr =fopen (file_path, "w");
	
	printf ("\nEnter the Text and Press ctrl+z-> Enter to Save file\n");
	while ((ch =getchar())!=EOF)	
		fputc(ch, fptr);
		
	fclose(fptr);	
	
	printf (" \n Options \n"
			" 1) Save and Exit\n"
			" 2) Save and Continue\n");
    scanf("%d", &back);

	return (back);
}

// List
int list(int p){
	
	struct dirent *dp;
	int back;
	char path[200]= "C:/TO_DO/";
	
	DIR *dir = opendir(path);
	
	if (!dir){
		printf (" Unable to opent the dir\n");}
	
	printf ("List of file at the path %s\n", path);
	
	while((dp=readdir(dir))!=NULL){
		printf ("%s\n",dp->d_name);
	}
	closedir(dir);
	
	if (p!=1){
	printf (" \n Options \n"
			" 1) Exit\n"
			" 2) Continue\n");
	scanf("%d", &back);
	}

    return (back);
}

// Show
int show(){
	
    char filename[200];
	char ch;
	char path[200]= "C:/TO_DO/";
	int back;
    list(1);
   
    printf ("\nEnter the file name to open\n");
    
    scanf("%s", filename);
	
	string_cat = strcat(path, filename);
	
	file_path = strcat(string_cat, ext);
	
	FILE *fptr;
	
	fptr = fopen (file_path, "r");
	
	if (fptr == NULL){
		printf(" Error while opening the file\n");
		exit(0);
	}
	printf("\n--------------------------------------------\n");
	while ((ch=fgetc(fptr))!=EOF){
			printf("%c", ch);
	}
	printf("\n--------------------------------------------\n");
	fclose(fptr);

	printf (" \n Options \n"
			" 1) Exit\n"
			" 2) Continue\n");
    scanf("%d", &back);

	return (back);
		
}
