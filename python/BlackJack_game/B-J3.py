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