/**
Author: George Kyriakides
Email: george.kyriakides2@gmail.com
Create Date: 16/06/2021
**/

// Bank.cpp
/* A C++ program for a Banking Management System I created where you can create an account, search for an account,
delete an account, deposit money into account or withdraw money from account. Once you have completed the tasks you want, you can exit the program. */

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// Account struct used to hold the account information.
struct Account {
     public:
        // Data fields
        string fullName;
        char accountType;
        int accountNumber = 0;
        double startingBalance = 0;
        double amountDeposited = 0;
        double withdrawAmount = 0;
        double currentBalance = 0;
        double availableBalance = -1;
};

template <class T> // Template class for Bank Class (Used in accounts vector)

// Bank class used to formulate the functionality of the program by utilising the Account struct for customer accounts (account object used to call the objects) and a template class for the accounts vector to hold the accounts.
class Bank {
    private:
        // Data Fields
        vector<T> accounts;
        Account account;
    public:
        // Functions of Bank class
        // Constructor
        Bank() {}
        // Destructor
        ~Bank() {}
        // addAccount() used to add more than one account by using vector.
        void addAccount(T value) {
            accounts.push_back(value);
        }
        // setCustomerDetails() function used to set the details of the customer.
        void setCustomerDetails() {
            // User inputs their full name.
            cout << "\n" << "Enter Full name: ";
            getline(cin >> ws, account.fullName);

            // User inputs their account number.
            cout << "Enter Account number (6 digits long starting with 1 e.g. 100000): ";
            cin >> account.accountNumber;
            // while loop used to check whether account number is invalid.
            while (account.accountNumber < 100000 || account.accountNumber >= 1000000) {
                cout << "Please enter a 6 digit long account number: ";
                cin >> account.accountNumber;
            }

            // User inputs their account type.
            cout << "Enter Account type ('S' for Savings, 'C' for Credit and 'D' for Debit): ";
            cin >> account.accountType;
            // while loop used to check whether account type is an invalid option.
            while (account.accountType != 'S' && account.accountType != 'C' && account.accountType != 'D') {
                cout << "Please enter a valid account type: ";
                cin >> account.accountType;
            }

            // User inputs their balance for their account.
            cout << "Enter Balance (more than 0 and no spaces/commas included): ";
            cin >> account.startingBalance;
            // while loop used to check whether balance is more than zero.
            while (account.startingBalance <= 0) {
                cout << "Please enter a valid balance: ";
                cin >> account.startingBalance;
            }

            // Add account into accounts vector so that it can be stored when needing to search for a particular account.
            addAccount(account);
        }

