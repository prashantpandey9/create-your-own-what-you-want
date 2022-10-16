def vending():

    # You can store your drinks here
    a = {"no": "1A", "item": "Frestea              ", "price": 1.67}
    b = {"no": "1B", "item": "Sosro Tea            ", "price": 1.67}
    c = {"no": "1C", "item": "Botol Tea            ", "price": 1.67}
    d = {"no": "2A", "item": "Good Day Coffee      ", "price": 3.63}
    e = {"no": "2B", "item": "Kopiko 78            ", "price": 3.56}
    f = {"no": "2C", "item": "Golda Coffee         ", "price": 3.44}
    g = {"no": "3A", "item": "Sprite               ", "price": 4.85}
    h = {"no": "3B", "item": "Coca Cola            ", "price": 4.85}
    i = {"no": "3C", "item": "Fanta                ", "price": 4.85}
    items = [a, b, c, d, e, f, g, h, i]

    # User credits initialization
    credits = 0

    print("")
    print("* "*31)
    print("*                    Mini Vending Machine" + (" "*19) + "*")
    print("*                 Tea, Coffee, and Soft Drink" + (" "*15) + "*")
    print("* "*31)
    print("")
    print("* "*31)

    def show(items):

        for item in items:

            # You can add your own currency in 'price' section before item.get("price") 
            print("* ", "Code:", item.get("no"), "||", "Item:", item.get("item"), "||", "Price:", item.get("price"), "  *")

        print("* "*31)
        print("")

    show(items)

    user = input("Please enter the code you want to buy: ")

    # Algorithm:
    for item in items:

        if user == item.get("no"):

            user = item
            price = user.get("price")
            print("")
            print("You will buy " + user.get("item"))
            print("Are you sure?")
            print("")
            print("1. Yes")
            print("2. No")
            print("")
            option = int(input("Press 1 or 2: "))

            if option == 1:

                print("")
                print("Total price: " + str(price - credits))
                credits = credits + int(input("Insert money: "))

                while credits < price:
                    print("")
                    print("The money you entered is still less than " + str(price))
                    print("You need to insert " + str(price - credits) + " more")
                    credits = credits + int(input("Insert money: "))

                print("")
                print("Transaction Complete!")
                print("You have purchased " + user.get('item'))

                credits -= price

                if credits != 0:

                    print("")
                    print("Change: " + str(credits))
                    print("")
                    credits = 0
                    print("Thank you for visiting our Vending Machine.")
                    print("Have a Nice Day!")
                    break

                else:

                    print("")
                    print("Thank you for visiting our Vending Machine.")
                    print("Have a Nice Day!")
                    break

            elif option == 2:

                print("")
                print("If you want to continue the transaction,")
                print("Please restart our Vending Machine")
                break

vending()
