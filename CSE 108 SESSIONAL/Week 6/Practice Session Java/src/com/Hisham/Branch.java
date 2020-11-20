package com.Hisham;

public class Branch {

    private final int id;
    private final String name;
    private final Account[] accounts;
    private int accountCount;
    private static int branchCount = 0;
    private static final Branch[] branches = new Branch[20];
    // add your code here
    // there can be at most 20 branches

    // you are not allowed to write any other constructor
    public Branch(int id, String name) {
        this.id = id;
        this.name = name;
        this.accounts = new Account[10];
        // add your code here
        this.accountCount = 0;
        branches[branchCount++] = this;
    }

    public void addAccount(Account a) {
        this.accounts[accountCount++] = a;
    }

    // add your code here
    public double getBranchBalance() {
        double total_balance = 0.0;
        for (int i = 0; i < this.accountCount; i++) {
            total_balance += accounts[i].getBalance();
        }
        return total_balance;
    }

    public Account getMinBalanceAccount() {
        double min = -1.0;
        Account account = null;
        for (int i = 0; i < this.accountCount; i++) {
            if (min == -1.0 || min < this.accounts[i].getBalance()) {
                min = this.accounts[i].getBalance();
                account = this.accounts[i];
            }
        }
        return account;
    }

    public static void transferBalance(Account from, Account to, double amount) {
        from.setBalance(from.getBalance() - amount);
        to.setBalance(to.getBalance() + amount);
    }

    public static void printAllBranchesInfo() {
        for (int i = 0; i < branchCount; i++) {
            Branch branch = branches[i];
            System.out.println("Branch Id: " + branch.id + " Branch Name: " + branch.name);
            for (int j = 0; j < branch.accountCount; j++) {
                Account account = branch.accounts[j];
                System.out.println("Account Number: " + account.getNumber() + " Customer Name: " + account.getCustomer()
                        + " Balance: " + account.getBalance());
            }
        }
    }
}
