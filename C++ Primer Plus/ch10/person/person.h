// person.h
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person {
    private:
        static const int LIMIT = 25;
        std::string lname;  // Person's last name
        char fname[LIMIT];  // Person's first name
    public:
        Person() { lname = ""; fname[0] = '\0'; }
        Person(const std::string & ln, const char * fn = "Heyyou");
        // the following methods display lname and fname
        void Show() const;      // firstname lastname format
        void FormalShow() const;  // lastname, firstname format
};

#endif
