from random import randint
from problem import Problem

class Individ:
    problem = Problem("test.txt")
    def __init__(self, param):
        self.config = []
        if not (len(param) == 0):
            self.config = param
        else:
            for i in range(len(Individ.problem.matrix)):
                self.config.append(randint(0, 1))
         

    def is_valid(self):
        nodes = []
        for i in range(len(self.config)):
            if self.config[i] == 1:
                nodes.append(i)

        t = int(Individ.problem.t)
        while t > 1:
            clone = []
            for elem in nodes:
                clone.append(elem)
            for elem in clone:
                for i in range(len(Individ.problem.matrix)):
                    if Individ.problem.matrix[elem][i] == 1:
                        if nodes.count(i) == 0:
                            nodes.append(i)
            if len(nodes) == len(Individ.problem.matrix):
                return True
            t = t - 1
        return False
                
    def fitness(self):
        score = 0
        if (not self.is_valid()):
            pos = randint(0, len(self.config) - 1)
            while (self.config[pos] == 1):
                pos = randint(0, len(self.config) - 1)
            self.config[pos] = 1
            return self.fitness()
        return len(Individ.problem.matrix) - self.config.count(1)
    

    def mutate(self): 
        p = 0.1 #mutation probability 1%
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
        return Individ(child1), Individ(child2)

i = Individ([0, 0, 0, 1, 0, 0])


