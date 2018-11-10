package Model.Expression;

import Model.Utils.MyDictionary;

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
    public int evaluate(MyDictionary<String, Integer> st){
        return this.value;
    }
}
