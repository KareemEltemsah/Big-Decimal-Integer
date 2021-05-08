#include <bits/stdc++.h>
#include <string>

using namespace std;

class BigDecimalInt
{
private:
    string num = "";

public :
    BigDecimalInt (string decStr)// Initialize from string and rejects bad input
    {
        num = decStr;
    }
    BigDecimalInt (int decInt)// Initialize from integer
    {
        num = to_string(decInt);
    }
    void operator+ (BigDecimalInt anotherDec)// add another BigDecimalInt
    {
        string num1 = num, num2 = anotherDec.num, sumResult = "";
        int max_size = max(num1.size(),num2.size());
        while (num1.size() < max_size)
            num1 = "0" + num1;
        while (num2.size() < max_size)
            num2 = "0" + num2;
        while (sumResult.size() < max_size)
            sumResult += "0";
        int remainder = 0;
        for (int i=max_size-1 ; i>=0 ; i--)
        {
            int digitSum = int(num1[i])-48 + int(num2[i])-48 + remainder;
            digitSum > 9 ? (sumResult[i] = char((digitSum - 10) + 48)) : (sumResult[i] = char(digitSum + 48));
            remainder = digitSum / 10;
        }
        if (remainder > 0)
            sumResult = char(remainder+48) + sumResult;
        cout << sumResult << endl;

    }
    BigDecimalInt operator- (BigDecimalInt anotherDec)// subtract another BigDecimalInt
    {
    }
    void operator= (BigDecimalInt anotherDec)// assign with another BigDecimalInt
    {
        num = anotherDec.num;
    }
    int size()
    {
        return num.length();
    }
    friend ostream& operator << (ostream& out, BigDecimalInt b);// print the BigDecimalInt
};

ostream& operator << (ostream& out, BigDecimalInt b)
{
    out << b.num;
}

int main()
{
    string a,b;
    cin >> a >> b;
    BigDecimalInt aa = BigDecimalInt(a);
    BigDecimalInt bb = BigDecimalInt(b);
    cout << aa << endl << bb << endl;
    bb + aa;
    return 0;
}
