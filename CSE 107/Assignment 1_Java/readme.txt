Instructions
Consider a class named Account with the following information:
double balance - the balance of the account
void debit (double amount) - this method subtracts the amount from the balance
void credit (double amount) -  this method adds the amount directly to the balance
The amount provided in the debit and credit method can’t be negative. The balance of the Account can’t also be negative.

Write complete Java code for the following:

* A custom exception named InvalidAmountException that triggers when the given 
  amount is negative and shows the message ‘The given amount can’t be negative.’

* A custom exception named InvalidBalanceException that triggers when the balance 
 goes negative and shows the message ‘The account balance can’t be less than zero.’ 

* The Account class to trigger this exception when needed
* Main class with the main method.