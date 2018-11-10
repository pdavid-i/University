package Repository;

import Model.ProgramState;
import Model.Statement.IStatement;

public interface IRepository {
    ProgramState getProgram();
    void addStatement(IStatement statement);
}
