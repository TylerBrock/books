// worker0.h -- working classes
#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker // an abstract base calss
{
    private:
        std::string fullname;
        long id;

    public:
        Worker() : fullname("no one"), id(0L) {}
        Worker(const std::string & s, long n)
            : fullname(s), id(n) {}
        virtual ~Worker() = 0;  // pure virtual destructor
        virtual void Set();
        virtual void Show() const;
};

class Waiter : public Worker
{

    private:
        int pananche;

    public:
        Waiter(): Worker(), pananche(0) {}
        Waiter(const std::string & s, long n, int p = 0)
            : Worker(s, n), pananche(p) {}
        Waiter(const Worker & wk, int p = 0)
            : Worker(wk), pananche(p) {}
        void Set();
        void Show() const;
};

class Singer : public Worker
{
    protected:
        enum {other, alto, contralto, soprano, bass, baritone, tenor};
        enum {Vtypes = 7};

    private:
        static const char *pv[Vtypes];    // string equivs of voice types
        int voice;

    public:
        Singer() : Worker(), voice(other) {}
        Singer(const std::string & s, long n, int v = other)
            : Worker(s, n), voice(v) {}
        void Set();
        void Show() const;
};

#endif
