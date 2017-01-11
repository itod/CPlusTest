//
//  main.cpp
//  CPlusTest
//
//  Created by Todd Ditchendorf on 5/30/16.
//  Copyright © 2016 Celestial Teapot. All rights reserved.
//

#include <iostream>
#include <string>
//#include <memory>
using std::shared_ptr;

class TextBlock;

typedef std::shared_ptr<TextBlock> TextBlockPtr;

class TextBlock {
private:
    std::string _text;

protected:
    explicit TextBlock(const std::string& str)
    : _text(str)
    {}

public:
    static TextBlockPtr create(const std::string& str) {
        return std::shared_ptr<TextBlock>(new TextBlock(str));
    }
    ~TextBlock() {
        std::cout << _text << "\n";
    }
    const std::string& text() { return _text; }
    
    char operator[](int idx) {
        char c = _text[idx];
        char *p = &c;
        std::cout << &p << "\n";
        return c;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    TextBlock tb1("dude");
//    TextBlock tb2(std::string("dude"));
    
//    char c1 = tb1[1];
//    char *p1 = &c1;
//    std::cout << c1 << "\n";
//    
//    char c2 = tb2[1];
//    char *p2 = &c2;
//    std::cout << c2 << "\n";
    
//    const char *zstr = "OHAI";
//    TextBlockPtr ptb1(new TextBlock(zstr));
//
//    const std::string str("OHAI");
//    TextBlockPtr ptb2(new TextBlock(str));
    
    const char *zstr = "OHAI";
    TextBlockPtr tb1(TextBlock::create(zstr));
    
    const std::string str("dude");
    TextBlockPtr tb2(TextBlock::create(str));
    
    std::cout << tb1->text() << "\n";
    std::cout << tb2->text() << "\n";
    
    
    return 0;
}
