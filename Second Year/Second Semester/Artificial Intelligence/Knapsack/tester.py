from solver import Solver

class Tester:
    @staticmethod
    def test1():
        path = "tests/test1/"
        s = Solver(path+"input.txt")
        s.save_solution(10, path)
        s.save_solution(25, path)
        s.save_solution(50, path)
        s.save_solution(100, path)

    @staticmethod
    def test2():
        path = "tests/test2/"
        s = Solver(path+"input.txt")
        s.save_solution(10, path)
        s.save_solution(25, path)
        s.save_solution(50, path)
        s.save_solution(100, path)


    @staticmethod
    def test3():
        path = "tests/test3/"
        s = Solver(path+"input.txt")
        s.save_solution(10, path)
        s.save_solution(25, path)
        s.save_solution(50, path)
        s.save_solution(100, path)
        
    @staticmethod
    def test4():
        path = "tests/test4/"
        s = Solver(path+"input.txt")
        s.save_solution(10, path)
        s.save_solution(25, path)
        s.save_solution(50, path)
        s.save_solution(100, path)

    @staticmethod
    def test5():
        path = "tests/test5/"
        s = Solver(path+"input.txt")
        s.save_solution(10, path)
        s.save_solution(25, path)
        s.save_solution(50, path)
        s.save_solution(100, path)

    @staticmethod
    def test6():
        path = "tests/test6/"
        s = Solver(path+"input.txt")
        s.save_solution(10, path)
        s.save_solution(25, path)
        s.save_solution(50, path)
        s.save_solution(100, path)

    @staticmethod
    def test7():
        path = "tests/test7/"
        s = Solver(path+"input.txt")
        s.save_solution(10, path)
        s.save_solution(25, path)
        s.save_solution(50, path)
        s.save_solution(100, path)

    @staticmethod
    def test_all():
        Tester.test1()
        Tester.test2()
        Tester.test3()
        Tester.test4()
        Tester.test5()
        Tester.test6()
        Tester.test7()

Tester.test_all()
