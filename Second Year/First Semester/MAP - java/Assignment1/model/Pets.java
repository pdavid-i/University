package model;

public class Pets {
    double age;
    String name;
    boolean mammal;

    public Pets(){
        this(0.5, "Goldy", false);
    }

    public Pets(double age, String name, boolean mammal) {
        this.age = age;
        this.name = name;
        this.mammal = mammal;
    }

    public boolean shareName(String name_p) {
        return (this.name.equals(name_p));
    }

    public String string() {
        return "Pet: "+name+", age: " + age;
    }

    public double getAge() {
        return age;
    }

    public String getName() {
        return name;
    }

    public boolean isMammal() {
        return mammal;
    }
}
