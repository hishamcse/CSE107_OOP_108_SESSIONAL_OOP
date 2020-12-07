package com.Hisham;

public class Account {

    private double balance;

    public Account(double balance) {
        this.balance = balance;
    }

    public double getBalance() {
        return balance;
    }

    public void debit(double amount) throws InvalidAmountException, InvalidBalanceException {
        if (amount < 0) {
            throw new InvalidAmountException();
        }
        if (this.balance - amount < 0) {
            throw new InvalidBalanceException();
        }
        this.balance -= amount;
    }

    public void credit(double amount) throws InvalidAmountException {
        if (amount < 0) {
            throw new InvalidAmountException();
        }
        this.balance += amount;
    }
}