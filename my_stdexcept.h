#ifndef LAB2_MY_STDEXCEPT_H
#define LAB2_MY_STDEXCEPT_H

#include <exception>
#include <string>

//класс logic_error -
class LogicError : public std::exception {
protected:
    std::string message;
public:
    explicit LogicError(const std::string &msg) : message(msg) {}
    explicit LogicError(const char *msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

//Производные от logic_error -
class DomainError : public LogicError {
public:
    explicit DomainError(const std::string& msg) : LogicError(msg) {}
    explicit DomainError(const char* msg) : LogicError(msg) {}
};

class InvalidArgument : public LogicError {
public:
    explicit InvalidArgument(const std::string& msg) : LogicError(msg) {}
    explicit InvalidArgument(const char* msg) : LogicError(msg) {}
};

class LengthError : public LogicError {
public:
    explicit LengthError(const std::string& msg) : LogicError(msg) {}
    explicit LengthError(const char* msg) : LogicError(msg) {}
};

class OutOfRange : public LogicError {
public:
    explicit OutOfRange(const std::string& msg) : LogicError(msg) {}
    explicit OutOfRange(const char* msg) : LogicError(msg) {}
};

//класс runtime_error -
class RuntimeError : public std::exception {
protected:
    std::string message;
public:
    explicit RuntimeError(const std::string& msg) : message(msg) {}
    explicit RuntimeError(const char* msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

//Производные от runtime_error ---
class RangeError : public RuntimeError {
public:
    explicit RangeError(const std::string& msg) : RuntimeError(msg) {}
    explicit RangeError(const char* msg) : RuntimeError(msg) {}
};

class OverflowError : public RuntimeError {
public:
    explicit OverflowError(const std::string& msg) : RuntimeError(msg) {}
    explicit OverflowError(const char* msg) : RuntimeError(msg) {}
};

class UnderflowError : public RuntimeError {
public:
    explicit UnderflowError(const std::string& msg) : RuntimeError(msg) {}
    explicit UnderflowError(const char* msg) : RuntimeError(msg) {}
};



#endif //LAB2_MY_STDEXCEPT_H