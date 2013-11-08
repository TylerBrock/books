// exc_mean3.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>

class mean_error : public std::logic_error
{
    protected:
        double a;
        double b;
    public:
        mean_error(const char * m = "mean error", double arg1 = 0, double arg2 = 0)
            : std::logic_error(m), a(arg1), b(arg2) {}
        virtual void mesg() const = 0;
};

class bad_hmean : public mean_error
{
    public:
        bad_hmean(double arg1, double arg2)
            : mean_error("hmean error", arg1, arg2) {}
        void mesg() const;
};

inline void bad_hmean::mesg() const
{
    std::cout << what() << std::endl;
    std::cout << "invalid arguments: a = -b\n"
              << "values were: " << a << ", " << b << std::endl;
}

class bad_gmean : public mean_error
{
    public:
        bad_gmean(double arg1, double arg2)
            : mean_error("gmean error", arg1, arg2) {}
        void mesg() const;
};

inline void bad_gmean::mesg() const
{
    std::cout << what() << std::endl;
    std::cout << "arguments should be >= 0\n"
              << "values were: " << a << ", " << b << std::endl;
}
