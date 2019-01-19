package Model.Utils;

import java.util.Collection;

public interface IDictionary<K, V> {
    void put(K key, V value);
    void remove(K key);

    boolean contains(K key);
    V get(K key);
    Collection<V> values();
    public Collection<K> keySet();
    String toString();

}
