#include <iostream>
#include <string>
#include "../courseNamespace.h"
using std::endl;
using std::cin;
using std::cout;
using std::string;

using namespace courseNamespace;

namespace Sales
{
	class Sale
	{
	public:
		Sale();
		Sale(double thePrice);
		virtual double bill() const;
		double savings(const Sale& other) const;
		//Returns the savings if you buy other instead of the calling object.
	protected:
		double price;
	};

	bool operator <(const Sale& first, const Sale& second);
	//Compares two sales to see which is larger.

	class DiscountSale : public Sale
	{
	public:
		DiscountSale();
		DiscountSale(double thePrice, double theDiscount);
		//Discount is expressed as a percent of the price.
		virtual double bill() const;
		// Adding virtual here isn't required, but makes it more readable
	protected:
		double discount;
		string age;
	};
}

namespace Pets
{
	class Pet
	{
	public:
		virtual void print();
		string name;
	};

	class Dog : public Pet
	{
	public:
	 	virtual void print(); // virtual just for clarity
		string breed;
	};

	class Pet2
	{
	public:
		void print();
		string name;
	};
	class Dog2 : public Pet2
	{
	public:
	 	void print(); // virtual just for clarity
		string breed;
	};
}

namespace Error
{
	class VirtualFunctionError
	{
	public:
		virtual void print();
	};

	class BetterVirtualFunctionError
	{
	public:
		virtual void print();
		bool better = true;
	};
}

