package utils;

public class Validator {
    public Validator(){};

    public static boolean validateMenuChoice(int choice){
        return (0<=choice && choice<=4);
    }

    public static boolean validatePositiveDouble(double val){
        //the value should be smaller than 99 because it is about a pet's age
        return (0<= val && val <= 99);
    }

    public static boolean validatePetChoice(int val){
        return (val == 1 || val == 2);
    }

}
