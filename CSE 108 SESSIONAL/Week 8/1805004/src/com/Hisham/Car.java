package com.Hisham;

public class Car {

    private final String regNo;
    private final int year;
    private final String color1, color2, color3;
    private final String carMake;
    private final String carModel;
    private final int price;

    public Car(String regNo, int year, String color1, String color2, String color3, String carMake, String carModel, int price) {
        this.regNo = regNo;
        this.year = year;
        this.color1 = color1;
        this.color2 = color2;
        this.color3 = color3;
        this.carMake = carMake;
        this.carModel = carModel;
        this.price = price;
    }

    public String getRegNo() {
        return regNo;
    }

    public String getCarMake() {
        return carMake;
    }

    public String getCarModel() {
        return carModel;
    }

    public String details(){
        return "Registration No:'"+regNo+"' Year:"+year+" Color1:'"+color1+"' Color2:'"+color2+"' Color3:'"+color3+
                "' Car Make:'"+carMake+"' Model:'"+carModel+"' Price:"+price;
    }

    @Override
    public String toString() {
        return regNo + ',' + year + ',' + color1 + ',' + color2 + ',' + color3 + ',' + carMake + ',' + carModel + ',' + price;
    }
}