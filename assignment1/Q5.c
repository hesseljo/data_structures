/* CS261- Assignment 1 - Q. 5*/
/* Name: Joshua Hesseltine
 * Date: 10/9/15
 * Solution description: char assignments
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch)
{
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch)
{
     return ch-'A'+'a';
}

int isUpperCase(char ch)
{
    return 'A'<=ch && ch<='Z';
}

int isLowerCase(char ch)
{
    return 'a'<=ch && ch<='z';
}

void sticky(char* word)
{
	/*Convert to sticky caps*/
	for (int i = 0; i < strlen(word); i++)
	{
	    if (i % 2 == 0)
	    {
	        if ( isLowerCase(word[i]) )
	        {
	            word[i] = toUpperCase(word[i]);
	        }
	        else
	        {
	            // do nothing.
	        }
	    }
	    else
	    {
	        if ( isUpperCase(word[i]) )
	        {
	            word[i] = toLowerCase(word[i]);
	        }
	        else
	        {
	            // do nothing.
	        }
	    }
	}
}

int main()
{
    /*Read word from the keyboard using scanf*/
    char str[100];
    scanf("%s", str);
    /*Call sticky*/
    sticky(str);
    /*Print the new word*/
    printf("%s\n", str);
    return 0;
}
