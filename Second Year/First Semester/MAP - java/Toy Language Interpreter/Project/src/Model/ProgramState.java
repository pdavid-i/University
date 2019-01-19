package Model;

import Model.Exceptions.ADT_Exception;
import Model.Statement.IStatement;
import Model.Utils.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Map;

public class ProgramState {
    int id;
    private MyStack<IStatement> exeStack;
    private MyList<Integer> output;
    private MyDictionary<String, Integer> symTable;
    private MyDictionary<Integer, Pair<String, BufferedReader>> fileTable;
    private MyHeap<Integer> heap;

    public ProgramState(MyStack<IStatement> exeStack, MyList<Integer> output, MyDictionary<String, Integer> symTable,
                        IStatement program,  MyDictionary<Integer, Pair<String, BufferedReader>> fileTable,
                        MyHeap<Integer> heap, int id) {

        this.exeStack = exeStack;
        this.output = output;
        this.symTable = symTable;
        this.fileTable = fileTable;
        this.heap = heap;
        this.id = id;
        exeStack.push(program);
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public MyDictionary<String, Integer> getSymTable() {
        return symTable;
    }

    public void setSymTable(MyDictionary<String, Integer>
                                    symTable) {
        this.symTable = symTable;
    }

    public MyStack<IStatement> getExeStack() {
        return exeStack;
    }

    public void setExeStack(MyStack<IStatement> exeStack) {
        this.exeStack = exeStack;
    }

    public void execute_top() throws IOException {
        IStatement st = exeStack.pop();
        st.execute(this);
    }

    public MyDictionary<Integer, Pair<String, BufferedReader>> getFileTable() {
        return fileTable;
    }

    public MyList<Integer> getOutput() {
        return output;
    }

    public void setOutput(MyList<Integer> output) {
        this.output = output;
    }

    public MyHeap<Integer> getHeap(){
        return this.heap;
    }

    public boolean isNotCompleted(){
        return !exeStack.isEmpty();
    }

    public ProgramState oneStep() throws IOException{
        if(exeStack.isEmpty())
            throw new ADT_Exception("Execution stack is empty!");
        IStatement crtStmt = exeStack.pop();
        return crtStmt.execute(this);
    }

    //void setProgram(IStatement prg) {
      //  this.program = prg;
    //}

    //IStatement getProgram() {
    //   return this.program;
    //}
}
