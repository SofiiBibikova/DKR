#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <fstream>

class Customer {
private:
    int id;
    std::string lastName;
    std::string firstName;
    std::string creditCardNumber;
    std::string bankAccountNumber;

public:
    Customer();
    Customer(int id, const std::string& lastName, const std::string& firstName, const std::string& creditCardNumber, const std::string& bankAccountNumber);

    // Setters
    void setId(int id);
    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);
    void setCreditCardNumber(const std::string& creditCardNumber);
    void setBankAccountNumber(const std::string& bankAccountNumber);

    // Getters
    int getId() const;
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getCreditCardNumber() const;
    std::string getBankAccountNumber() const;

    std::string toString() const;
};

// Overloaded output operator for Customer class
std::ostream& operator<<(std::ostream& os, const Customer& customer);

#endif  // CUSTOMER_H