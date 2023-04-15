#pragma once
#include "InputManager.h"

namespace SomeNamespace {

	void SomeFunction();

	static void StaticFunction() {
		std::cout << "Called from Test.cpp : SomeNamespace::StaticFunction [ memory address: ] " << &Input::Get() << std::endl;

		Input::Get().SomeInputStuff();
	}

	inline void InlineFunction() {

		std::cout << "Called from Test.h : SomeNamespace::InlineFunction [ memory address: ] " << &Input::Get() << std::endl;

		Input::Get().SomeInputStuff();
	}
}