#include<cs50.h>
#include<stdio.h>

/*
TODO:
    prompt for user input
        datatype: get_long_long (cs50 library function)
                        -ensures that the user inputs an integer:
                            -accepts:
                                        positive;
                                        negative integers;
                                        0;
        further validate whether user input is valid or not (define the acceptable condition)
    multiply every other digit
    sum those digits
    add to remaining digits
    validate checksum
    validate company's identifier
    validate number's length
*/
//int cc; //variable declaration for credit card w/ datatype int
//long long cc;   //in order for the cc digits to be stored in (long long cc) it must be declared first otherwise the digits are too long & program will reprompt user for another cc number.
long long cc;   //credit card string is stored in variable cc
long long oddNum;
long long evenNum;
int oddSum;
int evenSum;
int checkSum;
int main(void)
{
    do  //prompt user for input
    {
        cc = get_long_long("Enter credit card number: \n");
    }
    while (cc < 0);     //if the value is invalid loop until valid input

    /*
    validate user input by running for loop
        add value of oddNum digits
    */
    for (oddNum = cc; oddNum > 0; oddNum /= 100)    //address odd nums by storing cc string in variable oddNum; oddNum > 0; oddNum /=100
    {
        oddSum += oddNum % 10;                      //modding oddNum by 10 isolates the last digit; then every other odd digit in cc string
    }

    /*
        add value of evenNum digits
    */
    for (evenNum = cc/10; evenNum > 0; evenNum /= 100)  //iterate over even digits and multiply by to for the evenSum
    {                                                   //divide cc by 10 starts the loop @ 2nd last digit in cc string
        if (2 * (evenNum % 10) > 9)                     //mod the evenNum by 10 * 2, if > 9
        {                                                   //execute (evenNum % 10) * 2 / 10, add to the evenSum (evenSum = 0)
            evenSum += (2*(evenNum % 10) / 10);             //execute (evenNum % 10) * 2 % 10, add to the evenSum (evenSum +=)
            evenSum += (2*(evenNum % 10) % 10);
        }
        else
        {                                                   //if evenNum % 10 * 2 != 9
            evenSum += (2*(evenNum % 10));                  //just run (evenNum % 10 * 2) += evenSum
        }
    }
    checkSum = oddSum + evenSum;                        //add oddSum + evenSum to get checkSum value;
    //printf("%i", checkSum);                           //testing for validity of checkSum ending in 0 = valid, else = invalid;

    //Define range of each card type
    if ((cc >= 340000000000000 && cc < 350000000000000) || (cc >= 370000000000000 && cc < 380000000000000))
    {
        printf("Amex\n");
    }

    if ((cc >= 5100000000000000 && cc < 5600000000000000))
    {
        printf("MasterCard\n");
    }

    if ((cc >= 4000000000000 && cc < 5000000000000) || (cc >= 4000000000000000 && cc < 5000000000000000))
    {
        printf("Visa\n");
    }
    else                                                //beyond this point numbers to return invalid
    {
        printf("Card is invalid\n");
    }
}