#ifndef AIRGEAD_BANKING_INVESTMENTCALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENTCALCULATOR_H_

class InvestmentCalculator {
public:
    // Constructor to initialize the investment calculator object
    InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears);

    // Method to display year-end reports
    void displayYearEndReports(bool includeMonthlyDeposits);
    // Method to get user input for investment parameters
    void getUserInput();

private:
    double initialInvestment; // Initial investment amount
    double monthlyDeposit; // Monthly deposit amount
    double annualInterest; // Annual interest rate
    int numberOfYears; // Number of years for investment
};

#endif // AIRGEAD_BANKING_INVESTMENTCALCULATOR_H_