class Nqueen:
    def __init__(self , n):
        if not isinstance(n , int):
            raise TypeError("n must be integer")
        if n < 4:
            raise ValueError("n must be greater than 4")
        
        self.__n = n
    @property
    def n(self):
        return self.__n
    @n.setter
    def n(self , value):
        if not isinstance(value , int):
            raise TypeError("n must be integer")
        if value < 4:
            raise ValueError("n must be greater than 4")
        self.__n = value
    def solve(self , n):
        col = set()
        posdiag = set()
        negdiag = set()

        res = []
        chess = [[""] for i in range(n)]
        def backtrack(r):
            if r == n:
                clone = ["".join(row) for row in chess]
                res.append(clone)
                return res
            for c in range(n):
                if c in col or (r + c) in posdiag or (r - c) in negdiag:
                    continue

                col.add(c)
                posdiag.add(r + c)
                negdiag.add(r - c)
                chess[r][c] = "Q"

                backtrack(r + 1)

                col.remove(c)
                posdiag.remove(r + c)
                negdiag.remove(r - c)
                chess[r][c] = ""
        def __str__(self):
            return str(res)
res = Nqueen(4)
res.solve(4)
print(res)



        