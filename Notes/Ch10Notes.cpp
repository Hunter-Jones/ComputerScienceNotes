#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void print(string line)
{
	cout << line << endl;
}

// WB-1
struct PNCBankAccount
{
	double balance;
	double interestRate;
	double term;
};

// WB-2
struct ShoeTypes
{
	char type;
	int price;
};

// WB-3
class DayOfYear  // Creates the DayOfYear class
{
public:
	void output();  // Member function declaration
	void input();
	// THIS IS JUST A HEADER, NEEDS DECLARED BELOW
	int month;
	int day;
};

// WB-4
class Temperature
{
 public:
	 void set(double newDegrees, char newScale);
	// Sets the member variables to the values given as
	 double degrees;
	 char scale; //'F' for Fahrenheit or 'C' for Celsius.
 };


//WB-5
 class SavingsAccount : public PNCBankAccount  // Creates a child of PNCBankAccount
 {
 public:
 	SavingsAccount(int dollars, int cents, double rate);  // Needs a new constructor
 	void deposit(int dollars, int cents);  // Classes added to SA not in BA
 	void withdraw(int dollars, int cents);

 	// This has access to all PNCBankAccount members
 };

 class CDAccount : public SavingsAccount  // Child of a child
 {
 public:
 	CDAccount(int dollars, int cents, double rate);
 	int getMaturity();
 	// Post: Returns the member variable 
 	void decramentDaysToMaturity();
 	// Pre should be run daily to accurately count down the days to matrity
 	// Post subtraces 1 from the maturity variable
 private:
 	int maturity;
 	// Days until CD matures

 };

 class CheckingsAccount : public PNCBankAccount  // You can have inheritance branch
 {
 public:
 	CheckingsAccount(int dollars, int cents, double rate);
 	// More extra stuff
 };

// WB-6
class DayOfYear2
{
public:  // EVERYTHING FROM HERE TO PRIVATE IS PUBLIC
	void input();
	void output();
	void set(int newMonth, int newDay);
	int getMonth();
	int getDay();
	// void checkDate(); // Self-check 14, chose not to do because tediousness/simplicity	
private:   
	void checkDate();
	int month;
	int day;
};

// WB-7
class DayOfYear3
{
public:  // EVERYTHING FROM HERE TO PRIVATE IS PUBLIC
	DayOfYear3();
	// Initialize the values month and day to 1
	DayOfYear3(int mon, int dayOfMonth, bool holiday);
	// Initializes values mon to month and dayOfMonth to day
	// Also prints the date if the user says it is a holiday
	void input();
	// Post: Prompts the user to enter a day and month
	// Then stores the values to day and month
	void output();
	// Post: Outputs the month and day to console formatted
	void set(int newMonth, int newDay);
	// Pre: Requires the user to enter a month (1-12) and day (1-31)
	// Post: sets month and day to newMonth and newDay
	int getMonth();
	// Post: eturns month
	int getDay();
	// Post: returns day

	// void checkDate(); // Self-check 14, chose not to do because tediousness/simplicity	
private:   
	void checkDate();
	// Used to check if the date entered was valid
	int month;
	int day;
};

void structure();
	PNCBankAccount addUser(int);
	void readShoeRecord(ShoeTypes& newShoe);
	ShoeTypes discount(ShoeTypes);
void classes();
void abstractDataTypes();
void introductionToInheritance();


int main() 
{
	cout << "---Chapter 10: Defining Classes---\n";
	structure();
	classes();
	abstractDataTypes();
	introductionToInheritance();
}

