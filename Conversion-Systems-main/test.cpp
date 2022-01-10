// Assignment 1- Infomration Technology
// Huzaifa Zia
// Hanzalah Patel
// Zubair Islam

#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

// Function Prototypes
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

    // do while user still wants to convert
    do
    {
        // Introduction statements
        cout << "------------------------------------------" << endl;
        cout << "Welcome to the Numbering System Converter:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "This Program will allow you to convert between all the following:" << endl;
        cout << "Binary--Octal--Decimal--Hexadecimal" << endl;

        cout << "\nEnter a valid number to convert:" << endl;
        cin >> read;                 // reads a string value
        stringstream readHexa(read); // Converts string to integer
        readHexa >> num;             // stores int value to num

        cout << "What is the source base? Please enter in valid format: " << endl;
        cout << "------------------------------------------" << endl;
        bases();
        cout << "------------------------------------------" << endl;
        cin >> sourceBase;
        sourceBase = checkBaseNumber(sourceBase);          // check if source base number is between 1-4
        validInput = validateInput(num, sourceBase, read); // validate input according to base

        // If input does not match base ask user for number and source base again
        while (validInput == false)
        {
            cout << "\nEnter a valid number to convert that corresponds with the Base: \nYou will be asked to choose the base again so you may change your number: " << endl;
            cin >> num;

            cout << "Enter the source base again. Please enter in valid format: " << endl;
            cout << "------------------------------------------" << endl;
            bases();
            cout << "------------------------------------------" << endl;
            cin >> sourceBase;
            sourceBase = checkBaseNumber(sourceBase);
            validInput = validateInput(num, sourceBase, read);
        }

        cout << "What is the target base? Please enter in valid format: " << endl;
        cout << "------------------------------------------" << endl;
        bases();
        cout << "------------------------------------------" << endl;
        cin >> targetBase;
        targetBase = checkBaseNumber(targetBase);

        // OUTPUT conversions
        if (sourceBase == 1 && targetBase == 2)
        {
            cout << "Conversion of " << num << " from " << conversionNames[1] << " to " << conversionNames[2] << " is: " << convert_binary_octal(num) << endl;
        }
        else if (sourceBase == 1 && targetBase == 3)
        {
            cout << "Conversion of " << num << " from " << conversionNames[1] << " to " << conversionNames[3] << " is: " << convert_binary_decimal(num) << endl;
        }
        else if (sourceBase == 1 && targetBase == 4)
        {
            cout << "Conversion of " << num << " from " << conversionNames[1] << " to " << conversionNames[4] << " is: " << convert_binary_hexa(num) << endl;
        }
        else if (sourceBase == 2 && targetBase == 1)
        {
            cout << "Conversion of " << num << " from " << conversionNames[2] << " to " << conversionNames[1] << " is: " << convert_octal_binary(num) << endl;
        }
        else if (sourceBase == 2 && targetBase == 3)
        {
            cout << "Conversion of " << num << " from " << conversionNames[2] << " to " << conversionNames[3] << " is: " << convert_octal_decimal(num) << endl;
        }
        else if (sourceBase == 2 && targetBase == 4)
        {
            cout << "Conversion of " << num << " from " << conversionNames[2] << " to " << conversionNames[4] << " is: " << convert_octal_hexa(num) << endl;
        }
        else if (sourceBase == 3 && targetBase == 1)
        {
            cout << "Conversion of " << num << " from " << conversionNames[3] << " to " << conversionNames[1] << " is: " << convert_decimal_binary(num) << endl;
        }
        else if (sourceBase == 3 && targetBase == 2)
        {
            cout << "Conversion of " << num << " from " << conversionNames[3] << " to " << conversionNames[2] << " is: " << convert_decimal_octal(num) << endl;
        }
        else if (sourceBase == 3 && targetBase == 4)
        {
            cout << "Conversion of " << num << " from " << conversionNames[3] << " to " << conversionNames[4] << " is: " << convert_decimal_hexa(num) << endl;
        }
        else if (sourceBase == 4 && targetBase == 1)
        {
            cout << "Conversion of " << read << " from " << conversionNames[4] << " to " << conversionNames[1] << " is: " << convert_hexa_binary(read) << endl;
        }
        else if (sourceBase == 4 && targetBase == 2)
        {
            cout << "Conversion of " << read << " from " << conversionNames[4] << " to " << conversionNames[2] << " is: " << convert_hexa_octal(read) << endl;
        }
        else if (sourceBase == 4 && targetBase == 3)
        {
            cout << "Conversion of " << read << " from " << conversionNames[4] << " to " << conversionNames[3] << " is: " << convert_hexa_decimal(read) << endl;
        }
        else
        {
            cout << "Your number after conversion results in: " << num << endl;
        }

        cout << "Enter Y to run again or any other letter to stop the program" << endl;
        cin >> again;

    } while (again == "Y" || again == "y");
}

