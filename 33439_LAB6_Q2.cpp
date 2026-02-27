#include <iostream>
using namespace std;

class BankAccount {
    private :
    double balance;
    public :
    BankAccount(double bal) {
        balance = bal;
    }
    BankAccount() {}
    void setBalance(double bal) {
        balance = bal;
    }
    double getBalance() {
        return balance;
    }
    
};

class SavingsAccount : protected BankAccount {
    public :
    SavingsAccount(double bal) : BankAccount(bal) {}
    void addInterest(double rate) {
        setBalance(getBalance()*(1+rate/100));
    }
};

int main () {
    SavingsAccount myAccount(999.9);     
    myAccount.addInterest(8);
    myAccount.getBalance();
    /*Function call fails because getBalance(double bal) is set to protected access 
      and thus is only accesible in derived class and not in main function.*/
    return 0;
}