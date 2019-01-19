package Repository;

import Model.ProgramState;
import Model.Utils.MyList;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Repo implements IRepo {
    private List<ProgramState> prgList;
    private int current = 0;
    private String logFile;
    private PrintWriter printWriter;
    private boolean first_time;
    private static int c = 0;

    public Repo(String filename) throws IOException {
        this.logFile = filename;
        this.prgList = new ArrayList<ProgramState>();
        printWriter = null;
        first_time = true;
    }

    public List<ProgramState> getPrgList(){return prgList;}

    public void setPrgList(List<ProgramState> ls){ this.prgList = ls; }

    @Override
    public ProgramState getCurPrg() {
        return this.prgList.get(current);
    }

    @Override
    public void add(ProgramState p) {
        prgList.add(p);
    }

    public void logPrgStateExec(ProgramState p) throws IOException {
        if(first_time == true) {
            /// first, clear the content
            try {
                PrintWriter writer = new PrintWriter(new File(logFile));
                writer.print("");
                writer.close();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
            first_time = false;
        }

        this.printWriter = new PrintWriter(new FileWriter(logFile, true));

        this.printWriter.println("Thread ID: " + p.getId());
        this.printWriter.println("_________________________");
        this.printWriter.println("ExeStack:");
        this.printWriter.println(p.getExeStack().toString());
        this.printWriter.println("SymTable:");
        this.printWriter.println(p.getSymTable().toString());
        this.printWriter.println("Out:");
        this.printWriter.println(p.getOutput().toString());
        this.printWriter.println("Heap:");
        this.printWriter.println(p.getHeap().toString());
        this.printWriter.println("_________________________");

        this.printWriter.close();
    };
}
