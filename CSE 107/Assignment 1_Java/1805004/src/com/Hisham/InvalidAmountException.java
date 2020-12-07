package com.Hisham;

import static com.Hisham.ColorCode.ANSI_RED;

public class InvalidAmountException extends Exception {

    @Override
    public String toString() {
        return ANSI_RED + "InvalidAmountException: The given amount can't be negative";
    }
}