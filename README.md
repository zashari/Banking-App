# First Semester Project: Banking App

### Introduction

This C program is an implementation of a basic banking system, designed as my final assignment for my first-year college course. It demonstrates a more advanced understanding of C programming, including the use of structures, file handling, dynamic memory allocation, and user interface design.

### Program Breakdown

1. **Data Structure**:
   - A structure `nasabah` is defined to hold customer information including name, phone number, account creation date, and balance.

2. **Global Functions**:
   - `add()`: Adds a new customer to the bank system.
   - `setor()`: Deposits money into a customer's account.
   - `tarik()`: Withdraws money from a customer's account.
   - `print()`: Displays all customer information.
   - `hapus()`: Deletes a customer's account.

3. **File Handling**:
   - The program uses text files (`datanasabah.txt`, `temp.txt`, and `trash.txt`) for data storage and retrieval.

4. **Main Menu**:
   - The main function presents a menu with options to add, deposit, withdraw, display, and delete accounts. 
   - User inputs are handled using a switch statement.

### Key Functionalities

1. **Adding a New Account**:
   - The `add()` function prompts the user for customer details and writes this data to `datanasabah.txt`.

2. **Depositing Money**:
   - The `setor()` function allows users to deposit money into an existing account. It modifies the account's balance and updates the file.

3. **Withdrawing Money**:
   - The `tarik()` function is similar to `setor()`, but it subtracts the specified amount from the account balance.

4. **Displaying Account Information**:
   - The `print()` function reads customer data from the file and displays it.

5. **Deleting an Account**:
   - The `hapus()` function removes a customer's data from the file.

### Improvements and Recommendations

1. **Error Handling**: Improve error handling for file operations and user inputs.
2. **Data Validation**: Implement checks to validate user inputs, such as ensuring correct data formats and preventing negative balances.
3. **Dynamic Memory Allocation**: Currently, the program uses static allocation. Implementing dynamic allocation can improve memory management.
4. **Security Measures**: Adding password protection or encryption for sensitive customer data can enhance security.
5. **Modularity**: Refactoring the code into smaller, more manageable functions can improve readability and maintainability.

### Conclusion

This program showcases a comprehensive application of C programming concepts. It demonstrates skills in structuring programs, handling files, and creating a user-friendly interface. With additional features and improvements, this program could be developed into a more robust banking system application.
