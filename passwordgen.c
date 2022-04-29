//Imports
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variables
char input; //Stores Y/N input for capitals first question.
int cp1; //CP1 = Capital 1st. Integer version of "input".
int chrlim; //Stores input on character limit, and is used to keep track of characters needed for the new password.
 //An array used to set a random amount of characters/letters. Used for making the password.

int main (){
    srand(time(NULL));//Allows the rand function to properly work, because C is just like that.
    //Asks if your password requires a capital letter at the beginning. Yes, companies do this although it's safer NOT to have this limit.
    printf("Type y/Y or n/N. \n\vPassword requires a capital letter at beginning?\n\v"); //Asks if capital letter at the beginning is required.
    scanf("%c", &input); //Grabs Input
    //Converts y/n into variable, because C actually cares what type of thing I store in the variables.
    if (input == 'y' || input == 'Y'){ //Prevents case sensitivity. Both y and Y should work.
        cp1 = 1; //Y turns into 1, representing "true".
    } else if ((input =! 'n') || (input =! 'N')){ //This checks if neither Y nor N were inputted. Prevents case sensitivity. Both n and N should work.
        //cp1 variable is already 0, no need to set it to 0. Same for if you choose N.
        printf( "\n\vInput failed! Setting to false...\n\v" ); //If Y or N were not picked, will not pick Y by default, and addresses the error.
    }
    //Maximum Characters Input
    printf("\n\vWhat's the character limit? (If not, pick a length)\n\v"); //Prints line asking for character limit.
    scanf("%d", &chrlim); //Grabs Inupt
    //Password Maker
    char password[chrlim]; //Makes array for password.
    char randomLetter;
    printf("\n\vYour newly generated password is:\n\v"); //Prints intro line
    for (int i = 0; i < chrlim; i++){ //i was chosen to start at 1 due to character limits typically starting at 1 and not 0.
        if (i == 0 && cp1 == 1){
            randomLetter = rand() % (90 + 1 - 65) + 65; //Picks a capital letter for the first password if that option was selected. 65-90 capital alphabet ASCII ID.
        } else {
            randomLetter = rand() % (126 + 1 - 33) + 33; //Picks random letter. 33 starts with !, 126 ending with ~. Goes through all numbers, letters, and symbols.
        }
        password[i] = randomLetter; //Adds random letter to the array, gradually creating a random password.
        printf("%c", password[i]); //Debug
    }
    printf("\n\vFeel free to copy it from your terminal!\n\v"); //Prints outro line
    return 0; //Return Function for Main (Unused, but needed for C).
}
