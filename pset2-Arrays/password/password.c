// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library


//check50 cs50/labs/2023/x/password
//style50 password.c


#include <cs50.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_digit = false;
    bool has_symbol = false;

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
        {
            has_uppercase = true;
        }
        else if (islower(password[i]))
        {
            has_lowercase = true;
        }
        else if (isdigit(password[i]))
        {
            has_digit = true;
        }
        else if (ispunct(password[i]))
        {
            has_symbol = true;
        }
    }

    if (has_uppercase && has_lowercase && has_digit && has_symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}
