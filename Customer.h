#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <windows.h>

class Customer {
public:
    Customer(LPSTR className,LPSTR windowName);
    DWORD GetPid();
    uint32_t GetNumberOfContractors();
    Customer() = delete;
private:
    DWORD pid;
};

#endif /* CUSTOMER_H */

