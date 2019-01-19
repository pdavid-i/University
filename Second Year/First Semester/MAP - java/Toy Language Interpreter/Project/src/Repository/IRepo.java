package Repository;

import Model.ProgramState;
import Model.Utils.MyList;

import java.io.IOException;
import java.util.List;

public interface IRepo {
    ProgramState getCurPrg();
    void add(ProgramState p);
    void logPrgStateExec(ProgramState p) throws IOException;
    List<ProgramState> getPrgList();
    void setPrgList(List<ProgramState> ls);
}
