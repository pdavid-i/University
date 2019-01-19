package Model.Expression;

import Model.Exceptions.ADT_Exception;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public class BooleanExpression implements IExpression {
    IExpression left;
    IExpression right;
    String operator;

    public BooleanExpression(IExpression left, IExpression right, String operator) {
        this.left = left;
        this.right = right;
        this.operator = operator;
    }

    public int evaluate(MyDictionary<String, Integer> st, MyHeap<Integer> heap) {
        switch (operator) {
            case "==":
                return left.evaluate(st, heap) == right.evaluate(st, heap) ? 1 : 0;
            case "!=":
                return left.evaluate(st, heap) == right.evaluate(st, heap) ? 0 : 1;
            case ">":
                return left.evaluate(st, heap) > right.evaluate(st, heap) ? 1 : 0;
            case "<":
                return left.evaluate(st, heap) < right.evaluate(st, heap) ? 1 : 0;
            case ">=":
                return left.evaluate(st, heap) >= right.evaluate(st, heap) ? 1 : 0;
            case "<=":
                return left.evaluate(st, heap) <= right.evaluate(st, heap) ? 1 : 0;
            default:
                throw new ADT_Exception("Invalid operator!");
        }
    }
    public String toString()
    {
        return " ("+this.left.toString() + operator + this.right.toString()+") ";
    }
}