package Model.Expression;

import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public class ConstantExpression implements IExpression {
    int value;

    public ConstantExpression(int value){
        this.value = value;
    }

    @Override
    public String toString(){
        return String.valueOf(value);
    }

    @Override
    public int evaluate(MyDictionary<String, Integer> st, MyHeap<Integer> heap){
        return this.value;
    }
}
