MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "milk": 0,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}


def enough_of_ingredients(drink):
    for item in MENU[drink]["ingredients"]:
        if item > resources[item]:
            print(f"Sorry, there is not enough {item} in the machine.")
            return False
    return True


def process_coins():
    quarters = int(input("Insert coins: \nQuarters: "))
    dimes = int(input("Dimes: "))
    nickles = int(input("Nickles: "))
    pennies = int(input("Pennies: "))
    total = (quarters * 25 + dimes * 10 + nickles * 5 + pennies) / 100
    return total


def make_coffee(drink):
    if drink != "espresso":
        for item in resources:
            resources[item] -= MENU[drink]["ingredients"][item]
    else:
        resources["water"] -= MENU[drink]["ingredients"]["water"]
        resources["coffee"] -= MENU[drink]["ingredients"]["coffee"]


def report():
    print(f"Machine Status:\nWater: {resources['water']}ml\n"
          f"Milk: {resources['milk']}ml\nCoffee: {resources['coffee']}g")


machine_on = True
while machine_on:
    coffee = input("What would you like? (espresso/latte/cappuccino): ")
    coffee = coffee.lower()
    if coffee == "report":
        report()
    elif coffee == "off":
        machine_on = False
    elif coffee in MENU:
        can_be_made = enough_of_ingredients(coffee)
        if can_be_made:
            print(f"That will be ${MENU[coffee]['cost']}0")
            inserted_coins = process_coins()
            if inserted_coins >= MENU[coffee]["cost"]:
                change = inserted_coins - MENU[coffee]["cost"]
                print(f"Here is your change: ${change}0")
                report()
                make_coffee(coffee)
                report()
                print(f"Here is your {coffee}. Enjoy!")
            else:
                print("Sorry, that is not enough money.")
    else:
        print("Sorry, this item is not on the menu.")
