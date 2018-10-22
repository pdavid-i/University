package utils;

import model.Fish;
import model.Pets;
import model.Turtle;
import repository.Repo;

import java.util.NoSuchElementException;


public class Tester {
    public static void test_all(){
        test_model();
        test_repo();
        test_validator();
    }

    public static void test_model(){
        Pets pet = new Pets(6, "Woofy", true);
        assert pet.getAge() == 6;
        assert (pet.getName().equals("Woofy"));
        assert (pet.isMammal() == true);

        Fish fish = new Fish(2, "Wishy", false, 12.5);
        assert(fish.getAge() == 2);
        assert (fish.getName().equals("Wishy"));
        assert (fish.isMammal() == false);
        assert (fish.getSwimSpeed() == 12.5);

        Turtle turtle = new Turtle(56, "Turtwig", false, 22.5);
        assert(turtle.getAge() == 56);
        assert (turtle.getName().equals("Turtwig"));
        assert (turtle.isMammal() == false);
        assert (turtle.getShellSize() == 22.5);
    }

    public static void test_repo(){
        Repo repo = new Repo(2);
        assert repo.getSize() == 0;
        assert repo.getCapacity() == 2;
        repo.add(new Turtle(12,"jobbles", false, 10));
        assert repo.getSize() == 1;
        repo.add(new Fish(8,"bobbles", false, 11));
        assert repo.getSize() == 2;
        repo.add(new Fish(0.7,"trobbles", false, 11));
        assert repo.getCapacity() == 4;
        assert repo.getSize() == 3;
        repo.delete("jobbles");
        assert repo.getSize() == 2;
        try{ repo.delete("inexistent pet"); }
        catch (NoSuchElementException e){}
        assert repo.getSize() == 2;
    }

    public static void test_validator(){
        assert Validator.validatePetChoice(1) == true;
        assert Validator.validatePetChoice(2) == true;
        assert Validator.validatePetChoice(3) == false;
        assert Validator.validatePetChoice(0) == false;

        assert Validator.validateMenuChoice(0) == true;
        assert Validator.validateMenuChoice(1) == true;
        assert Validator.validateMenuChoice(2) == true;
        assert Validator.validateMenuChoice(3) == true;
        assert Validator.validateMenuChoice(4) == true;
        assert Validator.validateMenuChoice(-1) == false;
        assert Validator.validateMenuChoice(5) == false;

        assert Validator.validatePositiveDouble(12) == true;
        assert Validator.validatePositiveDouble(-12) == false;
        assert Validator.validatePositiveDouble(67.23) == true;
        assert Validator.validatePositiveDouble(32132) == false;
    }

}
