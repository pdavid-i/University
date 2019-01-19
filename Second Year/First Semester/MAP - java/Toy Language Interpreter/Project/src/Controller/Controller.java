package Controller;

import Model.Expression.ConstantExpression;
import Model.ProgramState;
import Model.Statement.CloseRFile;
import Model.Statement.IStatement;
import Model.Utils.MyList;
import Model.Utils.MyStack;
import Model.Utils.Pair;
import Repository.IRepo;

import javax.xml.bind.SchemaOutputResolver;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collection;
import java.util.Map;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {
    private IRepo repo;
    private ExecutorService executor;


    public Controller(IRepo repo) {
        this.repo = repo;
    }

    Map<Integer,Integer> conservativeGarbageCollector(Collection<Integer> symTableValues,
                                                      Map<Integer,Integer> heap){
        return heap.entrySet().stream()
                .filter(e->symTableValues.contains(e.getKey()))
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));}

        public void allSteps() throws Exception  {
        //executor = Executors.newFixedThreadPool(2);
        executor = Executors.newCachedThreadPool();
            List<ProgramState> prgList = removeCompletedPrg(repo.getPrgList());
            ProgramState fpg = prgList.get(0);
            while(prgList.size() > 0) {
                oneStepForAllPrg(prgList);
                prgList = removeCompletedPrg(repo.getPrgList());
            }
        executor.shutdownNow();
        repo.setPrgList(prgList);

        List<ProgramState> tmpList = repo.getPrgList();
        if(tmpList!=null)
            CloseOpenedFiles(fpg);
    }

    private void CloseOpenedFiles(ProgramState ps) throws IOException {
        List<Map.Entry<Integer, Pair<String, BufferedReader>>> files = ps.getFileTable().All().entrySet().stream().
                collect(Collectors.toList());

        for(Map.Entry<Integer, Pair<String, BufferedReader>> k : files)
        {
            new CloseRFile(new ConstantExpression(k.getKey())).execute(ps);
        }
    }


    void oneStepForAllPrg(List<ProgramState> prgList) throws InterruptedException{
        prgList.forEach(prg -> {
            try {
                repo.logPrgStateExec(prg);
            } catch (IOException e) {
                e.printStackTrace();
            }
        });

        List<Callable<ProgramState>> callList = prgList.stream()
                .map((ProgramState p) -> (Callable<ProgramState>)(() -> {return p.oneStep();}))
                .collect(Collectors.toList());

        List<ProgramState> newPrgList = executor.invokeAll(callList).stream()
                .map(future -> {
                    try {
                        return future.get();
                    } catch (Exception ex) {
                        System.out.println(ex.getMessage());
                    }
                    return null;
                })
                .filter(p -> p != null)
                .collect(Collectors.toList());

        prgList.addAll(newPrgList);
        prgList.forEach(prg -> {
            try {
                repo.logPrgStateExec(prg);
            } catch (IOException e) {
                e.printStackTrace();
            }
        });

        repo.setPrgList(prgList);
    }

    public List<ProgramState> removeCompletedPrg(List<ProgramState> prgStateList) {
        return prgStateList.stream()
                .filter(p -> p.isNotCompleted())
                .collect(Collectors.toList());
    }

    private void DisplayState() {
        System.out.print("Thread id: " + Integer.toString(repo.getCurPrg().getId()) );
        System.out.println("ExeStack: ");
        System.out.println(repo.getCurPrg().getExeStack().toString());
        System.out.println("Symbol Table: ");
        System.out.println(repo.getCurPrg().getSymTable().toString());
        System.out.println("Output: ");
        System.out.println(repo.getCurPrg().getOutput().toString());
        System.out.println("Heap: ");
        System.out.println(repo.getCurPrg().getHeap().toString());
    }

}
