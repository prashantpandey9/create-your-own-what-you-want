def show_some():
    print("\n Dealer's hand")
    print("<card hidden>")
    print('',dealer.cards[1])
    print('Player hand',player.cards,sep='\n')

def show_all():
    print("\n Dealer's hand: ",*dealer.cards,sep='\n')
    print("\n Player's hand: ",*player.cards,sep='\n' )
    print("\n Dealer's value: ",dealer.value)
    print("\n Player's value: ",player.value)    