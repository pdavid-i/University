package controller;

import model.Pets;
import repository.IRepo;
import repository.Repo;

public class Controller {
    IRepo repo;

    public Controller(){
        this(new Repo());
    }

    public Controller(Repo repo) {
        this.repo = repo;
    }

    public void add(Pets pet){
        this.repo.add(pet);
    }

    public void delete(String name){
        this.repo.delete(name);
    }

    public IRepo getRepo(){
        return this.repo;
    }

    public Pets[] getOlder(){
        return this.repo.getOlder();
    }
}
