#include <iostream>
//The lock must be unique to the key
class Lock {
    private:
      static Lock* instance;
      Lock() {
        std::cout << "Lock created." << std::endl;
      }
      ~Lock() {
        std::cout << "Lock destroyed." << std::endl;
      }
      Lock(const Lock& other)  = delete;
      Lock& operator=(const Lock& other) = delete;
    public:
      static Lock* getInstance() {
        if(Lock::instance == nullptr) {
            Lock::instance = new Lock();
        }
        return Lock::instance;
      }
      static void release() {
        delete Lock::instance;
        Lock::instance = nullptr;
      }
};

Lock* Lock::instance = nullptr;

int main() {
  /*Lock* lock1 = Lock::getInstance();
  Lock* lock2 = Lock::getInstance();
  std::cout << lock1 << ' ' << lock2 << std::endl;*/
  Lock* lock1 = Lock::getInstance();
  //lock1->release();
  Lock* lock2 = Lock::getInstance();
  //lock2->release();
  std::cout << "lock1's address: " << lock1 << std::endl;
  std::cout << "lock2's address: " << lock2 << std::endl;
}
