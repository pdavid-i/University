package view;
import controller.Controller;
import model.Fish;
import model.Pets;
import model.Turtle;
import repository.IRepo;
import utils.Validator;

import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class UI {
    Controller control;

    public Controller getControl() {return control;}

    public UI(){
        this(new Controller());
    }

    public UI(Controller control) {
        this.control = control;
    }

    public void run(){
        initRepo(this.control.getRepo());
        while (true) {
            showMenu();
            int option = getMenuChoice();
            switch (option) {
                case 1:
                    add();
                    break;
                case 2:
                    delete();
                    break;
                case 3:
                    printList(control.getRepo().getAll(), control.getRepo().getSize());
                    break;
                case 4:
                    printList(control.getOlder(), control.getOlder().length);
                    break;
                case 0:
                    return;
            }
        }
    }

    public static int getPetChoice()
    {
        Scanner reader = new Scanner(System.in);
        System.out.println("Enter your choice: ");
        int n = reader.nextInt();
        if (!Validator.validatePetChoice(n))
        {
            System.out.println("Invalid choice! Try again! ");
            return getPetChoice();
        }
        return n;
    }

    public static boolean getTurtleness(){
        System.out.println("What kind of pet is it?");
        System.out.println("1. Turtle");
        System.out.println("2. Fish");
        int choice = getPetChoice();
        if (!Validator.validatePetChoice(choice))
        {
            System.out.println("Invalid value! Must be 1 or 2!");
            return getTurtleness();
        }
        return (1 == choice);
    }

    public static double getAge(){
        System.out.println("How old is your pet? (in years, non integers are accepted)");
        Scanner reader = new Scanner(System.in);
        System.out.print("Enter age: ");
        double age = reader.nextDouble();
        if (!Validator.validatePositiveDouble(age))
        {
            System.out.println("Invalid value! Must be between 0 and 99!");
            return getAge();
        }
        return age;
    }

    public static String getName(){
        Scanner reader = new Scanner(System.in);
        System.out.print("Enter name: ");
        String name = reader.next();
        return name;
    }

    public static void showMenu(){
        System.out.println("_______________________");
        System.out.println("0. Exit");
        System.out.println("1. Add a pet");
        System.out.println("2. Release a pet");
        System.out.println("3. See all pets");
        System.out.println("4. See all pets older than 1 year");
    }

    public static double getTrait(boolean isTurtle)
    {
        if(isTurtle)
            System.out.print("How big is your turtle? Enter shell size: ");
        else
            System.out.print("How fast is your goldfish? Enter speed: ");
        Scanner reader = new Scanner(System.in);
        double trait = reader.nextDouble();
        if (!Validator.validatePositiveDouble(trait))
        {
            System.out.println("Invalid value! Must be between 0 and 99!");
            return getTrait(isTurtle);
        }
        return trait;
    }

    public static int getMenuChoice() {
        System.out.print("Enter your choice: ");
        Scanner reader = new Scanner(System.in);
        int n;
        try {
             n = reader.nextInt();
        }
        catch (InputMismatchException e){
            System.out.println("Invalid input! Try again!");
            return getMenuChoice();
        }
            if (!Validator.validateMenuChoice(n))
        {
            System.out.println("Invalid choice! Try again!");
            return getMenuChoice();
        }
        return n;
    }

    public void add() {
        try {
            double age = getAge();
            String name = getName();
            boolean isTurtle = getTurtleness();
            double trait = getTrait(isTurtle);
            if (isTurtle) {
                Turtle pet = new Turtle(age, name, false, trait);
                this.control.add(pet);
            } else {
                Fish pet = new Fish(age, name, false, trait);
                this.control.add(pet);
            }
        }
        catch (RuntimeException e){
            System.out.println(e.toString());
            System.out.println("Operation was not executed!");
        }
    }

    public void delete(){
       try {
           String name = getName();
           this.control.delete(name);
       }
       catch (NoSuchElementException e){
           System.out.println(e.toString());
           System.out.println("Operation was not executed!");
       }
    }

    public void printList(Pets[] list, int size){
        for(int i=0;i<size;i++)
            System.out.println(list[i].string());
    }

    public void initRepo(IRepo rep){
            rep.add(new Fish(1.1, "first", false, 11));
            rep.add(new Fish(2.5, "second", false, 12));
            rep.add(new Turtle(3.12, "third", false, 13));
            rep.add(new Turtle(0.76, "fourth", false, 14));
            rep.add(new Fish(0.94, "fifth", false, 15));
            rep.add(new Turtle(0.65, "sixth", false, 16));
            rep.add(new Turtle(1.85, "seventh", false, 17));
            rep.add(new Fish(2.12, "eight", false, 18));
            rep.add(new Fish(3.03, "ninth", false, 19));
    }
}
