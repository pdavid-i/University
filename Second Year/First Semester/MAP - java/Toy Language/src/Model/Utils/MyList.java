package Model.Utils;

import java.util.ArrayList;

public class MyList<T> implements IList<T> {
    private ArrayList<T> elems;

    public MyList() {
        this.elems = new ArrayList<>();
    }

    @Override
    public void add(T elem) {
        this.elems.add(elem);
    }

    @Override
    public int size() {
        return this.elems.size();
    }

    @Override
    public void remove(T elem) {
        this.elems.remove(elem);
    }

    @Override
    public String toString() {
        String s = "";
        for(T elem : this.elems)
            s += elem.toString() + " ";
        return s;
    }

    public T get(int pos) {
        return elems.get(pos);
    }
}
