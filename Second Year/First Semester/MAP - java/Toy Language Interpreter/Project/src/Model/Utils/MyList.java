package Model.Utils;

import java.util.ArrayList;
import java.util.List;

public class MyList<T> implements IList<T> {
    private List<T> elems;

    public MyList() { this.elems = new ArrayList<>(); }

    public MyList(List<T> list) {
        this.elems = new ArrayList<>();
        for (T elem: list){
            elems.add(elem);
        }
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

    public List<T> toList(){
        return elems;
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
