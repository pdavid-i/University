package repository;

import model.Pets;

public interface IRepo {

    int getCapacity();
    int getSize();
    boolean isFull();
    void add(Pets p);
    void resize();
    void delete(String name);
    int find(String name_p);
    Pets[] getOlder();
    Pets[] getAll();

}
