#include "Developer.h"
#include <algorithm>

Developer::Developer(DWORD Pid,uint32_t ContractorsNumber)
{
    searcher.reset(new Searcher(manager));
    ThreadPool.resize(ContractorsNumber);
    for (uint32_t i = 0;i < ContractorsNumber;i++)
    {
        Contractor currentContractor(manager,*searcher.get());        
        ThreadPool[i] = std::thread {currentContractor,Pid};
    }
}

void Developer::Update()
{
    searcher->FindTopLevelWindows();
    std::for_each(ThreadPool.begin(),ThreadPool.end(),[](std::thread& thr)
    {
       thr.join(); 
    });
}


