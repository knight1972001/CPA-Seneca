#include "header.h"
#include "tool.h"

Gift::Gift() {
	name = nullptr;
}
Gift::Gift(const char*p) {
	name = nullptr;
	cpyString(p, name);
}
const char* Gift::getName() {
	return name;
}
Gift::~Gift() {
	std::cout << "DELETED PTR: " << name << std::endl;

	if (name != nullptr) {
		delete[]name;
		name = nullptr;
	}
}