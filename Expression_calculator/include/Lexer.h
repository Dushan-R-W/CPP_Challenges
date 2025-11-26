#pragma once
#include "Token.h"
#include <vector>
#include <string>

class Lexer {
private:
	char peek() const;
	char advance();
	void skipWhiteSpace();
	Token number();

	std::string input;
	size_t index;


public:
	Lexer(const std::string& input);
	std::vector<Token> tokenise();
};
