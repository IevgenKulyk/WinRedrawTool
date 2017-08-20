#include "Manager.h"

 void Manager::push_pack(HWND window)
 {
     std::lock_guard<std::mutex> sync(this->lock);
     this->windowsTop.push(window);
 }
 
 HWND Manager::pop_front()
 {
     std::lock_guard<std::mutex> sync(this->lock);
     
     if (this->windowsTop.empty())
     {
         throw std::logic_error("Reading empty queue is not allowed");
     }
     
     HWND result = this->windowsTop.front();
     this->windowsTop.pop();
     return result;
 }



