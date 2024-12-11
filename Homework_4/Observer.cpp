#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <string>


class Observer {
    public:
     virtual void Update(const std::string& message) = 0;
     virtual ~Observer() = default;
};

class Subject {
    public:
      virtual void attach(std::shared_ptr<Observer> observer) = 0;
      virtual void detach(std::shared_ptr<Observer> observer) = 0;
      virtual void notify(const std::string& message) = 0;
      virtual ~Subject() = default;
};

class LinuxKernel : public Subject {
    private:
      std::vector<std::shared_ptr<Observer>> users;
    public:
      void attach(std::shared_ptr<Observer> observer) override {
        users.push_back(observer);
      }
      void detach(std::shared_ptr<Observer> observer) override {
          users.erase(std::remove(users.begin(), users.end(), observer), users.end());
      }
      void notify(const std::string& message) override {
        for(auto& user : users) {
            user->Update(message);
        }
      }
      void KernelUpdate(const std::string& version) {
        std::string message = "New Linux kernel version " + version + " now is available.";
        notify(message);
      }
};

class LinuxUsers : public Observer {
    private:
      std::string username_;
    public:
      LinuxUsers(const std::string& username) : username_(username) {}
      void Update(const std::string& message) override {
        std::cout << "User " << username_ << " received update: " << message << std::endl;
      }
};

int main() {
    auto user_1 = std::make_shared<LinuxUsers>("John");
    auto user_2 = std::make_shared<LinuxUsers>("Mary");
    auto user_3 = std::make_shared<LinuxUsers>("Leo");
    auto kernel = std::make_shared<LinuxKernel>();
    kernel->attach(user_1);
    kernel->attach(user_2);
    kernel->attach(user_3);
    kernel->KernelUpdate("3.0.1");
    kernel->detach(user_1);
    kernel->KernelUpdate("3.0.2");
}