        // searchForAccount() function used to search for account that the customer wants displayed.
        void searchForAccount() {
            // for loop used to find the account in the accounts vector by searching through it using the account number as the unique identifier of each persons account.
            for (int counter = 0; counter < accounts.size(); counter++) {
                int accountNum; // accountNum is the account number of the account.
                bool valAccount = false; // valAccount to see if account number matches with any available accounts and is set to invalid to start.
                // if-else loop to see if there is more than one account so if there is more than one account, the user can select which account they want displayed using their account number.
                // if there is more than one account.
                if (accounts.size() > 1) {
                    // User asked to enter the desired account number for account they want displayed.
                    cout << "\n" << "Enter the account number for the account you want displayed: ";
                    cin >> accountNum;
                    // if loop to see whether account number matches the first account placed at the zero index in the vector.
                    if (accountNum == accounts[0].accountNumber) {
                        valAccount = true; // set account to valid.
                        // Full name of account selected from vector outputted.
                        cout << "\n" << "Full Name: " << accounts[counter].fullName << endl;
                        // Account number of account selected from vector outputted.
                        cout << "Account Number: " << accounts[counter].accountNumber << endl;
                        // else-if loop used to output the account type based on the selected account type (being a char and then outputted as a string) of account.
                        if (accounts[counter].accountType == 'S') {
                            cout << "Account Type: Savings" << endl;
                        } else if (accounts[counter].accountType == 'C') {
                            cout << "Account Type: Credit" << endl;
                        } else if (accounts[counter].accountType == 'D') {
                            cout << "Account Type: Debit" << endl;
                        }
                        // Starting balance of account outputted.
                        cout << "Starting balance: $" << accounts[counter].startingBalance << endl;
                        /* if-else loop outputs the current balance based on whether the deposit/withdraw functions have been used. So the
                        balance when using either or both of those functions is changed and held with the availableBalance object, which allows for
                        the check of whether or not it equals zero. If it equals zero, then the currentBalance object is set to startingBalance object.
                        Otherwise, the currentBalance object is set to availableBalance object which is the up-to-date balance for the user. */
                        if (accounts[counter].availableBalance == -1) {
                            accounts[counter].currentBalance = accounts[counter].startingBalance;
                            cout << "Current balance: $" << accounts[counter].currentBalance << endl;
                        } else {
                            accounts[counter].currentBalance = accounts[counter].availableBalance;
                            cout << "Current balance: $" << accounts[counter].currentBalance << endl;
                        }
                        // return function used to break out of for loop since only one iteration of selection is desired.
                        return;
                    }
                    /* for loop used to find the account in the accounts vector (Starting from 1 index) by searching through it using the account number
                    as the unique identifier of each persons account. */
                    for (int counter = 1; counter < accounts.size(); counter++) {
                        // if loop to see whether account number matches the an account that is in the index of one or bigger which is less than the entire accounts vector.
                        if (accountNum == accounts[counter].accountNumber) {
                            valAccount = true; // set account to valid.
                            // Full name of account selected from vector outputted.
                            cout << "\n" << "Full Name: " << accounts[counter].fullName << endl;
                            // Account number of account selected from vector outputted.
                            cout << "Account Number: " << accounts[counter].accountNumber << endl;
                            // else-if loop used to output the account type based on the selected account type (being a char and then outputted as a string) of account.
                            if (accounts[counter].accountType == 'S') {
                                cout << "Account Type: Savings" << endl;
                            } else if (accounts[counter].accountType == 'C') {
                                cout << "Account Type: Credit" << endl;
                            } else if (accounts[counter].accountType == 'D') {
                                cout << "Account Type: Debit" << endl;
                            }
                            // Starting balance of account outputted.
                            cout << "Starting balance: $" << accounts[counter].startingBalance << endl;
                            /* if-else loop outputs the current balance based on whether the deposit/withdraw functions have been used. So the
                            balance when using either or both of those functions is changed and held with the availableBalance object, which allows for
                            the check of whether or not it equals zero. If it equals zero, then the currentBalance object is set to startingBalance object.
                            Otherwise, the currentBalance object is set to availableBalance object which is the up-to-date balance for the user. */
                            if (accounts[counter].availableBalance == -1) {
                                accounts[counter].currentBalance = accounts[counter].startingBalance;
                                cout << "Current balance: $" << accounts[counter].currentBalance << endl;
                            } else {
                                accounts[counter].currentBalance = accounts[counter].availableBalance;
                                cout << "Current balance: $" << accounts[counter].currentBalance << endl;
                            }
                            // return function used to break out of for loop since only one iteration of selection is desired.
                            return;
                        }
                    }
                    if (!valAccount) {
                        cout << "\n" << "Invalid account number! Please try again later." << endl;
                        return;
                    }
                } else { // else there is only one account.
                    // Full name of account selected from vector outputted.
                    cout << "\n" << "Full Name: " << accounts[counter].fullName << endl;
                    // Account number of account selected from vector outputted.
                    cout << "Account Number: " << accounts[counter].accountNumber << endl;
                    // else-if loop used to output the account type based on the selected account type (being a char and then outputted as a string) of account.
                    if (accounts[counter].accountType == 'S') {
                        cout << "Account Type: Savings" << endl;
                    } else if (accounts[counter].accountType == 'C') {
                        cout << "Account Type: Credit" << endl;
                    } else if (accounts[counter].accountType == 'D') {
                        cout << "Account Type: Debit" << endl;
                    }
                    // Starting balance of account outputted.
                    cout << "Starting balance: $" << accounts[counter].startingBalance << endl;
                    /* if-else loop outputs the current balance based on whether the deposit/withdraw functions have been used. So the
                    balance when using either or both of those functions is changed and held with the availableBalance object, which allows for
                    the check of whether or not it equals zero. If it equals zero, then the currentBalance object is set to startingBalance object.
                    Otherwise, the currentBalance object is set to availableBalance object which is the up-to-date balance for the user. */
                    if (accounts[counter].availableBalance == -1) {
                        accounts[counter].currentBalance = accounts[counter].startingBalance;
                        cout << "Current balance: $" << accounts[counter].currentBalance << endl;
                    } else {
                        accounts[counter].currentBalance = accounts[counter].availableBalance;
                        cout << "Current balance: $" << accounts[counter].currentBalance << endl;
                    }
                    // return function used to break out of for loop since only one iteration of selection is desired.
                    return;
                }
            }
        }

