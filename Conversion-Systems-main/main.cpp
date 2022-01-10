// Assignment 1- Information Technology
// Huzaifa Zia
// Hanzalah Patel
// Zubair Islam

#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

//Function Prototypes
void bases();
int checkBaseNumber(int base);
bool validateInput(int num, int sourceBase, string read);
bool validateBinary(int num);
bool validateOctal(int num);
bool validateDecimal(int num);
bool validateHexaDecimal(string read);
int convert_binary_octal(int num);
int convert_binary_decimal(int num);
string convert_binary_hexa(int num);
int convert_octal_binary(int num);
int convert_octal_decimal(int num);
string convert_octal_hexa(int num);
int convert_decimal_octal(int num);
int convert_decimal_binary(int num);
string convert_decimal_hexa(int num);
int convert_hexa_octal(string hexa);
int convert_hexa_binary(string hexa);
int convert_hexa_decimal(string hexVal);

string conversionNames[5] = {" ", "Binary", "Octal", "Decimal", "Hexadecimal"};

int main()
{
    int num, sourceBase, targetBase;
    bool validInput = false;
    string again;
    string read;
    string test2;
    string magenta;

    // do while user still wants to convert
    do
    {
        // Introduction statements
        cout << "------------------------------------------" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Welcome to the Numbering System Converter:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "This Program will allow you to convert between all the following:" << endl;
        cout << "Binary--Octal--Decimal--Hexadecimal" << endl;

        //asks user for number to convert
        cout << "\nEnter a valid number to convert:" << endl;
        cin >> read;                 // reads a string value
        stringstream readHexa(read); // Converts string to integer
        readHexa >> num;             // stores int value to num

        //asks for source base of number user entered
        cout << "What is the source base? Please enter in valid format: " << endl;
        cout << "------------------------------------------" << endl;
        bases();
        cout << "------------------------------------------" << endl;
        cin >> sourceBase;
        sourceBase = checkBaseNumber(sourceBase);          // calls function to check if source base number is between 1-4
        validInput = validateInput(num, sourceBase, read); // calls function validate input according to base

        // If input does not match base, keep asking user for number and source base until user inputs correct base match
        while (validInput == false)
        {
            //ask if user wants to use a different number or use original number
            cout << "\nEnter a valid number to convert that corresponds with the Base: \nYou will be asked to choose the base again so you may change your number: " << endl;
            cin >> num;

            cout << "Enter the source base again. Please enter in valid format: " << endl;
            cout << "------------------------------------------" << endl;
            bases();
            cout << "------------------------------------------" << endl;
            cin >> sourceBase;

            // calls function to check if source base number is between 1-4
            sourceBase = checkBaseNumber(sourceBase);

            // calls function validate input according to base
            validInput = validateInput(num, sourceBase, read);
        }

        //ask user what base they want to convert number to
        cout << "What is the target base? Please enter in valid format: " << endl;
        cout << "------------------------------------------" << endl;
        bases();
        cout << "------------------------------------------" << endl;
        cin >> targetBase;
        // calls function to check if source base number is between 1-4
        targetBase = checkBaseNumber(targetBase);

        // OUTPUT conversions
        {
            //Remember source base and target base 1 - 4 is binary, octal, decimal and hexadecimal respectively

            //if user input is a binary number and wants to convert to octal
            //then program will do calculation and convert to octal
            if (sourceBase == 1 && targetBase == 2)
            {
                cout << "Conversion of " << num << " from " << conversionNames[1] << " to " << conversionNames[2] << " is: " << convert_binary_octal(num) << endl;
            }

            //if user input is a binary number and wants to convert to decimal
            //then program will do calculation and convert to decimal
            else if (sourceBase == 1 && targetBase == 3)
            {
                cout << "Conversion of " << num << " from " << conversionNames[1] << " to " << conversionNames[3] << " is: " << convert_binary_decimal(num) << endl;
            }
            //if user input is a binary number and wants to convert to hexadecimal
            //then program will do calculation and convert to hexadecimal
            else if (sourceBase == 1 && targetBase == 4)
            {
                cout << "Conversion of " << num << " from " << conversionNames[1] << " to " << conversionNames[4] << " is: " << convert_binary_hexa(num) << endl;
            }
            //if user input is a octal number and wants to convert to binary
            //then program will do calculation and convert to binary
            else if (sourceBase == 2 && targetBase == 1)
            {
                cout << "Conversion of " << num << " from " << conversionNames[2] << " to " << conversionNames[1] << " is: " << convert_octal_binary(num) << endl;
            }
            //if user input is a octal number and wants to convert to decimal
            //then program will do calculation and convert to decimal
            else if (sourceBase == 2 && targetBase == 3)
            {
                cout << "Conversion of " << num << " from " << conversionNames[2] << " to " << conversionNames[3] << " is: " << convert_octal_decimal(num) << endl;
            }
            //if user input is a octal number and wants to convert to hexadecimal
            //then program will do calculation and convert to hexadecimal
            else if (sourceBase == 2 && targetBase == 4)
            {
                cout << "Conversion of " << num << " from " << conversionNames[2] << " to " << conversionNames[4] << " is: " << convert_octal_hexa(num) << endl;
            }
            //if user input is a decimal number and wants to convert to binary
            //then program will do calculation and convert to binary
            else if (sourceBase == 3 && targetBase == 1)
            {
                cout << "Conversion of " << num << " from " << conversionNames[3] << " to " << conversionNames[1] << " is: " << convert_decimal_binary(num) << endl;
            }
            //if user input is a decimal number and wants to convert to octal
            //then program will do calculation and convert to octal
            else if (sourceBase == 3 && targetBase == 2)
            {
                cout << "Conversion of " << num << " from " << conversionNames[3] << " to " << conversionNames[2] << " is: " << convert_decimal_octal(num) << endl;
            }
            //if user input is a decimal number and wants to convert to hexadecimal
            //then program will do calculation and convert to hexadecimal
            else if (sourceBase == 3 && targetBase == 4)
            {
                cout << "Conversion of " << num << " from " << conversionNames[3] << " to " << conversionNames[4] << " is: " << convert_decimal_hexa(num) << endl;
            }
            //if user input is a hexadecimal value and wants to convert to binary
            //then program will do calculation and convert to binary
            else if (sourceBase == 4 && targetBase == 1)
            {
                cout << "Conversion of " << read << " from " << conversionNames[4] << " to " << conversionNames[1] << " is: " << convert_hexa_binary(read) << endl;
            }
            //if user input is a hexadecimal value and wants to convert to octal
            //then program will do calculation and convert to octal
            else if (sourceBase == 4 && targetBase == 2)
            {
                cout << "Conversion of " << read << " from " << conversionNames[4] << " to " << conversionNames[2] << " is: " << convert_hexa_octal(read) << endl;
            }
            //if user input is a hexadecimal value and wants to convert to decimal
            //then program will do calculation and convert to decimal
            else if (sourceBase == 4 && targetBase == 3)
            {
                cout << "Conversion of " << read << " from " << conversionNames[4] << " to " << conversionNames[3] << " is: " << convert_hexa_decimal(read) << endl;
            }
            else
            {
                cout << "Your number after conversion results in: " << num << endl;
            }
        }
        cout << "Enter Y to run again or any other letter to stop the program" << endl;
        cin >> again;

    } while (again == "Y" || again == "y");
}

