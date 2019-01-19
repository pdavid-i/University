package View;

import Controller.Controller;
import Model.Commands.ExitCommand;
import Model.Commands.RunExample;
import Model.Expression.*;
import Model.ProgramState;
import Model.Statement.*;
import Model.Utils.*;
import Repository.IRepo;
import Repository.Repo;

import java.io.BufferedReader;

public class View2 {

    private static void displayMenu(){
        System.out.println("Choose a program:");
        System.out.println("1: v = 2; print(v)");
        System.out.println("2: a = 2 + 3 * 5; b = a + 1; print(b)");
        System.out.println("3: a=2-2; (if a then v=2 else v=3); print(v)");
    }

    public static void main(String args[]) throws Exception {

//        a=7;b=3;c=a+b;Print(c)
        MyDictionary<String, Integer> symDict1 = new MyDictionary<>();
        MyList<Integer> out1 = new MyList<>();
        MyStack<IStatement> exeStack1 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable1 = new MyDictionary<>();

        IStatement ex1 =  new CompoundStatement(new AssignStatement("a", new ConstantExpression(7)),
                new CompoundStatement(new AssignStatement("b", new ConstantExpression(3)),
                        new CompoundStatement(new AssignStatement("c", new ArithmeticExpression(new VariableExpression("a"), new VariableExpression("b"), '+')),
                                new PrintStatement(new VariableExpression("c")))));
        ProgramState programState1 = new ProgramState(exeStack1, out1,symDict1, ex1, fileTable1, new MyHeap<>(), 1);
        IRepo repo1 = new Repo("test.txt");
        repo1.add(programState1);
        Controller ctrl1 = new Controller(repo1);

//         x=2+3*4;Print(x)
        MyDictionary<String, Integer> symDict2 = new MyDictionary<>();
        MyList<Integer> out2 = new MyList<>();
        MyStack<IStatement> exeStack2 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable2 = new MyDictionary<>();
        IStatement ex2 =  new CompoundStatement(new AssignStatement("x", new ArithmeticExpression(new ConstantExpression(2),
                new ArithmeticExpression(new ConstantExpression(3), new ConstantExpression(4), '*'), '+')), new PrintStatement(new VariableExpression("x")));
        ProgramState programState2 = new ProgramState(exeStack2, out2, symDict2, ex2, fileTable2, new MyHeap<>(), 2);
        IRepo repo2 = new Repo("test2.txt");
        repo2.add(programState2);
        Controller ctrl2 = new Controller(repo2);

//        nr=1;x=5;y=7;If(nr)Then(Print(x))Else(Print(y))
        MyDictionary<String, Integer> symDict3 = new MyDictionary<>();
        MyList<Integer> out3 = new MyList<>();
        MyStack<IStatement> exeStack3 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable3 = new MyDictionary<>();
        IStatement ex3 = new CompoundStatement(new AssignStatement("nr", new ConstantExpression(1)),
                new CompoundStatement(new AssignStatement("x", new ConstantExpression(5)),
                        new CompoundStatement(new AssignStatement("y", new ConstantExpression(7)),
                                new IfStatement(new VariableExpression("nr"), new PrintStatement(new VariableExpression("x")),
                                        new PrintStatement(new VariableExpression("y"))))));
        ProgramState programState3 = new ProgramState(exeStack3, out3, symDict3, ex3, fileTable3, new MyHeap<>(), 3);
        IRepo repo3 = new Repo("test3.txt");
        repo3.add(programState3);
        Controller ctrl3 = new Controller(repo3);

////      openRFile(var_f,"test.in");
////      readFile(var_f,var_c);print(var_c);
////      (if var_c then readFile(var_f,var_c);print(var_c)
////      else print(0));
////      closeRFile(var_f)
        MyDictionary<String, Integer> symDict4 = new MyDictionary<>();
        MyList<Integer> out4 = new MyList<>();
        MyStack<IStatement> exeStack4 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable4 = new MyDictionary<>();
        IStatement ex4 = new CompoundStatement(
                new OpenRFile("test.in.txt", "var_f"),
                new CompoundStatement(
                        new ReadFile(new VariableExpression("var_f"), "var_c"),
                        new CompoundStatement(
                                new PrintStatement(new VariableExpression("var_c")),
                                new CompoundStatement(
                                        new IfStatement(
                                                new VariableExpression("var_c"),
                                                new CompoundStatement(
                                                        new ReadFile(new VariableExpression("var_f"), "var_c"),
                                                        new PrintStatement(new VariableExpression("var_c"))
                                                ),
                                                new PrintStatement(new ConstantExpression(0))
                                        ),
                                        new CloseRFile(new VariableExpression("var_f"))
                                )
                        )
                )
        );
/*
        IStatement ex4 = new CompoundStatement(new OpenRFile("test.in.txt", "var_f"),
                new CompoundStatement(new ReadFile(new VariableExpression("var_f"), "var_c" ),
                        new PrintStatement(new VariableExpression("var_c"))));
*/
        ProgramState programState4 = new ProgramState(exeStack4, out4, symDict4, ex4, fileTable4, new MyHeap<>(), 4);
        IRepo repo4 = new Repo("test4.txt");
        repo4.add(programState4);
        Controller ctrl4 = new Controller(repo4);

//      openRFile(var_f,"test.in");
//      readFile(var_f+2,var_c);print(var_c);
//      (if var_c then readFile(var_f,var_c);print(var_c)
//      else print(0));
//      closeRFile(var_f)
        MyDictionary<String, Integer> symDict5 = new MyDictionary<>();
        MyList<Integer> out5 = new MyList<>();
        MyStack<IStatement> exeStack5 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable5 = new MyDictionary<>();
        IStatement ex5 = new CompoundStatement(
                new OpenRFile("test.in.txt", "var_f"),
                new CompoundStatement(
                        new ReadFile(new ArithmeticExpression(new VariableExpression("var_f"), new ConstantExpression( 2), '+'), "var_c"),
                        new CompoundStatement(
                                new PrintStatement(new VariableExpression("var_c")),
                                new CompoundStatement(
                                        new IfStatement(
                                                new VariableExpression("var_c"),
                                                new CompoundStatement(
                                                        new ReadFile(new VariableExpression("var_f"), "var_c"),
                                                        new PrintStatement(new VariableExpression("var_c"))),
                                                new PrintStatement(new ConstantExpression(0))),
                                        new CloseRFile(new VariableExpression("var_f")))
                        )
                )
        );
        ProgramState programState5 = new ProgramState(exeStack5, out5, symDict5, ex5, fileTable5, new MyHeap<>(), 5);
        IRepo repo5 = new Repo("test5.txt");
        repo5.add(programState5);
        Controller ctrl5 = new Controller(repo5);


        //Example: v=10;new(v,20);new(a,22);wH(a,30);print(a);print(rH(a))

        MyDictionary<String, Integer> symDict6 = new MyDictionary<>();
        MyList<Integer> out6 = new MyList<>();
        MyStack<IStatement> exeStack6 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable6 = new MyDictionary<>();
        MyHeap<Integer> heap6 = new MyHeap<>();
        IStatement ex6 = new CompoundStatement(
                new AssignStatement("v", new ConstantExpression(10)),
                new CompoundStatement(
                        new New("v", new ConstantExpression(20)),
                        new CompoundStatement(
                                new New("a", new ConstantExpression(22)),
                                new CompoundStatement(
                                        new HeapWrite("a", new ConstantExpression(30)),
                                        new CompoundStatement(
                                                new PrintStatement(new VariableExpression("a")),
                                                new CompoundStatement(
                                                        new PrintStatement(new ReadHeap("a")),
                                                        new AssignStatement("a", new ConstantExpression(0)))))
                        )
                )
        );
        ProgramState programState6 = new ProgramState(exeStack6, out6, symDict6, ex6, fileTable6, heap6, 6);
        IRepo repo6 = new Repo("test6.txt");
        repo6.add(programState6);
        Controller ctrl6 = new Controller(repo6);


        // 10 + (2<6) evaluates to 11
        MyDictionary<String, Integer> symDict7 = new MyDictionary<>();
        MyList<Integer> out7 = new MyList<>();
        MyStack<IStatement> exeStack7 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable7 = new MyDictionary<>();
        MyHeap<Integer> heap7 = new MyHeap<>();
        IStatement ex7 = new PrintStatement(new ArithmeticExpression(new ConstantExpression(10),
                new BooleanExpression(new ConstantExpression(2), new ConstantExpression(6), "<"),
                '+'));
        ProgramState programState7 = new ProgramState(exeStack7, out7, symDict7, ex7, fileTable7, heap7, 7);
        IRepo repo7 = new Repo("test9.txt");
        repo7.add(programState7);
        Controller ctrl7 = new Controller(repo7);

        //(10+2)<6 evaluates to 0
        MyDictionary<String, Integer> symDict8 = new MyDictionary<>();
        MyList<Integer> out8 = new MyList<>();
        MyStack<IStatement> exeStack8 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable8 = new MyDictionary<>();
        MyHeap<Integer> heap8 = new MyHeap<>();
        IStatement ex8 = new PrintStatement(new BooleanExpression(new ArithmeticExpression(new ConstantExpression(10),
                new ConstantExpression(2), '+'), new ConstantExpression(6), "<"));
        ProgramState programState8 = new ProgramState(exeStack8, out8, symDict8, ex8, fileTable8, heap8, 8);
        IRepo repo8 = new Repo("test8.txt");
        repo8.add(programState8);
        Controller ctrl8 = new Controller(repo8);




        //v=6; (while (v-4) print(v);v=v-1);print(v)
        MyDictionary<String, Integer> symDict9 = new MyDictionary<>();
        MyList<Integer> out9 = new MyList<>();
        MyStack<IStatement> exeStack9 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable9 = new MyDictionary<>();
        MyHeap<Integer> heap9 = new MyHeap<>();
        IStatement ex9 = new CompoundStatement(new CompoundStatement(new AssignStatement
                ("v", new ConstantExpression(6)), new WhileStatement(new ArithmeticExpression(
                        new VariableExpression("v"), new ConstantExpression(4), '-'), new CompoundStatement(
                                new PrintStatement(new VariableExpression("v")), new AssignStatement("v", new
                ArithmeticExpression(new VariableExpression("v"), new ConstantExpression(1), '-')
                ))
        )
        ),new PrintStatement(new VariableExpression("v")));
        ProgramState programState9 = new ProgramState(exeStack9, out9, symDict9, ex9, fileTable9, heap9, 9);
        IRepo repo9 = new Repo("test9.txt");
        repo9.add(programState9);
        Controller ctrl9 = new Controller(repo9);

        //v=6; (while (v-4) print(v);v=v-1);print(v)
        MyDictionary<String, Integer> symDict10 = new MyDictionary<>();
        MyList<Integer> out10 = new MyList<>();
        MyStack<IStatement> exeStack10 = new MyStack<>();
        MyDictionary<Integer, Pair<String, BufferedReader>> fileTable10 = new MyDictionary<>();
        MyHeap<Integer> heap10 = new MyHeap<>();
        IStatement ex10 = new CompoundStatement(
                new CompoundStatement(
                        new AssignStatement("v", new ConstantExpression(10)),
                        new New("a", new ConstantExpression(22))
                ),
                new CompoundStatement(
                        new ForkStatement(
                                new CompoundStatement(
                                        new HeapWrite("a", new ConstantExpression(30)),
                                        new CompoundStatement(
                                                new AssignStatement("v", new ConstantExpression(32)),
                                                new CompoundStatement(
                                                        new PrintStatement(new VariableExpression("v")),
                                                        new PrintStatement(new ReadHeap("a"))
                                                )
                                        )
                                )
                        ),
                        new CompoundStatement(
                                new PrintStatement(new VariableExpression("v")),
                                new PrintStatement(new ReadHeap("a"))
                        )
                )
        );


        ProgramState programState10 = new ProgramState(exeStack10, out10, symDict10, ex10, fileTable10, heap10, 1);
        IRepo repo10 = new Repo("test10.txt");
        repo10.add(programState10);
        Controller ctrl10 = new Controller(repo10);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1", ex1.toString(), ctrl1));
        menu.addCommand(new RunExample("2", ex2.toString(), ctrl2));
        menu.addCommand(new RunExample("3", ex3.toString(), ctrl3));
        menu.addCommand(new RunExample("4", ex4.toString(), ctrl4));
        menu.addCommand(new RunExample("5", ex5.toString(), ctrl5));
        menu.addCommand(new RunExample("6", ex6.toString(), ctrl6));
        menu.addCommand(new RunExample("7", ex7.toString(), ctrl7));
        menu.addCommand(new RunExample("8", ex8.toString(), ctrl8));
        menu.addCommand(new RunExample("9", ex9.toString(), ctrl9));
        menu.addCommand(new RunExample("10", ex10.toString(), ctrl10));


        menu.show();

    }
}
