#include<iostream>
#include<cmath>
using namespace std;

class EMI
{
    private:
    int ID;
    string Appname;
    double amount;
    double interestRate;
    double loantenure;
    double Emi;
public:

    EMI()
    {
        ID=0;
        Appname="unknown";
        amount=0;
        interestRate=0;
        loantenure=0;
        Emi=0;
    }

    EMI(int id,string n,double a,double IR,double LT)
    {
        ID=id;
        Appname=n;
        amount=a;
        interestRate=IR;
        loantenure=LT;
    }

    calculate()
    {
        double r=interestRate / (12 * 100);

        Emi = amount * r * pow(1+r,loantenure)/(pow(1+r,loantenure)-1);

    }
    void display()
    {
        cout<<"id is"<<ID<<endl;
        cout<<"name is"<<Appname<<endl;
        cout<<"amount is"<<amount<<endl;
        cout<<"interestrate is"<<interestRate<<endl;
        cout<<"loantenure is"<<loantenure<<endl;
        cout<<"Emi is"<<Emi<<endl;
    }
};
int main()
{
    EMI E1;
    EMI E2(123,"Bhavi",200000,9,36);

    E2.calculate();
    E2.display();

    return 0;
}

