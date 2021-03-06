#ifndef PCALC_SP_H
#define PCALC_SP_H

#include <cmath>
#include "PCalc.h"

// Add your PCalc_SP class definition here as a child class of PCalc
// Be sure to overload the right methods from PCalc or it won't compile

class PCalc_SP : public PCalc{

public:
    PCalc_SP(unsigned int count_to);
    ~PCalc_SP();

    void markNonPrimes();

protected:

private:


};

// This class should manage the single process implementation of the prime number generator. I'd recommend
// getting this working first, then tackling multithreaded

#endif
