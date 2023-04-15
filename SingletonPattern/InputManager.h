#include <iostream>
#include "Singleton.h"

class InputManager : NoCopyOrAssignment {

	//-- Necessary as our InputManager has private constructor
	friend class Singleton<InputManager>;

public:
	bool Initialize() { std::cout << "Input Manager : Initializing...\n"; return true; }
	void SomeInputStuff() { std::cout << "Input Manager : Some input event...\n"; }
	void Shutdown() { std::cout << "Input Manager : Shutting down...\n"; }
	~InputManager() { std::cout << "Input Manager : Destructor called\n"; }

private:
	InputManager() { std::cout << "Input Manager : Constructor called\n"; }
};

typedef Singleton<InputManager> Input;