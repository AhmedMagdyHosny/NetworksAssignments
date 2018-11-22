#include <iostream>
#include <string>

using namespace std;



string CRC(string message, string generator, string & remain) {
	int  glength = generator.length();
	int mlength = message.length() + glength - 1;
	int Donebits = glength;
	string message1, result, y;
	message1 = message;
	for (int i = 1; i < glength; i++) {
		message1 += "0";
	}
	string x = message1.substr(0, glength);

	while (Donebits <= mlength) {
		if (isFirstBitOne(x)) {
			x = XOR(x, generator);
			result += "1";
		}
		else {
			result += "0";
		}
		y = x.substr(1, glength - 1) + message1[Donebits];
		x = y;
		Donebits++;
	}
	remain = x;

	return message + remain;
}
