#include <iostream>



using namespace std; 

class LivingThing
{
	public: 
		int i;
};

class Animal: public LivingThing
{
	public: 
	void Move() {
		cout<< "The animal moved!" <<endl;
	}
};

class Insect: public Animal 
{
	public: 
		int legs; 
		int eyes;
		
};


int main()
{
	Insect gucci; 
	gucci.legs = 6; 
	gucci.eyes = 6;
	gucci.Move(); 
	

}; 




