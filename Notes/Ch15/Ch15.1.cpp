#include <iostream>
#include <string>
#include "../courseNamespace.h"

using namespace courseNamespace;
using std::endl;
using std::cin;
using std::cout;
using std::string;

//WB-1.1
class Employee
{
public: 
	int getPayPrivate() {return privatePay;}
	int getPayProtected() {return protectedPay;}
private:
	int privatePay = 5;
protected:
	int protectedPay = 10;

};
//WB-1.2
class InheritedEmployee : public Employee
{
public:
	// int newGetPayPrivate() {return privatePay;}
	// Gives an error
	int newGetPayProtected() {return protectedPay;}

	int getPayProtected() {return protectedPay + 1;}  // (Just an example of redefinition)
	// When you call getPayProtected, for the IE, it runs the ovverridden pp + 1 version
};

int main() 
{
	print("---Chapter 15: Inheritance---");
	print("Ch 15.1- Inheriance Basics\n");

	print("\nInheritance- Process where a new class is created from another class");
	print("Derived Class (child class/ sub class)- new class being created");
	print("Base Class (parent class/ super class)- class getting inherited");
	
	print("\nAncestor class- Parent class of a parent... class");
	print("Descendant class- Child of a child... class");
	// Can be parent of a parent of a parent, etc
	
	print("\nThe derived class gets all member variables and functions that a base class has");
	print("It can also have it's own additional members");

	// Inheritance example: home appliances
	// You have a thermostat, garage door, and computer you want to sync
	// Make a device class which has stuff like model and serial number
	// Make a computer, thermostat, and garage door class which is a derived class of the device class
	// Each device will have its own unique member functions (openDoor, closeDoor), thermostat 
	// (getTemp, setTemp, incrementTemp, decrementTemp), etc
	// Then allow each to access the model of the others to sync them

	print("\nRedefining- You can overwrite a member function in a derived class");
	// If both the derived class and the base class define the same function,
	// the derived class' version will overwrite it when inherited in the derived class


	// Overwriting ex: If you have 2 types of employees, hourly and salary
	// create a default employee class which has a variable for pay and a function getPay
	// You can create a derived class for salary workers, which shares all the class
	// It will have its own getPay that overrides the original to work with salary pay instead of hourly
	
	print ("\nConstructors are not inherited from the parent class");
	print("They can be inherited with special syntax");
	print("When defining the constructor type:\n"
		"SubclassName::SubclassName() : SuperclassName()");
	print("After that include any new variables needed");
	
	print("\nYou should always directly invoke the base class constructor in the superclass");
	print("If you don't directly invoke it, the zero-argument constructor for the base class is"
		"automatically activated");
	// HourlyEmployee::HourlyEmployee( ) : Employee( )
	// {
	// 	//deliberately empty
	// }
	// Even if it didnt include a call to Employee(), the default constructor for 
	// Employee will automatically run, because the variables in the superclass
	// still need allocated

	print("\nYou can also use this syntax to automatically run other functions");
	// HourlyEmployee::HourlyEmployee() : Employee(), setWage(0), setHours(40)
	// {
	// 	//deliberately empty
	// }

	//WB-1
	Employee Chris;
	Chris.getPayProtected();
	Chris.getPayPrivate();

	InheritedEmployee Christopher;
	Christopher.getPayProtected();
	Christopher.getPayPrivate(); // Still accessible with inherited public functions
	Christopher.newGetPayProtected();
	// Christopher.newGetPayPrivate(); // Doesn't work because the subclass can't make 
	// new member functions that access private members of the superclass

	print("\nPrivate vs protected");
	//Private
	print("  If a variable in a superclass is private, the subclass can't inherit it");
	print("The variable will be allocated, it just won't be accessible");
	print("  This means you can't create new member functions in the subclass to get/set it");
	print("  It can access it with getter and setters functions inherited from the superclass");
	//Protected
	print("\n  Protected members act like private, but can be inherited");
	print("  This means you can directly access them with new member functions in the subclass");
	print("  Like private, they still can't be accessed outside the class/classes inheriting it");
	print("  Basically, use protected if you want to have the private member be fully inherited");
	//Sum up
	print("\n  Try to make your classes as private as possible (encapsulation)");
	print("  Protected variables are accessable and overwritable");
	print("  Private variables are only accessible (only be using getters/setters)");
	print("  General Rule: Use private unless you have a good reason not to");

	print("You can assign a parent class as a child class, but not the other way around");
	// If a function asks for an employee parameter, you can use a inheritedEmployee
	// You can also set a inheritedEmployee equal to an employee

	Employee Christian = Christopher;  // Setting derived equal to a base
	// InheritedEmployee Christ = Chris; // Setting a base equal to a derived is illegal
	return 0;


	// SELF TEST START
	
	// 	1. Is the following program legal (assuming appropriate #include and using
	// directives are added)?

	// 	void showEmployeeData(const Employee object);
	// 	int main( )
	// 	{
	// 		HourlyEmployee joe("Mighty Joe", "123-45-6789", 20.50, 40);
	// 		SalariedEmployee boss("Mr. Big Shot","987-65-4321", 10500.50);
	// 		showEmployeeData(joe);
	// 		showEmployeeData(boss);

	// 		return 0;
	// 	}
	// 	// Yes, Employee is the superclass for HEmployee and SEmployee
	// 	// You can use a subclass as the variable for a superclass argument

	// 	void showEmployeeData(const Employee object)
	// 	{
	// 		cout << "Name: " << object.getName( ) << endl;
	// 		cout << "Social Security Number: " << object.getSSN( ) << endl;
	// 	}

	// 	2. Give a definition for a class SmartBut that is a derived class of the base class
	// 	Smart , which we reproduce for you here. Do not bother with #include
	// 	directives or namespace details.

	// 	class Smart
	// 	{
	// 	public:
	// 		Smart( );
	// 		void printAnswer( ) const;
	// 	protected:
	// 		int a;
	// 		int b;
	// 	};
	// 	class SmartBut : public Smart
	// 	{
	// 	public:
	// 		SmartBut()
	// 		bool isCrazy()
	// 	private:
	// 		bool crazy;
	// 	}

	// 	This class should have an additional data field, crazy , that is of type bool ,
	// 	one additional member function that takes no arguments and returns a
	// 	value of type bool , and suitable constructors. The new function is named
	// 	isCrazy . You do not need to give any implementations, just the class
	// 	definition.


	// 	3. Is the following a legal definition of the member function isCrazy in
	// 	the derived class SmartBut discussed in Self-Test Exercise 2? Explain your
	// 	answer. (Remember, the question asks if it is legal, not if it is a sensible
	// 	definition.)
	// 	bool SmartBut::isCrazy( ) const
	// 	{
	// 		if (a > b)
	// 			return false;
	// 		else
	// 			return true;
	// 		}
	// 	}

	// 	// Yes because a & b are protected which is inheritable, but act like private members

	// SELF TEST END

	print("\nRedefining vs Overloading");
	print("\n  Not the same thing");
	print("  Redefined functions have the same name and paramters as the superclass function");
	print("  If you do redefine with different paramters, then the subclass will have access "
		"to the redefined function and the original superclass member function");
	print("  Redefining with different paramters is an example of overloading");

	print ("\nFunction Signature- a functions name with the types of parameters");
	print("It doesn't include const or &");
	print("If a function has the same name but a different signature, then it is overloading");
	// EX: 		 void printOrder(const int& cost, string& item, string& order);
	// Signature void printOrder(int, string, string);
	print("Some compilers add const to the signature");
	// UNRELIABLE
	// This means void print(const string words) and void print(string words)
	// Are both different signatures and it is valid overloading
	// NEVER DO THIS!

	print("\nIt is possible to call the superclass version of a redefined function in the "
		"subclass");
	print("Use the syntax: SubclassInstance.Superclass::memberFunction")
	Christopher.Employee::getPayProtected();  
	// Uses the superclass employee version of gPP instead of the redefinition 
	// Rare you will ever want to use it
}
