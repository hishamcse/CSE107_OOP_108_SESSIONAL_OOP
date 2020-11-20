package com.Hisham;

public class Animal {

    private final String name;
    private final int age;

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
//        return name + " is a " + this.getClass().getName().split("\\.")[3] + ", aged " + age;
        return name + " is a " + this.getClass().getSimpleName() + ", aged " + age;
    }
}