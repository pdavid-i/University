package Model.Expression;

//import Model.Utils.ISymTable;
import Model.Utils.MyDictionary;

public interface IExpression {
    int evaluate(MyDictionary<String, Integer> st);
    String toString();
}
