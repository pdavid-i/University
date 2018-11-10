package Model.Utils;

import java.util.HashMap;

public class MyDictionary<K, V> implements IDictionary<K,
        V       > {

    private HashMap<K, V> dictionary;

    public MyDictionary(){
        dictionary =  new HashMap<K,V>();
    }

    @Override
    public void put(K key, V value) {
        dictionary.put(key, value);
    }

    @Override
    public void remove(K key) {
        dictionary.remove(key);
    }

    @Override
    public boolean contains(K key) {
        return dictionary.containsKey(key);
    }

    @Override
    public V get(K key) {
        return dictionary.get(key);
    }

    public String toString(){
        String s = "";
        for(K key : dictionary.keySet())
            s += key.toString() + "->" + dictionary.get
                    (key).toString();
        return s;
    }
}