int main()
{
	print("Chapter 15: Inheritance");
	print("Ch 15.3- Polymorphism\n");

	print("\nPolymorphism- ability to associate multiple meanings to one function name by late binding");
	print("Virtual functions are functions that can be used before they are defined");

	print("\nWhen you use the virtual function keyword, you tell the compiler to wait"
	" until runtime to check the definition");
	print("This is another name for late binding or dynamic binding");

	{
		using namespace Sales;
		DiscountSale walmartPS4(400, 20);
		DiscountSale bestBuyPS4(375, 15);
		Sale gameStopPS4(315);

		cout << "Walmart " <<  walmartPS4.bill() << "   ";
		cout << "Best Buy " << bestBuyPS4.bill() << "   ";
		cout << "GameStop " << gameStopPS4.bill() << "\n";

		cout << "Walmart vs Best Buy " << walmartPS4.savings(bestBuyPS4) << "\n";
		cout << "Gamestop vs Walmart " << gameStopPS4.savings(walmartPS4) << "\n";
		cout << "Best buy vs GameStop " << bestBuyPS4.savings(gameStopPS4);
		// Example of polymorphism
		// C++ when calling savings (a function only present in the base class) runs the bills function
		// It knows to use the bills function in the derieved class
		// Even though it is a function in the base class
		// Otherwise it would call the base class function bills, which would go based on only the flat rate (without the discount)

		// Polymorphism works when you have a derieved class object
		// You can call base class functions
		// That use member functions overriden in the derieved class
	}

	print("\nRules for virtual functions:");
	print("  If functions have a different definition in the derrived class than the base class "
		"and you want it to be virtual add the virtual keyword to the decleration in the base class");
	print("  If a function is virtual in the base class, its automatically virtual in the derived class");
	print("  The keyword virtual is added in the decleration NOT the definition");
	print("  The only way to use a virtual function is with the keyword virtual");

	print("\nVirtual functions cause less efficiency");
	print("So only use them when you need them");
	// Otherwise, programmers would just make every function virtaul

	print("Remember- Overriding is whenever a virtual function's definition is changed in the "
		"derived class");
	print("It is redefined if its a regular function and overriden if it is a virtual function");
	// They both do the same thing, but the compiler treats them differently

	// Polymorphism, virtual functions, and late binding are all the same thing

	// SELF TEST
	
	// 	11. Suppose you modify the definitions of the class Sale (Display 15.9) by
	// deleting the reserved word virtual . How would that change the output of
	// the program

	// It would use the Sales version of 
	// This would mean it calculates based on the price only, not the price with the discount

	// SELF TEST END

	print("\nBasically, virtual functions are used to let old functions from a base class"
		" work with newly written functions in derieved classes");

	print("C++ is very strict about type mismatching (Strong typing)");
	print("Coercions are automatic type conversions");
	print("Unlike some other languages, coercions work for very few C++ types");

	{
		using namespace Pets;

		Pet myPet;
		Dog myDog;

		myPet.name = "Fishy";

		myDog.name = "Marley";
		myDog.breed = "Husky";

		Pet newPet;
		Dog newDog;
		
		newPet = myDog;  	// can set base class equal to derieved class
		// newDog = myPet; // can not set derieved class equal to base class

		print("\nWhen you set a derieved class to a base class, it loses access to members "
			"from the derieved class");
		print("When you try to access them, it will give an error the member doesn't exist");
		// newPet.breed;  // ex if splicing problem
		print("This is the slicing problem");

		Pet *petPointer;
		Dog *dogPointer;
		dogPointer = new Dog;
		dogPointer->name = "Rex";
		dogPointer->breed = "Chihuahua";
		petPointer = dogPointer;
		
		cout << "\nExample with polymorphism\n";
		petPointer->print();
		dogPointer->print();
		print("Because it is a virtual function, C++ knows to use the derieved class"
			" version of print in both instances");
		print("If it was not a virtual function, C++ would use the base class print function "
			" for the perPointer");

		// cout << petPointer->breed; // Still doesn't work bc slice problem
		// Even though the petPointer doesn't have access to breed, it can still be used
		// in the virtual print function

		Dog2 *dogPointer2;
		Pet2 *petPointer2;
		dogPointer2 = new Dog2;
		dogPointer2->name = "Rex";
		dogPointer2->breed = "Chihuahua";
		petPointer2 = dogPointer2;

		cout << "\nExample without polymorphism\n";
		petPointer2->print();
		dogPointer2->print();
		print("Without polymorphism, it calls the subclass print function in the subclass"
			" pointer and the superclass member function in the superclass pointer");

		Dog *dogPointer3;
		Pet *petPointer3;
		dogPointer3 = new Dog;
		dogPointer3->name = "Rex";
		petPointer3 = dogPointer3;

		cout << "\nExample without defining breed\n";
		petPointer3->print();
		dogPointer3->print();
		print("Works the same regardless of polymorphism or not");
		print("Because breed is undefined, C++ automatically calls the version in the "
			"superclass for both the superclass and subclass instance");
		print("This is because the subclass version of print would not work");
		print("Again, this would happen with or without it being a virtual function");
	}

	// Sum up
	print("\nWhen assigning superclasses to subclasses, you lose any member functions "
		"defined in the subclass");
	print("Virtual functions can be used to gain the benefits of extended type compatability");
	// Can't directly access the members, but it can call virtual functions that use them

	// Another way at looking at the sum up
	print("\n So when demoting a class, it can't access promoted member functions directly");
	print("The promoted data isn't lost, it is just only accessible in with virtual functions");

	{
		using namespace Error;
		print("\nIf you try to run C++ code with a virtual function that hasn't been defined, "
			"it will give an error");
		print("You have to give a definition for the virtual member function in the base class "
			"AND any derieved class that uses it");

		// VirtualFunctionError vfe;
		// Uncomment to see the error message
		// Even if VirtualFunctionError::print was defined, 
		// if you create a BetterVirtualFunctionError class instance
		// it also needs BetterVirtualFunctionError::print or it will give an error
	}

	print("\nDestructors should always be virtual");
	print("If not, deleting a pointer to a demoted subclass will only destroy the dynamic "
		"members it has access to");
	print("This means any dynamic member variable defined in the superclass will not be deleted");

	print("In C++, all destructors act like they have the same name");
	print("(Even if the class name is different, so it looks like they have different names)");
	print("When you use the virtual keyword for the destructor in the base class, it also is "
		"automatically applied to the subclass destructor, even if you didnt implicity state it");
	// Remember, even ~Dog() and ~Pet() appear to have different names
	// C++ treats them both as the same name
	// So calling the deconstructor in the demoted Dog, should call ~Dog
	// But if it isn't virtual, the demoted subclass only has access to the ~Pet deconstructor
	// This causes dynamic memory to never fully be deleted
	// SO ALWAYS MAKE DESTRUCTORS VIRTUAL

	//SELF TEST START

	// 12. Why can’t we assign a base class object to a derived class variable?

	// Promotion is impossible, but demotion is possible
	// This is because when the base class instance is instantiated, it only has the 
	// members for the base class
	// it can't gain access to members in the derieved class, because they don't exist

	// It is possible to demote a class and lose access to members (slicing)

	// 13. What is the problem with the (legal) assignment of a derived class object
	// to a base class variable?

	// Slicing problem

	// It loses access to the members from the derieved class
	// They aren't deleted from memory though
	// They can still be accessed by virtual functions that use them

	// 14. Suppose the base class and the derived class each have a member function
	// with the same signature. When you have a pointer to a base class object
	// and call a function member through the pointer, discuss what determines
	// which function is actually called—the base class member function or the
	// derived-class function.

	// If it is a virtual function in the base class
		// It depends on if the object was initialized as the subclass or the superclass 
		// So if you create it as a Dog but demote it to pet, it will use the Dog version
	// If it was not a virtual class
		// It deponds on if the pointer is of the subclass or superclass type
		// If you create it as a Dog but demote it to pet, it will use the Pet version

	// SELF TEST END

	print("\n\nChapter Summary:");
	print("  Inheritance can be used to save code by deriving one class from another and "
		"adding new members to the derieved class");
	print("  Derieved classes inherit all non-private members from the base class (private members "
		"can still be accesssed with public member functions (getters/setters primarily");
	print(  "Late binding (AKA polymorphism and virtual functions) means C++ waits until "
		"run-time to choose which version of a member function to call");
	print("  Protected keyword acts like private, but can be directly accessed by derieved "
		" classes, not requiring them to use getter/setter functions");
}

namespace Sales
{
	Sale::Sale() : price(0)
	{

	}
	Sale::Sale(double thePrice) : price(thePrice)
	{

	}

	double Sale::bill() const
	{
		return price;
	}
	double Sale::savings(const Sale& other) const
	{
		return ( bill() - other.bill());
	}

	bool operator <(const Sale& first, const Sale& second)
	{
		return (first.bill() < second.bill());
	}

	DiscountSale::DiscountSale() : Sale(), discount(0)
	{

	}
	DiscountSale::DiscountSale(double thePrice, double theSale) : Sale(thePrice), discount(theSale)
	{

	}

	double DiscountSale::bill() const
	{
		double fraction = discount/100;
		return price * (1 - fraction);
	}
}

namespace Pets
{
	void Pet::print()
	{
		cout << "The pet " << name << "\n"; 
	}
	void Pet2::print()
	{
		cout << "The pet " << name << "\n"; 
	}

	void Dog::print()
	{
		cout << "The dog " << name << " " << breed << "\n"; 
	}
	void Dog2::print()
	{
		cout << "The dog " << name << " " << breed << "\n"; 
	}
}