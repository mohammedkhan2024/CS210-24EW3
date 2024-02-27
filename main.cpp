/*
 * ProjectTwo.cpp
 *
 *  Date: 02/05/2024
 *  Author: Mohammed Khan
 */

#include <iostream>
#include "InvestmentCalculator.h"
#include <iomanip> // For setting precision of output

InvestmentCalculator::InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears)
    : initialInvestment(initialInvestment), monthlyDeposit(monthlyDeposit), annualInterest(annualInterest), numberOfYears(numberOfYears) {
}

void InvestmentCalculator::displayYearEndReports(bool includeMonthlyDeposits) {
    // Display headers for the table
    std::cout << std::setw(5) << "Year" << std::setw(15) << "Opening Amount" << std::setw(18) << "Deposited Amount"
        << std::setw(12) << "Total" << std::setw(15) << "Interest" << std::setw(18) << "Closing Balance" << std::endl;

    // Calculate and display results for each year
    double openingAmount = initialInvestment;
    double closingBalance;

    for (int year = 1; year <= numberOfYears; ++year) {
        // Calculate interest
        double interest = (openingAmount + (includeMonthlyDeposits ? monthlyDeposit : 0.0)) * ((annualInterest / 100) / 12);

        // Calculate closing balance
        closingBalance = openingAmount + (includeMonthlyDeposits ? monthlyDeposit : 0.0) + interest;

        // Display results in a tabular format
        std::cout << std::setw(5) << year << std::fixed << std::setprecision(2)
            << std::setw(15) << openingAmount << std::setw(18) << (includeMonthlyDeposits ? monthlyDeposit : 0.0)
            << std::setw(12) << openingAmount + (includeMonthlyDeposits ? monthlyDeposit : 0.0)
            << std::setw(15) << interest << std::setw(18) << closingBalance << std::endl;

        // Update opening amount for the next iteration
        openingAmount = closingBalance;
    }
}

// Function to get user input
void InvestmentCalculator::getUserInput() {
    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDeposit;

    std::cout << "Annual Interest (Compounded): %";
    std::cin >> annualInterest;

    std::cout << "Number of Years: ";
    std::cin >> numberOfYears;
}

// Main function
int main() {
    // Display the initial screen
    std::cout << "Initial Investment Amount: $";
    double initialInvestment;
    std::cin >> initialInvestment;

    std::cout << "Monthly Deposit: $";
    double monthlyDeposit;
    std::cin >> monthlyDeposit;

    std::cout << "Annual Interest (Compounded): %";
    double annualInterest;
    std::cin >> annualInterest;

    std::cout << "Number of Years: ";
    int numberOfYears;
    std::cin >> numberOfYears;

    std::cout << "Press any key to continue...\n";
    std::cin.get(); // Wait for user input

    // Create an instance of the InvestmentCalculator class
    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

    // Display year-end reports
    std::cout << "Year-end balances without additional deposits:\n";
    calculator.displayYearEndReports(false);

    std::cout << "Year-end balances with monthly deposits:\n";
    calculator.displayYearEndReports(true);

    // Allow the user to test different scenarios
    char userChoice;
    do {
        std::cout << "Do you want to test another scenario? (Y/N): ";
        std::cin >> userChoice;
        if (userChoice == 'Y' || userChoice == 'y') {
            calculator.getUserInput();  // Prompt user for new input
            calculator.displayYearEndReports(true); // Display reports with updated input
        }
       
    } while (userChoice == 'Y' || userChoice == 'y');

    return 0;
}