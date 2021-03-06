#ifndef PCALC_T_H
#define PCALC_T_H

#include <atomic>
#include <cmath>
#include <mutex>
#include <thread>
#include "PCalc.h"

// Your implementation of PCalc_T class should go here. 
// Make sure your constructor takes in two parameters:

// PCalc_T::PCalc_T(unsigned int array_size, unsigned int num_threads);

class PCalc_T : public PCalc{

public:
    PCalc_T(unsigned int array_size, unsigned int num_threads);
    ~PCalc_T();

    void markNonPrimes();
    void tMark( unsigned int end, unsigned int stop );

protected:

private:
    
    unsigned int nThreads = 0;
    unsigned int start = 2;
    std::mutex numLock;

};
// Call the parent constructor when initializing your constructor and pass in array_size. Then
// use num_threads to cap off how many threads you use to calculate all prime numbers

#endif