//function to print out base options for user
void bases()
{
    cout << "For Binary: Select 1" << endl;
    cout << "For Octal: Select 2" << endl;
    cout << "For Decimal: Select 3" << endl;
    cout << "For Hexadecimal: Select 4" << endl;
}

//function to make sure base input is between 1 and 4 otherwise it keeps asking for input
int checkBaseNumber(int base)
{
    while (base < 1 || base > 4)
    {
        cout << "Please choose an option between 1 and 4 " << endl;
        cout << "------------------------------------------" << endl;
        bases();
        cout << "------------------------------------------" << endl;
        cin >> base;
    }
    return base;
}

//VALIDATE SOURCE BASE INPUT FUNCTIONS---------------------

//function to check if user input matches the base the user chooses
bool validateInput(int num, int sourceBase, string read)
{
    bool test;

    if (sourceBase == 1)
    {
        //calls function to check if user input is a binary number
        test = validateBinary(num);
        return test;
    }
    else if (sourceBase == 2)
    {
        //calls function to check if user input is a octal number
        test = validateOctal(num);
        return test;
    }
    else if (sourceBase == 3)
    {
        //calls function to check if user input is a decimal number
        test = validateDecimal(num);
        return test;
    }
    else if (sourceBase == 4)
    {
        //calls function to check if user input is a hexadecimal number
        test = validateHexaDecimal(read);
        return test;
    }
    return false;
}

