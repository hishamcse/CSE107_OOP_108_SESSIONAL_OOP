package com.Hisham;

import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);
    private static final CarWareHouse wareHouse = new CarWareHouse();

    public static void main(String[] args) {
        wareHouse.read_From_File();
        String mainMenu = create_Main_Menu();
        String subMenu = create_Sub_Menu();
        boolean exit = false;
        int choice;

        while (!exit) {
            System.out.println(mainMenu);
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    search_Car(subMenu);
                    break;
                case 2:
                    addCar_To_WareHouse();
                    break;
                case 3:
                    System.out.println("Delete Car Option Activated");
                    System.out.println("Enter Registration Number: ");
                    String reg = scanner.next();
                    wareHouse.deleteCar(reg);
                    break;
                case 4:
                    exit = true;
                    wareHouse.write_To_File();
                    break;
                default:
                    System.err.println("Please Enter a Valid Main Menu Option");
                    break;
            }
        }
    }

    private static String create_Main_Menu() {
        return "Main Menu:" + "\n" +
                "(1). Search Cars" + "\n" +
                "(2). Add Car" + "\n" +
                "(3). Delete Car" + "\n" +
                "(4). Exit System" + "\n" + "\n" +
                "Choose any one option above: ";
    }

    private static String create_Sub_Menu() {
        return "Car Searching Options:" + "\n" +
                "(1). By Registration Number" + "\n" +
                "(2). By Car Make and Car Model" + "\n" +
                "(3). Back to Main Menu" + "\n" + "\n" +
                "Choose any one searching option above: ";
    }

    private static void search_Car(String subMenu) {
        System.out.println("Searching Option Activated");
        boolean exit = false;
        int choice;

        while (!exit) {
            System.out.println(subMenu);
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Enter a Registration Number:");
                    String reg = scanner.next();
                    wareHouse.Car_By_Reg(reg, false);
                    break;
                case 2:
                    System.out.println("Enter Car Make: ");
                    String maker = scanner.next();
                    System.out.println("Enter Car Model: ");
                    String model = scanner.next();
                    wareHouse.Cars_By_MakeAndModel(maker, model);
                    break;
                case 3:
                    exit = true;
                    break;
                default:
                    System.err.println("Please enter a valid searching option");
                    break;
            }
        }
    }

    private static void addCar_To_WareHouse() {
        System.out.println("Add Car Option Activated");

        StringBuilder sb = new StringBuilder();
        System.out.println("Enter Registration No: ");
        String s = scanner.next();
        if (wareHouse.Car_By_Reg(s, true) != null) {
            System.err.println("Error!!This registration number has already been used");
            return;
        }
        sb.append(s).append(",");
        System.out.println("Enter Year of Production: ");
        s=scanner.next();
        try {
            Integer.parseInt(s);
        }catch (NumberFormatException e){
            System.err.println("Please enter a valid Integer for Year");
            return;
        }
        sb.append(s).append(",");
        scanner.nextLine();
        System.out.println("Enter Colour1: ");
        sb.append(scanner.nextLine()).append(",");
        System.out.println("Enter Colour2: ");
        sb.append(scanner.nextLine()).append(",");
        System.out.println("Enter Colour3: ");
        sb.append(scanner.nextLine()).append(",");
        System.out.println("Enter Car Make: ");
        sb.append(scanner.next()).append(",");
        System.out.println("Enter Car Model: ");
        sb.append(scanner.next()).append(",");
        System.out.println("Enter Price:");
        s=scanner.next();
        try {
            Integer.parseInt(s);
        }catch (NumberFormatException e){
            System.err.println("Please enter a valid Integer for Year");
            return;
        }
        sb.append(s);

        wareHouse.addCar(sb.toString());
    }
}