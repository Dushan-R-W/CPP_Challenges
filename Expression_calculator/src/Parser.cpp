#include "Lexer.h"
#include "Parser.h"


Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), index(0) {}

Token Parser::peek() const {
	return tokens[index];
}

Token Parser::advance() {
	return tokens[index++];
}
                                

double Parser::third() {
	Token t = peek();                    

	if (t.type == TokenType::Number) {
		advance();
		return std::stod(t.value);
	}

	if (t.type == TokenType::Paran_open) {
		advance();                          
		double result = first();
		advance();
		return result;
	}
}

double Parser::second() {
	double left = third();                 

	while (peek().type == TokenType::Star || peek().type == TokenType::Slash) {
		Token Current_operator = advance();
		double right = third();            

		if (Current_operator.type == TokenType::Star) {
			left = left * right;
		}
		if (Current_operator.type == TokenType::Slash) {
			left = left / right;
		}
	}

	return left;
}

double Parser::first() {
	double left = second();                  

	while (peek().type == TokenType::Plus || peek().type == TokenType::Minus) {
		Token Current_operator = advance();    
		double right = second();       

		if (Current_operator.type == TokenType::Plus) {
			left = left + right;

		}else if (Current_operator.type == TokenType::Minus) {
			left = left - right;
		}
	}

	return left;
}

int Parser::parse() {

	return first();
}
