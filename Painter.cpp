#include <iostream>
#include <windows.h>

#include "Searcher.h"
#include "Manager.h"
#include "Customer.h"
#include "Developer.h"

int main(int argc, char** argv)
{
    Customer customer((LPSTR) "Progman",(LPSTR) "Program Manager");
    std::cout << "Current PID = " << customer.GetPid() << std::endl;
    std::cout << "Current thread pool size = " << 
            customer.GetNumberOfContractors() << std::endl;
    Developer developer(customer.GetPid(),customer.GetNumberOfContractors());
    developer.Update();
    
    return 0;
}

