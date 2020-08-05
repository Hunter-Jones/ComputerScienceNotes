#include <iostream>
#include <string>
#include "../courseNamespace.h"

using std::endl;
using std::cin;
using std::cout;
using std::string;
using namespace std;
using namespace courseNamespace;

// Pre: Requires 2 int/char
// Post: Puts the value in int1 into int2 (or char)
void swapValues( int& v1, int& v2);  // WB-1.1
void swapValues( char& v1, char& v2);

// Pre: Requires 2 of the same variable type
// Post: Takes the value in v1 and swaps it with the value in v2
template<class VariableType>  // WB-2.1
void newSwapValues(VariableType v1, VariableType v2);



// template<class VariableType>  // WB-3.1
// VariableType newSwapValues(VariableType v1, VariableType v2);

// template<class VariableType1, class VariableType2>  // WB-2.1
// void newSwapValues(VariableType1 v1, VariableType2 v2);4

// Pre: Requires 2 variables of the same type
// NOTE: They must work with comparison operators
// Post: Returns whichever value is greater 9 > 0, z > a
template <class val>
val maximum(val n1, val n2)
{
	if (n1 > n2)
	{
		return n1;
	}
	return n2;
}

// Pre: Requires 1 value
// NOTE: The value must work with comparison operators 
// and be comparable to the int 0 and be multipliable by ints
// Post: Returns the absolute value of n1
template <class val>
val absolute(val n1)
{
	if (n1 < 0)
		n1 *= -1;
	return n1;
}

// Pre: Requires an array of any type and the arraySize
// NOTE: Comparison operations must work on the array type
// Post: Sorts the array
template <class val>
void sort(val a[], int numberUsed)
{
	int indexOfNextSmallest;
	for (int index = 0; index < numberUsed - 1; index++)
	{//Place the correct value in a[index]:
		indexOfNextSmallest = indexOfSmallest(a, index, numberUsed);
		// iOS needs defined, just an example
		swapValues(a[index], a[indexOfNextSmallest]);
		//a[0] <= a[1] <=...<= a[index] are the smallest of
		//the original array elements. The rest of the
		//elements are in the remaining positions.
	}
}

int main(int argc, char const *argv[])
{
	print ("Chapter 17: Templates");
	print("Ch 17.1- Templates for Algorithm Abstraction\n");

	print("\nIf you want a function to work with multiple variable types you can overload it");
	print("If it is the same code each time with different variable types, "
		"there is an easier way to do it");
	// Example is WB-1
	// If you wanted a swapValues for every primitive, it would take a long time to write
	print("Templates can be used to fix the issue");

	print("\nTemplate prefix- Tells the compiler that the function definition is for a template");
	print("EX: template<class T>");
	print("Template- The function definition following the prefix");
	print("Type parameter- what is in the <> in a template prefix");
	print("(T in the example), class means type");
	//WB-2

	print("\nYou can make the template type also the return type");
	print("Its also possible to have multiple template types in 1 function");
	//WB-3

	int a1 = 3, a2 = 4;
	double b1 = 4.3, b2 = 4.8;
	char c1 = 'c', c2 = 'd'; 	
	newSwapValues(a1, a2);
	newSwapValues(b1, b2);
	newSwapValues(c1, c2);

	print("\nC++ does not allow you to seperate implementation and interface files with templates");
	print("The best way to use templates is to not include a declaration and have the definition at the top of the file");
	print("Or you  can put the definition and declaration in the same header (interface) file");
	print("Many compilers have additional rules for templates");
	// G++ makes you put the template<> at the definition and declaration

	// SELF TEST START

	// 1. Write a function template named maximum . The function takes two values
	// of the same type as its arguments and returns the larger of the two argu-
	// ments (or either value if they are equal). Give both the function declara-
	// tion and the function definition for the template. You will use the operator
	// < in your definition. Therefore, this function template will apply only to
	// types for which < is defined. Write a comment for the function declaration
	// that explains this restriction.
	// cout << maximum(3, 4);
	// cout << maximum('a', 'd');
	// cout << maximum(3.2, -1.0);

	// 2. We have used three kinds of absolute value function: abs , labs , and fabs .
	// These functions differ only in the type of their argument. It might be better
	// to have a function template for the absolute value function. Give a function
	// template for an absolute value function called absolute . The template
	// will apply only to types for which < is defined, for which the unary
	// negation operator is defined, and for which the constant 0 can be used in
	// a comparison with a value of that type. Thus, the function absolute can be
	// called with any of the number types, such as int , long , and double . Give
	// both the function declaration and the function definition for the template.
	cout << absolute(-1.0);
	cout << absolute('d');
	cout << absolute(-4);

	// 3. Define or characterize the template facility for C++.


	// // It allows you to quickly define an overloaded function to work with any type
	// what kind of variable is the parameter T ?
	// a. T must be a class.
	// b. T must not be a class.
	// c. T can be only types built into the C++ language.
	// d. T can be any type, whether built into C++ or defined by the programmer.

	// D

	// SELF TEST

	print("\nA good template writing strategy is create a version without using templates");
	print("Once you created one, replace the needed parameter types with the template types");
	// Dealing with primitives is easier to visualize than templates

	print("\nYou also need to make sure to only use types that work with the template when calling it");
	print("For example, if the template function uses an assignment operator, "
		"all classes you use as a paramter for it must work with the assignment operator");
	// Good idea to write a comment for teplate specifying the requirements for the parameter types
	// ex: variable must work with assignment operator and be comparable to zero

	// SELF TEST START
	
	// 6. In Practice Program 8 of Chapter 4 you were asked to overload the abs
	// function so that the name abs would work with several of the built-in
	// types that had been studied at the time. Compare and contrast function
	// overloading of the abs function with the use of templates for this purpose
	// in Self-Test Exercise 2.

	// Overloading only requires you to specify each type that is allowed
	// EX: int, float, double
	// Templates allow you to write the function once and let it work with any type
	// It takes less code, but doesn't prevent the user from entering types that wont work
	// ex (char/string)

	// SELF TEST END

	print("\n Modified the print function to be a template clas", 's');

	return 0;
}

void swapValues(int& v1, int& v2)
{ //WB-1.21
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}
void swapValues(char& v1, char& v2)
{  // WB-2.2
	char temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

template<class VariableType>
void newSwapValues(VariableType v1, VariableType v2)
{  // WB-1.22
	VariableType temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}