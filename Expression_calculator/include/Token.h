#pragma once
#include <string>


enum class TokenType {
	Number,
	Plus,
	Minus,
	Star,
	Slash,
	Paran_open,
	Paran_close,
	EndofFile,
	Unknown

};

struct Token {
	TokenType type;
	std::string value;
};
