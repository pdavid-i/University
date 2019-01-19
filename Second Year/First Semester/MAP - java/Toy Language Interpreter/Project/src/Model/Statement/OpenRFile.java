package Model.Statement;

import Model.Exceptions.ADT_Exception;
import Model.Exceptions.DuplicateVariableException;
import Model.ProgramState;
import Model.Utils.MyDictionary;
import Model.Utils.MyStack;
import Model.Utils.Pair;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class OpenRFile implements IStatement {
    private static int numberOfVarFileId = 1;
    private String filename;
    private String varFileId;

    public OpenRFile(String filename, String varFileId) {
        this.filename = filename;
        this.varFileId = varFileId;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws DuplicateVariableException, FileNotFoundException {
        MyStack<IStatement> exeStack = programState.getExeStack();
        MyDictionary<String, Integer> symTable = programState.getSymTable();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable = programState.getFileTable();
        for(Pair<String, BufferedReader> e : fileTable.values())
            if(e.getFirst().equals(filename))
                throw new ADT_Exception("Filename already exists");

        BufferedReader reader = new BufferedReader(new FileReader(filename));
        Pair<String, BufferedReader> p = new Pair<>(filename, reader);
        fileTable.put(numberOfVarFileId, p);
        symTable.put(varFileId, numberOfVarFileId);
        numberOfVarFileId ++;

        return null;
    }

    @Override
    public String toString() {
        return "OpenRFile Statement, filename: " + filename + ", varFileId: " + varFileId + ", id: " + this.numberOfVarFileId;
    }
}
