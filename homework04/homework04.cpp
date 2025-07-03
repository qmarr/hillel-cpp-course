#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <math.h>
#include <array>
#include <map>
#include <string>
#include <windows.h>


int factorialRecursive(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorialRecursive(n - 1);
    }
}

int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void fibo() {
    std::cout << "Fibonacci till 30 = " << fibonacciRecursive(30) << "\n";
}

void factorOfFifteen() {
    std::cout << "Factorial of 15 = " << factorialRecursive(15) << "\n";
}

void sumOfSqrs() {
    int sum = 0;
    for (size_t i = 1; i <= 1000; i++)
    {
        sum += sqrt(i);
    }
    std::cout << "Sum of square roots from 1 to 1000 = " << sum << "\n";
}

void findPrimes(int n) {
    std::vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    for (auto& i : primes)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class Shop
{
public:
    static const std::map<std::string, double> productPrices;
    static std::map<std::string, int> productInventory;
    void printProductsOnScreen() {
        std::cout << "We have such products in our shop:\n";
        for (const auto& [name, price] : productPrices) {
            std::cout << "|  Name: " << name << "   \tPrice: " << price << "\n";
        }
    }
};

const std::map<std::string, double> Shop::productPrices = {
    { "PHONE", 14545.00 }, { "LAPTOP", 2499.99 }, { "HEADSET", 3999.99 },
    { "MOUSE", 1000.99 }, { "KEYBOARD", 8999.99 }, { "PROCESSOR", 9000.99 },
    { "MOUSEPAD", 459.0 }, { "GLASSES", 1000.00 }, { "LAMP", 799.00 },
    { "EARPLUGS", 349.99 }
};

std::map<std::string, int> Shop::productInventory = {
    { "PHONE", 345 }, { "LAPTOP", 115 }, { "HEADSET", 259 }, { "MOUSE", 1123 },
    { "KEYBOARD", 567 }, { "PROCESSOR", 89 }, { "MOUSEPAD", 600 },
    { "GLASSES", 20 }, { "LAMP", 0 }, { "EARPLUGS", 123 }
};

class Order {
private:
    static int m_idGenerator;
    int m_id;
    std::vector<std::string> m_items;
    double m_totalPrice = 0;
    std::string m_status;
public:
    Order() : m_totalPrice(0) {
        m_id = m_idGenerator++;
    }
    Order(std::vector<std::string> itemList) : m_items(std::move(itemList)), m_totalPrice(0) { 
        m_id = m_idGenerator++; 
    }

    void calculatePrice() {
        for (auto& i : m_items)
        {
            m_totalPrice += Shop::productPrices.at(i);
        }
    }
    void showCart() const {
        for (auto& i : m_items)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    int getID() const {
        return m_id;
    }
    bool isCartEmpty() const {
        return m_items.empty();
    }
    void checkIfAvailable() {
        std::vector<std::string> finalCart;
        for (auto& item : m_items)
        {
            if (Shop::productInventory[item] > 0) {
                finalCart.push_back(item);
            }
            else {
                std::cout << "Sorry this item is currently unavailabe. Please come check later";
            }
        }
        m_items = std::move(finalCart);
    }
    void createInvoice() const {
        std::cout << "Order #"<< m_id <<" was successful. You bought: \n";
        for (const auto& item : m_items)
        {
            std::cout << item << "\n";
        }
        setColor(2);
        std::cout << "Thank you for shopping. See you next time!\n";
        setColor(7);
    }
};

int Order::m_idGenerator = 1;

class OrderProcessor {
public:
    std::vector<Order> validateOrders(const std::vector<Order>& rawOrders);
    std::vector<Order> calculatePricing(const std::vector<Order>& validOrders);
    std::vector<Order> checkInventory(const std::vector<Order>& pricedOrders);
    void generateInvoices(const std::vector<Order>& finalOrders);
};

int main() {
    {
        //Перше завдання
        /*std::vector<std::thread> threads;
        threads.emplace_back(factorOfFifteen);
        threads.emplace_back(sumOfSqrs);
        threads.emplace_back(fibo);
        threads.emplace_back(findPrimes, 100);
        for (auto& i : threads)
        {
            i.join();
        }*/
    }

    Shop shop;
    OrderProcessor processor;

    shop.printProductsOnScreen();

    std::vector<Order> rawOrders = {
        Order({"PHONE", "MOUSE", "LAMP"}),
        Order({"LAPTOP", "EARPLUGS"}),
        Order(std::vector<std::string>{})
    };

    std::vector<Order> validOrders; 
    std::vector<Order> pricedOrders; 
    std::vector<Order> finalOrders; 

    std::thread thread1([&]() {
        validOrders = processor.validateOrders(rawOrders);
        });
    thread1.join();

    std::thread thread2([&]() {
        pricedOrders = processor.calculatePricing(validOrders);
        });

    thread2.join();
    
    std::thread thread3([&]() {
        finalOrders = processor.checkInventory(pricedOrders);
        });

    thread3.join();


    std::thread thread4([&]() {
        processor.generateInvoices(finalOrders);
        });
    
    thread4.join();



    setColor(7);
    return 0;
}

std::vector<Order> OrderProcessor::validateOrders(const std::vector<Order>& rawOrders)
{
    std::vector<Order> validOrders;
    for (auto& i : rawOrders)
    {
        if ((i.getID() > 0) && !i.isCartEmpty()) {
            validOrders.push_back(i);
        }
        else {
            std::cout << "Order #" << i.getID() << " failed. It will be ignored\n";
        }
    }
    return validOrders;
}

std::vector<Order> OrderProcessor::calculatePricing(const std::vector<Order>& validOrders)
{
    std::vector<Order> pricedOrders;
    for (auto& order : validOrders)
    {
        pricedOrders.push_back(order);

    }
    for (auto& i : pricedOrders)
    {
        i.calculatePrice();
    }

    return pricedOrders;
}

std::vector<Order> OrderProcessor::checkInventory(const std::vector<Order>& pricedOrders)
{   
    std::vector<Order> finalOrders;
    for (auto& order : pricedOrders)
    {
        finalOrders.push_back(order);
    }
    for (auto& order : finalOrders)
    {
        order.checkIfAvailable();
    }

    return finalOrders;
}

void OrderProcessor::generateInvoices(const std::vector<Order>& finalOrders)
{
    for (auto& order : finalOrders)
    {
        order.createInvoice();
    }
}
