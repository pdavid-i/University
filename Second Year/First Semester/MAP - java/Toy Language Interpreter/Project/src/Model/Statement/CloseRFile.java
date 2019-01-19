package Model.Statement;


import Model.Exceptions.ADT_Exception;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.MyDictionary;
import Model.Utils.MyStack;
import Model.Utils.Pair;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseRFile implements IStatement {
    private IExpression expressionFileId;

    public CloseRFile(IExpression expressionFileId) {
        this.expressionFileId = expressionFileId;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws IOException {
        MyStack<IStatement> exeStack = programState.getExeStack();
        MyDictionary<String, Integer> symTable = programState.getSymTable();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable = programState.getFileTable();
        int val = expressionFileId.evaluate(symTable, programState.getHeap());
        BufferedReader reader = fileTable.get(val).getSecond();
        if( reader == null ){
            throw new ADT_Exception("No such file descriptor");
        }
        reader.close();
        fileTable.remove(val);
        return null;
    }

    @Override
    public String toString() {
        return "CloseRFile Statement";
    }
}