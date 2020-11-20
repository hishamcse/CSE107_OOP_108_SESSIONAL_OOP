package com.Hisham;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;

public class CarWareHouse {

    private static final String fileName = "cars.txt";

    private final List<Car> allCars = new ArrayList<>();
    private final List<String> regNumbers = new ArrayList<>();

    public void read_From_File() {
        try {
            String line;
            BufferedReader br = new BufferedReader(new FileReader(fileName));
            while (true) {
                line = br.readLine();
                if (line == null) break;
                addCar(line);
            }
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void write_To_File() {
        StringBuilder sb = new StringBuilder();
        for (Car car : allCars) {
            sb.append(car.toString()).append("\n");
        }
        sb.deleteCharAt(sb.length() - 1);
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter(fileName));
            bw.write(sb.toString());
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void addCar(String str) {
        String[] splits = str.split(",");
        String reg = splits[0];
        if (regNumbers.contains(reg.toUpperCase())) {
            System.err.println("Error!!This registration number has already been used");
            return;
        }
        regNumbers.add(reg.toUpperCase());
        int year = Integer.parseInt(splits[1]);
        String c1 = splits[2];
        String c2 = splits[3];
        String c3 = splits[4];
        String maker = splits[5];
        String model = splits[6];
        int price = Integer.parseInt(splits[7]);
        Car car = new Car(reg, year, c1, c2, c3, maker, model, price);
        allCars.add(car);
    }

    public void deleteCar(String reg) {
        Car car = Car_By_Reg(reg, true);
        if (car == null) {
            System.err.println("No such car with this registration number!");
            return;
        }
        System.out.println("Deletion Successful");
        System.out.println();
        allCars.remove(car);
        regNumbers.remove(reg.toUpperCase());
    }

    public Car Car_By_Reg(String regNo, boolean should_return) {
        if (!regNumbers.contains(regNo.toUpperCase())) {
            if (!should_return) {
                System.err.println("No such car with this registration number!");
            }
            return null;
        }
        for (Car car : allCars) {
            if (car.getRegNo().equalsIgnoreCase(regNo)) {
                if (should_return) {
                    return car;
                } else {
                    System.out.print("Car details: ");
                    System.out.println(car.details());
                    break;
                }
            }
        }
        System.out.println();
        return null;
    }

    public void Cars_By_MakeAndModel(String maker, String model) {
        List<Car> requiredCars = new ArrayList<>();
        for (Car car : allCars) {
            if (car.getCarMake().equalsIgnoreCase(maker)) {
                if (car.getCarModel().equalsIgnoreCase(model) || model.equalsIgnoreCase("any")) {
                    requiredCars.add(car);
                }
            }
        }
        show_CarDetailsList(requiredCars);
    }

    public void show_CarDetailsList(List<Car> cars) {
        if (cars.isEmpty()) {
            System.err.println("No such car with this Car Make and Car Model!");
            return;
        }
        System.out.println("Cars with this Car Make and Car Model");
        for (Car car : cars) {
            System.out.println(car.details());
        }
        System.out.println();
    }
}