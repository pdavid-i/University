package repository;

import model.Pets;
import java.util.NoSuchElementException;

public class Repo implements IRepo {

    Pets[] list;
    int size;
    int capacity;

    public Repo(Pets[] list, int size) {
        this(list, size, list.length);
    }

    public Repo(Pets[] list, int size, int capacity ) {
        this.list = list;
        this.size = size;
        this.capacity = capacity;
    }

    public Repo(int capacity){
        this(new Pets[capacity], 0, capacity);
    }

    public Repo(){
        this(new Pets[100], 0, 100);
    }

    @Override
    public int getCapacity() { return capacity;}

    @Override
    public int getSize() {
        return size;
    }

    @Override
    public boolean isFull(){
        return (capacity == size);
    }

    @Override
    public void add(Pets p){
        //tries to add a pet to the repository
        //throws RuntimeException if there already is a pet with that name
        if (isFull())   //if the repository is full, we allocate more space
        {
            resize();
        }
        if (find(p.getName()) != -1)
            throw new RuntimeException("There is already a pet with that name!");
        list[size++] = p;   //increment the size and store the element
    }

    @Override
    public void resize(){
        //doubles the capacity of the array
        Pets[] larger = new Pets[2*capacity];
        System.arraycopy( list, 0, larger, 0, list.length );
        list = larger;
        capacity = 2* capacity;
    }

    @Override
    public void delete(String name){
        //removes a pet from the repository
        //throws NoSuchElementException if there is no pet with the name given
        int pos = find(name);
        if (pos == -1)
            throw new NoSuchElementException("There is no pet named " + name + "!");
        for (int i=pos; i<size-1; i++)
        {
            list[i]=list[i+1];
        }
        size--;
    }

    @Override
    public int find(String name_p){
        //searches for an element with a given name in the repository
        // returns:  the position of the element - If the element is found
        //        :  -1 - If the element is not in the repository
        for(int i = 0; i<size; i++)
        {
            if (list[i].shareName(name_p))
                return i;
        }
        return -1;
    }

    @Override
    public Pets[] getOlder(){
        //returns an array of all the pets which are older than one
        Pets[] older = new Pets[100];
        Pets[] all = this.getAll();
        int count_older = 0;
        for (int i=0; i<this.getSize(); i++)
        {
            if (all[i].getAge() > 1)
            {
                older[count_older++] = all[i];
            }
        }
        return new Repo(older, count_older).getAll();
    }

    public Pets[] getAll()
    {
        return list;
    }
}
