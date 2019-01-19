package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

import java.io.IOException;

public class New implements IStatement {
    private String variable;
    private IExpression expression;
    public New(String variable, IExpression expression){
        this.variable = variable;
        this.expression = expression;
    }
    @Override
    public ProgramState execute(ProgramState programState) throws IOException {
        MyDictionary<String, Integer> symTable = programState.getSymTable();
        MyHeap<Integer> heap = programState.getHeap();
        int value = expression.evaluate(symTable, heap);
        int index = heap.allocate(value);
        symTable.put(variable, index);
        return null;
    }

    public String toString(){
        String s = "";
        s += "new ( " + variable + "," + expression.toString() + ")";
        return s;
    }
}
