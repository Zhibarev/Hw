#include "expression.h"

using namespace std;

enum {id, signExpression};

bool isSign(char symbol) {
	return (symbol == '+' || symbol == '*' || symbol == '-' || symbol == '/');
}

bool expressionRecursive(FILE *input, int state) {
	char symbol = '0';
	switch (state) {
		case id:
			if (!isFloat(input))
				return false;
			symbol = getc(input);
			return symbol == '\n' || symbol == '\r' || symbol == EOF ? true : expressionRecursive(input, signExpression);
		break;
		case signExpression:
			if (!isSign(getc(input)))
				return false;
			getc(input);
			return isExpression(input);
		break;
	}
}

bool isExpression(FILE *input) {
	return expressionRecursive(input, id);
}