#include <bits/stdc++.h>

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
    BigDecimalInt operator+ (BigDecimalInt anotherDec)// add another BigDecimalInt
    {
        string num1 = num, num2 = anotherDec.num, sumResult = "";
        int max_size = max(num1.length(),num2.length());
        while (num1.length() < max_size)
            num1 = "0" + num1;
        while (num2.length() < max_size)
            num2 = "0" + num2;
        while (sumResult.length() < max_size)
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
        return BigDecimalInt(sumResult);
    }
    BigDecimalInt operator- (BigDecimalInt anotherDec)// subtract another BigDecimalInt
    {
        string num1 = num, num2 = anotherDec.num;
        bool overload=false;
        if (num1.length() < num2.length())
        {
            swap(num1,num2);
            overload=true;
        }
        else if (num1.length() == num2.length())
        {
            for (int i =0 ; i<num1.length() ; i++)
            {
                if (num1[i]<num2[i])
                {
                    swap(num1,num2);
                    overload=true;
                    break;
                }
                else if (num1[i]>num2[i])
                    break;
                else
                    continue;
            }
        }
        while (num2.length() < num1.length())
            num2 = "0" + num2;
        bool borrow;
        for (int i=num1.length()-1 ; i>=0 ; i--)
        {
            borrow=false;
            int digitSub = (int(num1[i])-48) - (int(num2[i])-48);
            digitSub < 0 ? (num1[i] = char((digitSub + 10) + 48)),borrow=true : (num1[i] = char(digitSub + 48));
            borrow = digitSub < 0 ? true : false;
            if (borrow)
                num1[i-1] = char(int(num1[i-1])-1);
        }
        while (num1[0] == '0' && num1.length() > 1)
            num1.erase(0,1);
        if (overload)
            num1 = "-" + num1;
        return BigDecimalInt(num1);
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
bool isValid(string &s)
{
    while (s[0]=='0')
        s.erase(0,1);
    while (s[1]=='0' && s[0]=='-')
        s.erase(1,1);
    if (s == "-" || s.length() == 0)
        return false;
    for (int i=0 ; i<s.length() ; i++)
    {
        if ((int(s[i])>=48 && int(s[i])<=57) || (int(s[0])==45 && i==0))
            continue;
        else
            return false;
    }
    return true;
}
void readNumbers(string& num1, string& num2)
{
    cout << "Enter num1: ";
    cin >> num1;
    while (!isValid(num1))
    {
        cout << "Enter a valid number (ONLY numbers and \"-\" sign)" << endl;
        cout << "Enter num1: ";
        cin >> num1;
    }
    cout << "num1 = " << num1 << endl;

    cout << "Enter num2: ";
    cin >> num2;
    while (!isValid(num2))
    {
        cout << "Enter a valid number (ONLY numbers and \"-\" sign)" << endl;
        cout << "Enter num2: ";
        cin >> num2;
    }
    cout << "num2 = " << num2 << endl;
}
int main()
{
    string num1,num2;//numbers
    char choose;
    while (true)
    {
        cout << "Welcome to FCI Calculator" << endl << "-------------------------" << endl;
        cout << "1- Perform Addition\n2- Perform Subtraction\n0- Exit\n" << endl;
        cin >> choose;
        if (choose == '1')
        {
            readNumbers(num1,num2);
            cout << "num1 + num2 = ";
            if (num1[0]=='-' && num2[0]=='-')//in case that (-num1)+(-num2)
            {
                num1.erase(0,1);
                num2.erase(0,1);
                BigDecimalInt n1(num1);
                BigDecimalInt n2(num2);
                cout << "-" << n1+n2 << endl;//-num1+-num2 == -(num1+num2)
            }
            else if (num1[0]=='-' && num2[0]!='-')//in case that (-num1)+(num2)
            {
                num1.erase(0,1);
                BigDecimalInt n1(num1);
                BigDecimalInt n2(num2);
                cout << n2-n1 << endl;//-num1+num2 == num2-num1

            }
            else if (num1[0]!='-' && num2[0]=='-')//in case that (num1)+(-num2)
            {
                num2.erase(0,1);
                BigDecimalInt n1(num1);
                BigDecimalInt n2(num2);
                cout << n1-n2 << endl;//num1+-num2 == num1-num2
            }
            else//the default case that num1+num2
            {
                BigDecimalInt n1(num1);
                BigDecimalInt n2(num2);
                cout << n1+n2 << endl;
            }
        }
        else if (choose == '2')
        {
            readNumbers(num1,num2);
            cout << "num1 - num2 = ";
            if (num1[0]=='-' && num2[0]=='-')//in case that (-num1)-(-num2)
            {
                num1.erase(0,1);
                num2.erase(0,1);
                BigDecimalInt n1(num1);
                BigDecimalInt n2(num2);
                cout << n2-n1 << endl;//-num1--num2 == -num1+num2 == num2-num1
            }
            else if (num1[0]=='-' && num2[0]!='-')//in case that (-num1)-(num2)
            {
                num1.erase(0,1);
                BigDecimalInt n1(num1);
                BigDecimalInt n2(num2);
                cout << "-" << n1+n2 << endl;//-num1-num2 == -(num1+num2)

            }
            else if (num1[0]!='-' && num2[0]=='-')//in case that (num1)-(-num2)
            {
                num2.erase(0,1);
                BigDecimalInt n1(num1);
                BigDecimalInt n2(num2);
                cout << n1+n2 << endl;//num1--num2 == num1+num2
            }
            else//The default case that (num1)-(num2)
            {
                BigDecimalInt n1(num1);
                BigDecimalInt n2(num2);
                cout << n1-n2 << endl;
            }
        }
        else if (choose == '0')
            return 0;
        else
            cout << "Not a valid option" << endl;
        cout << endl;

    }
}
