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