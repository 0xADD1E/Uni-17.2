#ifndef PFASTRING_HPP
#define PFASTRING_HPP

#include <string>

class PFAString {
public:
    PFAString();
    PFAString(const int);
    PFAString(const int, const std::string);
    PFAString(const PFAString&);
    ~PFAString();

    int get_capacity();
    int get_size();
    void push_back(std::string);                    // Places a string at the back of the array
    void pop_back();                                // Destroys the string at the back of the array
    void resize(int);                               // Grows or shrinks array accordingly
    void resize(int, std::string);                  // Grows or shrinks array accordingly
    void empty_array();                             // Sets the size to zero

    std::string& operator[](const int) const;       // Needs to work as l-value
    PFAString operator=(const PFAString);           // MUST work as l-value

    bool operator==(const PFAString) const;
    bool operator<(const PFAString) const;
    bool operator>(const PFAString) const;
    bool operator<=(const PFAString) const;
    bool operator>=(const PFAString) const;
private:
    std::string *arr;
    int capacity;                                   // Capacity and size are two different things
    int size;
};
#endif
