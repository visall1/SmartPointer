#include<iostream>
#include<memory>
class Temp
{
	int TEMP;
public:
	//Constructor
	Temp() { TEMP = 25; }
	//Function display on the screen
	void TempFunction();
	//Function set Value setting
	void TempSet(int T);
	~Temp();

private:

};
class SmartPointer {
	//pointer to class temp
	Temp* ptr;
	int count_copies;
public:
	//constructor
	SmartPointer(Temp*p=NULL):ptr(p),count_copies(0){}
	//copy constructor
	SmartPointer(const SmartPointer& copy) {
		ptr = copy.ptr;
		count_copies++;
	}
	SmartPointer operator=(const SmartPointer& other) {
		ptr = other.ptr;
		count_copies++;
		return *this;
	}
	~SmartPointer() {
		if (ptr != NULL && count_copies == 0) {
			std::cout << "Delete Object" << std::endl;
			delete ptr;
		}
		else {
			std::cout << " Delete Copy." << std:: endl;
			count_copies--;

		}
	}
	operator Temp* () {
		return ptr;
	}
	Temp* operator->() {
		return ptr;
	}

};
void Temp::TempFunction()
{
	std::cout << "Temp : " << TEMP << std::endl;
}

void Temp::TempSet(int T)
{
	TEMP = T;
}

Temp::~Temp()
{
}
int main() {
	/*Temp* tmp1 = new Temp;
	tmp1->TempFunction();

	Temp* tmp2 = tmp1;

	delete tmp1;
	tmp2->TempFunction(); 
	delete tmp2;*/
	//SmartPointer tmp1(new Temp);
 //   tmp1->TempFunction();
 //   SmartPointer tmp2 = tmp1;// Copy Constructor
 //   tmp2 = tmp1;//assignment operator
 //   tmp2->TempFunction();


	std::unique_ptr<Temp> tmp1(new Temp);
	tmp1->TempFunction();
	std::unique_ptr<Temp> tmp2 = std::move(tmp1);
	tmp2->TempSet(4);
	tmp2->TempFunction();

	return 0;
}