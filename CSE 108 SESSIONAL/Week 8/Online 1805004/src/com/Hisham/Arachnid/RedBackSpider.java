package com.Hisham.Arachnid;

import com.Hisham.Venomous;

public class RedBackSpider extends Arachnid implements Venomous {

    public RedBackSpider(String name, int age) {
        super(name, age);
    }

    @Override
    public boolean isLethalToAdultHumans() {
        return false;
    }
}