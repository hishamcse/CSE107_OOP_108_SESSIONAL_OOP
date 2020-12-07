package com.Hisham;

import static com.Hisham.ColorCode.ANSI_BLUE;

public class InvalidBalanceException extends Exception {

    @Override
    public String toString() {
        return ANSI_BLUE + "InvalidBalanceException: The account balance can't be less than zero";
    }
}