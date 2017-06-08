#ifndef LINEARPROBEHT_H_
#define LINEARPROBEHT_H_

#include "OpenAddressHT.h"
using namespace std;

/**
 * Class for open addressing hash tables
 * that use linear probing.
 */
class LinearProbeHT: public OpenAddressHT
{
public:
    LinearProbeHT();
    LinearProbeHT(int size);
    virtual ~LinearProbeHT();
    
protected:
    virtual int next_index(int index);
};

#endif /* LINEARPROBEHT_H_ */
