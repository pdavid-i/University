import Model.Expression.ArithmeticExpression;

import Model.Expression.ConstantExpression;

import Model.Expression.VariableExpression;
import Model.ProgramState;
import Model.Statement.*;
import Model.Utils.MyDictionary;
import Model.Utils.MyList;
import Model.Utils.MyStack;
import Repository.IRepo;
import Repository.IRepository;
import Repository.Repo;
import Controller.Controller;
import Repository.Repository;


import java.util.Scanner;

public class Main {

    private static void menu()
    {
        System.out.println("Choose a program:");
        System.out.println("1. a=7;b=3;c=a+b;Print(c)");
        System.out.println("2. x=2+3*4;Print(x)");
        System.out.println("3. nr=1;x=5;y=7;If(nr)Then(Print(x))Else(Print(y))");
    }

    public static void main(String[] args) {
        menu();
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();

        IStatement stm = null;

        if (x == 1) {
            stm = new CompoundStatement(new AssignStatement("a", new ConstantExpression(7)),
                    new CompoundStatement(new AssignStatement("b", new VariableExpression("3")),
                            new CompoundStatement(new AssignStatement("c", new ArithmeticExpression
                                    (new VariableExpression("a"), new VariableExpression("b"), '+')),
                                    new PrintStatement(new VariableExpression("c")))));
        }
        else if(x == 2) {
            stm = new CompoundStatement(new AssignStatement("x", new ArithmeticExpression(new ConstantExpression(2),
                    new ArithmeticExpression(new ConstantExpression(3), new ConstantExpression(4), '*'), '+')),
                    new PrintStatement(new VariableExpression("x")));
        }
        else if(x == 3) {
            stm = new CompoundStatement(new AssignStatement("nr", new ConstantExpression(1)),
                    new CompoundStatement(new AssignStatement("x", new ConstantExpression(5)),
                            new CompoundStatement(new AssignStatement("y", new ConstantExpression(7)),
                                    new IfStatement(new VariableExpression("n"), new PrintStatement(new VariableExpression("x")),
                                            new PrintStatement(new VariableExpression("y"))))));
        }
        else
        {
            System.out.println("Invalid choice!");
            System.exit(0);
        }

        try {
            IRepo repo = new Repo();
            MyStack<IStatement> exeStack = new MyStack<IStatement>();
            MyDictionary<String, Integer> symTable = new MyDictionary<String, Integer>();
            MyList<Integer> output = new MyList<Integer>();
            ProgramState ps = new ProgramState(exeStack, output, symTable, stm);
            repo.add(ps);
            Controller ctrl = new Controller(repo);

            while(!ps.getExeStack().isEmpty()) {
                System.out.println("Choose-> 1- one step, 2- all: ");
                x = scan.nextInt();

                if(x == 1) {
                    ctrl.oneStep(ps);
                }
                else if(x == 2) {
                    ctrl.allStep();
                }
            }
        }
        catch (Exception e) {
            System.out.println(e.toString());
        }

    }
}
