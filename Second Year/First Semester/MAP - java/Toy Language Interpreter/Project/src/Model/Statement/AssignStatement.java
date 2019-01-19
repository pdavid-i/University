package Model.Statement;

import Model.Exceptions.DuplicateVariableException;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public class AssignStatement implements IStatement{

    String var_name;
    IExpression var_value;

    public AssignStatement(String var_name, IExpression var_value) {
        this.var_name = var_name;
        this.var_value = var_value;
    }

    public ProgramState execute(ProgramState ps) {
        MyDictionary<String, Integer> st = ps.getSymTable();
        MyHeap<Integer> heap = ps.getHeap();
      //  if (st.contains(this.var_name))
      //      throw new DuplicateVariableException("That variable name is already used!");
        st.put(this.var_name, this.var_value.evaluate(st, heap));
        return null;
    }

    @Override
    public String toString(){
        return "Assign statement: Name " + var_name + " Value: " + var_value;
    }
}
