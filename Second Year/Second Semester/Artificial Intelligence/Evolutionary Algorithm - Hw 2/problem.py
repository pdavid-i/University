class Problem:
    def __init__(self, filename):
        with open(filename, 'r') as f:
            self.matrix = []
            self.t = f.readline()
            for line in f:
                lyne = []
                for elem in line.split():
                    lyne.append(int(elem))
                self.matrix.append(lyne)
