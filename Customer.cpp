#include <stdexcept>
#include <string>
#include <thread>
#include "Customer.h"

Customer::Customer(LPSTR className,LPSTR windowName) 
{
    HWND handle = FindWindowA(className,windowName);
    if (handle)
    {
        GetWindowThreadProcessId(handle,&this->pid);
    }
    else
    {
        throw std::logic_error("GetLastError returns "
                + std::to_string(GetLastError()));
    }
}

DWORD Customer::GetPid()
{
    return this->pid;
}

uint32_t Customer::GetNumberOfContractors()
{
    return std::thread::hardware_concurrency();
}