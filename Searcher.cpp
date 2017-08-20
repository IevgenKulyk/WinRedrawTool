#include "Searcher.h"
#include <windows.h>

Searcher::Searcher(Manager& manager):manager(manager),isFinished(false)
{
}

bool Searcher::FindTopLevelWindows()
{
    bool result = EnumWindows(
        reinterpret_cast<WNDENUMPROC>(Searcher::WindowTopWorker),
        reinterpret_cast<LPARAM>(this)
    );
    
    isFinished.store(true,std::memory_order_seq_cst);
    return result;
}

void Searcher::SendToManager(HWND hwnd)
{
    manager.push_pack(hwnd);
}

bool Searcher::IsSearchFinished() const
{
    return isFinished.load(std::memory_order_seq_cst);
}

bool Searcher::WindowTopWorker(HWND hwnd,LPARAM lParam)
{
    Searcher* searcher = reinterpret_cast<Searcher*>(lParam);
    if (searcher)
    {        
        searcher->SendToManager(hwnd);
        return true;
    }
    return false;
}