#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks[3];
    float average;

public:
    // Default constructor (for testing)
    Student() {
        rollNo = 1;
        name = "Test Student";
        marks[0] = 70;
        marks[1] = 75;
        marks[2] = 80;
        calculateAverage();
    }

    // Parameterized constructor (user input)
    Student(int r, string n, float m1, float m2, float m3) {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculateAverage();
    }

    // Function to calculate average
    void calculateAverage() {
        average = (marks[0] + marks[1] + marks[2]) / 3;
    }

    // Function to display student details
    void display() {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks[0] << ", " << marks[1] << ", " << marks[2];
        cout << "\nAverage Marks: " << average << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    // Default student (testing)
    cout << "\n--- Default Student Record ---";
    Student defaultStudent;
    defaultStudent.display();

    // User-defined students
    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        int roll;
        string name;
        float m1, m2, m3;

        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Roll Number: ";
        cin >> roll;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter marks in 3 subjects: ";
        cin >> m1 >> m2 >> m3;

        students[i] = Student(roll, name, m1, m2, m3);
    }

    cout << "\n--- Student Records ---";
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    delete[] students;
    return 0;
}