        // deleteAccount() function lets the user select an account they would like to delete by inputting the account number which uniquely identifies the account they would like to delete.
        void deleteAccount() {
            // for loop used to find the account in the accounts vector by searching through it using the account number as the unique identifier of each persons account.
            for (int counter = 0; counter < accounts.size(); counter++) {
                int accountNum; // accountNum is the account number of the account.
                bool validAccount = false; // validAccount to see if account number matches with any available accounts and is set to invalid to start.
                // if-else loop to see if there is more than one account so if there is more than one account the user can select the account they want to delete.
                if (accounts.size() > 1) {
                    // User asked to enter the desired account number for account they want to withdraw from.
                    cout << "\n" << "Enter the account number for the account you want to delete: ";
                    cin >> accountNum;
                    // for loop to make sure the accounts checked start from one.
                    for (int counter = 1; counter < accounts.size(); counter++) {
                        // if accountNum matches with account number at the one or more index in vector than continue.
                        if (accountNum == accounts[counter].accountNumber) {
                            validAccount = true; // validAccount set to valid.
                            accounts.erase(accounts.begin() + counter);
                            cout << "\n" << "Account with account number " << accountNum << " has been deleted." << endl;
                        } else if (accountNum == accounts[0].accountNumber) { // else if accountNum matches with account number at the zero index in vector than continue.
                            validAccount = true; // validAccount set to valid.
                            accounts.erase(accounts.begin());
                            cout << "\n" << "Account with account number " << accountNum << " has been deleted." << endl;
                        }
                    }
                    // if loop used when account number doesn't match with any available account which will output with the account number being invalid and needing to try again later.
                    if (!validAccount) {
                        cout << "\n" << "Invalid account number! Please try again later." << endl;
                    }
                } else {
                    accounts.erase(accounts.begin());
                    cout << "\n" << "Account with account number " << accounts[0].accountNumber << " has been deleted." << endl;
                }
                return; // return back to main menu
            }
        }

