#include<iostream>
using namespace std;

int tempid;

class Rectangles
{
private:
    int plotid;
    float length;
    float breadth;

public:
    //setters
    void setplotid(int pid)
    {
        plotid=pid;
    }

    void setlength(float l)
    {
        length=l;
    }

    void setbreadth(float b)
    {
        breadth=b;
    }

    //function definitions
    int viewdetails();
    int updatedimensions();

};

int Rectangles::viewdetails()
{
    if(plotid==tempid)
    {
        cout<<"Plot ID : "<<plotid<<endl;
        cout<<"Perimeter : "<<2.0*(length+breadth)<<endl;
        cout<<"Area : "<<(length*breadth)<<endl;
        cout<<"\n\n";
        return 1;
    }
    else
    {
        return 0;
    }
}

int Rectangles::updatedimensions()
{
    if(tempid==plotid)
    {
        float ul,ub;
        cout<<"Enter new length : ";
        cin>>ul;
        cout<<"Enter new breadth : ";
        cin>>ub;

        length=ul;
        breadth=ub;
        cout<<"Dimensions updated successfully!"<<endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Rectangles plot[50];
    int ch;
    int plotcount=0;

    M:
    cout<<"1. Add a plot. \n2. Update dimensions. \n3. View Area and Perimeter.\n";
    cout<<"4. Exit"<<endl;
    cout<<"Enter a choice : ";
    cin>>ch;

    switch(ch)
    {
    case 1:
        float l,b;
        cout<<"Enter Plot ID : ";
        cin>>tempid;
        plot[plotcount].setplotid(tempid);
        cout<<"Enter length for the plot : ";
        cin>>l;
        plot[plotcount].setlength(l);
        cout<<"Enter breadth for the plot : ";
        cin>>b;
        plot[plotcount].setbreadth(b);
        cout<<"Plot added successfully!"<<endl;
        plotcount++;
        goto M;

    case 2:
        cout<<"Enter Plot ID : ";
        cin>>tempid;
        int i;
        for(i=0;i<plotcount;i++)
        {
            if(plot[i].updatedimensions()==1)
            {
                break;
            }
        }
        if(i==plotcount)
        {
            cout<<"No plot exists with this ID!"<<endl;
        };

        goto M;

    case 3:
        cout<<"Enter Plot ID : ";
        cin>>tempid;

        for(i=0;i<plotcount;i++)
        {
            if(plot[i].viewdetails()==1)
            {
                break;
            }
        }
        if(i==plotcount)
        {
            cout<<"No plot exists with this ID!"<<endl;
        };

        goto M;

    case 4:
        cout<<"Thanks for using our service! Have a nice day";
        break;

    default:
        cout<<"Please enter a valid choice!"<<endl;
        goto M;
    }

    return 0;
}
