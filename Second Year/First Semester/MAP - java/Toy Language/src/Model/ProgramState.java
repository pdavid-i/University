package Model;

import Model.Statement.IStatement;
import Model.Utils.*;

public class ProgramState {
    private MyStack<IStatement> exeStack;
    private MyList<Integer> output;
    private MyDictionary<String, Integer> symTable;
  //  private IStatement program;

    public ProgramState(){
        this.exeStack = new MyStack<IStatement>();
        this.output = new MyList<Integer>();
        this.symTable = new MyDictionary<String, Integer>();
    //    this.program = new
    }

    public ProgramState(MyStack<IStatement> exeStack,
                        MyList<Integer> output,
                        MyDictionary<String, Integer>
                                symTable, IStatement program) {
        this.exeStack = exeStack;
        this.output = output;
        this.symTable = symTable;
  //      this.program = program;
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

    public void execute_top(){
        IStatement st = exeStack.pop();
        st.execute(this);
    }

    public MyList<Integer> getOutput() {
        return output;
    }

    public void setOutput(MyList<Integer> output) {
        this.output = output;
    }


    //void setProgram(IStatement prg) {
      //  this.program = prg;
    //}

    //IStatement getProgram() {
    //   return this.program;
    //}
}