void structure()
{
	cout << "--10.1: Structures--\n";
	cout << "-10.1.1: Structures for Diverse Data-\n\n";

	cout << "The struct keyword is used to create a structure\n";
	cout << "Just type struct identifier\n";
	cout << "Structures normally follow camel-case with the first letter capitalized\n";

	cout << endl << "Structure tag- the identifer for the structure, which can be any legal variable name\n";
	cout << "Member names- Identifiers created inside the { }\n";
	cout << "Structure value- collection of member values\n";
	cout << "Member values- Each member name has a member value, which is the name of each duplicate of the structure\n";
	cout << "Member variables- the individual values in each member name";

	cout << endl << "Structures let you have multiple variables and functions inside one organized structure and can be replicated\n";
	
	struct CDAccount  
	{
		double balance;
		double interestRate;
		double term;
	};

	CDAccount huntersAccount;
	huntersAccount.balance = -37.99;
	huntersAccount.interestRate = 0;
	huntersAccount.term = 99999;

	CDAccount musksAccount;
	musksAccount.balance = 100000000000;
	musksAccount.interestRate = 3.7;
	musksAccount.term = 24;

	cout << endl << "For this, the structure tag is CDAccount\n";
	cout << "The member names are balance, interestRate, and term\n";
	cout << "The structure values are huntersAccount and musksAccount\n";
	cout << "The member values are balance, interestRate, term, for both structure values";
	cout << "And the member variables are -37.99, 0, 99999, 100000000000, 3.7, 24\n";

		struct BankAccount  
	{
		double spendBalance;
		double saveBalance;
		double interestRate;
		string branch;
	}; // MAKE SURE TO ADD THE ; AFTER THE }

	double spendBalance;  // Even regular variables can have the same name as member variables
	cout << endl << "Multiple structures can use the same member names\n";

	huntersAccount.balance = musksAccount.balance;  // THIS IS SHALLOW COPYING
	cout << endl << "Shallow Copying- Directly copying\n";
	cout << "Shallow copying works for simple variables but can cause issues for dynamic vars\n";

	struct students  
	{
		char grade;
		string AcademicClass;
		double passFail;
	} hunter, randomStudentA;
	hunter.passFail = true;
	cout << endl << "You can create structs after it's creation by adding the structure values after the }\n";


	cout << endl << "-10.1.2 Structures as Functional Arguments-\n\n";

	PNCBankAccount testAccount = addUser(18);
	cout << endl << "If you define the structure above the function header & where the function is being called in global scope, it is possible to create which returns a structure\n";
	cout << "Global structure definitions is common unless specific situations\n";

	struct SchoolClass
	{
		string name;
		int credits;
		char gradeRecieved;
	};
	struct person
	{
		string name;
		struct Date  // Bad
		{
			int day;
			string month;
			int year;
		} birthday, graduationDate;
		SchoolClass science, history; // Good
	};
	person defaultGuy;
	defaultGuy.birthday.year = 2001;
	defaultGuy.graduationDate.year = 2020;
	defaultGuy.science.gradeRecieved = 'A';
	cout << endl << "Structs in structs is possible\n";  // UNLIMITED POWEEEER!!!

	cout << endl << "-10.1.3 Initializing Structures-\n\n";

	SchoolClass cs = {"Computer science", 4, 'C'};
	cout <<  endl << "You can initialize structures when declared\n";



	cout << endl << endl << endl << "Self Test Exercises:\n";

	// 1
	struct TermAccount
	{
		double balance;
		double interestRate;
		int term;
		char initial1;
		char initial2;
	};
	TermAccount account;
	// account.balance is a member variable
	// account.interestRate is mem var
	// TermAccount.term is a member name
	// account is a structure variable

	// 2
	struct ShoeType
	{
		char style;
		double price;
	};

	ShoeType shoe1, shoe2;
	shoe1.style ='A';
	shoe1.price = 9.99;
	cout << shoe1.style << " $" << shoe1.price << endl;
	shoe2 = shoe1;
	shoe2.price = shoe2.price/9;
	cout << shoe2.style << " $" << shoe2.price << endl;

	// This will output: 
	//'A' $9.99 
	//'S' $1.11 

	// 3

	// struct Stuff
	// {
	// 	int b;
	// 	int c;
	// }
	// int main( )
	// {
	// Stuff x;
	// //other code
	// }

	// // The error is that there is no ; after the }
	// // This causes an error because C++ doesnt know if the user wants to declare structs on creation

	// 4
	struct A
	{
		int memberB;
		int memberC;
	};
	A x = {1, 2};

	struct Date
	{
		int month;
		int day;
		int year;
	};
	Date dueDate1 = {12, 21};  // Sets month to 12, day to 21st and year to unknown (legal)
	// Date dueDate2 = {12, 21, 20, 22}; // HAS AN EXTRA VALUE
	// Date dueDate3 = {12, 21, 20, 22};  // HAS AN EXTRA VALUE
	Date dueDate4 = {12, 21, 22};  // sets month to 12 day to 21st, and year to 22

	// 6            		
	struct Records 
	{
		double wageRate;
		int vacationDays;
		char hourlyOrSalary;  // H or S
	};

	// 7

	// HAD TO CHANGE FROM SHOETYPE, BECAUSE IT WAS PASSING THE LOCAL SHOETYPE AND GIVING AN ERROR
	// ShoeTypes croc {'A', 3};
	// readShoeRecord(croc);

	// 8
	// croc = discount(croc);`

	// 9 
	struct StockRecord
	{
		ShoeTypes shoeType;
		Date arrivalDate;
	};

	// 10 
	StockRecord croc2;
	croc2.arrivalDate.year = 2006;
}