//function to check if user input is a binary number
bool validateBinary(int num)
{
    int test;
    // if number is not 0 or 1 return false
    while (num != 0)
    {
        test = num % 10;

        if (test > 1)
        {
            return false;
        }

        num = num / 10;
    }

    return true;
}

//function to check if user input is a octal number
bool validateOctal(int num)
{
    int test;
    // if number is greater than 7 return false
    while (num != 0)
    {
        test = num % 10;

        if (test > 7)
        {
            return false;
        }

        num = num / 10;
    }

    return true;
}

//function to check if user input is a decimal number
bool validateDecimal(int num)
{
    int test;
    // if number is greater than 9 return false
    while (num != 0)
    {
        test = num % 10;

        if (test > 9)
        {
            return false;
        }

        num = num / 10;
    }

    return true;
}

//function to check if user input is a hexadecimal number
bool validateHexaDecimal(string read)
{
    int length = read.length();
    // if string is not between 0 and 9 or between A and F return false
    for (int i = 0; i < length; i++)
    {
        char ch = read[i];

        if ((ch < '0' || ch > '9') &&
            (ch < 'A' || ch > 'F'))
        {
            return false;
        }
    }

    return true;
}

//CONVERSION BETWEEN NUMBER SYSTEMS FUNCTIONS---------------------

//function to convert from binary to octal
int convert_binary_octal(int num)
{
    int octal = 0, decimal = 0, i = 0, rem;

    //converting binary to decimal
    while (num != 0)
    {
        rem = num % 10;            // remainder = modulus 10
        int res = rem * pow(2, i); //multiply rem by 2^incremental i
        decimal += res;
        i++;
        num /= 10;
    }
    i = 1;

    //converting decimal to octal
    while (decimal != 0)
    {
        rem = decimal % 8; // remainder = modulus 8
        octal += rem * i;
        decimal /= 8; // consecutively devide number by 8 and then multiply remainder by 10
        i *= 10;
    }
    return octal;
}

//function to convert from binary to decimal
int convert_binary_decimal(int num)
{
    int decimal = 0, i = 0, rem;
    // multiply 2 to the power of incremental i by binary number at i
    // add all of them together to get decimal value
    while (num != 0)
    {
        rem = num % 10;
        int r = rem * pow(2, i);
        decimal += r;
        i++;
        num /= 10;
    }

    return decimal;
}

//function to convert from binary to hexadecimal
string convert_binary_hexa(int num)
{
    int hex = 0, test = 1, check = 1, i = 0, rem;
    char hexNum[20];
    string output;

    // while the number is not 0 run conversion
    while (num != 0)
    {
        rem = num % 10;           // modulus divide by 10
        hex = hex + (rem * test); // hex number is equal to current hex + remainder *1
        if (check % 4 == 0)       // if modulus 4 is 0 then
        {
            if (hex < 10)
                hexNum[i] = hex + 48; // convert to Int using ascii table
            else
                hexNum[i] = hex + 55; // convert to string using ascii table
            test = 1;
            hex = 0;
            check = 1;
            i++;
        }
        else
        {
            test = test * 2;
            check++;
        }
        num = num / 10;
    }
    if (check != 1)
        hexNum[i] = hex + 48;
    if (check == 1)
        i--;
    for (i = i; i >= 0; i--)
    {
        char test = hexNum[i];
        output += test; // add the character array index by index to output string
    }

    return output;
}

//function to convert from octal to binary
int convert_octal_binary(int num)
{
    int decimal = 0, i = 0;
    long binary = 0;
    //converting octal to decimal
    while (num != 0)
    {
        // divide number by 10 continuosly and multiply remainder by 8^index
        int rem = num % 10;
        int res = rem * pow(8, i);
        decimal += res;
        i++;
        num /= 10;
    }
    i = 1;
    //converting decimal to binary
    while (decimal != 0)
    {
        // modulus divide by 2 and add remainder to output
        int rem = decimal % 2;
        binary += rem * i;
        decimal /= 2;
        i *= 10;
    }
    return binary;
}

