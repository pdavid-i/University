package Controller;

import Model.ProgramState;
import Model.Statement.IStatement;
import Model.Utils.MyStack;
import Repository.IRepo;
import Repository.IRepository;
import Repository.IRepository;
import Repository.Repo;

public class Controller {
    private IRepo repo;

    public Controller(IRepo repo) {
        this.repo = repo;
    }

    public ProgramState oneStep(ProgramState state){
        MyStack<IStatement> stk=state.getExeStack();
        if(stk.isEmpty()) {
            return null;
        };
        IStatement crtStmt = stk.pop();
        crtStmt.execute(state);
        DisplayState();
        return null;
    }

    public void allStep(){
        ProgramState prg = repo.getCurPrg();

        while (!prg.getExeStack().isEmpty()){
            oneStep(prg);
            DisplayState();
        }
    }

    private void DisplayState() {
        System.out.println("ExeStack: ");
        System.out.println(repo.getCurPrg().getExeStack().toString());
        System.out.println("Symbol Table: ");
        System.out.println(repo.getCurPrg().getSymTable().toString());
        System.out.println("Output: ");
        System.out.println(repo.getCurPrg().getOutput().toString());
    }

}
