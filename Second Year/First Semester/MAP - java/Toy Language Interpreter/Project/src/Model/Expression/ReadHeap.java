package Model.Expression;


import Model.Exceptions.InexistentVariableExpression;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public class ReadHeap implements IExpression  {
    String id;
    public ReadHeap(String id) {
        this.id = id;
    }

    @Override
    public int evaluate(MyDictionary<String, Integer> symTable, MyHeap<Integer> heap) throws InexistentVariableExpression, ArithmeticException, NullPointerException {
        Integer var_val = symTable.get(this.id);
        if(var_val == null)
            throw new InexistentVariableExpression("Unknown variable exception\nError at ReadHeapExp: " + toString());
        Integer heap_val = heap.readAddr(var_val);
        if(heap_val == null)
            throw new NullPointerException("There is no such memory address\nError at ReadHeapExp: " + toString());
        return heap_val;
    }

    @Override
    public String toString() {
        return "readHeapExp(" + id + ")";
    }
}