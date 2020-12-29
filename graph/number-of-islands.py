grid3 = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]

grid2 = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

def solution(grid):
    def dfs(grid, row, col):
        if (row < 0 or row >= len(grid)) or \
                (col < 0 or col >= len(grid[0])):
            return

        try:
            if grid[row][col] == "1":
                grid[row][col] = "#"

                dfs(grid, row+1, col)
                dfs(grid, row, col+1)
        except Exception as e:
            print(e)
            print(row, col)



    # check size of grid matrix
    row_size = len(grid)
    col_size = len(grid[0])

    print('row_size', row_size)
    print('col_size', col_size)

    count = 0

    for row in range(row_size):
        for col in range(col_size):
            element = grid[row][col]

            if element == "1":
                dfs(grid, row, col)
                count += 1

    print(grid)
    print(count)

#solution(grid)
solution(grid2)
