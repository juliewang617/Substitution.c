#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) // checks that there is only 2 arguments
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int length = strlen(argv[1]);

    if (length != 26) // checks that the key has only 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < length; i++) // checks that the key only contains alphabetic characters
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }

    }

    for (int i = 0; i < length; i++) // checks that there is no repeat characters
    {
        for (int j = 0; j < length; j++)
        {
            if (i != j)
            {
                if (tolower(argv[1][i]) == tolower(argv[1][j]))
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }

        }
    }

    /////////////////////////////////////




    string text = get_string("plaintext:\n");

    int slength = strlen(text);

    int shift;
    
    printf("ciphertext: ");

    for (int i = 0; i < slength; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {

                shift = text[i] % 65;
                text[i] = toupper(argv[1][shift]);

            }
            else if (islower(text[i]))
            {
                shift = text[i] % 97;
                text[i] = tolower(argv[1][shift]);

            }
        }


        printf("%c", text[i]);

    }
    
    printf("\n");
}