        // deposit() function lets the user deposit the amount of money they like into the Bank.
        int deposit() {
            // for loop used to find the account in the accounts vector by searching through it using the account number as the unique identifier of each persons account.
            for (int counter = 0; counter < accounts.size(); counter++) {
                int accountNum; // accountNum is the account number of the account.
                bool validAccount = false; // validAccount to see if account number matches with any available accounts and is set to invalid to start.
                // if-else loop to see if there is more than one account so if there is more than one account the user can select the account they want to deposit in.
                // if there is more than one account.
                if (accounts.size() > 1) {
                    // User asked to enter the desired account number for account they want to deposit in.
                    cout << "\n" << "Enter the account number for the account you want to deposit in: ";
                    cin >> accountNum;
                    // for loop to make sure the accounts checked start from one.
                    for (int counter = 1; counter < accounts.size(); counter++) {
                        // if accountNum matches with account number at the one or more index in vector than continue.
                        if (accountNum == accounts[counter].accountNumber) {
                            validAccount = true; // validAccount set to valid.
                            // User asked to enter desired amount to withdraw from selected account.
                            cout << "\nEnter amount to be deposited: ";
                            cin >> accounts[counter].amountDeposited;
                            // while loop to catch invalid deposit amounts (<=0).
                            while (accounts[counter].amountDeposited <= 0) {
                                cout << "Invalid deposit amount (less or equal to zero). Please enter a valid deposit amount: ";
                                cin >> accounts[counter].amountDeposited;
                            }
                            /* if-else loop used to see whether the available balance is still equal to zero which in that case the start balance is
                            added with amount deposited. If not, then the current available balance is added with the amount deposited to make the new available balance. */
                            if (accounts[counter].availableBalance == -1) {
                                accounts[counter].availableBalance = accounts[counter].startingBalance + accounts[counter].amountDeposited;
                            } else {
                                accounts[counter].availableBalance = accounts[counter].availableBalance + accounts[counter].amountDeposited;
                            }
                            // Output the available balance.
                            cout << "\n" << "Available Balance: $" << accounts[counter].availableBalance << endl;
                            // return the available balance for the functions integer value.
                            return accounts[counter].availableBalance;
                        } else if (accountNum == accounts[0].accountNumber) { // else if accountNum matches with account number at the zero index in vector than continue.
                            validAccount = true; // validAccount set to valid.
                            // User asked to enter desired amount to withdraw from selected account.
                            cout << "\nEnter amount to be deposited: ";
                            cin >> accounts[0].amountDeposited;
                            // while loop to catch invalid deposit amounts (<=0).
                            while (accounts[counter].amountDeposited <= 0) {
                                cout << "Invalid deposit amount (less or equal to zero). Please enter a valid deposit amount: ";
                                cin >> accounts[counter].amountDeposited;
                            }
                            /* if-else loop used to see whether the available balance is still equal to zero which in that case the start balance is
                            added with amount deposited. If not, then the current available balance is added with the amount deposited to make the new available balance. */
                            if (accounts[0].availableBalance == -1) {
                                accounts[0].availableBalance = accounts[0].startingBalance + accounts[0].amountDeposited;
                            } else {
                                accounts[0].availableBalance = accounts[0].availableBalance + accounts[0].amountDeposited;
                            }
                            // Output the available balance.
                            cout << "\n" << "Available Balance: $" << accounts[0].availableBalance << endl;
                            // return the available balance for the functions integer value.
                            return accounts[0].availableBalance;
                        }
                    }
                    // if loop used when account number doesn't match with any available account which will output with the account number being invalid and needing to try again later.
                    if (!validAccount) {
                        cout << "\n" << "Invalid account number! Please try again later." << endl;
                    }
                } else { // else there is only one account.
                    // User asked to enter desired amount to withdraw from selected account.
                    cout << "\nEnter amount to be deposited: ";
                    cin >> accounts[counter].amountDeposited;
                    // while loop to catch invalid deposit amounts (<=0).
                    while (accounts[counter].amountDeposited <= 0) {
                        cout << "Invalid deposit amount (less or equal to zero). Please enter a valid deposit amount: ";
                        cin >> accounts[counter].amountDeposited;
                    }
                    /* if-else loop used to see whether the available balance is still equal to zero which in that case the start balance is
                    added with amount deposited. If not, then the current available balance is added with the amount deposited to make the new available balance. */
                    if (accounts[counter].availableBalance == -1) {
                        accounts[counter].availableBalance = accounts[counter].startingBalance + accounts[counter].amountDeposited;
                    } else {
                        accounts[counter].availableBalance = accounts[counter].availableBalance + accounts[counter].amountDeposited;
                    }
                    // Output the available balance.
                    cout << "\n" << "Available Balance: $" << accounts[counter].availableBalance << endl;
                    // return the available balance for the functions integer value.
                    return accounts[counter].availableBalance;
                }
                return accounts[counter].availableBalance; // return the available balance for the functions integer value.
            }
        }

