#ifndef CONTRACTOR_H
#define CONTRACTOR_H

#include "Manager.h"
#include "Searcher.h"

class Contractor {
public:
    Contractor(Manager& manager,const Searcher& searcher);
    void operator()(DWORD pid);
    Contractor() = delete;
private:
    Manager& manager;
    const Searcher& searcher;
    DWORD GetPidByHWND(HWND hwnd) const;
    static bool ParseChildren(HWND hwnd,LPARAM lParam);

};

#endif /* CONTRACTOR_H */

