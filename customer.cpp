#include "customer.h"

Customer::Customer() : id(0) {}

Customer::Customer(int id, const std::string& lastName, const std::string& firstName, const std::string& creditCardNumber, const std::string& bankAccountNumber)
    : id(id), lastName(lastName), firstName(firstName), creditCardNumber(creditCardNumber), bankAccountNumber(bankAccountNumber) {}

void Customer::setId(int id) {
    this->id = id;
}

void Customer::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Customer::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Customer::setCreditCardNumber(const std::string& creditCardNumber) {
    this->creditCardNumber = creditCardNumber;
}

void Customer::setBankAccountNumber(const std::string& bankAccountNumber) {
    this->bankAccountNumber = bankAccountNumber;
}

int Customer::getId() const {
    return id;
}

std::string Customer::getLastName() const {
    return lastName;
}

std::string Customer::getFirstName() const {
    return firstName;
}

std::string Customer::getCreditCardNumber() const {
    return creditCardNumber;
}

std::string Customer::getBankAccountNumber() const {
    return bankAccountNumber;
}

std::string Customer::toString() const {
    return std::to_string(id) + ": " + firstName + " " + lastName + ", Credit Card: " + creditCardNumber + ", Bank Account: " + bankAccountNumber;
}

std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << customer.toString();
    return os;
}