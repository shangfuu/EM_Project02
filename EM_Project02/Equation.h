#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Equation {
public:	
	std::vector<std::string> postfix(std::string);
	int priority(char);
};
