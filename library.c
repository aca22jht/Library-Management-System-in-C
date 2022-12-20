#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 49 //Number of characters in TITLE, AUTHOR & SUBJECT CANNOT EXCEED 49 CHARACTERS
//Nested data structures (1st problem that I encountered at first was discovering the nested data structure here)
struct book{
     char *title;
     char *author;
     char *subject;
     int no;
}b, bc;

struct library {
    struct book collection;
    int num_books;
    struct library* next; //library is a pointer to another node
}thislib;


struct library *head = NULL;
struct library *current = NULL;
struct library *last = NULL;

/*Case 1) Add a book to the collection (must have complete information, title, author and subject)
NOTE: Can BOTH ADD data to FILE and print in FILE & READ from FILE.*/
void addBook(struct library *thislib){
    thislib = (struct library*) malloc(sizeof(struct library));

    thislib->next = head;
    head = thislib;

	FILE *up;
	char stitle[MAX];
	char sauthor[MAX];
	char ssubject[MAX];
	up = fopen("library.txt", "a");
        system("cls");
	printf("Enter Title: ");
	scanf("%s", stitle);
	printf("Enter Author: ");
	scanf("%s", sauthor);
	printf("Enter Subject: ");
	scanf("%s", ssubject);

	b.title = stitle;
	b.author = sauthor;
	b.subject = ssubject;

    thislib->collection.title = stitle;
    thislib->collection.author = sauthor;
    thislib->collection.subject = ssubject;

    printf("\nThe book %s author %s subject %s has been added to the library.", stitle, sauthor, ssubject);

    fprintf(up, "\n1 %s %s %s", thislib->collection.title, b.author, b.subject);

    fclose(up);

    char line[100];
    unsigned int line_count =0;
    up = fopen ("library.txt", "r");
    if (up == NULL)
    {
        printf("\nCouldn't Open File'\n");
        exit (1);
    }
    printf("\n");
    printf("Available books in library: ");
    printf("\n");
    while(fgets(line, 100, up)){
        printf("%s", line);

        if(line[strlen(line)-1] != '\n')
            printf("\n");
    }
    fclose(up);

    return 0;
}

//case 2) Delete a book from the collection by a particular title)
void deleteTitle(char titleName()){
   char line[101];


	FILE *up = fopen("library.txt", "r");
	if(up == NULL){
        printf("\nERROR: FILE NOT FOUND!");
        return;
	}

	while(!feof(up)){
        fgets(line, 100, up);
        if(strstr(line, titleName)== NULL){
            printf("%s", line);
        }
	}
	fclose(up);
}

//case 3) Delete all books from the collection by a particular author)
void deleteAuthor(char authorName()){
   char line[101];


	FILE *up = fopen("library.txt", "r");
	if(up == NULL){
        printf("\nERROR: FILE NOT FOUND!");
        return;
	}

	while(!feof(up)){
        fgets(line, 100, up);
        if(strstr(line, authorName)== NULL){
            printf("%s", line);
        }
	}
	fclose(up);
}


//Case 4) Search for a book from the collection by a particular title)
void searchBook(char titleName[]){
    char line[101];

	FILE *up = fopen("library.txt", "r");
	if(up == NULL){
        printf("\nERROR: FILE NOT FOUND!");
        return;
	}

	while(!feof(up)){
        fgets(line, 100, up);
    if(strstr(line, titleName)!=NULL){
        printf("\nList of a book on %s", titleName);
        printf("\nFOUND: %s", line);
        printf("The book %s is currently in the library.", titleName);
        printf("\n");

    }
	}
    printf("\nThe book %s is NOT currently in the library.", titleName);

	fclose(up);

}

//Case 5) Search for all books from the collection by a particular author)
void searchAuthor(char authorName[]){
    char line[101];

	FILE *up = fopen("library.txt", "r");
	if(up == NULL){
        printf("\nERROR: FILE NOT FOUND!");
        return;
	}

	while(!feof(up)){
        fgets(line, 100, up);
    if(strstr(line, authorName)!=NULL){
        printf("\nFOUND: %s", line);
    }
	}
	fclose(up);
}

//Case 6)  List all of the books by a particular author from the collection)
void listAuthor(char authorName[]){ //(7)
    char line[101];

	FILE *up = fopen("library.txt", "r");
	if(up == NULL){
        printf("\nERROR: FILE NOT FOUND!");
        return;
	}

	while(!feof(up)){
        fgets(line, 100, up);
    if(strstr(line, authorName)!=NULL){
        printf("\nFOUND: %s", line);
    }
	}
	fclose(up);
}

