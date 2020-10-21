#import make suits rank values
#define a card __int__ define its rank and suit return its value
#make a deck using the card class and return whoe deck as str
#in dec decribe its methos for shuflling and picking a card for the deck
#define hand __init___define the values of and number of ace and rank of card
#in hand class decribe a function for ajusting for aces
#define another class Chips __init__ define the total chips of players and the betting chips
#__init__ define the win and lose condition of game
#define a function for betting chips and describe the total number of chips amount
#define a function for the hit condition of the player
#define a function for the hit and stand condtion of the player
#define a function for shwing the card of plaer and single card of the dealer
#define a function for showing all cards and dealer and player valuees
#define four function for the bust and win conditon output of the dealer and player
#intiate a while loop for playing and distrbute the two card and chips for player and dealer
#take bet from the player computer a dealer
#now show the some card function
#now initiate a while loop for the andcontinue playing and ask for hit and stand
#if the bust player encounters break the loop and show all cards and value ask for chips value
#if player is not bust check for the lose for win and the dealer bust condition
#and make a while condition for the dealer keep hitting for the value less than 17
#now check for the bust and win for the pllayer and make the all card show 
#print the new total chips of the player
#ask for the playing again if yes turn playing equals to true
#and if no break

import random
suits=['spade','heart','clubs','diamond']
ranks=['ace','queen','jack','king','two','three','four','five','six','seven','eight','nine','ten']
values={'ace':11, 'queen':10, 'jack':10, 'king':10, 'two':2, 'three':3, 'four':4, 'five':5, 'six':6, 'seven':7, 'eight':8, 'nine':9, 'ten':10}
playing=True

class Card:
        
    def __init__(self,rank,suit):
        self.rank=rank
        self.suit=suit
    def __str__(self):
        return f"{self.rank} of {self.suit}"
    
class Deck:
    def __init__(self):
        self.deck=[]
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(rank,suit))
    def __str__(self):
        deck_comp=''
        for card in self.deck:
            deck_comp += '\n' +card.__str__()
        return 'the deck has :'+deck_comp
    def shuffle(self):
        random.shuffle(self.deck)
    def deal(self):
        single_card=self.deck.pop()
        return single_card
    
class Hand:
    def __init__(self):
        self.cards=[]
        self.value=0
        self.aces=0
    def add_card(self,card):
        self.cards.append(card)
        self.value+=values[card.rank]
        if card.rank=='ace':
            self.aces+=1
    def ajust_4_ace():
        while self.value>21 and self.ace:
            self.value-=10
            self.aces-=1
                   
class Chips:
    
    def __init__(self):
        self.total=100 #we can override the total value by  putting __init__(self,total=100)
        self.bet=0 #self.total=total
    
    def __winbet__(self):
        self.total+=self.bet
        
    def __losebet__(self):
        self.total-=self.bet
        
def take_bet(Chips):
    while True:
        try:
            Chips.bet=int(input('Place your bet: '))
        except ValueError:
            print('Sorry!! bet must a integer')
        else:
            if Chips.total<Chips.bet:
                print('You dont have enough chips!!')
            else:
                break
            
def hit(Deck,Hand):
    Hand.add_card(Deck.deal())
    Hand.ajust_4_ace()
    
def hit_or_stand(Deck,Hand):
    global playing
    
    while True:
        x=input('Would u like to Hit or Stand: H\S').upper()
        if x=='H':
            hit(Deck,Hand)
        elif x=='S':
            print('Please wait while dealer is playing')
            playing=False
        else:
            print('Sorry! please try again.')
            continue
        break
    
def show_some(player_hand,dealer_hand):
    print("\n Dealer's hand")
    print("<card hidden>")
    print('',dealer_hand.cards[1])
    print('Player hand',*player_hand.cards,sep='\n')

def show_all(player_hand,dealer_hand):
    print("\n Dealer's hand: ",*dealer_hand.cards,sep='\n')
    print("\n Player's hand: ",*player_hand.cards,sep='\n' )
    print("\n Dealer's value: ",dealer_hand.value)
    print("\n Player's value: ",player_hand.value)    
    
def player_busts(player,dealer,Chips):
    print("Player Busts!!")
    Chips.__losebet__()

def player_win(player,dealer,Chips):
    print("Player wins!!")
    Chips.__winbet__()

def dealer_busts(player,dealer,chips):
    print("Dealer busts!")
    Chips.___winbet__()
    
def dealer_wins(player,dealer,chips):
    print("Dealer wins!")
    Chips.__losebet__()
    
def push(player,dealer):
    print("Dealer and Player tie! It's a push.")
        
while True:
    # Print an opening statement
    print('Welcome to BlackJack! Get as close to 21 as you can without going over!\n\
    Dealer hits until she reaches 17. Aces count as 1 or 11.')
    
    # Create & shuffle the deck, deal two cards to each player
    deck = Deck()
    deck.shuffle()
    
    player_hand = Hand()
    player_hand.add_card(deck.deal())
    player_hand.add_card(deck.deal())
    
    dealer_hand = Hand()
    dealer_hand.add_card(deck.deal())
    dealer_hand.add_card(deck.deal())
            
    # Set up the Player's chips
    player_chips = Chips()  # remember the default value is 100    
    
    # Prompt the Player for their bet
    take_bet(player_chips)
    
    # Show cards (but keep one dealer card hidden)
    show_some(player_hand,dealer_hand)
    
    while playing:  # recall this variable from our hit_or_stand function
        
        # Prompt for Player to Hit or Stand
        hit_or_stand(deck,player_hand) 
        
        # Show cards (but keep one dealer card hidden)
        show_some(player_hand,dealer_hand)  
        
        # If player's hand exceeds 21, run player_busts() and break out of loop
        if player_hand.value > 21:
            player_busts(player_hand,dealer_hand,player_chips)
            
            show_all(player_hand,dealer_hand)
            break        


    # If Player hasn't busted, play Dealer's hand until Dealer reaches 17 
    if player_hand.value <= 21:
        
        while dealer_hand.value < 17:
            hit(deck,dealer_hand)    
    
        # Show all cards
        show_all(player_hand,dealer_hand)
        
        # Run different winning scenarios
        if dealer_hand.value > 21:
            dealer_busts(player_hand,dealer_hand,player_chips)

        elif dealer_hand.value > player_hand.value:
            dealer_wins(player_hand,dealer_hand,player_chips)

        elif dealer_hand.value < player_hand.value:
            player_win(player_hand,dealer_hand,player_chips)

        else:
            push(player_hand,dealer_hand)        
    
    # Inform Player of their chips total 
    print("\nPlayer's winnings stand at",player_chips.total)
    
    # Ask to play again
    new_game = input("Would you like to play another hand? Enter 'y' or 'n' ")
    
    if new_game[0].lower()=='y':
        playing=True
        continue
    else:
        print("Thanks for playing!")
        break