#pragma once
#include "Token.h"
#include <vector>

class Parser{
private:

	double first();
	double second();
	double third();
	Token peek() const;
	Token advance();
	std::vector<Token> tokens;
	int index;

		

public:
	Parser(const std::vector<Token> &tokens);
	int parse();

};







