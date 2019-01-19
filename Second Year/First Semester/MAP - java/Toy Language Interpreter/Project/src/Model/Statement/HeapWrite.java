package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

import java.io.IOException;

public class HeapWrite implements IStatement {
    private String variableName;
    private IExpression expression;

    public HeapWrite(String variableName, IExpression expression) {
        this.variableName = variableName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws IOException {
        MyDictionary<String, Integer> symTable = programState.getSymTable();
        MyHeap<Integer> heap = programState.getHeap();
        int address = symTable.get(variableName);
        int value  = expression.evaluate(symTable, heap);
        heap.update(address, value);
        return null;
    }

    @Override
    public String toString(){
        String s = "";
        s += "heapWrite ( " + variableName + ", " + expression.toString() + " ) ";
        return s;
    }
}
