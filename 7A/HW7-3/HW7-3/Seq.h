#include <iostream>
#include "Box.h"

class Seq
{
public:
    Seq(int length);
    Seq(const Seq& other);
    Seq& operator=(const Seq& other);
    ~Seq();
    
    int get(int i) const { return 0 <= i && i < len ? boxes[i].value() : 0; }
    void set(int i, int v) { if (0 <= i && i < len) boxes[i].value(v); }
    void show() const {
        for (int i = 0; i < len; i++) std::cout << (i == 0 ? "[" : ", ")
            << boxes[i].value();
        std::cout << "] " << Box::objects() << " boxes" << std::endl; }
private:
    Box* boxes;
    int len;
};

