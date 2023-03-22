#ifndef MAIN_CPP_VALIDATOREXCEPTION_H
#define MAIN_CPP_VALIDATOREXCEPTION_H

#include<string>

class ValidatorException {
private:
    const std::string err;
public:
    const std::string &get_msg() const { return this->err; };

    ValidatorException(const std::string err) : err(err) {};

    friend std::ostream &operator<<(std::ostream &out, ValidatorException &err) {
        out << err.get_msg();
        return out;
    }
};


#endif //MAIN_CPP_VALIDATOREXCEPTION_H
