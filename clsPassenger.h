#pragma once

#include <iostream>
#include "clsPerson.h"
#include "DataStructures.h"
#include "clsCard.h"
#include <sstream>

using namespace std;

class clsPassenger : public clsPerson {
protected:
    clsCard Card;
    string Password;
    static int numberOfAllPassenger;
    
public:
    clsPassenger(short Age, string FirstName, string LastName, string PhoneNumber, string Email,
                 int id, clsCard card, string password = "")
        : clsPerson(id, Age, FirstName, LastName, PhoneNumber, Email), 
          Card(card), Password(password) {}

    clsPassenger(short Age, string FirstName, string LastName, string PhoneNumber, string Email,
                 clsCard card, string password = "")
        : clsPerson(Age, FirstName, LastName, PhoneNumber, Email), 
          Card(card), Password(password) {
            this->Id=++numberOfAllPassenger;
          }

    string getPassword() {
        return Password;
    }

    int getId(){
       return id;
    }

    void setPassword(string& newPassword) {
        Password = newPassword;
    }

    string toString() {
        ostringstream oss;
        oss << personToString() << ",,," << Card.toString() << ",,," << Password;
        return oss.str();
    }

    static clsPassenger parse(string line) {
        DoubleLinkedList<string> tokens = Split(line, ",,,");
        if (tokens.size() < 9) {
            throw invalid_argument("Not enough tokens in line");
        }

        int id = stoi(tokens[0]);
        short age = stoi(tokens[1]);
        string firstName = tokens[2];
        string lastName = tokens[3];
        string phoneNumber = tokens[4];
        string email = tokens[5];
        
        bool cardType = (tokens[6] == "Premium");
        double cardBalance = stod(tokens[7]);
        string password = tokens[8];
        
        clsCard card(cardType, cardBalance);
        
        return clsPassenger(age, firstName, lastName, phoneNumber, email, id, card, password);
    }
};

static int clsPassenger::numberOfAllPassenger = 0;
