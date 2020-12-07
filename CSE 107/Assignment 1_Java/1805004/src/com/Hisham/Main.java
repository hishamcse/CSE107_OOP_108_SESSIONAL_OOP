package com.Hisham;

import static com.Hisham.ColorCode.ANSI_RESET;

/**
 * Assignment on CSE 107
 * BY:
 * Syed Jarullah Hisham
 * Roll: 1805004
 **/

public class Main {

    public static void main(String[] args) {
        Account hisham = new Account(290.67);
        System.out.println("Before transaction: " + hisham.getBalance());

        System.out.print(ANSI_RESET + "After credit 100: ");
        try {
            hisham.credit(100);
            System.out.println(hisham.getBalance());
        } catch (InvalidAmountException e) {
            System.out.println("\n" + e.toString());
        }

        System.out.print(ANSI_RESET + "After credit -100: ");
        try {
            hisham.credit(-100);
            System.out.println(hisham.getBalance());
        } catch (InvalidAmountException e) {
            System.out.println("\n" + e.toString());
        }

        System.out.print(ANSI_RESET + "After debit 100: ");
        try {
            hisham.debit(100);
            System.out.println(hisham.getBalance());
        } catch (InvalidAmountException | InvalidBalanceException e) {
            System.out.println("\n" + e.toString());
        }

        System.out.print(ANSI_RESET + "After debit -100: ");
        try {
            hisham.debit(-100);
            System.out.println(hisham.getBalance());
        } catch (InvalidAmountException | InvalidBalanceException e) {
            System.out.println("\n" + e.toString());
        }

        System.out.print(ANSI_RESET + "After debit 500: ");
        try {
            hisham.debit(500);
            System.out.println(hisham.getBalance());
        } catch (InvalidAmountException | InvalidBalanceException e) {
            System.out.println("\n" + e.toString());
        }
    }
}