#ifndef CLASSIC2_H_
#define CLASSIC2_H_

#include "cd2.h"

class Classic : public Cd {
    private:
        char * primary_work;

    public:
        Classic(const char * pw, const char * s1, const char * s2,
                int n, double x);
        Classic(const Classic & c);
        Classic();
        virtual ~Classic();
        virtual void Report() const; // reports all CD data
        Classic & operator=(const Classic & c);
};

#endif
