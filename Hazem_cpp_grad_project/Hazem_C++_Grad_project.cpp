/**
 * @file Hazem_C++_Grad_project.cpp
 * @author mhmdreda99 (dev.mhmdreda99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// Include necessary Dependecies
#include <iostream>
#include <vector>
#include <string>

// Define a Person class with name and age attributes

class Person {
public:
    std::string name;
    int age;

    // Constructor for Person class
    Person(std::string name, int age) : name(name), age(age) {}
};

// Declare a vector to store Person objects
std::vector<Person> records;

/**
 * @brief 
 * Function to add a new Person to the records vector
 * @param name stores the preson name 
 * @param age stores person age 
 */
void AddRecord(std::string name, int age) {
    if (records.size() < 100) {
        records.push_back(Person(name, age));
    } else {
        std::cout << "Error: Maximum number of records reached." << std::endl;
    }
}
/**
 * @brief 
 *  Function to fetch a Person from the records vector by ID
 * @param id stores  the record id to be restored 
 * @return Person 
 */

Person FetchRecord(int id) {
    return records[id];
}

// App. Entry point 
int main() {

     std::cout << "User Sign-up Application\n" ;
    // Infinite loop to keep the program running until the user chooses to quit
    while (true) {
        // Display options to the user
        std::cout << "1. Add Record\n2. Fetch Record\n3. Quit\n" << "Enter Option: ";
        int option;
        // Get user's choice
        std::cin >> option;

        // Perform action based on user's choice
        switch (option) {
        case 1: {
            // Option 1: Add a new record
            std::string name;
            int age;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter age: ";
            std::cin >> age;
            AddRecord(name, age);
            break;
        }
        case 2: {
            // Option 2: Fetch a record
            int id;
            std::cout << "Enter ID: ";
            std::cin >> id;
            Person person = FetchRecord(id);
            std::cout << "Name: " << person.name << ", Age: " << person.age << "\n";
            break;
        }
        case 3:
            // Option 3: Quit the program
            return 0;
        default:
            // If the user enters an invalid option
            std::cout << "Invalid option\n";
        }
    }
}