from population import Population
from problem import Problem
import time

class Solver:
    def __init__(self, filename="test.txt"):
        print(filename)
        self.population = Population(Problem(filename))


    def run(self, iterations_limit, statistics = False):
        i = 0
        while self.population.evaluate() == False and i < iterations_limit:
            self.population.next_generation()
            i = i + 1
        self.population.sort()
        if statistics == True:
            return self.population.population[0].config, self.population.population[0].fitness(), self.population.population[0].fitness() - self.population.average_fitness()
        else:
            return self.population.population[0].config
        
    def save_solution(self, n, path):
        with open(path + "solution" + str(n) + "iterations" +".txt", 'w') as w:
            start = time.time()
            result, best_fitness, deviation = self.run(n, True)
            end = time.time()
            w.write(str(result) +"\n" )
            w.write("Solution for " + str(n) + " generations" +"\n" )
            w.write("Best Fitness: " + str(best_fitness) + ", Standard Deviation: " + str(deviation) + "\n")
            w.write("Time elapsed: " + str(end-start) + " seconds")
