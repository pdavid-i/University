package model;

public class Fish extends Pets {
    double swimSpeed;

    public Fish(){
        this(0.5, "Blobby", false, 10.5);
    }

    public Fish(double age, String name, boolean mammal, double swimSpeed) {
        super(age, name, mammal);
        this.swimSpeed = swimSpeed;
    }

    public double getSwimSpeed() {
        return swimSpeed;
    }

    @Override
    public String string()
    {
        return getName() + " fish, age: " + getAge() + " speed: " + swimSpeed;
    }
}
