import sys

cookbook = {
    'sandwich': {
        'ingredients': ['ham', 'bread', 'cheese', 'tomatoes'],
        'meal': 'lunch',
        'prep_time': 10
    },
    'cake': {
        'ingredients': ['flour', 'sugar', 'eggs'],
        'meal': 'dessert',
        'prep_time': 60
    },
    'salad': {
        'ingredients': ['avocado', 'arugula', 'tomatoes', 'spinach'],
        'meal': 'lunch',
        'prep_time': 15
    }
}

def add_recipe():
    name = input(">>> Enter a name:\n")
    
    print(">>> Enter ingredients:")
    ingredients = []
    while True:
        ingredient = input()
        if ingredient == "":
            break
        ingredients.append(ingredient)

    meal = input(">>> Enter a meal type:\n")
    prep_time = int(input(">>> Enter a preparation time:\n"))
    
    cookbook[name] = {
        'ingredients': ingredients,
        'meal': meal,
        'prep_time': prep_time
    }
    print(f"Recipe '{name}' added.\n")

def del_recipe(name):
    if name in cookbook:
        del cookbook[name]
        print(f"Recipe '{name}' deleted.\n")
    else:
        print(f"Recipe '{name}' not found.\n")

def print_recipe(name):
    recipe = cookbook[name]
    print(f"\nRecipe for {name}:")
    print(f"Ingredients list: {recipe['ingredients']}")
    print(f"To be eaten for {recipe['meal']}.")
    print(f"Takes {recipe['prep_time']} minutes of cooking.\n")

def print_cookbook():
    for name in cookbook:
        print_recipe(name)

def main():
    print("Welcome to the Python Cookbook !")
    while True:
        print("List of available options:")
        print("1: Add a recipe")
        print("2: Delete a recipe")
        print("3: Print a recipe")
        print("4: Print the cookbook")
        print("5: Quit")
        
        choice = input("\nPlease select an option:\n>> ")
        print()

        if choice == '1':
            add_recipe()
        elif choice == '2':
            name = input("Enter the recipe name to delete:\n>>>")
            del_recipe(name)
        elif choice == '3':
            name = input("Please enter a recipe name to get its details:\n>> ")
            if name in cookbook:
                print_recipe(name)
            else:
                print(f"Recipe '{name}' not found.\n")
        elif choice == '4':
            print_cookbook()
        elif choice == '5':
            print("Cookbook closed. Goodbye !")
            break
        else:
            print("Sorry, this option does not exist.")

if __name__ == "__main__":
    main()