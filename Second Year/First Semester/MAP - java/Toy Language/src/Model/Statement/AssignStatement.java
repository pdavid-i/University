package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.MyDictionary;

public class AssignStatement implements IStatement{

    String var_name;
    IExpression var_value;

    public AssignStatement(String var_name, IExpression var_value) {
        this.var_name = var_name;
        this.var_value = var_value;
    }

    public ProgramState execute(ProgramState ps) {
        MyDictionary<String, Integer> st = ps.getSymTable();
        st.put(this.var_name, this.var_value.evaluate(st));
        return ps;
    }

    @Override
    public String toString(){
        return "Assign statement: Name " + var_name + " Value: " + var_value;
    }
}