        // withdraw() function lets the user withdraw the amount of money they like (equal or less than their available balance) out of the Bank.
        int withdraw() {
            // for loop used to find the account in the accounts vector by searching through it using the account number as the unique identifier of each persons account.
            for (int counter = 0; counter < accounts.size(); counter++) {
                int accountNum; // accountNum is the account number of the account.
                bool validAccount = false; // validAccount to see if account number matches with any available accounts and is set to invalid to start.
                // if-else loop to see if there is more than one account so if there is more than one account the user can select the account they want to withdraw from.
                if (accounts.size() > 1) {
                    // User asked to enter the desired account number for account they want to withdraw from.
                    cout << "\n" << "Enter the account number for the account you want to withdraw from: ";
                    cin >> accountNum;
                    // for loop to make sure the accounts checked start from one.
                    for (int counter = 1; counter < accounts.size(); counter++) {
                        // if accountNum matches with account number at the one or more index in vector than continue.
                        if (accountNum == accounts[counter].accountNumber) {
                            validAccount = true; // validAccount set to valid.
                            // User asked to enter desired amount to withdraw from selected account.
                            cout << "\n" << "Enter amount to withdraw: ";
                            cin >> accounts[counter].withdrawAmount;
                            // while loop to catch invalid withdraw amounts (<=0).
                            while (accounts[counter].withdrawAmount <= 0) {
                                cout << "Invalid withdraw amount (less or equal to zero). Please enter a valid withdraw amount: ";
                                cin >> accounts[counter].withdrawAmount;
                            }
                            /* if-else loop used to see whether the available balance is still equal to zero which in that case the start balance is
                            subtracted with amount withdrawn. If not, then the current available balance is subtracted with the amount withdrawn to make the new available balance. */
                            if (accounts[counter].availableBalance == -1) {
                                // Set availableBalance for account to starting balance.
                                accounts[counter].availableBalance = accounts[counter].startingBalance;
                                // while loop to catch invalid amount (withdraw amount larger than available balance).
                                while (accounts[counter].withdrawAmount > accounts[counter].availableBalance) {
                                    cout << "Invalid withdraw amount (withdraw amount larger than available balance). Please enter a valid withdraw amount: ";
                                    cin >> accounts[counter].withdrawAmount;
                                }
                                // Set availableBalance to availableBalance minus withdrawAmount value.
                                accounts[counter].availableBalance = accounts[counter].availableBalance - accounts[counter].withdrawAmount;
                            } else {
                                // while loop to catch invalid amount (withdraw amount larger than available balance).
                                while (accounts[counter].withdrawAmount > accounts[counter].availableBalance) {
                                    cout << "Invalid withdraw amount (withdraw amount larger than available balance). Please enter a valid withdraw amount: ";
                                    cin >> accounts[counter].withdrawAmount;
                                }
                                // Set availableBalance to availableBalance minus withdrawAmount value.
                                accounts[counter].availableBalance = accounts[counter].availableBalance - accounts[counter].withdrawAmount;
                            }
                            // Output the available balance.
                            cout << "\n" << "Available Balance: $" << accounts[counter].availableBalance << endl;
                            // return the available balance for the functions integer value.
                            return accounts[counter].availableBalance;
                        } else if (accountNum == accounts[0].accountNumber) { // else if accountNum matches with account number at the zero index in vector than continue.
                            validAccount = true; // validAccount set to valid.
                            // User asked to enter desired amount to withdraw from selected account.
                            cout << "\n" << "Enter amount to withdraw: ";
                            cin >> accounts[0].withdrawAmount;
                            // while loop to catch invalid withdraw amounts (<=0).
                            while (accounts[0].withdrawAmount <= 0) {
                                cout << "Invalid withdraw amount (less or equal to zero). Please enter a valid withdraw amount: ";
                                cin >> accounts[0].withdrawAmount;
                            }
                            /* if-else loop used to see whether the available balance is still equal to zero which in that case the start balance is
                            subtracted with amount withdrawn. If not, then the current available balance is subtracted with the amount withdrawn to make the new available balance. */
                            if (accounts[0].availableBalance == -1) {
                                // Set availableBalance for account to starting balance.
                                accounts[0].availableBalance = accounts[0].startingBalance;
                                // while loop to catch invalid amount (withdraw amount larger than available balance).
                                while (accounts[0].withdrawAmount > accounts[0].availableBalance) {
                                    cout << "Invalid withdraw amount (withdraw amount larger than available balance). Please enter a valid withdraw amount: ";
                                    cin >> accounts[0].withdrawAmount;
                                }
                                // Set availableBalance to availableBalance minus withdrawAmount value.
                                accounts[0].availableBalance = accounts[0].availableBalance - accounts[0].withdrawAmount;
                            } else {
                                // while loop to catch invalid amount (withdraw amount larger than available balance).
                                while (accounts[0].withdrawAmount > accounts[0].availableBalance) {
                                    cout << "Invalid withdraw amount (withdraw amount larger than available balance). Please enter a valid withdraw amount: ";
                                    cin >> accounts[0].withdrawAmount;
                                }
                                // Set availableBalance to availableBalance minus withdrawAmount value.
                                accounts[0].availableBalance = accounts[0].availableBalance - accounts[0].withdrawAmount;
                            }
                            // Output the available balance.
                            cout << "\n" << "Available Balance: $" << accounts[0].availableBalance << endl;
                            // return the available balance for the functions integer value.
                            return accounts[0].availableBalance;
                        }
                    }
                    // if loop used when account number doesn't match with any available account which will output with the account number being invalid and needing to try again later.
                    if (!validAccount) {
                        cout << "\n" << "Invalid account number! Please try again later." << endl;
                    }
                } else {
                    // User asked to enter desired amount to withdraw from selected account.
                    cout << "\n" << "Enter amount to withdraw: ";
                    cin >> accounts[counter].withdrawAmount;
                    // while loop to catch invalid withdraw amounts (<=0).
                    while (accounts[counter].withdrawAmount <= 0) {
                        cout << "Invalid withdraw amount (less or equal to zero). Please enter a valid withdraw amount: ";
                        cin >> accounts[counter].withdrawAmount;
                    }
                    /* if-else loop used to see whether the available balance is still equal to zero which in that case the start balance is
                    subtracted with amount withdrawn. If not, then the current available balance is subtracted with the amount withdrawn to make the new available balance. */
                    if (accounts[counter].availableBalance == -1) {
                        // Set availableBalance for account to starting balance.
                        accounts[counter].availableBalance = accounts[counter].startingBalance;
                        // while loop to catch invalid amount (withdraw amount larger than available balance).
                        while (accounts[counter].withdrawAmount > accounts[counter].availableBalance) {
                            cout << "Invalid withdraw amount (withdraw amount larger than available balance). Please enter a valid withdraw amount: ";
                            cin >> accounts[counter].withdrawAmount;
                        }
                        // Set availableBalance to availableBalance minus withdrawAmount value.
                        accounts[counter].availableBalance = accounts[counter].availableBalance - accounts[counter].withdrawAmount;
                    } else {
                        // while loop to catch invalid amount (withdraw amount larger than available balance).
                        while (accounts[counter].withdrawAmount > accounts[counter].availableBalance) {
                            cout << "Invalid withdraw amount (withdraw amount larger than available balance). Please enter a valid withdraw amount: ";
                            cin >> accounts[counter].withdrawAmount;
                        }
                        // Set availableBalance to availableBalance minus withdrawAmount value.
                        accounts[counter].availableBalance = accounts[counter].availableBalance - accounts[counter].withdrawAmount;
                    }
                    // Output the available balance.
                    cout << "\n" << "Available Balance: $" << accounts[counter].availableBalance << endl;
                    // return the available balance for the functions integer value.
                    return accounts[counter].availableBalance;
                }
                return accounts[counter].availableBalance; // return the available balance for the functions integer value.
            }
        }
};

