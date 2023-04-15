#pragma once
#include "NoCopyOrAssignment.h"

template <class Implementer>
class Singleton : private NoCopyOrAssignment {

public:
	static Implementer& Get() {

		static Implementer instance;
		return instance;
	}

private:
	Singleton()  = delete;
	~Singleton() = delete;
};