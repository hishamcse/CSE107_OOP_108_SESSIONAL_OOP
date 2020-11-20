package com.Hisham;

public class Account {

    private final int number;
    private final String customer;
    private double balance;
    // you are not allowed to add any more class variables here

    // you are not allowed to write any other constructor
    public Account(int number, String customer, double balance) {
        this.number = number;
        this.customer = customer;
        this.balance = balance;
    }

    // add your code here
    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String getCustomer() {
        return customer;
    }

    public double getBalance() {
        return balance;
    }

    public int getNumber() {
        return number;
    }
}
