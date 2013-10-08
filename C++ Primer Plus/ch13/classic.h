#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd {
    private:
        char primary_work[50];

    public:
        Classic(const char * pw, const char * s1, const char * s2,
                int n, double x);
        Classic();
        virtual ~Classic() {};
        virtual void Report() const; // reports all CD data
};

#endif
