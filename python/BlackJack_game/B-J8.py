#def hit(Deck,Hand):
#    while True:    
 #       print('Do you want to hit? Y/N',O=input())
 #       try:
  #          if O=='Y':
   #             Hand.add_card(Deck.deal())
    #            Hand.ajust_4_ace()
     #       else:
      #          ValueError
       # except:
        #    pass
def hit(Deck,Hand):
    Hand.add_card(Deck.deal())
    Hand.ajust_4_ace()