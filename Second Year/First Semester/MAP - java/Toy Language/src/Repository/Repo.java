package Repository;

import Model.ProgramState;
import Model.Utils.MyList;

import java.util.ArrayList;
import java.util.List;

public class Repo implements IRepo {
    private MyList<ProgramState> prgList;
    private int current;

    public Repo() {
        this.prgList = new MyList<ProgramState>();
        current = 0;
    }

    @Override
    public ProgramState getCurPrg() {
        return this.prgList.get(current);
    }

    @Override
    public void add(ProgramState p) {
        prgList.add(p);
    }
}
