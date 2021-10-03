def player_busts(player,dealer,Chips):
    print("Player Busts!!")
    Chips.losebet()

def player_win():
    print("Player wins!!")
    Chips.winbet

def dealer_busts(player,dealer,chips):
    print("Dealer busts!")
    chips.win_bet()
    
def dealer_wins(player,dealer,chips):
    print("Dealer wins!")
    chips.lose_bet()
    
def push(player,dealer):
    print("Dealer and Player tie! It's a push.")