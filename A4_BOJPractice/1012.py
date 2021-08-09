#https://www.acmicpc.net/problem/1012

#유기농 배추

#격자 모양 배추밭의 몇몇 곳에 배추가 심어져 있다.
#배추에 배추흰지렁이를 놓아서 해충을 쫒아내고 싶다.
#배추흰지렁이는 상하좌우로 인접한 배추로도 이동할 수 있다.

#모든 배추가 배추흰지렁이가 갈 수 있도록 하는
#지렁이의 최소 마리수를 구하시오.

from collections import deque
testcase = int(input())

for tc in range(testcase):
    row, col, cabbageCount = [int(x) for x in input().split()]

    board = []

    for i in range(row):
        board.append(list())
        for j in range(col):
            board[i].append('X')

    
    for i in range(cabbageCount):
        rowNum, colNum = [int(x) for x in input().split()]
        board[rowNum][colNum] = 'O'

    count = 0
    for i in range(row):
        for j in range(col):
            if board[i][j] == 'O':
                count += 1
                bfsQueue = deque([(i, j)])

                while len(bfsQueue) > 0:
                    nowLoc = bfsQueue.popleft()
                    board[nowLoc[0]][nowLoc[1]] = 'V'
                    
                    if nowLoc[0] + 1 < row and board[nowLoc[0] + 1][nowLoc[1]] == 'O':
                        bfsQueue.append((nowLoc[0] + 1, nowLoc[1]))
                        board[nowLoc[0] + 1][nowLoc[1]] = 'E'
                    
                    if nowLoc[1] + 1 < col and board[nowLoc[0]][nowLoc[1] + 1] == 'O':
                        bfsQueue.append((nowLoc[0], nowLoc[1] + 1))
                        board[nowLoc[0]][nowLoc[1] + 1] = 'E'
                    
                    if nowLoc[0] - 1 >= 0 and board[nowLoc[0] - 1][nowLoc[1]] == 'O':
                        bfsQueue.append((nowLoc[0] - 1, nowLoc[1]))
                        board[nowLoc[0] - 1][nowLoc[1]] = 'E'
                    
                    if nowLoc[1] - 1 >= 0 and board[nowLoc[0]][nowLoc[1] - 1] == 'O':
                        bfsQueue.append((nowLoc[0], nowLoc[1] - 1))
                        board[nowLoc[0]][nowLoc[1] - 1] = 'E'
    
    print(count)
    

