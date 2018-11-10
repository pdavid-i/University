package Model.Expression;
import Model.Utils.MyDictionary;

public class VariableExpression implements IExpression {
    private String name;

    public VariableExpression(String name) {
        this.name = name;
    }

    public int evaluate(MyDictionary<String, Integer> st) {
        if (st.contains(this.name)) {
            return st.get(this.name);
        } else {
            throw new RuntimeException("Inexistent variable");
        }
    }

    public String toString(){
        return name;
    }
}
