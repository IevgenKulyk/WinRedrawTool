#ifndef SEARCHER_H
#define SEARCHER_H

#include "Manager.h"
#include <atomic>

class Searcher {
public:
    Searcher(Manager& manager);
    bool FindTopLevelWindows();
    void SendToManager(HWND hwnd);
    bool IsSearchFinished() const;
private:
    Manager& manager;
    std::atomic<bool> isFinished;
    static bool WindowTopWorker(HWND hwnd,LPARAM lParam);
};

#endif /* SEARCHER_H */

