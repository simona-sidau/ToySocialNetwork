#ifndef MAIN_CPP_SERVICEEXCEPTION_H
#define MAIN_CPP_SERVICEEXCEPTION_H

#include <string>

class ServiceException {
private:
    std::string err;
public:
    ServiceException(const std::string &msg) : err{msg} {};

    std::string &get_msg() { return this->err; };

    friend std::ostream &operator<<(std::ostream &out, ServiceException &err){
        out << err.get_msg();
        return out;
    }
};




#endif //MAIN_CPP_SERVICEEXCEPTION_H
