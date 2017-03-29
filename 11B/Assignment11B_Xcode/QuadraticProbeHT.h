#ifndef QUADRATICPROBEHT_H_
#define QUADRATICPROBEHT_H_

#include "OpenAddressHT.h"
using namespace std;

/**
 * Class for open addressing hash tables
 * that use quadratic probing.
 */
class QuadraticProbeHT: public OpenAddressHT
{
public:
    QuadraticProbeHT();
    QuadraticProbeHT(int size);
    virtual ~QuadraticProbeHT();
    
    virtual int search(const string& word, int& probe_count);
    
protected:
    virtual int next_index(int index);
    
private:
    int odd;
};

#endif /* QUADRATICPROBEHT_H_ */
