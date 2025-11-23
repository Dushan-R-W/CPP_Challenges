
#include <iostream>
#include "Lexer.h"
#include "Parser.h"



int main() {
	std::string input = "12 + 34 * (5 - 2) + (8 * 5 - 10)";
	Lexer lexer(input);
	std::vector<Token> tokens = lexer.tokenise();

	for (const auto& t : tokens) {
		std::cout << "Token(" << (int)t.type << ", \"" << t.value << "\")\n";
	}

	Parser t(tokens);
	int answer = t.parse();
	std::cout << "Answer: " << answer << std::endl;
}