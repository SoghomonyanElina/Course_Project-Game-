#include <iostream>
#include <memory>

class ProblemHandler {
    protected:
      std::shared_ptr<ProblemHandler> next;
    public:
      void setNext(std::shared_ptr<ProblemHandler> handler) {
        next = handler;
      }
      virtual void HandleProblem(const std::string& problem) = 0; 
      virtual ~ProblemHandler() = default;
};

class Intern : public ProblemHandler {
    public:
     void HandleProblem(const std::string& problem) override {
        if(problem == "Easy") {
            std::cout << "Intern will solve the problem." << std::endl;
        }
        else if(next) {
            std::cout << "Problem passed to the Buddy." << std::endl;
            next->HandleProblem(problem);
        }
        else {
            std::cout << "Can't handle the problem." << std::endl;
        }
      }
};

class Buddy : public ProblemHandler {
    public:
      void HandleProblem(const std::string& problem) override {
        if(problem == "Medium") {
            std::cout << "Buddy will solve the problem." << std::endl;
        }
        else if (next) {
            std::cout << "Problem passed to the team manager." << std::endl;
            next->HandleProblem(problem);
        }
        else {
            std::cout << "Can't handle the problem." << std::endl;
        }
      }
};

class TeamManager : public ProblemHandler {
    public:
      void HandleProblem(const std::string& problem) override {
        if(problem == "Complex") {
            std::cout << "Team Manager will solve the problem." << std::endl;
        }
        else if (next) {
            std::cout << "Problem passed to the CEO." << std::endl;
            next->HandleProblem(problem);
        }
        else {
            std::cout << "Can't handle the problem." << std::endl;
        }
      }
};

class CEO : public ProblemHandler {
    public:
      void HandleProblem(const std::string& problem) override {
        if(problem == "Most Complex") {
            std::cout << "Ceo will solve the problem." << std::endl;
        }
        else if (next) {
            next->HandleProblem(problem);
        }
        else {
            std::cout << "Can't handle the problem." << std::endl;
        }
      }
};

int main() {
    auto intern = std::make_shared<Intern>();
    auto buddy = std::make_shared<Buddy>();
    auto teamManager = std::make_shared<TeamManager>();
    auto ceo = std::make_shared<CEO>();

    intern->setNext(buddy);
    buddy->setNext(teamManager);
    teamManager->setNext(ceo);

    intern->HandleProblem("Easy");
    intern->HandleProblem("Medium");
    ceo->HandleProblem("Impossible");
    teamManager->HandleProblem("Complex");
    ceo->HandleProblem("Most Complex");
}