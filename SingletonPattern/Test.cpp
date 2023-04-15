#include "Test.h"

void SomeNamespace::SomeFunction()
{
	std::cout << "Called from Test.h : SomeNamespace::SomeFunction [ memory address: ] " << &Input::Get() << std::endl;

	Input::Get().SomeInputStuff();
}