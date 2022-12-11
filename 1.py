import inflect

engine = inflect.engine()
your_string = input('Your word: ')
print("New word is: ")
plural = engine.plural(your_string)
print(plural)   
i = 1

while i == 1:
    engine = inflect.engine()
    your_string = input('Your word: ')
    print("New word is: ")
    plural = engine.plural(your_string)
    print(plural)
    