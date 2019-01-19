package Model.Expression;
import Model.Exceptions.InexistentVariableExpression;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public class VariableExpression implements IExpression {
    private String name;

    public VariableExpression(String name) {
        this.name = name;
    }

    public int evaluate(MyDictionary<String, Integer> st, MyHeap<Integer> heap) {
        if (st.contains(this.name)) {
            return st.get(this.name);
        } else {
            throw new InexistentVariableExpression("Inexistent variable");
        }
    }

    public String toString(){
        return name;
    }
}
