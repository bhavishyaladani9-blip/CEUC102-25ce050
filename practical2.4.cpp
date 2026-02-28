
#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    int itemID;
    string itemName;
    float price;
    int quantity;

public:

    Item()
    {
        itemID = 0;
        itemName = "Unknown";
        price = 0;
        quantity = 0;
    }


    Item(int id, string name, float p, int q)
    {
        itemID = id;
        itemName = name;
        price = p;
        quantity = q;
    }

    void setItem(int id, string name, float p, int q)
    {
        itemID = id;
        itemName = name;
        price = p;
        quantity = q;
    }

    void addStock(int qty)
    {
        quantity += qty;
        cout << "Stock Added Successfully\n";
    }


    void sellItem(int qty)
    {
        if(qty <= quantity)
        {
            quantity -= qty;
            cout << "Item Sold Successfully\n";
        }
        else
        {
            cout << "Insufficient Stock!\n";
        }
    }

    // Display item details
    void display()
    {
        cout << "\nItem ID: " << itemID;
        cout << "\nItem Name: " << itemName;
        cout << "\nPrice: " << price;
        cout << "\nQuantity in Stock: " << quantity;
        cout << "\n---------------------------";
    }
};

int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    for(int i = 0; i < n; i++)
    {
        int id, q;
        string name;
        float price;

        cout << "\nEnter details of Item " << i+1 << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> q;

        items[i].setItem(id, name, price, q);
    }

    cout << "\nInventory Details:";
    for(int i = 0; i < n; i++)
    {
        items[i].display();
    }


    int choice, qty;
    cout << "\nEnter item number to add stock: ";
    cin >> choice;
    cout << "Enter quantity to add: ";
    cin >> qty;
    items[choice-1].addStock(qty);


    cout << "\nEnter item number to sell: ";
    cin >> choice;
    cout << "Enter quantity to sell: ";
    cin >> qty;
    items[choice-1].sellItem(qty);


    cout << "\nUpdated Inventory:";
    for(int i = 0; i < n; i++)
    {
        items[i].display();
    }

    return 0;
}