void classes()
{
	cout << "--10.2: Classes--";
	cout << "-10.2.1 Defining Classes and Member Functions-\n\n";

	cout << endl << "Class- datatype whose variables are objects\n";
	cout << "Object- variable that has member functions as well as the ability to hold datatypes\n";

	cout << endl << "Classes are created the same way as structures but with the keyword class instead of struct\n";
	cout << "It also lists the member function output\n";
	cout << "You can intermix ordering of member variables and member functions\n";
	cout << "Standard practice says member functions before member variables\n";
	cout << "You also have to list the scope of the class (public, private, etc)\n";
	cout << "NORMALLY DECLARE IN GLOBAL SCOPE\n";

	DayOfYear birthday, today;
	birthday.month = 9;
	birthday.day = 15;
	// today.output( );
	cout << "Your birthday is ";
	birthday.output();
	cout << "Calling output shows that you can create functions in classes\n";
	// You can write the function in the class or just make a header and call it below


	class Person
	{
	public: // This must be before all public variables and classes
		int age;
		string name;
		void intro(string phrase)
		{
			cout << "Hi my name is " << name << " and I am " << age << ". " << phrase << ".\n";
		}
	};
	Person hunter;
	hunter.name = "Hunter Jones";
	hunter.age = 18;
	hunter.intro("This is coming from the person class Hunter");


	// void DayOfYear::output;
	cout << endl << ":: is scope resolution operator\n";
	// Used to specify class name when giving the function definition of a member function
	cout << "This was used when creating the definition for output\n";
	cout << "It is used to create definitions and not confuse them, there can be multiple output functions in each in different classes because they are defined with ::\n";
	cout << ". is dot operator\n";
	//Specify a member of an object
	// Used when calling the functions and variables in code
	// This is also the answer to self-test 13

	// birthday.input();  // Now with input function from self-test exercise 11
	// birthday.output();
	
	cout << "-10.2.2 Public and Private Variables-\n\n";

	// You can build libraries of custom classes and import them from another file
	// If you change how the class works for efficiency (as long as it does the same thing) then all the files using it are effected

	// Look at DayOfYear2 to see proper use of private and public
	cout << "Private member variables/functions- Use private: keyword and can ONLY be used inside the function\n";
	// This means that you can't access the private variables inside regular code, but they can be accessed in functions in the private variable

	DayOfYear2 christmas;
	// christmas.month = 12;
		// Because month is declared private, it can't be  accessed outside of the function
	christmas.set(12, 25);
	// This is now how you set the day/month, with a custom set function
	cout << endl <<"You can access the variables with the getter functions: " << "month- " << christmas.getMonth() << " day: " << christmas.getDay() << endl;
	cout << "This makes directly accessing member variables impossible\n";
	cout << "By not allowing direct access to variables, it can allow you to make sure the user inputs everything correctly\n";
		// Assuming you have data validation within the set function
	cout << "It also makes it easier to change the implementation later, because now you just have to change the set function instead of everywhere you set the data\n";

	cout << endl << "Encapsulation- (data hiding), a technique of making variables in a class private and only controlled through public protected functions\n";

	cout << endl <<"Public members- uses public keyword, can be accessed anywhere including main/functions within main\n";
	// There are no limits to how many member vars/funcs can be private or public
	// Just using either keyword will make all members bellow private or public, until the next keyword is used

	class SampleClass
	{
		int secrets;  // PRIVATE
		void secrety();  // private
	public:
		void doSomething(); // public
		int stuff; // public
		bool stuffing;
	private:
		void doSomethingElse();  // private
		char moreStuff;  // private
	public:
		double doYetAnotherThing();  // public
		double evenMoreStuff;  // public
	};

	cout << endl << "If you don't say if members are private or public, they are considered private\n";
	// You should still explicitly say they are private so it is more readable

	cout << endl << "ALL member variables should be private if following encapsulation\n";
	// Remember to have public getters and setters

	cout << endl <<  "== does not work in classes to test equality\n";

	cout << endl << "Accessor functions- (getters), functions that are getVAR_NAME\n";
	cout << "They are public and just return the requrested variable\n";
	cout << "How people access private variables\n";

	cout << endl << "Mutator function- (setters), functions that are setVARIABLE_NAME\n";
	cout << "They just set an argument equal to a private variable\n";
	cout << "How people modify private variables\n";

	// SELF TEST 15
	class Automobile
	{
	public:
		void setPrice(double newPrice);
		void setProfit(double newProfit);
		double getPrice();
		void set(double newPrice, double newProfit);
		// You can call functions member functions within member functions without . operator, 
		// So set could just be a function that runs setPrice and setProfit
		void set(double newPriceDollars, double newPriceCents, double newProfit);
		// OVERLOAD BAYBEE
		// Class member function overloading works like regular function overloading
	private:
		double price;
		double profit;
		double getProfit();
	};
	// hyundai.price = 4999.99; ILLEGA:
	// jaguar.setPrice(30000.97);
	// double aPrice, aProfit;
	// aPrice = jaguar.getPrice();
	// aProfit = jaguar.getProfit(); ILLEGAL
	// aProfit = hyundai.getProfit(); //ILLEGAL

	// Self test 16: If you omit the word private, nothing changes because inexplicit are considered private

	// Self test 17: Not making everything public allows encapsulation which lets you
		// Make more readable code
		// Easier to manage/ modify
		// Allow easier data validation

	// Self test 18
		// A: An unlimited amount of public members are allowed to be helpful
			// C: There should be a public getter/setter for anything the user should be able to access
		// B: An unlimited amount of private members are allowed to be helpful
			// D: All variables should be private and any functions the user doesn't need direct access to 

	DayOfYear2 easter, laborDay;
	easter = laborDay;

	cout << endl << "You can set classes equal to each other with = , but remember you cant compare classes with ==\n";

	cout << endl << "Class summary\n";
	cout << "     " << "Classes have member variables and functions\n";
	cout << "     " << "Members can be private or publcic\n";
	cout << "     " << "Normally all members are labeled public or private\n";
	cout << "     " << "Private members can only be used within the definition of another member function in the same class\n";
	cout << "     " << "Member functions can be overloaded like regular functions\n";
	cout << "     " << "Classes can use other classes as the type for a membr variable\n";
	// Class recursion
	cout << "     " << "A function may use classes as formal paramters\n";
	cout << "     " << "A function can return an object (can be a class\n";


	cout << endl << "-Constructors and Initializers-\n\n";

	print("Constructor- member function automatically called when an object of the class is declared");
	print("Oftentimes used to pre-initialize member variables");

	print("\nConstructors must:");
		print("     Have the same name as the class");
		print("     Not return a value, shouldn't include a return type (NOT EVEN VOID");

	DayOfYear3 randomDate(7, 21, false);
	// Because DOTY3 has a constructor which calls for 2 ints and a bool it is needed when called
	// randomDate.output();

	print("\nYou can overload constructors (at this point, what isn't overloaded)");
	print("If you don't want to change the data after declaration, you can use a constructor to set the first value, then remove the set member functions");

	print("\nInitialization Section- Way to create constructors with a : instead of encased in ()");
	print("It lets you set the member variables on declaration instead of passing arguments to to be set equal to member variables");
	print("When you create the member function, dont add () after the name also");
	// Requrires the user to not input any information
	// DayOfYear3 randomDateA(); // WRONG!!!
	DayOfYear3 randomDateA;  // CORRECT
	// randomDateA.output();

	// PSA: If you create this, you wont be able to call DayOfYear3() unless you add another constructor which is default paramter that doesn't use :


	randomDate = DayOfYear3(6,9, false);
	print("\nYou can recall constructors");
	print("Just type memberFunctionName = ClassName(arguements)");
	print("Can be used to rechange all the values in a class");

	print("\nDefault constructor- Constructor that can be called with no parameters");
	// Good with the intialization section call
	print("If you have no constructors, C++ creates a default constructor that does nothing if one was not already created");
	print("This means if you create at lesast 1 constructor, then unless you declare a default constructor, you can't pass no arguments");
	print("This means every class has a constructor (even if it is just a default constructor C++ created which does nothin");
	//You should always include a default constructor
		// Even if it has an empty body (doesn't do anything)

		// DayOfYear3 randomDateA;  
		// remember not adding () is correct for calling without any paramters

	// Self-test

	class YourClass
	{
	public:
		YourClass(int newInfo, char moreNewInfo);
		YourClass();
		void doStuff();
	private:
		int information;
		char moreInformation;
	};

	// YourClass anObject(42, 'A');  // LEGAL
	// YourClass anotherObject;  //LEGAL
	// YourClass yetAnotherObject();  // ILLEGAL
	// anObject = YourClass(99, 'B');  // LEGAL
	// anObject = YourClass(); // ILLEGAL
	// anObject = YourClass;  // LEGAL
}

