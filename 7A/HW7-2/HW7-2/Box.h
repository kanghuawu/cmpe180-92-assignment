#ifndef BOX_H
#define BOX_H

class Box
{
public:
    Box();
    Box(int v);
    Box(const Box& other);
    ~Box();
    Box& operator=(const Box& other);
    int value() const;
    void inc();
    static int objects();
private:
    int _value;
    static int _objects;
};

#endif

