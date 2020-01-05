class Problem:
    def __init__(self, filename):
        with open(filename, 'r') as f:
            limits = f.readline().split()
            self.weight_limit = limits[0]
            self.min = limits[1]
            self.max = limits[2]
            self.prices = f.readline().split()
            self.weights = f.readline().split()

        
