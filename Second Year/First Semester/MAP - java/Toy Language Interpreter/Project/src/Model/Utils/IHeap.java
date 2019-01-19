package Model.Utils;

import java.io.Serializable;
import java.util.Map;

public interface IHeap <T> extends Serializable {
        int allocate(T value);
        T readAddr(int addr);
        void writeAddr(int addr, T value);
        void deallocate(int addr);
        void update(Integer address, T value);


        void setMap(Map<Integer, T> map);
        Map<Integer, T> toMap();
}
