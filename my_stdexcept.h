#ifndef LAB2_MY_STDEXCEPT_H
#define LAB2_MY_STDEXCEPT_H

#include <exception>
#include <string>

class ParentForErrors: public std::exception {
private:
    std::string message;

protected:
    explicit ParentForErrors(const char *msg): message(msg) {}

public:
    const char* what() const noexcept override {
        return message.c_str();
    }
};
//правило ягни - вам никогда не понадобиться))

class InvalidArgument : public ParentForErrors {
public:
    explicit InvalidArgument(const char* NameOfArgument) :
    ParentForErrors((std::string("неправильный аргумент:") + NameOfArgument).c_str()) {}

class OutOfRange : public ParentForErrors {
public:
    OutOfRange(const char* name, int value, int min, int max)
        : ParentForErrors(
            (std::string("значение ") + name + " = " + std::to_string(value) +
             " вне диапазона [" + std::to_string(min) + ", " + std::to_string(max) + "]").c_str()) {}
};




#endif //LAB2_MY_STDEXCEPT_H