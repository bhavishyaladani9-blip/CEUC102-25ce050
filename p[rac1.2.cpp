#include<iostream>
using namespace std;

int bookcount=0,tempid=0;

class Library
{
private:
    int bookid;
    char booktitle[100];
    char bookauthor[100];
    int bookstock;

public:
    void addbook();
    int bookdetails();
    int issuebook();
    int returnbook();
    void displayallbooks();
};

void Library::addbook()
{
    cout<<"Enter book's ID : ";
    cin>>bookid;
    cout<<"Enter book's Title : ";
    cin>>booktitle;
    cout<<"Enter book's Author : ";
    cin>>bookauthor;
    cout<<"Enter book's quantity : ";
    cin>>bookstock;

    cout<<"Book added successfully!"<<endl;
    cout<<"\n\n";
    bookcount++;
}
int Library::bookdetails()
{
    if(tempid==bookid)
    {
        cout<<"Book ID : "<<bookid<<endl;
        cout<<"Book Title : "<<booktitle<<endl;
        cout<<"Book Author : "<<bookauthor<<endl;
        cout<<"Available currently : "<<bookstock<<endl;
        cout<<"\n\n";
        return 1;
    }

    else
    {
        return 0;
    }
}

int Library::issuebook()
{
    if(tempid==bookid)
    {
        if(bookstock>=1)
        {
            bookstock--;
            cout<<"Book issued successfully."<<endl;
            return 1;
        }
        else
        {
            cout<<"Sorry ! But currently this book is out of stock."<<endl;
            return 1;
        }
    }
    return 0;
}

int Library::returnbook()
{
    if(tempid==bookid)
    {
        cout<<"Book returned successfully!"<<endl;
        bookstock++;
        return 1;
    }
    else
    {
        return 0;
    }
}

void Library::displayallbooks()
{
    cout<<" Book ID : "<<bookid<<endl;
    cout<<" Book Title : "<<booktitle<<endl;
    cout<<" Book Author : "<<bookauthor<<endl;
    cout<<" Book Stock : "<<bookstock<<endl;
    cout<<"\n\n\n";
}

int main()
{
    Library books[100];
    int ch=0;

    M:
    cout<<"1.Add a book."<<endl;
    cout<<"2.View book details."<<endl;
    cout<<"3.Issue a book."<<endl;
    cout<<"4.Return a book."<<endl;
    cout<<"5.Display all book."<<endl;
    cout<<"6.Exit."<<endl;
    cout<<"\n\n";
    cout<<"Enter choice : ";
    cin>>ch;

    switch(ch)
    {
    case 1:
        books[bookcount].addbook();
        goto M;

    case 2:
        int i;
        cout<<"Enter book ID : ";
        cin>>tempid;
        for(i=0;i<bookcount;i++)
        {
            if(books[i].bookdetails()==1)
            {
                break;
            }
        }

        if(i==bookcount)
        {
            cout<<"There does not exist any book by this ID!"<<endl;
            cout<<"\n\n";
        }
        goto M;

    case 3:
        cout<<"Enter book Id : ";
        cin>>tempid;

        for(i=0;i<bookcount;i++)
        {
            if(books[i].issuebook()==1)
            {
                break;
            }
        }
        if(i==bookcount)
        {
            cout<<"There is no book with this ID!"<<endl;
        }
        goto M;

    case 4:
        cout<<"Enter book ID : ";
        cin>>tempid;
        for(i=0;i<bookcount;i++)
        {
            if(books[i].returnbook()==1)
            {
                break;
            }
        }
        if(i==bookcount)
        {
            cout<<"No book exists with this ID!"<<endl;
        }
        goto M;

    case 5:
        if(bookcount==0)
        {
            cout<<"No data found! Please add some books."<<endl;
        }
        else
        {
            for(i=0;i<bookcount;i++)
            {
                cout<<i+1<<") ";
                books[i].displayallbooks();
            }

        }


        goto M;

    case 6:
        cout<<"Please visit us again , have a nice day!"<<endl;
        break;

    default:
        cout<<"Please enter a valid choice!."<<endl;
        cout<<"\n\n";
        goto M;
    }




    return 0;
}
