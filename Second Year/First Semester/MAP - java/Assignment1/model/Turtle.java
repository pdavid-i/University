package model;

public class Turtle extends Pets {
    double shellSize;

    public Turtle(){
        this(2, "Turtwig", false, 10.0);
    }

    public Turtle(double age, String name, boolean mammal, double shellSize) {
        super(age, name, mammal);
        this.shellSize = shellSize;
    }

    @Override
    public String string()
    {
        return getName() + " turtle, age: " + getAge() + " shellSize: " + shellSize;
    }

    public double getShellSize() {
        return shellSize;
    }
}
