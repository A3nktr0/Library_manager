#include "custom_fgets.h"

void empty_buffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

int custom_fgets(char* string, int length)
{
	char* inputPosition = NULL;

	if (fgets(string, length, stdin) != NULL)
	{
		inputPosition = strchr(string, '\n');
		if (inputPosition != NULL)
		{
			*inputPosition = '\0';
		}
		else
		{
			empty_buffer();
		}
		return 1;
	}
	else
	{
		empty_buffer();
		return 0;
	}
}

int custom_fgets_number()
{
	char number[100] = { 0 };
	if (custom_fgets(number, 100))
	{
		return atoi(number);
	}
	else
	{
		return 0;
	}
}