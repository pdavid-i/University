import controller.Controller;
import repository.Repo;
import utils.Tester;
import view.UI;

public class Main {

    public static void main(String[] args) {

        //Tester.test_all();
        Repo r = new Repo();
        UI u = new UI(new Controller(r));
        u.run();
    }
}
