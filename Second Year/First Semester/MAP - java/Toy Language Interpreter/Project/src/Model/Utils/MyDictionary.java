package Model.Utils;

import java.util.Collection;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Map;

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
    public Collection<K> keySet(){
        return this.dictionary.keySet();
    }

    @Override
    public boolean contains(K key) {
        return dictionary.containsKey(key);
    }

    @Override
    public V get(K key) {
        return dictionary.get(key);
    }

    @Override
    public Collection<V> values(){
        return dictionary.values();
    }

    @Override
    public MyDictionary<K, V> clone() {
        MyDictionary<K, V> new_dict = new MyDictionary<>();
        for(K key : this.keySet())
            new_dict.put(key, this.get(key));
        return new_dict;
    }

    public Map<K, V> All(){return dictionary;}

    public String toString(){
        String s = "";
        for(K key : dictionary.keySet())
            s += key.toString() + "->" + dictionary.get
                    (key).toString();
        return s;
    }
}
