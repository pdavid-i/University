package Model.Statement;

import Model.ProgramState;
import Model.Utils.MyStack;
import Model.Utils.Pair;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Stack;


public class ForkStatement implements IStatement {
    private IStatement stmt;
    public ForkStatement(IStatement stmt) {
        this.stmt = stmt;
    }
    @Override
    public ProgramState execute(ProgramState state)  {
        ProgramState forkProgram = new ProgramState( new MyStack<IStatement>(), state.getOutput(),  state.getSymTable().clone() , this.stmt, state.getFileTable(), state.getHeap(), state.getId() * 10);
        return forkProgram;
    }

    @Override
    public String toString() {
        return "fork(" + this.stmt.toString() + ")";
    }
}
