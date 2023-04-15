#pragma once

class NoCopyOrAssignment {

protected:
	NoCopyOrAssignment() = default;
	~NoCopyOrAssignment() = default;
	NoCopyOrAssignment(const NoCopyOrAssignment&) = delete;
	NoCopyOrAssignment& operator=(const NoCopyOrAssignment&) = delete;
};