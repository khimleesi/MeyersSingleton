//-- Example templated Singleton design pattern using popular Meyer's method
//-- Created by Kim Kane www.khimleesi.com

//-- The Singleton class is not to be instantiated directly, it is a skeleton for Implementer classes only
//-- Thread safe providing C++11 onwards, using lazy initialization, static Implementer& instance variable initialized upon first function call
//-- Not inherited as we don't want derived classes to be able to create instances of their own
//-- We make a Implementer class a friend of Singleton e.g. friend class Singleton<InputManager> where InputManager is the Implementer

#include "Test.h"

class Player {

public:
	Player() {}
	~Player() {}

	void Update() { std::cout << "Called from main.cpp : class Player function Update [ memory address: ] " << &Input::Get() << std::endl; }
};

int main() {

	//-- Don't do this!! The instance Intialize() should always run at the top-most level of your program, prior to any other classes/functions
	//-- who call the Input::Get() instance - like our sample Player class above, for example
	//Player player;

	//-- Call Initialize as soon as needed (usually when program starts), prior to using the Input::Get() instance anywhere else
	//-- This function gives you a chance to take care of any setup needed 
	//-- In terms of an Input class, this setup could involve mapping the buttons, maybe you read the values in from a file, etc.
	if (!Input::Get().Initialize()) { std::cout << "Input Failed to Initialize..." << std::endl; }
	
	//-- No direct access to Singleton class, we do not create Singleton objects directly

	//-- No direct creation of Implementer allowed
	//InputManager input;
	
	//-- No assignment of Implementer allowed
	//InputManager* ptr = &Input::Get();
	//*ptr = input;

	//-- No copying of Implementer allowed
	//auto second(Input::Get());

	std::cout << "Called from main.cpp : main [ memory address: ] " << &Input::Get() << std::endl;
	
	Player player;
	player.Update();

	SomeNamespace::SomeFunction();
	SomeNamespace::StaticFunction();
	SomeNamespace::InlineFunction();

	//-- Clean up after yourself ;)
	Input::Get().Shutdown();
	
	system("Pause");

	return 0;
} //-- Singleton instance will be destroyed upon program shutdown