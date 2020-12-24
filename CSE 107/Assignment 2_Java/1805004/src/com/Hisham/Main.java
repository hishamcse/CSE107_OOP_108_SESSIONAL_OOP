package com.Hisham;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

/**
 * Created By:
 * Syed Jarullah Hisham
 * Roll : 1805004
 * CSE '18 Section A
 **/

public class Main {

    public static void main(String[] args) {
        List<Product> myProducts = new ArrayList<>();
        int charValue = 65;
        Random random = new Random();

        /*----------------------- Adding Products -----------------------*/
        for (int i = 0; i < 5; i++) {
            myProducts.add(new Product(String.valueOf((char) (charValue)), 10000 * random.nextDouble()));
            charValue++;
        }

        /*---------------- Adding Product at specific index -------------*/
        myProducts.add(1, new Product("PDummy", 1000));

        /*--------------- Sorting myProducts according to price --------*/
        Collections.sort(myProducts);

        /*--------------------- Print All Products ---------------------*/
        myProducts.forEach(System.out::println);
    }
}