#ifndef MANAGER_H
#define MANAGER_H

#include <queue>
#include <mutex>
#include <windows.h>

class Manager {
public:
    Manager() = default;
    void push_pack(HWND window);
    HWND pop_front();
private:
    std::mutex lock;
    std::queue<HWND> windowsTop;
};

#endif /* MANAGER_H */

