#include <iostream>
#include <vector>
#include <algorithm>
#include "customer.h"
#include "logger.h"

bool sortByLastName(const Customer& customer1, const Customer& customer2) {
    return customer1.getLastName() < customer2.getLastName();
}

std::vector<Customer> filterCustomersByCreditCard(const std::vector<Customer>& customers, const std::string& startRange, const std::string& endRange) {
    std::vector<Customer> filteredCustomers;
    for (const Customer& customer : customers) {
        std::string creditCardNumber = customer.getCreditCardNumber();
        if (creditCardNumber >= startRange && creditCardNumber <= endRange) {
            filteredCustomers.push_back(customer);
        }
    }
    return filteredCustomers;
}

int main() {
    std::vector<Customer> customers;
    customers.push_back(Customer(1, "Smith", "John", "1234", "56789"));
    customers.push_back(Customer(2, "Johnson", "Amy", "9876", "54321"));
    customers.push_back(Customer(3, "Brown", "Michael", "5678", "98765"));
    customers.push_back(Customer(4, "Davis", "Sarah", "4321", "67890"));

    std::cout << "Choose an option:\n";
    std::cout << "1. Sort by last name\n";
    std::cout << "2. Filter by credit card range\n";
    int option;
    std::cin >> option;

    if (option == 1) {
        std::sort(customers.begin(), customers.end(), sortByLastName);
        std::cout << "Customers sorted by last name:" << std::endl;
    } else if (option == 2) {
        std::string startRange, endRange;
        std::cout << "Enter start range of credit card numbers: ";
        std::cin >> startRange;
        std::cout << "Enter end range of credit card numbers: ";
        std::cin >> endRange;
        std::vector<Customer> filteredCustomers = filterCustomersByCreditCard(customers, startRange, endRange);
        std::cout << "Customers with credit card numbers in the range [" << startRange << ", " << endRange << "]:" << std::endl;
        customers = filteredCustomers;
    } else {
        std::cout << "Invalid option. Exiting..." << std::endl;
        return 0;
    }

    for (const Customer& customer : customers) {
        std::cout << customer << std::endl;
    }

    Logger logger("logfile.txt");
    logger.log("Application started.");
    logger.log("Customers data loaded.");
    if (option == 1) {
        logger.log("Sorted customers by last name.");
    } else if (option == 2) {
        logger.log("Filtered customers by credit card range.");
    }

    return 0;
}