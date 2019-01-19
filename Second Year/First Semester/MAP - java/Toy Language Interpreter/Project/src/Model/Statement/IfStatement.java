package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;

public class IfStatement implements IStatement {
    private IExpression exp;
    private IStatement then;
    private IStatement els;

    public IfStatement(IExpression exp, IStatement then, IStatement els) {
        this.exp = exp;
        this.then = then;
        this.els = els;
    }

    public String toString() {
        return "If Statement: if(" + exp.toString() + ") then " + then.toString() + " else " + els.toString() + " end";
    }

    public ProgramState execute(ProgramState ps) {
        if(exp.evaluate(ps.getSymTable(), ps.getHeap()) == 0)
            ps.getExeStack().push(els);
        else
            ps.getExeStack().push(then);
        return null;
    }
}