void abstractDataTypes()
{
	cout << "--10.3: Abstract Data Types--\n\n";

	print("Data type- Set of values with basic operations defined for them");
	// EX: the set of values for short  int would be -32; to 32k
	//     the operations would be + - * / %
	print("Abstract data type- name for a data type when programmer doesn't have access to how ovalues and perations are implemented");
	// Ints (and most basic types) would be ADT because you dont know how operations like + work
	// Self-created data types can be ADT depending on implementation

	print("\nYou should try to write classes to be ADTs\n");
	// Makes program easier to understand

	cout << "\n-10.3.1 Classes to Produce Abstract Data Types\n";

	print("\nThe idea is to make is to make it so programmers using your class don't need to understand how your function works, just what it does/returns");

	print("\n To make a class an ADT:");
		print("Make all member variables private\n");
		print("Make basic operations the programmer needs public member functions and specify how to use each member function");
		print("\nMake helper functions private");
		// Basically just privatize what the user doesn't need to know and publicize what the user should know

	print("\nInterface- Part of ADT that tells you how to use it");
	print("This includes public members and comments");

	print("\nImplementation- part of ADT telling how interface works");
	print("Definitions and private members");

	print("\nThe programmer needs to know the interface but not the implementation of a ADT to use it");
	print("This also means you should be able to change the implementation without change other parts of the program");

	// ---SELF TEST START---
	//  25- When you define an ADT as a C++ class, should you make the member
	// variables public or private? Should you make the member functions
	// public or private?

	// member variables-
	// member functions- private, operations public & helper private

	// 26- When you define an ADT as a C++ class, what items are considered
	// part of the interface for the ADT? What items are considered part of the
	// implementation for the ADT?

	//Interface- public operation member functions and comments
	// Implementation- private helper member functions, and function headers

	// 27- Suppose your friend defines an ADT as a C++ class in the way we described
	// in Section 10.3. You are given the task of writing a program that uses this
	// ADT. That is, you must write the main part of the program as well as any
	// nonmember functions that are used in the main part of the program. The
	// ADT is very long and you do not have a lot of time to write this program.
	// What parts of the ADT do you need to read and what parts can you safely
	// ignore?

	// Read the interface and skip the implementation

	// 28- Redo the three- and two-parameter constructors in Display 10.7 so that all
	// member variables are set using a constructor initialization section.

	// Check class DayofYear3

	// ---SELF TEST END---
}

