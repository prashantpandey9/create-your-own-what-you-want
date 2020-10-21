class Chips:
    
    def __init__(self):
        self.total=100 #we can override the total value by  putting __init__(self,total=100)
        self.bet=0 #self.total=total
    
    def __winbet__(self):
        self.total+=self.bet
        
    def __losebet__(self):
        self.total-=self.bet