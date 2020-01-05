from random import randint
from problem import Problem

class Individ:
    def __init__(self, param=[], problem=Problem("input.txt")):
        self.config = []
        self.problem = problem
        if not (len(param) == 0):
            self.config = param
        else:
            for i in range(len(self.problem.weights)):
                self.config.append(randint(0, 1))

    def fitness(self):
        score = 0
        weight = 0 
        for i in range(len(self.config)):
            score = score + self.config[i] * int(self.problem.prices[i])
            weight = weight + self.config[i] * int( self.problem.weights[i])
            if (weight > int(self.problem.weight_limit)) or (self.config.count(1) > int(self.problem.max)):
                pos = randint(0, len(self.config) - 1)
                while (self.config[pos] == 0):
                    pos = randint(0, len(self.config) - 1)
                self.config[pos] = 0
                return self.fitness()
            elif (self.config.count(1) < int(self.problem.min)):
                pos = randint(0, len(self.config) - 1)
                while (self.config[pos] == 1):
                    pos = randint(0, len(self.config) - 1)
                self.config[pos] = 1
                return self.fitness()
        return score

    def mutate(self): 
        p = 0.01 #mutation probability 1%
        for elem in self.config:
            chance = randint(1, 100)
            if chance <= p * 100:
                elem = (elem + 1)%2

    @staticmethod
    def crossover(parent1, parent2):
        delimiter = randint(0, len(parent1.config) - 1)
        child1 = []
        child2 = []
        for i in range(len(parent1.config)):
            if i < delimiter:
                child1.append(parent1.config[i])
                child2.append(parent2.config[i])
            else:
                child1.append(parent2.config[i])
                child2.append(parent1.config[i])
        return Individ(child1, parent1.problem), Individ(child2, parent2.problem)