// main() function being the driver program.
int main() {

    // Data Fields
    Bank<Account> bank; // Bank class object used to call functions from class.
    int optionSelected; // optionSelected object used to hold the users selection of an option from the menu which is numeric.

    // while loop is an infinite loop used to display program options and functions until program is exited (using option 5).
    while (1) {
        cout << "\n================= ANZ Bank =================\n" << endl;
        cout << "1. Create Account\n";
        cout << "2. Search for Account\n";
        cout << "3. Delete Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Exit Bank\n";
        cout << "\n============================================\n" << endl;

        cout << "Enter an option to select from the above menu (select by number value e.g. 1 for create account): ";
        cin >> optionSelected;

        // switch case is used to change between the menus options depending on the users selection.
        switch (optionSelected) {
            case 1:
                bank.setCustomerDetails();
                break;
            case 2:
                bank.searchForAccount();
                break;
            case 3:
                bank.deleteAccount();
                break;
            case 4:
                bank.deposit();
                break;
            case 5:
                bank.withdraw();
                break;
            case 6:
                cout << "\n" << "Thanks for attending ANZ Bank. We hope the process was smooth and looking forward to seeing you again soon." << endl;
                exit(1);
            default:
                if (optionSelected < 1 || optionSelected > 5) {
                    cout << "\nERROR: Invalid option (valid option between 1-5)" << endl;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "   - NOTE: Character entered (needs to be a number meeting the above expectation)" << endl;
                    }
                }
        }
    }
    return 0; // return 0 to end driver program.
}
