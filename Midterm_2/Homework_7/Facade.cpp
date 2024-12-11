#include <iostream>
#include <string>

class Account {
  public:
    void createAccount(const std::string& accountName) {
        std::cout << "Creating account for: " << accountName << std::endl;
    }
    void checkBalance(const std::string& accountName) {
        std::cout << "Checking balance for account: " << accountName << std::endl;
    }
};

class Loan {
  public:
    void checkLoanEligibility(const std::string& customerName) {
        std::cout << "Checking loan eligibility for: " << customerName << std::endl;
    }
    void approveLoan(const std::string& customerName, double amount) {
        std::cout << "Approving loan for " << customerName << " amount: " << amount << std::endl;
    }
};

class Transaction {
  public:
    void makeTransaction(const std::string& fromAccount, const std::string& toAccount, double amount) {
        std::cout << "Transferring $" << amount << " from " << fromAccount << " to " << toAccount << std::endl;
    }
};

class Customer {
  public:
    void updateCustomerInfo(const std::string& customerName, const std::string& newInfo) {
        std::cout << "Updating info for " << customerName << ": " << newInfo << std::endl;
    }
    void getCustomerInfo(const std::string& customerName) {
        std::cout << "Getting information for " << customerName << std::endl;
    }
};

class CreditCard {
  public:
    void checkCreditCardStatus(const std::string& cardNumber) {
        std::cout << "Checking status for card: " << cardNumber << std::endl;
    }
    void issueNewCard(const std::string& customerName) {
        std::cout << "Issuing new credit card for: " << customerName << std::endl;
    }
};

class BankFacade {
  private:
    Account account;
    Loan loan;
    Transaction transaction;
    Customer customer;
    CreditCard creditCard;
  public:
    void createNewCustomerAccount(const std::string& customerName, const std::string& accountName) {
        customer.getCustomerInfo(customerName);
        account.createAccount(accountName);
    }
    void transferMoney(const std::string& fromAccount, const std::string& toAccount, double amount) {
        account.checkBalance(fromAccount);
        transaction.makeTransaction(fromAccount, toAccount, amount);
    }
    void applyForLoan(const std::string& customerName, double loanAmount) {
        loan.checkLoanEligibility(customerName);
        loan.approveLoan(customerName, loanAmount);
    }
    void issueCreditCard(const std::string& customerName) {
        creditCard.issueNewCard(customerName);
    }
    void updateCustomerDetails(const std::string& customerName, const std::string& newInfo) {
        customer.updateCustomerInfo(customerName, newInfo);
    }
};

int main() {
    BankFacade bankFacade;
    bankFacade.createNewCustomerAccount("John Doe", "John's Savings Account");
    bankFacade.transferMoney("John's Savings Account", "Mary's Checking Account", 1000);
    bankFacade.applyForLoan("John Doe", 5000);
    bankFacade.issueCreditCard("John Doe");
    bankFacade.updateCustomerDetails("John Doe", "New Address: 123 Main St");
}
