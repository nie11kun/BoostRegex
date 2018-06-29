// BoostRegex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "boost/regex.hpp"
#include "string"
#include "sstream"

using namespace std;


void findAndReplaceInString(string in, char* find, char* replace)
{
	boost::regex e;
	e.assign(find);
	std::ostringstream t(std::ios::out | std::ios::binary);
	std::ostream_iterator<char, char> oi(t);
	boost::regex_replace(oi, in.begin(), in.end(),
		e, replace, boost::match_default | boost::format_all);
	cout << t.str() << endl;
}

int main(int argc, const char * argv[]) {

	string in = "abc.def..ab....abc...def..";

	char* find = (char*)
		"((abc).*?(def))|"
		"((ab)\\b)"
		;
	char* replace = (char*)
		"(;)"
		;

	findAndReplaceInString(in, find, replace);

	cin.clear();
	cin.get();

	return 0;
}


