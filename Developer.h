#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <memory>
#include <vector>
#include <thread>
#include "Manager.h"
#include "Contractor.h"
#include "Searcher.h"

class Developer {
public:
    Developer(DWORD Pid,uint32_t ContractorsNumber);
    void Update();
private:
    Manager manager;
    std::unique_ptr<Searcher> searcher;
    std::vector<std::thread> ThreadPool;
};

#endif /* DEVELOPER_H */