void introductionToInheritance()
{
	cout << "---10.4: introduction To Inheritance---\n\n";

	print("Derived classes means inheritance");
	// Very useful and poweful in C++

	print("\nInheritance allows you to create a general class, then create more specialized classes from the general class later");
	print("This means any members in the general class are also in the specialized class, but the specialized class has extra members also");

	// Imagine a school DB with basic functions for students, but more for teachers

	// Another would be the bamkAccount
		// A checking account (specialized class) does everything a savings account (general class) does, but allows you to withdraw and spend money 

	print("\n Inheritence allows you to not rewrite class members and also not change the general class to modify the specialized class");

	print("\nDerived class0 name for a class that inherits from another class");
	// (Specialized class)
	print("Derived classes have all the functionality of the original class with added features");

	// Hierarchy example
		// BankAccount
			// CheckingAccount
				//MoneyMarketingAccount
			// SavingsAccount
				// CDAccount

		// This means CheckingsAccount and SavingsAccount both have everything from BanKAccount with their own added features
		// MoneyMarketingAccount has everything from BankAccount and the added features from CheckingsAccount along with its own features
		// Same with CDAccount

	// This shows there can be multiple levels of hierarchy

	print("Derived classes do not have access to private members");
	print("They do have acess to public getter/setter functions");

	print("\nDerived Class Medaphor (Inheritance)");
	print("     Child- Derived class");
	print("     Parent/Base- Class getting derived from");

	print("Inheritance Formula:  class childAccount : public ParentAccount");
	// SEE WB-5 for example

	// ---Self Test Start---
	// 29. How does inheritance support code reuse and make code easier to
	// maintain?

	// You dont have to rewrite all of the code from the parent class for the child class

	// 30. Can a derived class directly access by name a private member variable of
	// the parent class?

	//  No, but they have access to them through public functions

	// 31. Suppose the class SportsCar is a derived class of a class Automobile .
	// Suppose also that the class Automobile has public member functions
	// named accelerate and addGas . Will an object of the class SportsCar
	// have member functions named accelerate and addGas ?

	// Yes
}