//function to convert from octal to decimal
int convert_octal_decimal(int num)
{
    int decimal = 0, i = 0;
    // divide number by 10 continuosly and multiply remainder by 8^index
    while (num != 0)
    {
        int rem = num % 10;
        int res = rem * pow(8, i);
        decimal += res;
        i++;
        num /= 10;
    }
    return decimal;
}

//function to convert from octal to hexadecimal
string convert_octal_hexa(int num)
{
    int binary;
    string hexa;

    binary = convert_octal_binary(num); // call previous methods to convert to binary then to hexa
    hexa = convert_binary_hexa(binary);

    return hexa;
}

//function to convert from decimal to octal
int convert_decimal_octal(int num)
{
    int rem, i = 1, octal = 0;
    // modulus divide by 8 and then multiply remainder by ni*10, n=index
    while (num != 0)
    {
        rem = num % 8;
        num /= 8;
        octal += rem * i;
        i *= 10;
    }
    return octal;
}

//function to convert from decimal to binary
int convert_decimal_binary(int num)
{
    int binary, i = 1;
    // modulus divide by 2 and add remainder to output
    while (num != 0)
    {
        int rem = num % 2;
        binary += rem * i;
        num /= 2;
        i *= 10;
    }
    return binary;
}

//function to convert from decimal to hexadecimal
string convert_decimal_hexa(int num)
{
    int binary;
    string hexa;

    binary = convert_decimal_binary(num); // call previous methods to convert to binary then to hexa
    hexa = convert_binary_hexa(binary);

    return hexa;
}

//function to convert from hexadecimal to octal
int convert_hexa_octal(string hexa)
{
    int octal;
    int length = hexa.size();
    int base = 1;
    int decimal = 0;

    // Extract char from hexadecimal value
    for (int i = length - 1; i >= 0; i--)
    {
        // if char is between 0-9, convert to int using ascii table subtraction value (48)
        if (hexa[i] >= '0' && hexa[i] <= '9')
        {
            decimal += (int(hexa[i]) - 48) * base;
            // incrementing the base by power
            base = base * 16;
        }

        // if char is between A-F, convert to int between 10-15 using ascii table subtraction value (55)
        else if (hexa[i] >= 'A' && hexa[i] <= 'F')
        {
            decimal += (int(hexa[i]) - 55) * base;
            base = base * 16;
        }
    }
    // convert decimal int to octal and return
    octal = convert_decimal_octal(decimal);

    return octal;
}

//function to convert from hexadecimal to binary
int convert_hexa_binary(string hexa)
{
    int binary;
    int length = hexa.size();
    int base = 1;
    int decimal = 0;

    // Extract char from hexadecimal value
    for (int i = length - 1; i >= 0; i--)
    {
        // if char is between 0-9, convert to int using ascii table subtraction value (48)
        if (hexa[i] >= '0' && hexa[i] <= '9')
        {
            decimal += (int(hexa[i]) - 48) * base;
            // incrementing the base by power
            base = base * 16;
        }

        // if char is between A-F, convert to int between 10-15 using ascii table subtraction value (55)
        else if (hexa[i] >= 'A' && hexa[i] <= 'F')
        {
            decimal += (int(hexa[i]) - 55) * base;
            base = base * 16;
        }
    }
    // convert decimal int to binary and return
    binary = convert_decimal_binary(decimal);

    return binary;
}

//function to convert from hexadecimal to decimal
int convert_hexa_decimal(string hexa)
{
    int length = hexa.size();
    int base = 1;
    int decimal = 0;

    // Extract char from hexadecimal value
    for (int i = length - 1; i >= 0; i--)
    {
        // if char is between 0-9, convert to int using ascii table subtraction value (48)
        if (hexa[i] >= '0' && hexa[i] <= '9')
        {
            decimal += (int(hexa[i]) - 48) * base;
            // incrementing the base by power
            base = base * 16;
        }

        // if char is between A-F, convert to int between 10-15 using ascii table subtraction value (55)
        else if (hexa[i] >= 'A' && hexa[i] <= 'F')
        {
            decimal += (int(hexa[i]) - 55) * base;
            base = base * 16;
        }
    }
    return decimal;
}
