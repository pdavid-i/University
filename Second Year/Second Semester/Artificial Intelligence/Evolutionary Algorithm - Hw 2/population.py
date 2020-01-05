from individ import Individ
from random import randint

class Population:
    no_individuals = 100
    def __init__(self):
        self.population = []
        for i in range(Population.no_individuals):
            p = Individ([])
            self.population.append(p)

    def evaluate(self):
        self.sort()
        for i in range(len(self.population) * 8 // 10):
            if self.population[i].fitness() != self.population[i+1].fitness:
                return False
        return True

    def selection(self):
        total_fitness = 0
        for elem in self.population:
            total_fitness = total_fitness + elem.fitness()
        index = randint(0, total_fitness)
        for elem in self.population:
            index = index - elem.fitness()
            if (index <= 0):
                return elem

    def sort(self):
        self.population = sorted(self.population, key=lambda elem: elem.fitness(), reverse = True)

            
    def next_generation(self):
        self.sort()
        new_population = []
        for i in range(Population.no_individuals//10):            #elitism  -  the top 10% are automatically preserved
            new_population.append(self.population[i])
        while (len(new_population) < Population.no_individuals):
            parent1 = self.selection()
            parent2 = self.selection()
            child1, child2 = Individ.crossover(parent1, parent2)
            child1.mutate()
            child2.mutate()
            new_population.append(child1)
            new_population.append(child2)

        self.population = new_population

    def printit(self):
        for elem in self.population:
            print(elem.fitness())
  
