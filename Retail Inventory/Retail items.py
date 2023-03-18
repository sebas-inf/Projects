#Retail items
#Sebastian Infante(Navigator)U04743487
#Benjamin(Driver)U61105360
#This program takes user input for two types of clothing items at a retail store, it's current stock, and it's listed
#price. It will format the user's input in a neat table, that displays all of the inputted information. 

class Retail_Item:
    def __init__(self, i_type, stock, price):
        self.i_type = i_type
        self.stock = stock
        self.price = price

    def __str__(self, i_type, stock, price):
        i_type = i_type.ljust(10)
        stock = stock.ljust(5)
        price = price
        return i_type, stock, price


def main():

    type_item1 = input('Type of item 1: ')
    stock_item1 = input('Current stock of item 1: ')
    price_item1 = float(input('Price of item 1: '))

    item1 = Retail_Item(type_item1.title(), stock_item1, price_item1)

    type_item2 = input('\nType of item 2: ')
    stock_item2 = input('Current stock of item 2: ')
    price_item2 = float(input('Price of item 2: '))

    item2 = Retail_Item(type_item2.title(), stock_item2, price_item2)

    print('\nHere is a summary of the items you provided:')
    print('Item               Amount              Price')
    print('--------------------------------------------')
    print('{:21}{:17}${:.2f}'.format(item1.i_type, item1.stock, item1.price))
    print('{:21}{:17}${:.2f}'.format(item2.i_type, item2.stock, item2.price))

main()
