#include "Contractor.h"

#include <windows.h>

Contractor::Contractor(Manager& manager,const Searcher& searcher):
    manager(manager),searcher(searcher)
{
}

DWORD Contractor::GetPidByHWND(HWND hwnd) const
{
    DWORD pid = 0;
    if (IsWindow(hwnd))
    {
        GetWindowThreadProcessId(hwnd,&pid);
    }
    return pid;
}

bool Contractor::ParseChildren(HWND hwnd, LPARAM lParam)
{    
    SendMessageA(hwnd,WM_PAINT,0,0);
    return EnumChildWindows(hwnd,
            reinterpret_cast<WNDENUMPROC>(ParseChildren),
            reinterpret_cast<LPARAM>(nullptr));  
}

void Contractor::operator()(DWORD pid)
{
    do
    {
        try
        {
            while (true)
            {
                HWND currentWindow = manager.pop_front();
                DWORD windowPid = GetPidByHWND(currentWindow);
                if (windowPid == pid)
                {                    
                    SendMessageA(currentWindow,WM_PAINT,0,0);
                    EnumChildWindows(currentWindow,
                            reinterpret_cast<WNDENUMPROC>(ParseChildren),
                            reinterpret_cast<LPARAM>(nullptr));                
                }
            }
        }
        catch(const std::logic_error&){ }
    }while (searcher.IsSearchFinished() == false);    
}
