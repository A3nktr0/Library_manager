#include "library_manager.h"


int main(int argc, char* argv[])
{
	int choice = 0;
	char inputTitle[100];
	char inputAuthor[100];
	int inputRelease = 0;
	int inputPages = 0;
	int inputID = 0;
	int IDChoice = 0;
	int updateChoice = 0;


	printf("\n**************** WELCOME TO YOUR AWESOME LIBRARY ****************\n");
	List* myLibrary = initialize();
	delete_node(myLibrary, 0);

	do
	{
		printf("\n1) List all books		2) Create new book	3) Update book	4) Delete book	5) EXIT\n");
		printf("\nChoice : ");
		choice = custom_fgets_number();

		if (choice == 1)
		{
			display_list(myLibrary);
		}
		else if (choice == 2)
		{
			inputID++;
			printf("\nEnter book's title : ");
			custom_fgets(inputTitle, 100);
			printf("Enter author's name : ");
			custom_fgets(inputAuthor, 100);
			printf("Enter date of release : ");
			inputRelease = custom_fgets_number();
			printf("Enter number pages : ");
			inputPages = custom_fgets_number();

			insert_node(myLibrary,inputID ,inputTitle, inputAuthor, inputRelease, inputPages);
		}
		else if (choice == 3)
		{
			printf("\nSelect ID to update : ");
			IDChoice = custom_fgets_number();
			printf("\n1) Update Title		2) Update Author	3) Update Release	4) Update Pages		5) Cancel\n");
			do
			{
				printf("\nUpdate choice : ");
				updateChoice = custom_fgets_number();
				if (updateChoice == 1)
				{
					printf("New title : ");
					custom_fgets(inputTitle, 100);
				}
				else if (updateChoice == 2)
				{
					printf("New author : ");
					custom_fgets(inputAuthor, 100);
				}
				else if (updateChoice == 3)
				{
					printf("New release : ");
					inputRelease = custom_fgets_number();
				}
				else if (updateChoice == 4)
				{
					printf("New pages : ");
					inputPages = custom_fgets_number();
				}

				update_node(myLibrary, IDChoice, inputTitle, inputAuthor, inputRelease, inputPages);

			} while (updateChoice != 5);

		}
		else if (choice == 4)
		{
			char deleteChoice;

			printf("\nChoose id to be deleted : ");
			IDChoice = custom_fgets_number();


			printf("\n********** WARNING **********\n");
			printf("Are you sure you want to delete this book (y/n) : ");
			deleteChoice = getchar();
			if (deleteChoice == 'y' || deleteChoice == 'Y')
			{
				delete_node(myLibrary, IDChoice);
				empty_buffer();
			}
			else
			{
				empty_buffer();
				continue;
			}
		}
		else if (choice == 5)
		{
			break;
		}
	} while (choice != 5);
	printf("\nBye, come back soon !\n");
	return 0;
}