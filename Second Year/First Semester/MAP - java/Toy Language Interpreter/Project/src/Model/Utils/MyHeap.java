package Model.Utils;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class MyHeap<T> implements IHeap<T> {
    int memory=0;
    private Map<Integer,T> heap;

    public MyHeap(Map<Integer, T> heap) {
        this.heap = heap;
    }

    public MyHeap()
    {
        this.heap = new HashMap<Integer, T>();
    }
    @Override
    public int allocate(T value) {
        ++ this.memory;
        this.heap.put(this.memory, value);
        return memory;
    }

    @Override
    public T readAddr(int addr) {
        return this.heap.get(addr);
    }

    @Override
    public void writeAddr(int addr, T value) {
        this.heap.put(addr, value);
    }

    @Override
    public void deallocate(int addr) {
        this.heap.remove(addr);
    }

    public Collection<T> values(){
        return heap.values();
    }


    @Override
    public String toString() {
        String ret = "";
        boolean ok = false;
        String s = "";
        for(Integer key : heap.keySet()){

            s += key.toString();
            s += "->";
            s += heap.get(key).toString();
            s +=  "\n";
        }

        return s;
    }

    @Override
    public void setMap(Map<Integer, T> heap) {
        this.heap = heap;
    }

    @Override
    public Map<Integer, T> toMap() {
        return this.heap;
    }

    public void update(Integer address, T value) {
        heap.put(address, value);
    }
}
