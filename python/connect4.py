import numpy as np

Numer_of_Rows = 6
Numer_of_Columns = 7

#Initialy defining functions whick will be called while playing the game

# reversing the orientation of the matrix
# to the connect four upside down format
def reverseBoard(curr_board):
    print(np.flip(curr_board, 0))

#Check if the location selected by the user is a valid location
def Check_valid_location(curr_board, column):
    if (curr_board[Numer_of_Rows - 1, column] != 0):
        return False
    else:
        return True

# Finding the lowest possible row when the user enters the piece
def FindLowestRow(curr_board, column):
    for row in range(Numer_of_Rows):
        if curr_board[row][column] == 0:
            return row

# Check if the position is winning
def Check_if_won(curr_board, curr_move):
    # vertically winning
    for col in range(Numer_of_Columns):
        for row in range(Numer_of_Rows - 3):
            if curr_board[row][col] == curr_move and curr_board[row + 1][col] == curr_move and curr_board[row + 2][col] == curr_move and curr_board[row + 3][
                col] == curr_move:
                return True

    # horizontally winning 
    for col in range(Numer_of_Columns - 3):
        for row in range(Numer_of_Rows):
            if curr_board[row][col] == curr_move and curr_board[row][col + 1] == curr_move and curr_board[row][col + 2] == curr_move and curr_board[row][
                col + 3] == curr_move:
                return True
    
    # 1st diagonal 
    for col in range(Numer_of_Columns - 3):
        for row in range(Numer_of_Rows - 3):
            if curr_board[row][col] == curr_move and curr_board[row + 1][col + 1] == curr_move and curr_board[row + 2][col + 2] == curr_move and curr_board[row + 3][
                col + 3] == curr_move:
                return True
    # 2nd diagonal 
    for col in range(Numer_of_Columns - 3):
        for row in range(3, Numer_of_Rows):
            if curr_board[row][col] == curr_move and curr_board[row - 1][col + 1] == curr_move and curr_board[row - 2][col + 2] == curr_move and curr_board[row - 3][
                col + 3] == curr_move:
                return True

# Board Creation
board = np.zeros((Numer_of_Rows, Numer_of_Columns))
move = 1
status = True


print("********** CONNECT 4 **********")
# Game begins!
reverseBoard(board)
while status:
    # Player 1's move
    if move == 1:
        while True:
            while True:
                col = int(input("Player 1 select the row where you want to drop the piece (0 <= row < 7): "))
                if (col < 0 or col >= Numer_of_Columns):
                    print("Please enter a valid column")
                else:
                    break
            move = 2

            if Check_valid_location(board, col):
                row = FindLowestRow(board, col)
                board[row][col] = 1
                break
            else:
                print("Select another column. This column is already Full!")
        reverseBoard(board)
        if Check_if_won(board, 1):
            print("We've a winner!! Congratulations @Player 1")
            status = False


    else:
        # Player 2's move
        while True:
            while True:
                col = int(input("Player 2 select the row where you want to drop the piece (0 <= row < 7): "))
                if (col < 0 or col >= Numer_of_Columns):
                    print("Please enter a valid column")
                else:
                    break
            move = 1

            if Check_valid_location(board, col):
                row = FindLowestRow(board, col)
                board[row][col] = 2
                break
            else:
                print("ERROR 503 THE COLUMN IS FULL")
        reverseBoard(board)
        if Check_if_won(board, 2):
            print("We've a winner!! Congratulations @Player 2")
            status = False