//WB-8
PNCBankAccount addUser(int number)
{
	PNCBankAccount newAccount;
	newAccount.balance = 0;
	newAccount.interestRate = 2;
	newAccount.term = number;

	return newAccount;
}

// WB-9
void readShoeRecord(ShoeTypes& newShoe)
{
	cout << "Enter a price: ";
	cin >> newShoe.price;

	cout << "Enter a character for the type: ";
	cin.clear();
	cin.ignore();
	cin.get(newShoe.type);
}
//Fills newShoe with values read from the keyboard.

// WB-10
ShoeTypes discount(ShoeTypes oldRecord) 
{
	oldRecord.price *= .9;
	return oldRecord;
}
//Returns a structure that is the same as its argument,
//but with the price reduced by 10%.

// WB-11
void DayOfYear::output()
{
	cout << "month = " << month
	<< ", day = " << day << endl; // It automatically has access to day and month from the class
}
void DayOfYear::input()
{
	cout << "Enter 0-12 for the month: ";
	cin >> month;
	cout << "Enter the day of month " << month << ":";
	cin >> day; 
}

// WB-12
void Temperature::set(double newDegrees, char newScale)
{
	scale = newScale;
	degrees = newDegrees;
}

// WB-13
void DayOfYear2::output()
{
	cout << "month = " << month
	<< ", day = " << day << endl; // It automatically has access to day and month from the class
}
void DayOfYear2::input()
{
	cout << "Enter 0-12 for the month: ";
	cin >> month;
	cout << "Enter the day of month " << month << ":";
	cin >> day; 
}
void DayOfYear2::set(int newMonth, int newDay)
{
	month = newMonth;
	day = newDay;
}
void DayOfYear2::checkDate()
{
	if ((month < 1 ) || (month > 12) || (day < 1) || (day > 31))
	{
		cout << "Invalid input";
	} 
}
int DayOfYear2::getMonth()
{
	return month;
}
int DayOfYear2::getDay()
{
	return day;
}

// void BankAccount::output(ostream& outs)
// {
// 	outs.setf(ios::fixed);
// 	outs.setf(ios::showpoint);
// 	outs.precision(2);
// 	outs << "Account balance $" << balance << endl;
// 	outs << "Interest rate " << interestRate << "%" << endl;

// 	// This works so that you can use cout as the argument or you can usae a file
// }

// Self-Test 19
// double difference(BankAccount account1, BankAccount account2);
//Precondition: account1 and account2 have been given values
//(that is, their member variables have been given values).
//Returns the balance in account1 minus the balance in
// account2

// double difference(BankAccount account1, BankAccount account2)
// {
// 	return accoun1.getBalance() - account2.getBalance();
// }

// void doubleUpdate(BankAccount& theAccount);
//Precondition: theAccount has previously been given a value
//(that is, its member variables have been given values).
//Postcondition: The account balance has been changed so that
//two years' interest has been posted to the account.

// Self test exercise 21
// BankAccount newAccount(BankAccount oldAccount);
//Precondition: oldAccount has previously been given a value
//(that is, its member variables have been given values).
//Returns the value for a new account that has a balance of zero
//and the same interest rate as the oldAccount.

// BankAccount newAccount(BankAccount oldAcc)
// {
// 	BankAccount newAcc = oldAcc;
// 	newAcc.setBalance(0);
// 	return newAcc;
// }

// Since the overload name is the same as the function name, it must occur twice
// ORIGINAL WAY
DayOfYear3::DayOfYear3(int mon, int dayOfMonth, bool holiday)
{  // Make sure the arguments arent the same as the private member variables
	// Ex: day couldnt be an argument (needed switched to dayOfMonth) bc day is already declared as a private member variable 
	if(holiday)
	{
		cout << mon << "/" << day << " is a holdiay";
 	}
 	month = mon;
 	day = dayOfMonth;
}

// Initialization section 
// Also an example of overloading
// Automatically sets month to whatever the user puts as well as date
// Within the () is the default value being set
	// This is the same as setting month and date to 1
	// Only runs if the user types nothing

	// You could just set the private variables equal to 1 when you declare them instead (ex: int day = 1)
		// Because of that, this is pretty useless
DayOfYear3::DayOfYear3() : month(1), day(1)
{  

}
void DayOfYear3::output()
{
	cout << "month = " << month
	<< ", day = " << day << endl; // It automatically has access to day and month from the class
}