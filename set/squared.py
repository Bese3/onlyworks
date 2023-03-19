def square_matrix_simple(matrix=[]):
    squared = []
    for i in matrix:
        squared.append(list(map(lambda x: x**2 , i)))
    return squared