package Model.Statement;

import Model.Exceptions.ADT_Exception;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Statement.IStatement;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;
import Model.Utils.MyStack;

import Model.Utils.Pair;
import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements IStatement {
    private IExpression expressionFileId;
    private String variableName;

    public ReadFile(IExpression expressionFileId, String variableName) {
        this.expressionFileId = expressionFileId;
        this.variableName = variableName;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws IOException  {
        MyDictionary<String, Integer> symTable = programState.getSymTable();
        MyHeap<Integer> heap = programState.getHeap();
        System.out.println("nigga");
        int x = expressionFileId.evaluate(symTable, heap);
        System.out.println("bigga");
        MyStack<IStatement> exeStack = programState.getExeStack();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable = programState.getFileTable();
        BufferedReader reader = fileTable.get(x).getSecond();
        if(reader == null)
            throw new ADT_Exception("No such file descriptor");
        String line = reader.readLine();
        System.out.println(line);
        int val;
        if(line == null) {
            val = 0;
        }
        else {
            val = Integer.parseInt(line);
        }
        symTable.put(variableName, val);
        return null;
    }

    @Override
    public String toString() {
        return "ReadFile Statement, variable: " + this.variableName;
    }
}