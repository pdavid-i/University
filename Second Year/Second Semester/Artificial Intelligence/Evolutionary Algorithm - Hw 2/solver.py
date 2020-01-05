from population import Population

class Solver:
    def __init__(self):
        self.population = Population()

    def run(self, iterations_limit):
        i = 0
        while self.population.evaluate() == False and i < iterations_limit:
            self.population.next_generation()
            i = i + 1
        self.population.sort()
        return self.population.population[0].config
        
