def take_bet(chips):
    while True:
        try:
            Chips.bet=int(input('Place your bet: '))
        except ValueError:
            print('Sorry!! bet must a integer)
        else:
            if Chips.total<Chips.bet:
                print('You dont have enough chips!!')
            else:
                break