package Repository;

import Model.ProgramState;

import java.util.List;

public interface IRepo {
    ProgramState getCurPrg();
    void add(ProgramState p);
}
