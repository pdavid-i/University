package Repository;

import Model.ProgramState;
import Model.Statement.IStatement;

public class Repository implements IRepository{
    ProgramState program;

    public Repository(){
        this(new ProgramState());
    }

    public Repository(ProgramState program) {
        this.program = program;
    }

    @Override
    public ProgramState getProgram(){
        return program;
    }

    @Override
    public void addStatement(IStatement statement){
        this.program.getExeStack().push(statement);
    }
}
