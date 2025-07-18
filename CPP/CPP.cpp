#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void setName(std::string n) {
        name = n;
    }

    void setAge(int a) {
        if (a >= 0) age = a;
    }
};

void runDemo() {
    // Create two Person objects
    Person person1("Alice", 25);
    Person person2("Bob", 30);

    // Display initial information
    std::cout << "Initial Persons:\n";
    std::cout << "Person 1: " << person1.getName() << ", Age: " << person1.getAge() << "\n";
    std::cout << "Person 2: " << person2.getName() << ", Age: " << person2.getAge() << "\n";

    // Modify person1
    person1.setName("Alicia");
    person1.setAge(26);

    // Display updated information
    std::cout << "\nAfter modification:\n";
    std::cout << "Person 1: " << person1.getName() << ", Age: " << person1.getAge() << "\n";
    std::cout << "Person 2: " << person2.getName() << ", Age: " << person2.getAge() << "\n";
}

// Function prototype
void DisplayDataTypes()
{
    // Integer types
    int age = 25;
    short smallNum = 100;
    long largeNum = 100000L;

    // Floating-point types
    float temperature = 36.6f;
    double pi = 3.14159265359;

    // Character type
    char grade = 'A';

    // String type
    string name = "John Doe";

    // Boolean type
    bool isStudent = true;

    // Output values
    cout << "Integer types:" << endl;
    cout << "Age (int): " << age << endl;
    cout << "Small number (short): " << smallNum << endl;
    cout << "Large number (long): " << largeNum << endl;

    cout << "\nFloating-point types:" << endl;
    cout << "Temperature (float): " << temperature << endl;
    cout << "Pi (double): " << pi << endl;

    cout << "\nCharacter type:" << endl;
    cout << "Grade (char): " << grade << endl;

    cout << "\nString type:" << endl;
    cout << "Name (string): " << name << endl;

    cout << "\nBoolean type:" << endl;
    cout << "Is student (bool): " << (isStudent ? "true" : "false") << endl;
}

void DisplayControlDemo() {
    std::cout << "C++ Control Structures Demo\n";
    std::vector<int> numbers = { 1, 4, 7, 2, 5 };

    // If-Else: Check if first number is even or odd
    if (numbers[0] % 2 == 0) {
        std::cout << numbers[0] << " is even\n";
    }
    else {
        std::cout << numbers[0] << " is odd\n";
    }

    // For loop: Print all numbers
    std::cout << "Numbers in array (using for loop): ";
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    // While loop: Sum numbers until sum > 15
    int sum = 0;
    int i = 0;
    while (i < numbers.size() && sum <= 15) {
        sum += numbers[i];
        std::cout << "Current sum: " << sum << "\n";
        i++;
    }
    std::cout << "Final sum: " << sum << "\n";
}
void writetofile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Hello world";
        file.close();
        std::cout << "Successfully wrote to " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}

void SwitchExample() 
{
    int choice;
    do {
        cout << "\nStudent Database Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. View Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Adding new student to database...\n";
            // Add student logic here
            break;
        case 2:
            cout << "Displaying student information...\n";
            // View student logic here
            break;
        case 3:
            cout << "Updating student information...\n";
            // Update student logic here
            break;
        case 4:
            cout << "Deleting student from database...\n";
            // Delete student logic here
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-5.\n";
        }
    } while (choice != 5);
}

class Interest {
protected:
    double principal;
    double rate;
    double time;

public:
    Interest(double p, double r, double t) : principal(p), rate(r), time(t) {}

    virtual double calculateInterest() = 0; // Pure virtual function for polymorphism

    virtual void display() {
        std::cout << "Principal: $" << principal << ", Rate: " << rate << "%, Time: " << time << " years" << std::endl;
    }

    virtual ~Interest() {} // Virtual destructor for proper cleanup
};

class SimpleInterest : public Interest {
public:
    SimpleInterest(double p, double r, double t) : Interest(p, r, t) {}

    double calculateInterest() override {
        return (principal * rate * time) / 100.0;
    }

    void display() override {
        Interest::display();
        std::cout << "Simple Interest: $" << calculateInterest() << std::endl;
    }
};

class CompoundInterest : public Interest {
private:
    int compoundsPerYear;

public:
    CompoundInterest(double p, double r, double t, int n = 1) : Interest(p, r, t), compoundsPerYear(n) {}

    double calculateInterest() override {
        return principal * (std::pow(1 + (rate / (100.0 * compoundsPerYear)), compoundsPerYear * time) - 1);
    }

    void display() override {
        Interest::display();
        std::cout << "Compound Interest (compounded " << compoundsPerYear << " times/year): $" << calculateInterest() << std::endl;
    }
};

void ClassHierarchyExample() {
    Interest* interests[] = {
        new SimpleInterest(1000, 5, 2),
        new CompoundInterest(1000, 5, 2, 12) // Mcompounding
    };

    for (Interest* interest : interests) {
        interest->display();
        delete interest; // Clean up
    }
}

int main() 
{
    try
    {
        //DisplayDataTypes();
        //DisplayControlDemo();
        //writetofile("output.txt");
        //SwitchExample();
        //runDemo();
        ClassHierarchyExample();
    }
    catch(...)
    {
		std::cerr << "An error occurred during execution." << std::endl;
    }
    return 0;
}