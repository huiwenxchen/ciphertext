#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

bool only_digits(string s);
char rotate(char c, int k);


int main(int argc, string argv[])
{
    
    //check if the command-line argument is correct and all argv is digits
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    if (only_digits(argv[1]) == true)
    {
        // use atoi to convert argv[1] to int
        int key = atoi(argv[1]);

        //prompt user to input plaintext
        string text = get_string("plaintext: ");

        // modify the character in the plaintext
        int b = strlen(text);
        //array of characters convert into a word
        char Ciphertext[b];
        printf("ciphertext: ");

        for (int i = 0; i < b; i++)
        {
            Ciphertext[i] = rotate(text[i], key);
            printf("%c", Ciphertext[i]);
        }
            printf("\n");
    }

    else if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// function to make sure that the argument is a string between the digits 0-9
bool only_digits(string s)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    
    return true;
}

//rotate function
char rotate(char c, int k)
{
    char Ciphertext;
    
    // if the character is alphabetic, rotate/shift plaintext char by key
    if (isalpha(c) && isupper(c))
    {
        c -= 65; 
        Ciphertext = (c + k)%26;
        Ciphertext += 65;
    }
    
    else if (isalpha(c) && islower(c))
    {
        c -= 97;
        Ciphertext = (c + k)%26;
        Ciphertext += 97;
    }
    
    else
    {
        return c;
    }

    return Ciphertext;
}