//Case 7) List all of the books by a particular subject from the collection)
void listSub(char subName[]){
    char line[101];

	FILE *up = fopen("library.txt", "r");
	if(up == NULL){
        printf("\nERROR: FILE NOT FOUND!");
        return;
	}

	while(!feof(up)){
        fgets(line, 100, up);
    if(strstr(line, subName)!=NULL){
        printf("\nFOUND: %s", line);
    }
	}
	fclose(up);
}

//Case 8) List all of the books in the original order
void display(struct library *thislib){
    char line[100];
    unsigned int line_count =0;
    FILE* up;
    up = fopen ("library.txt", "r");
    if (up == NULL)
    {
        printf("\nCouldn't Open File'\n");
        exit (1);
    }

    while(fgets(line, 100, up)){
        printf("%s", line);

        if(line[strlen(line)-1] != '\n')
            printf("\n");
    }
    fclose(up);
}

void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Press ENTER on keyboard to continue.....");
    getch();
}

//Function for updating no.of books in library, which will be printed out in the MAIN MENU when this program is executed
int numberofbooks(struct library *thislib){
    thislib = (struct library*) malloc(sizeof(struct library));
    FILE *fp = fopen("library.txt","r");
    char ch;
   int booksCount=0;
   if(fp==NULL) {
      printf("File \"%s\" does not exist!!!\n", "library.txt");
      return -1;
   }
   //read character by character and check for new line
   while((ch=fgetc(fp))!=EOF) {
      if(ch=='\n')
         booksCount++;
   }
   //close the file
   fclose(fp);
   thislib->num_books = booksCount;
   printf("Total number of books in library are currently: %d\n", booksCount);
   return 0;
}


int main()
{
    welcomeMessage();
    system("cls"); //clears current page for next executable instruction
	printf("DONE BY: Jasmine Hui Ping Tay\n");
	printf("STUDENT ID: ACCA22JHT");

	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MAIN MENU>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	unsigned int choice;
    int num_books, a;
    char stitle[MAX];
    char sauthor[MAX];
    char ssubject[MAX];
   
        printf("\n\n1) Add a book to a collection\n");
        printf("2) Delete a book from the collection by a particular title\n");
        printf("3) Delete all books from the collection by a particular author\n");
        printf("4) Search for a book from the collection by a particular title\n");
        printf("5) Search for all books from the collection by a particular author\n");
        printf("6) List all of the books by a particular author from the collection\n");
        printf("7) List all of the books by a particular subject from the collection\n");
        printf("8) List all of the books in the original order\n");
        printf("\n");
        numberofbooks(num_books); //call function for updating the number of books in library
        printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        printf("\n\nEnter choice: ");
        scanf("%u", &choice);

                    switch(choice){
					case 1:
					    addBook(0);
					break;

					case 2:
					    system("cls");
                        printf("\nEnter the title to delete the book(s) with this particular title: ");
                        getchar();
                        gets(stitle);
                        printf("Available books now in library are: ");
                        deleteTitle(stitle);
					break;

					case 3:
					    system("cls");
                        printf("\nEnter the author name to delete all books authored by him/her: ");
                        getchar();
                        gets(sauthor);
                        printf("Available books now in library are: ");
                        deleteAuthor(sauthor);
					break;

					case 4:
                        system("cls");
                        printf("\nEnter the title: ");
                        getchar();
                        gets(stitle);
                        searchBook(stitle);
					break;

					case 5:
                        system("cls");
                        printf("\nEnter an author to search for all books in the library authored by him/her: ");
                        getchar();
                        gets(sauthor);
                        printf("\nList of all books by %s: ", sauthor);
                        searchAuthor(sauthor);
					break;

					case 6:
                        system("cls");
                        printf("\nEnter an author to list all books in the library authored by him/her: ");
                        getchar();
                        gets(sauthor);
                        printf("\nList of all books by %s: ", sauthor);
                        listAuthor(sauthor);
                    break;

                    case 7:
                        system("cls");
                        printf("\nEnter a subject to list all books in the library containing it: ");
                        getchar();
                        gets(ssubject);
                        printf("\nList of all books on %s: ", ssubject);
                        listSub(ssubject);
                    break;

					case 8:
					    system("cls");
						display(0); 
					break;
					default:
					    system("cls");
						printf("Invalid choice...\n");
						printf("Thank you & have a nice day! :D\n");
                    }

}



