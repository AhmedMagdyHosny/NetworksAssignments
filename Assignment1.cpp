#include <iostream>
#include <string>

using namespace std;



bool isFirstBitOne(string x) {
	if (x[0] == '1') {
		return 1;
	}
	else { return 0; }
}


bool isZeros(string x) {

	for (int i = 0; i < x.length(); i++) {
		if(x[i] == '1'){
			return false;
		}
	}
	return true;
}



string XOR(string x, string y) {
	string result = "";
	int j = x.length();
	for (int i = 0; i <j; i++) {
		if (x[i] == y[i]) {
			result += "0";
		}
		else {
			result += "1";
		}
	}
	return result;
}



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

string verifier(string message, string generator,string & remain) {
	int  glength = generator.length();
	int mlength = message.length() + glength - 1;
	int Donebits = glength;
	string message1, result, y;
	message1 = message+remain ;
	
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

	if (isZeros(remain)) {
		return "True";
	}
	else {
		return "Error";
	}
}
