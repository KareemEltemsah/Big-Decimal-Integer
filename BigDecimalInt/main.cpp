#include <iostream>

using namespace std;

class BigDecimalInt
{
private:
    String number;

public :
    BigDecimalInt (string decStr)// Initialize from string and rejects bad input
    {
    }
    BigDecimalInt (int decInt)// Initialize from integer
    {
    }
    BigDecimalInt operator+ (BigDecimalInt anotherDec)// add another BigDecimalInt
    {
    }
    BigDecimalInt operator- (BigDecimalInt anotherDec)// subtract another BigDecimalInt
    {
    }
    BigDecimalInt operator= (BigDecimalInt anotherDec)// assign with another BigDecimalInt
    {
    }
    Int size()
    {
    }
    friend ostream& operator << (ostream& out, BigDecimalInt b)// print the BigDecimalInt
    {
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
