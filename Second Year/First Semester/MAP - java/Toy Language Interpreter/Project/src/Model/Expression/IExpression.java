package Model.Expression;

//import Model.Utils.ISymTable;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public interface IExpression {
    int evaluate(MyDictionary<String, Integer> st, MyHeap<Integer> heap);
    String toString();
}