void bases()
{
    cout << "For Binary: Select 1" << endl;
    cout << "For Octal: Select 2" << endl;
    cout << "For Decimal: Select 3" << endl;
    cout << "For Hexadecimal: Select 4" << endl;
}

int checkBaseNumber(int base)
{
    while (base < 1 || base > 4)
    {
        cout << "Please choose an option between 1 and 2 " << endl;
        cout << "------------------------------------------" << endl;
        bases();
        cout << "------------------------------------------" << endl;
        cin >> base;
    }
    return base;
}

//   VALIDATE SOURCE BASE INPUT FUNCTIONS---------------------

bool validateInput(int num, int sourceBase, string read)
{
    bool test;

    if (sourceBase == 1)
    {
        test = validateBinary(num);
        return test;
    }
    else if (sourceBase == 2)
    {
        test = validateOctal(num);
        return test;
    }
    else if (sourceBase == 3)
    {
        test = validateDecimal(num);
        return test;
    }
    else if (sourceBase == 4)
    {
        test = validateHexaDecimal(read);
        return test;
    }
    return false;
}
bool validateBinary(int num)
{
    int test;

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

bool validateOctal(int num)
{
    int test;

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
bool validateDecimal(int num)
{
    int test;

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
bool validateHexaDecimal(string read)
{
    int length = read.length();

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

//   CONVERSION BETWEEN NUMBER SYSTEMS FUNCTIONS---------------------

int convert_binary_octal(int num)
{
    int octal = 0, decimal = 0, i = 0, rem;
    //converting binary to decimal
    while (num != 0)
    {
        rem = num % 10;
        int res = rem * pow(2, i);
        decimal += res;
        i++;
        num /= 10;
    }
    i = 1;
    //converting decimal to octal
    while (decimal != 0)
    {
        rem = decimal % 8;
        octal += rem * i;
        decimal /= 8;
        i *= 10;
    }
    return octal;
}
int convert_binary_decimal(int num)
{
    int decimal = 0, i = 0, rem;

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
string convert_binary_hexa(int num)
{
    int hex = 0, test = 1, check = 1, i = 0, rem;
    char hexNum[20];
    string output;

    while (num != 0)
    {
        rem = num % 10;
        hex = hex + (rem * test);
        if (check % 4 == 0)
        {
            if (hex < 10)
                hexNum[i] = hex + 48;
            else
                hexNum[i] = hex + 55;
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
        output += test;
    }

    return output;
}
int convert_octal_binary(int num)
{
    int decimal = 0, i = 0;
    long binary = 0;
    //converting octal to decimal
    while (num != 0)
    {
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
        int rem = decimal % 2;
        binary += rem * i;
        decimal /= 2;
        i *= 10;
    }
    return binary;
}
int convert_octal_decimal(int num)
{
    int decimal = 0, i = 0;
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
string convert_octal_hexa(int num)
{
    int binary;
    string hexa;

    binary = convert_octal_binary(num);
    hexa = convert_binary_hexa(binary);

    return hexa;
}
int convert_decimal_octal(int num)
{
    int rem, i = 1, octal = 0;
    while (num != 0)
    {
        rem = num % 8;
        num /= 8;
        octal += rem * i;
        i *= 10;
    }
    return octal;
}
int convert_decimal_binary(int num)
{
    int binary, i = 1;
    //converting decimal to binary
    while (num != 0)
    {
        int rem = num % 2;
        binary += rem * i;
        num /= 2;
        i *= 10;
    }
    return binary;
}
string convert_decimal_hexa(int num)
{
    int binary;
    string hexa;

    binary = convert_decimal_binary(num);
    hexa = convert_binary_hexa(binary);

    return hexa;
}
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