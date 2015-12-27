#include "float.h"

using namespace std;

enum {start, sign, beforeComa, point, afterComa, degree, degreeSign, order};

bool isDigit(char symbol) {
	return (symbol >= '0' && symbol <= '9');
}

bool isFloat(FILE *input) {
	bool result = true;
	int state = start;
	char symbol = getc(input);
	while (result) {
		switch (state) {
			case start:
				if (!isDigit(symbol) && symbol != '+' && symbol != '-')
					return false;
				state = beforeComa;
				if (symbol == '+' || symbol == '-')
					state = sign;
			break;
			case sign:
				if (!isDigit(symbol))
					return false;
				state = beforeComa;
			break;
			case beforeComa:
				if (symbol != 'E' && symbol != 'e' && symbol != ',' && symbol != '.' && !isDigit(symbol))
					return false;
				if (symbol == ',' || symbol == '.')
					state = point;
				if (symbol == 'E' || symbol == 'e')
					state = degree;
			break;
			case point:
				if (!isDigit(symbol))
					return false;
				state = afterComa;
			case afterComa:
				if (symbol != 'E' && symbol != 'e' && !isDigit(symbol))
					return false;
				if (symbol == 'E' || symbol == 'e')
					state = degree;	
			break;
			case degree:
				if (symbol != '+' && symbol != '-' && !isDigit(symbol))
					return false;
				state = order;
				if (symbol == '+' || symbol == '-')
					state = degreeSign;
			break;
			case degreeSign:
				if (isDigit(symbol))
					state = order;
			break;
			case order:
				if (!isDigit(symbol))
					return false;
			break;
		}
		symbol = getc(input);
	}
	ungetc(symbol, input);
	return (state == beforeComa || state == afterComa || state == order);
}
