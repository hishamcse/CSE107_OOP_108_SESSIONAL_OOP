package com.Hisham.Mammal;

import com.Hisham.Animal;

public abstract class Mammal extends Animal {

    public Mammal(String name, int age) {
        super(name, age);
    }

    public void printBloodType() {
        System.out.print(", Warm-Blooded!");
    }
}