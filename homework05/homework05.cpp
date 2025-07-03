#include <iostream>
#include <thread>
#include <vector>
#include <windows.h>
#include <random>
#include <mutex>
#include <atomic>

void setColor(int color) {
    //0	    Black
    //1	    Blue
    //2	    Green
    //4	    Red
    //6	    Yellow
    //7	    Light gray(default)
    //8	    Dark gray
    //15	White
    //You can also combine colors like FOREGROUND_RED | FOREGROUND_INTENSITY.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

 


class SafeBankAccount {
private:
    double balance = 1000.0;  // Початковий баланс
    mutable std::mutex balanceMutex;

public:

    void deposit(double amount) {
        std::lock_guard<std::mutex> lock(balanceMutex);
        balance += amount;
    }

    bool withdraw(double amount) {
        std::lock_guard<std::mutex> lock(balanceMutex);
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double get_balance() const {
        std::lock_guard<std::mutex> lock(balanceMutex);
        return balance;
    }

    void printFinalInfo() const {
        std::lock_guard<std::mutex> lock(balanceMutex);
        setColor(1);
        std::cout << "\nFinal balance: " << balance << "\n";
        setColor(7);
    }
};

class SafeBankStatistics {
private:
    std::atomic<int> transaction_count = 0;
    std::atomic<double> total_amount = 0.0;

public:
    void record_transaction(double amount) {
        transaction_count++;
        total_amount += amount;
    }

    int get_total_transactions() const { return transaction_count.load(); }
    double get_total_amount() const { return total_amount.load(); }
};


void cashierWork(SafeBankStatistics& bank, SafeBankAccount& bankAcc) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> depDistr(50, 500);
    std::uniform_real_distribution<> wdDistr(10, 200);
    std::uniform_int_distribution<> opDistr(0, 1);
    int operationTk = 0;
    double depositMoney = 0.0;
    double withdrMoney = 0.0;
    
    for (size_t i = 0; i < 100; i++)
    {   
        
        operationTk = opDistr(gen);
        depositMoney = depDistr(gen);
        withdrMoney = wdDistr(gen);
        if (operationTk == 0) {


            bankAcc.deposit(depositMoney);
            std::cout << "\tDeposit\n";
            std::cout << "Current balance: \t" << bankAcc.get_balance() << "\n";
            bank.record_transaction(depositMoney);
        } else {
            

            bankAcc.withdraw(withdrMoney);
            std::cout << "\tWithdrawal\n";
            std::cout << "Current balance: \t" << bankAcc.get_balance() << "\n";
            bank.record_transaction(withdrMoney);
        }
    }

    
    bankAcc.printFinalInfo(); //чому колір виводу інших потоків змінюється навіть якщо тут стоїть lock_guard?
    
}

int main() {
    SafeBankStatistics bank;
    SafeBankAccount bankAcc1, bankAcc2, bankAcc3, bankAcc4, bankAcc5;


    std::vector<std::thread> cashiers;
    cashiers.emplace_back(cashierWork, std::ref(bank), std::ref(bankAcc1));
    cashiers.emplace_back(cashierWork, std::ref(bank), std::ref(bankAcc2));
    cashiers.emplace_back(cashierWork, std::ref(bank), std::ref(bankAcc3));
    cashiers.emplace_back(cashierWork, std::ref(bank), std::ref(bankAcc4));
    cashiers.emplace_back(cashierWork, std::ref(bank), std::ref(bankAcc5));
    for (auto& cashier : cashiers)
    {
        cashier.join();
    }

    setColor(6);
    
    std::cout << "Total transactions happend: =" << bank.get_total_transactions() << "=. Total transaction amount is ==" << bank.get_total_amount() << "==.";

    setColor(7);
    return 0;
}
