#include "Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& input) : input(input), index(0) {}

char Lexer::peek() const {
	return index < input.length() ? input[index] : '\0';
}

char Lexer::advance() {
	return input[index++];
}

void Lexer::skipWhiteSpace() {
	while (std::isspace(peek())) {
		advance();
	}
}

Token Lexer::number() {
	std::string value;

	while (std::isdigit(peek())) {

		value += advance();
	}

	return { TokenType::Number, value };
}

std::vector<Token> Lexer::tokenise() {
	std::vector<Token> tokens;

	while (true) {
		skipWhiteSpace();
		char c = peek();

		if (c == '\0') {
			tokens.push_back({ TokenType::EndofFile, "" });
			break;
		}

		if (std::isdigit(c)) {
			tokens.push_back(number());
			continue;
		}

		switch (c) {
		case '+':
			tokens.push_back({ TokenType::Plus, std::string(1, c) });
			break;
		case '-':
			tokens.push_back({ TokenType::Minus, std::string(1, c) });
			break;
		case '*':
			tokens.push_back({ TokenType::Star, std::string(1, c) });
			break;
		case '/':
			tokens.push_back({ TokenType::Slash, std::string(1, c) });
			break;
		case '(':
			tokens.push_back({ TokenType::Paran_open, std::string(1, c) });
			break;
		case ')':
			tokens.push_back({ TokenType::Paran_close, std::string(1, c) });
			break;
		default: 
			tokens.push_back({ TokenType::Unknown, std::string(1, c) });
		}

		advance();
	}
	return tokens;
}






