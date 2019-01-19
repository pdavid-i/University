package Model.Expression;

import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public class ArithmeticExpression implements IExpression{
    IExpression left ;
    IExpression right;
    char operator;

    public ArithmeticExpression(IExpression left, IExpression right, char operator) {
        this.left = left;
        this.right = right;
        this.operator = operator;
    }

    @Override
    public int evaluate(MyDictionary<String, Integer> st, MyHeap<Integer> heap) {
        int leftRes = left.evaluate(st, heap);
        int rightRes = right.evaluate(st, heap);
        switch (operator) {
            case '+':
                return leftRes + rightRes;
            //break;

            case '-':
                return leftRes - rightRes;
            //break;

            case '*':
                return leftRes * rightRes;
            //break;

            case '/':
                if (rightRes == 0) {
                    // throw exception
                }
                return leftRes / rightRes;
            //break;
            default:
                throw new RuntimeException("invalid");
        }
    }
        public String toString() {
            String ret = this.left.toString();
            if(operator == '+')
                ret += " + ";
            else if(operator == '-')
                ret += " - ";
            else if(operator == '*')
                ret += " * ";
            else if(operator == '/')
                ret += " / ";
            ret += this.right.toString();
            return ret;
    }
}
