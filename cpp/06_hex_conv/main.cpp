#include <iostream>
#include <fstream>
#include <string>

int strToInt(std::string);
std::string getHex(int);
char getHexDigit(int);

int main(int argc, const char* argv[])
{
    std::ofstream ofs;
    ofs.open("nums.txt");
    
    if(argc > 1)
    {
        //converting all args to hex values
        for(int i = 1; i < argc; i++)
        {
            int x = strToInt(argv[i]);
            std::string s = getHex(x);
            std::cout << s << " ";
            ofs << s << " ";
        }
    }

    ofs.close();
    return 0;
}

/* Must convert argv strings to ints before determining hex values */
int strToInt(std::string s)
{
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '.')
            return 0;
        if(s[i] >= 48 && s[i] <= 57)
        {
            sum = (sum * 10) + (s[i] - 48);
        }
    }
    return sum;
}

/* Parsing through the int to create the hex string */
std::string getHex(int x)
{
    std::string hexVal = "";

    int check = 16;
    int loop = 1;

    //getting check up to x's value and setting up the for loop
    //if this runs once, then we will have two hex digits
    while((x) >= check)
    {
        check *= 16;
        loop++;
    }

    //check will always be 16x greater than x here
    check /= 16;

    //digit will always be between 0 and 15 (inclusive)
    //each step appends another character to our hex string after decoding digit
    for(int i = 0; i < loop; i++)
    {
        int digit = x / check;

        x -= check * digit;
        check /= 16;
        hexVal.push_back(getHexDigit(digit));
    }

    return hexVal;
}

/* decoding int value to hex digit - 0 <= x < 16 */
char getHexDigit(int x)
{
    if(x >= 0 && x < 10)
    {
        return (x + 48);
    }
    switch(x)
    {
        case 10:
        {
            return 'A';
        }
        case 11:
        {
            return 'B';
        }
        case 12:
        {
            return 'C';
        }
        case 13:
        {
            return 'D';
        }
        case 14:
        {
            return 'E';
        }
        case 15:
        {
            return 'F';
        }
    }
    return '\0';
}
