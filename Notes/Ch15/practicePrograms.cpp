#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>

#include "../courseNamespace.h"

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::rand;

// Practice program 1
namespace practice1
{

	int generateRegistration();
	// Pre: Requries nothing
	// Returns a random number using rand between 10000 and 99999

	class FreightContainer
	{
	public:
		FreightContainer();
		FreightContainer(string name);
		FreightContainer(string name, int registration);

		int getRegistration(){return registrationNumber;};
		void setRegistration(int number){registrationNumber = registrationNumber;};

		string getName(){return itemName;};
		void setName(string name){itemName = name;}
	private: 
		int registrationNumber;
		string itemName;
	};
	class TransportVehicle
	{
	public:
		TransportVehicle();
		TransportVehicle(int age, int capacity);
		TransportVehicle(int registration, int age, int capacity);

		int getRegistration(){return registrationNumber;};
		void setRegistration(int number){registrationNumber = number;};

		int getAge(){return age;};
		void setAge(int number){age = number;};

		int getMaxCapacity(){return maxCapacity;};
		void setMaxCapacity(int capacity){maxCapacity = capacity;};
		int getCurrentCapacity(){return currentCapacity;};
		// void setCurrentCapacity(int capacity){currentCapacity = capacity;};
		float getCapacityPercent();

		bool addFreight(FreightContainer &item);
		vector<FreightContainer*>* getFreightVector(){return &freight;};

		virtual void printVehicle();

	private:
		int registrationNumber;
		int age;
		int maxCapacity;
		int currentCapacity = 0;
		vector<FreightContainer*> freight;
	};

	class Truck : public TransportVehicle
	{
	public:
		Truck();
		Truck(int age, int capacity, int miles);
		Truck(int registration, int age, int capacity, int miles);

		int getMiles(){return milesTravelled;};
		void setMiles(int miles){milesTravelled = miles;};

		virtual void printVehicle();

	private: 
		int milesTravelled;
	};

	class Plane : public TransportVehicle
	{
	public:
		Plane();
		Plane(int age, int capacity, int hours);
		Plane(int registration, int age, int capacity, int hours);

		int getHours(){return hoursTravelled;};
		void setHours(int hours){hoursTravelled = hours;};

		virtual void printVehicle();

	private: 
		int hoursTravelled;
	};

	class Driver
	{
	public:
		Driver();

		void printVehicles();

		void addVehicle(TransportVehicle &vehicle);
	private:
		vector<TransportVehicle*> vehicles;
	};
}

using namespace courseNamespace;

int main()
{

	srand(time(NULL));

	{
		using namespace practice1;

		Driver hunter;

		TransportVehicle car(12345, 5, 4);
		TransportVehicle scooter;
		TransportVehicle bus(12, 36);
		Plane boeing;
		Plane fighterJet(3245, 2, 50, 100);

		FreightContainer food;
		FreightContainer ammo("Ammo");
		FreightContainer guns("Guns", 54321);
		FreightContainer supplies("Supplies");
		FreightContainer parts("Parts");

		car.addFreight(food);
		car.addFreight(ammo);
		car.addFreight(guns);
		car.addFreight(supplies);
		car.addFreight(parts);

		bus.addFreight(food);
		bus.addFreight(ammo);
		bus.addFreight(guns);
		bus.addFreight(supplies);
		bus.addFreight(parts);

		fighterJet.addFreight(supplies);

		car.printVehicle();
		cout << endl;
		scooter.printVehicle();
		cout << endl;
		bus.printVehicle();
		cout << endl << endl;

		hunter.addVehicle(car);
		hunter.addVehicle(scooter);
		hunter.addVehicle(boeing);
		hunter.addVehicle(fighterJet);
		hunter.addVehicle(bus);

		hunter.printVehicles();
	}
}

namespace practice1
{
	int generateRegistration()
	{
		return rand() % 99999 + 10000;
	}


	FreightContainer::FreightContainer() : itemName("Unknown"),
	registrationNumber(generateRegistration())
	{
		
	}

	FreightContainer::FreightContainer(string name) : itemName(name), 
	registrationNumber(generateRegistration())
	{

	}
	FreightContainer::FreightContainer(string name, int registration) : itemName(name), 
	registrationNumber(registration)
	{

	}

	TransportVehicle::TransportVehicle() : age(0), maxCapacity(0), 
	registrationNumber(generateRegistration())
	{
		
	}
	TransportVehicle::TransportVehicle(int age, int capacity) : age(age), maxCapacity(capacity), 
	registrationNumber(generateRegistration())
	{
	}
	TransportVehicle::TransportVehicle(int registration, int age, int capacity) : age(age), 
	maxCapacity(capacity), registrationNumber(registration)
	{
		
	}

	bool TransportVehicle::addFreight(FreightContainer &item)
	{
		if(currentCapacity >= maxCapacity)
		{
			cout << "\nMax capacity already reached, discarding freigt\n";
			return false;
		}

		FreightContainer *newFreight = new FreightContainer; 
		newFreight = &item; 

		freight.push_back(newFreight);
		++currentCapacity;
		return true;
	}	

	void Driver::addVehicle(TransportVehicle &vehicle)
	{
		TransportVehicle *newVehicle = new TransportVehicle; 
		newVehicle = &vehicle; 
		vehicles.push_back(newVehicle);
	}

	Truck::Truck() : milesTravelled(0), TransportVehicle()
	{

	}
	Truck::Truck(int age, int capacity, int miles) : milesTravelled(miles), 
	TransportVehicle(age, capacity)
	{

	}
	Truck::Truck(int registration, int age, int capacity, int miles) : milesTravelled(miles), 
	TransportVehicle(registration, age, capacity)
	{

	}

	Plane::Plane() : hoursTravelled(0), TransportVehicle()
	{

	}
	Plane::Plane(int age, int capacity, int hours) : hoursTravelled(hours), 
	TransportVehicle(age, capacity)
	{

	}
	Plane::Plane(int registration, int age, int capacity, int hours) : hoursTravelled(hours), 
	TransportVehicle(registration, age, capacity)
	{

	}

	Driver::Driver()
	{

	}

	void Driver::printVehicles()
	{
		for(auto & vehicle : vehicles)
		{
			vehicle->printVehicle();
			cout << endl;
		}
	}

	void TransportVehicle::printVehicle()
	{
		cout << "Transport vehicle " << registrationNumber << " which is " << age
		 << " years old used " << getCapacityPercent() << "% capacity";
	}
	void Truck::printVehicle()
	{
		TransportVehicle::printVehicle(); 
		cout << " and has driven " << milesTravelled << " miles";
	}
	void Plane::printVehicle()
	{
		TransportVehicle::printVehicle(); 
		cout << " and has flown " << hoursTravelled << " hours";
	}

	float TransportVehicle::getCapacityPercent()
	{

		if(maxCapacity == 0)  // Prevents /0 error
		{
			return 0;
		}
		// cout << currentCapacity;
		return ((float)currentCapacity / (float)maxCapacity) * 100;
	}
}