from abc import ABC, abstractmethod
import math

class Interest(ABC):
    def __init__(self, principal, rate, time):
        self.principal = principal
        self.rate = rate
        self.time = time

    @abstractmethod
    def calculate_interest(self):
        pass

    def display(self):
        print(f"Principal: ${self.principal}, Rate: {self.rate}%, Time: {self.time} years")

class SimpleInterest(Interest):
    def calculate_interest(self):
        return (self.principal * self.rate * self.time) / 100.0

    def display(self):
        super().display()
        print(f"Simple Interest: ${self.calculate_interest():.2f}")

class CompoundInterest(Interest):
    def __init__(self, principal, rate, time, compounds_per_year=1):
        super().__init__(principal, rate, time)
        self.compounds_per_year = compounds_per_year

    def calculate_interest(self):
        return self.principal * (math.pow(1 + (self.rate / (100.0 * self.compounds_per_year)), self.compounds_per_year * self.time) - 1)

    def display(self):
        super().display()
        print(f"Compound Interest (compounded {self.compounds_per_year} times/year): ${self.calculate_interest():.2f}")

def ClassHierarchyExample():
    interests = [
        SimpleInterest(1000, 5, 2),
        CompoundInterest(1000, 5, 2, 12)  # Monthly compounding
    ]

    for interest in interests:
        interest.display()

class Person:
    def __init__(self, name, age):
        self._name = name
        self._age = age

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value

    @property
    def age(self):
        return self._age

    @age.setter
    def age(self, value):
        if value >= 0:
            self._age = value

def display_demo(persons, header):
    print(header)
    for i, person in enumerate(persons, 1):
        print(f"Person {i}: {person.name}, Age: {person.age}")

def DisplayDataTypes():
    # Integer types
    age = 25
    small_num = 100
    large_num = 100000

    # Floating-point types
    temperature = 36.6
    pi = 3.14159265359

    # Character type (Python uses strings for single characters)
    grade = 'A'

    # String type
    name = "John Doe"

    # Boolean type
    is_student = True

    # Output values
    print("Integer types:")
    print(f"Age (int): {age}")
    print(f"Small number (int): {small_num}")
    print(f"Large number (int): {large_num}")

    print("\nFloating-point types:")
    print(f"Temperature (float): {temperature}")
    print(f"Pi (float): {pi}")

    print("\nCharacter type:")
    print(f"Grade (str): {grade}")

    print("\nString type:")
    print(f"Name (str): {name}")

    print("\nBoolean type:")
    print(f"Is student (bool): {is_student}")

def DisplayControlDemo():
    print("Python Control Structures Demo")
    numbers = [1, 4, 7, 2, 5]
    
    # If-Else: Check if first number is even or odd
    if numbers[0] % 2 == 0:
        print(f"{numbers[0]} is even")
    else:
        print(f"{numbers[0]} is odd")
    
    # For loop: Print all numbers
    print("Numbers in list (using for loop):", end=" ")
    for num in numbers:
        print(num, end=" ")
    print()
    
    # While loop: Sum numbers until sum > 15
    sum_numbers = 0
    i = 0
    while i < len(numbers) and sum_numbers <= 15:
        sum_numbers += numbers[i]
        print(f"Current sum: {sum_numbers}")
        i += 1
    print(f"Final sum: {sum_numbers}")

def writetofile(filename):
    try:
        with open(filename, 'w') as file:
            file.write("Hello world")
        print(f"Successfully wrote to {filename}")
    except Exception as e:
        print(f"Error writing to file: {e}")

def SwitchExample():
    while True:
        print("\nStudent Database Menu:")
        print("1. Add Student")
        print("2. View Student")
        print("3. Update Student")
        print("4. Delete Student")
        print("5. Exit")
        choice = input("Enter your choice (1-5): ")

        match choice:
            case "1":
                print("Adding new student to database...")
                # Add student logic here
            case "2":
                print("Displaying student information...")
                # View student logic here
            case "3":
                print("Updating student information...")
                # Update student logic here
            case "4":
                print("Deleting student from database...")
                # Delete student logic here
            case "5":
                print("Exiting program...")
                break
            case _:
                print("Invalid choice! Please select 1-5.")
def DisplayPersonDemo():
    persons = [
        Person("Alice", 30),
        Person("Bob", 25),
        Person("Charlie", 35)
    ]
    display_demo(persons, "Person Information:")
    
    # Update a person's name and age
    persons[0].name = "Alicia"
    persons[0].age = 31
    display_demo(persons, "Updated Person Information:")

if __name__ == "__main__":
    #DisplayDataTypes()
    #DisplayControlDemo()
    #writetofile("output.txt")
    #SwitchExample()
    #DisplayPersonDemo()
    ClassHierarchyExample()