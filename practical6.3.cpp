#include <iostream>
#include <queue>
using namespace std;

// Fuel Class
class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f) {
        fuelType = f;
    }
};

// Brand Class
class Brand {
protected:
    string brandName;

public:
    Brand(string b) {
        brandName = b;
    }
};

// Car Class (Hybrid Inheritance)
class Car : public Fuel, public Brand {
public:
    // Constructor using initialization list
    Car(string f, string b) : Fuel(f), Brand(b) {}

    void display() {
        cout << "Brand: " << brandName << ", Fuel Type: " << fuelType << endl;
    }
};

// Method 1: Using Queue (Efficient structured approach)
void processUsingQueue() {
    cout << "\nProcessing using Queue (FIFO):\n";

    queue<Car> q;

    // Adding cars
    q.push(Car("Petrol", "Toyota"));
    q.push(Car("Diesel", "Mahindra"));
    q.push(Car("Electric", "Tesla"));

    // Processing cars
    while (!q.empty()) {
        Car c = q.front();
        q.pop();
        c.display();
    }
}

// Method 2: Using Static Array (Direct method)
void processUsingArray() {
    cout << "\nProcessing using Static Array:\n";

    Car cars[3] = {
        Car("Petrol", "Honda"),
        Car("Diesel", "Ford"),
        Car("Electric", "Tata")
    };

    for (int i = 0; i < 3; i++) {
        cars[i].display();
    }
}

// Main Function
int main() {
    processUsingQueue();
    processUsingArray();

    return 0;
}
