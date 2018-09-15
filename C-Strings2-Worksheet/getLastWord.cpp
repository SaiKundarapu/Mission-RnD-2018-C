/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>


char * get_last_word(char * str)
{
	int endspace = -1, i = 0, j = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			endspace = i;
		}
		i++;
	}

	if (endspace == -1)
		return "";

	char *res = (char *)malloc((i - endspace)*sizeof(char));
	i = endspace + 1;

	while (str[i] != '\0' && str[i] != ' ')
	{
		res[j++] = str[i++];
	}
	res[j] = '\0';

	return res;
}
