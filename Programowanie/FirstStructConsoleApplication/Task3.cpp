#include <iostream>

struct address
{
	std::string street;
	std::string houseNumber;
	std::string apartmentNumber;
};

struct person
{
	std::string name, surname;
	unsigned short age;
	unsigned short height;
	address homeAddress;
	address hauseAddress;
};

void taks3()
{
	person firstPerson;
	firstPerson.name = "Jan";
	firstPerson.homeAddress.street = "Majowa";
}