def hit_or_stand(Deck,Hand):
    global playing
    
    while True:
        x=input('Would u like to Hit or Stand: H\S').upper()
        if x=='H':
            hit(Deck,Hand)
        elif x='S'
            print('Please wait while dealer is playing')
            playing=False
        else:
            print('Sorry! please try again.')
            continue
        break