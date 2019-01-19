package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;

public class PrintStatement implements IStatement {
    IExpression expr;

    public PrintStatement(IExpression expr) {
        this.expr = expr;
    }

    @Override
    public ProgramState execute(ProgramState ps){
        System.out.println(expr.evaluate(ps.getSymTable(), ps.getHeap()));
        ps.getOutput().add(expr.evaluate(ps.getSymTable(), ps.getHeap()));
        return null;
    }

    @Override
    public String toString(){
        return "Print statement: " + expr.toString();
    }
}
