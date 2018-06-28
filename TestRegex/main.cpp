//
//  main.cpp
//  TestRegex
//
//  Created by Marco Nie on 2018/6/28.
//  Copyright © 2018 Marco Nie. All rights reserved.
//

#include <iostream>
#include "boost/regex.hpp"
#include "string"

using namespace std;


void findAndReplaceInString(string in, char* find, char* replace)
{
    boost::regex e;
    e.assign(find);
    std::ostringstream t(std::ios::out | std::ios::binary);
    std::ostream_iterator<char, char> oi(t);
    boost::regex_replace(oi, in.begin(), in.end(),
                         e, replace, boost::match_default | boost::format_all);
    cout << t.str() <<endl;
}

int main(int argc, const char * argv[]) {
    
    string in = "abc.de..def....def...";
    char* find =
    "(abc.*(?!.*(def)).*def)"
    ;
    char* replace =
    "(;)"
    ;
    
    findAndReplaceInString(in, find, replace);
    
    return 0;
}
