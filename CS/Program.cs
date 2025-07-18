using System;
using System.Collections.Generic;
using System.IO;

abstract class Interest
{
    protected double principal;
    protected double rate;
    protected double time;

    public Interest(double p, double r, double t)
    {
        principal = p;
        rate = r;
        time = t;
    }

    public abstract double CalculateInterest(); // Abstract method for polymorphism

    public virtual void Display()
    {
        Console.WriteLine($"Principal: ${principal}, Rate: {rate}%, Time: {time} years");
    }
}

class SimpleInterest : Interest
{
    public SimpleInterest(double p, double r, double t) : base(p, r, t) { }

    public override double CalculateInterest()
    {
        return (principal * rate * time) / 100.0;
    }

    public override void Display()
    {
        base.Display();
        Console.WriteLine($"Simple Interest: ${CalculateInterest():F2}");
    }
}

class CompoundInterest : Interest
{
    private int compoundsPerYear;

    public CompoundInterest(double p, double r, double t, int n = 1) : base(p, r, t)
    {
        compoundsPerYear = n;
    }

    public override double CalculateInterest()
    {
        return principal * (Math.Pow(1 + (rate / (100.0 * compoundsPerYear)), compoundsPerYear * time) - 1);
    }

    public override void Display()
    {
        base.Display();
        Console.WriteLine($"Compound Interest (compounded {compoundsPerYear} times/year): ${CalculateInterest():F2}");
    }
}

public class Person
{
    private string name;
    private int age;

    public Person(string name, int age)
    {
        this.name = name;
        this.age = age;
    }

    public string Name
    {
        get { return name; }
        set { name = value; }
    }

    public int Age
    {
        get { return age; }
        set { if (value >= 0) age = value; }
    }
}

class Program
{
    static void DisplayDataTypes()
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
        Console.WriteLine("Integer types:");
        Console.WriteLine($"Age (int): {age}");
        Console.WriteLine($"Small number (short): {smallNum}");
        Console.WriteLine($"Large number (long): {largeNum}");

        Console.WriteLine("\nFloating-point types:");
        Console.WriteLine($"Temperature (float): {temperature}");
        Console.WriteLine($"Pi (double): {pi}");

        Console.WriteLine("\nCharacter type:");
        Console.WriteLine($"Grade (char): {grade}");

        Console.WriteLine("\nString type:");
        Console.WriteLine($"Name (string): {name}");

        Console.WriteLine("\nBoolean type:");
        Console.WriteLine($"Is student (bool): {isStudent}");
    }

    static void DisplayControlDemo()
    {
        Console.WriteLine("C# Control Structures Demo");
        List<int> numbers = new List<int> { 1, 4, 7, 2, 5 };

        // If-Else: Check if first number is even or odd
        if (numbers[0] % 2 == 0)
        {
            Console.WriteLine($"{numbers[0]} is even");
        }
        else
        {
            Console.WriteLine($"{numbers[0]} is odd");
        }

        // For loop: Print all numbers
        Console.Write("Numbers in list (using for loop): ");
        for (int j = 0; j < numbers.Count; j++)
        {
            Console.Write(numbers[j] + " ");
        }
        Console.WriteLine();

        // While loop: Sum numbers until sum > 15
        int sum = 0;
        int i = 0;
        while (i < numbers.Count && sum <= 15)
        {
            sum += numbers[i];
            Console.WriteLine($"Current sum: {sum}");
            i++;
        }
        Console.WriteLine($"Final sum: {sum}");
    }
    static void WriteToFile(string filename)
    {
        try
        {
            File.WriteAllText(filename, "Hello world");
            Console.WriteLine($"Successfully wrote to {filename}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error writing to file: {ex.Message}");
        }
    }

    static void SwitchExample()
    {
        int choice;
        do
        {
            Console.WriteLine("\nStudent Database Menu:");
            Console.WriteLine("1. Add Student");
            Console.WriteLine("2. View Student");
            Console.WriteLine("3. Update Student");
            Console.WriteLine("4. Delete Student");
            Console.WriteLine("5. Exit");
            Console.Write("Enter your choice (1-5): ");
            choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    Console.WriteLine("Adding new student to database...");
                    // Add student logic here
                    break;
                case 2:
                    Console.WriteLine("Displaying student information...");
                    // View student logic here
                    break;
                case 3:
                    Console.WriteLine("Updating student information...");
                    // Update student logic here
                    break;
                case 4:
                    Console.WriteLine("Deleting student from database...");
                    // Delete student logic here
                    break;
                case 5:
                    Console.WriteLine("Exiting program...");
                    break;
                default:
                    Console.WriteLine("Invalid choice! Please select 1-5.");
                    break;
            }
        } while (choice != 5);
    }
    static void DisplayDemo(List<Person> persons, string header)
    {
        Console.WriteLine(header);
        for (int i = 0; i < persons.Count; i++)
        {
            Console.WriteLine($"Person {i + 1}: {persons[i].Name}, Age: {persons[i].Age}");
        }
    }

    static void LoadAndDisplayPersons()
    {
        List<Person> persons = new List<Person>
        {
            new Person("Alice", 30),
            new Person("Bob", 25),
            new Person("Charlie", 35)
        };
        DisplayDemo(persons, "List of Persons:");
    }

    static void ClassHierarchyExample()
    {
        Interest[] interests = {
            new SimpleInterest(1000, 5, 2),
            new CompoundInterest(1000, 5, 2, 12) // Monthly compounding
        };

        foreach (var interest in interests)
        {
            interest.Display();
        }
    }

    static void Main()
    {
        //DisplayDataTypes();
        //DisplayControlDemo();
        //WriteToFile("output.txt");
        //SwitchExample();
        //LoadAndDisplayPersons();
        ClassHierarchyExample();
    }
}