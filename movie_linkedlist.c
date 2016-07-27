/*
 	Author		:Felipe Corona
	Date		:November 21, 2014
	Description	: Lab 8 - Movie Linked List
*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct movie_node
{
	char title[250];
	int year;
	unsigned char rating;
	struct movie_node *next;
};

typedef struct movie_node movie_t;

int main()
{
	movie_t *first = NULL;
	movie_t *last = NULL;
	int count = 0;
	
	printf("%d Movie(s) in the database. Update, Search, or Quit (U/S/Q): ", count);
	char response;
	scanf(" %c",&response);
	printf("\n");

	while(response != 'Q')
	{
		if(response == 'U' || response == 'u')
		{
			if(count == 0)
			{
				first = malloc(sizeof(movie_t));
				movie_t *temp = malloc(sizeof(movie_t));
				printf("Name of the movie: ");
				scanf(" %[^\n]%*c", temp->title);
				printf("Year: ");
				scanf("%d", &temp->year);
				printf("Rating: ");
				scanf("%hhu", &temp->rating);			
				temp->next = NULL;
		
				first = temp;
				last = first;
				count++;

				printf("Movie %s is added to the database.\n", temp->title);	
				printf("\n");
			}
			else
			{
				movie_t *temp = malloc(sizeof(movie_t));
				printf("Name of the movie: ");
				scanf(" %[^\n]%*c", temp->title);
				printf("Year: ");
				scanf("%d", &temp->year);
				printf("Rating: ");
				scanf("%hhu", &temp->rating);
				temp->next = NULL;

				last->next = temp;
				last  = temp;
				count++;
				
				printf("Movie %s is added to the database.\n", temp->title);
				printf("\n");
			}
		}
		if(response == 's' || response == 'S')
		{
			char temptitle[250];
			int found = 0;
			printf("Name of the movie: ");
			scanf(" %[^\n]%*c", temptitle);
			if(first == NULL)
			{
				printf("Movie %s does not exist in the database. \n", temptitle);
			}
			else
			{
			movie_t *traverse = malloc(sizeof(movie_t));
			traverse = first;
			while(traverse->next != NULL && found == 0)
			{
				if(strcmp(traverse->title, temptitle) == 0)
				{
					found = 1;
					printf("Year: %d\n", traverse->year);
					printf("Rating: %hhu\n", traverse->rating);
				}
				else
				{
				
					traverse = traverse->next;
				}
			}
			if((strcmp(traverse->title, temptitle) == 0) && found == 0)
			{
				printf("Year: %d\n", traverse->year);
				printf("Rating: %hhu\n", traverse->rating);
			}
			else if(found != 1)
			{
				printf("Movie %s does not exist in the database.\n", temptitle);
			}
			}	
		}
		printf("%d Movie(s) in the database. Update, Search, or Quit (U/S/Q): ", count);
		scanf(" %c", &response);
	}
	


	free(first);
	free(last);
		
	return 0;
}
