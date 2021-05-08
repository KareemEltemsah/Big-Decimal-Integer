#include <bits/stdc++.h>

using namespace std;

class BigDecimalInt
{
private:
    string number = "";

public :
    BigDecimalInt (string decStr)// Initialize from string and rejects bad input
    {
        for (int i = 0 ; i < decStr.length() ; i++)
        {
            if ((int(decStr[i]) <= 57 && int(decStr[i]) >= 48) || (int(decStr[i])==45 && i == 0))
                number += decStr[i];
        }
    }
    BigDecimalInt (int decInt)// Initialize from integer
    {
        number = to_string(decInt);
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
    int size()
    {
        return number.length();
    }
    friend ostream& operator << (ostream& out, BigDecimalInt b);// print the BigDecimalInt
};

ostream& operator << (ostream& out, BigDecimalInt b)
{
    out << b.number;
}

int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    BigDecimalInt aa = BigDecimalInt(a);
    BigDecimalInt bb = BigDecimalInt(b);
    BigDecimalInt cc = BigDecimalInt(c);
    cout << aa << endl << bb << endl << cc << endl;
    return 0;
}
