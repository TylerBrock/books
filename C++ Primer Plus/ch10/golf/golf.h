// golf.h -- for ex1.cpp
#ifndef GOLF_H_
#define GOLF_H_

const int Len = 40;

class Golf
{
    private:
        char fullname[Len];
        int handicap;

    public:
        Golf();

        // non-interactive version:
        //   function sets golf structure to provided name, handicap
        //   using values passed as arguments to the function
        Golf(const char * name, int hc);

        // interactive version:
        //   function solicits name and handicap from user
        //   and sets the members of g to the values entered
        //   returns 1 if name is entered, 0 if name is empty string
        int setgolf(Golf & g);

        // function resets handicap to new value
        void set_handicap(int hc);

        // function displays contents of golf structure
        void showgolf();
};

#endif
