#ifndef CD2_H_
#define CD2_H_

// base class
class Cd {
    private:
        char * performers;
        char * label;
        int selections;     // number of selections
        double playtime;    // playing time in minutes

    public:
        Cd(const char * s1, const char * s2, int n, double x);
        Cd(const Cd & d);
        Cd();
        virtual ~Cd();
        virtual void Report() const; // reports all CD data
        Cd & operator=(const Cd & d);
};

#endif
