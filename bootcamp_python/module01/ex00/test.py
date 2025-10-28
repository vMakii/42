from book import Book
from recipe import Recipe
import datetime

def test_recipe_creation():
    """Test Recipe creation with valid data."""
    print("=== Testing Recipe Creation ===")
    
    # Test valid recipe
    try:
        recipe = Recipe(
            name="Pasta Carbonara",
            cooking_lvl=3,
            cooking_time=30,
            ingredients=["pasta", "eggs", "bacon", "parmesan"],
            description="Classic Italian pasta dish",
            recipe_type="lunch"
        )
        print("✓ Valid recipe created successfully")
        print(recipe)
    except Exception as e:
        print(f"✗ Error creating valid recipe: {e}")

def test_recipe_validation():
    """Test Recipe validation with invalid data."""
    print("\n=== Testing Recipe Validation ===")
    
    # Test invalid name (empty)
    try:
        Recipe("", 3, 30, ["pasta"], "desc", "lunch")
        print("✗ Should have failed with empty name")
    except ValueError as e:
        print(f"✓ Correctly caught empty name: {e}")
    
    # Test invalid cooking level (out of range)
    try:
        Recipe("Test", 6, 30, ["pasta"], "desc", "lunch")
        print("✗ Should have failed with cooking level > 5")
    except ValueError as e:
        print(f"✓ Correctly caught invalid cooking level: {e}")
    
    # Test invalid cooking time (negative)
    try:
        Recipe("Test", 3, -10, ["pasta"], "desc", "lunch")
        print("✗ Should have failed with negative cooking time")
    except ValueError as e:
        print(f"✓ Correctly caught negative cooking time: {e}")
    
    # Test empty ingredients list
    try:
        Recipe("Test", 3, 30, [], "desc", "lunch")
        print("✗ Should have failed with empty ingredients")
    except ValueError as e:
        print(f"✓ Correctly caught empty ingredients: {e}")
    
    # Test invalid recipe type (empty)
    try:
        Recipe("Test", 3, 30, ["pasta"], "desc", "")
        print("✗ Should have failed with empty recipe type")
    except ValueError as e:
        print(f"✓ Correctly caught empty recipe type: {e}")

def test_book_creation():
    """Test Book creation."""
    print("\n=== Testing Book Creation ===")
    
    # Test avec dates automatiques
    book1 = Book(name="Auto Date Book")
    print(f"✓ Book created with auto dates: {book1.name}")
    print(f"✓ Creation date set: {book1.creation_date}")
    print(f"✓ Last update equals creation date: {book1.last_update == book1.creation_date}")
    
    # Test avec dates manuelles
    now = datetime.datetime.now()
    earlier = now - datetime.timedelta(days=1)
    book2 = Book(
        name="Manual Date Book",
        creation_date=earlier,
        last_update=now
    )
    print(f"✓ Book created with manual dates: {book2.name}")
    print(f"✓ Creation date < last_update: {book2.creation_date < book2.last_update}")
    
    print(f"✓ Default recipes_list structure: {list(book1.recipes_list.keys())}")
    print(f"✓ All categories empty: {all(len(recipes) == 0 for recipes in book1.recipes_list.values())}")

def test_book_add_recipe():
    """Test adding recipes to book."""
    print("\n=== Testing Book add_recipe ===")
    
    book = Book("Test Book")
    
    # Create test recipes
    recipe1 = Recipe("Salad", 1, 10, ["lettuce", "tomato"], "Fresh salad", "starter")
    recipe2 = Recipe("Burger", 2, 20, ["beef", "bun"], "Tasty burger", "lunch")
    recipe3 = Recipe("Ice Cream", 1, 5, ["milk", "sugar"], "Cold dessert", "dessert")
    
    # Test adding valid recipes
    old_update = book.last_update
    # Petit délai pour s'assurer que la date change
    import time
    time.sleep(0.001)
    book.add_recipe(recipe1)
    print(f"✓ Added starter recipe: {recipe1.name}")
    print(f"✓ Last update changed: {book.last_update > old_update}")
    
    book.add_recipe(recipe2)
    book.add_recipe(recipe3)
    print(f"✓ Added lunch and dessert recipes")
    
    # Test adding invalid recipe (not Recipe instance)
    print("Testing invalid recipe addition:")
    book.add_recipe("not a recipe")
    
    # Verify recipes were added correctly
    print(f"✓ Starter recipes: {len(book.recipes_list['starter'])}")
    print(f"✓ Lunch recipes: {len(book.recipes_list['lunch'])}")
    print(f"✓ Dessert recipes: {len(book.recipes_list['dessert'])}")

def test_book_get_recipe_by_name():
    """Test getting recipe by name."""
    print("\n=== Testing Book get_recipe_by_name ===")
    
    book = Book("Test Book")
    
    # Add test recipes
    recipe1 = Recipe("Caesar Salad", 2, 15, ["lettuce", "croutons", "dressing"], "Classic salad", "starter")
    recipe2 = Recipe("Spaghetti", 3, 25, ["pasta", "tomato sauce"], "Italian pasta", "lunch")
    
    book.add_recipe(recipe1)
    book.add_recipe(recipe2)
    
    # Test finding existing recipe
    print("Looking for 'Caesar Salad':")
    found_recipe = book.get_recipe_by_name("Caesar Salad")
    if found_recipe and found_recipe.name == "Caesar Salad":
        print("✓ Found correct recipe")
    else:
        print("✗ Failed to find recipe")
    
    # Test finding non-existing recipe
    print("\nLooking for 'Pizza':")
    not_found = book.get_recipe_by_name("Pizza")
    if not_found is None:
        print("✓ Correctly returned None for non-existing recipe")
    else:
        print("✗ Should have returned None")

def test_book_get_recipes_by_types():
    """Test getting recipes by type."""
    print("\n=== Testing Book get_recipes_by_types ===")
    
    book = Book("Test Book")
    
    # Add test recipes
    starter1 = Recipe("Soup", 2, 20, ["vegetables", "broth"], "Warm soup", "starter")
    starter2 = Recipe("Bruschetta", 1, 10, ["bread", "tomato"], "Italian appetizer", "starter")
    lunch1 = Recipe("Sandwich", 1, 5, ["bread", "ham"], "Quick lunch", "lunch")
    
    book.add_recipe(starter1)
    book.add_recipe(starter2)
    book.add_recipe(lunch1)
    
    # Test getting starters
    starters = book.get_recipes_by_types("starter")
    print(f"✓ Starter recipes: {starters}")
    if len(starters) == 2 and "Soup" in starters and "Bruschetta" in starters:
        print("✓ Correct starter recipes returned")
    else:
        print("✗ Incorrect starter recipes")
    
    # Test getting lunch recipes
    lunch_recipes = book.get_recipes_by_types("lunch")
    print(f"✓ Lunch recipes: {lunch_recipes}")
    if len(lunch_recipes) == 1 and "Sandwich" in lunch_recipes:
        print("✓ Correct lunch recipes returned")
    else:
        print("✗ Incorrect lunch recipes")
    
    # Test empty category
    desserts = book.get_recipes_by_types("dessert")
    print(f"✓ Dessert recipes (empty): {desserts}")
    if len(desserts) == 0:
        print("✓ Correctly returned empty list for desserts")
    else:
        print("✗ Should have returned empty list")
    
    # Test invalid category
    print("\nTesting invalid category:")
    invalid = book.get_recipes_by_types("invalid_type")
    if len(invalid) == 0:
        print("✓ Correctly handled invalid recipe type")
    else:
        print("✗ Should have returned empty list for invalid type")

def test_recipe_str():
    """Test Recipe string representation."""
    print("\n=== Testing Recipe __str__ ===")
    
    recipe = Recipe(
        name="Test Recipe",
        cooking_lvl=4,
        cooking_time=45,
        ingredients=["ingredient1", "ingredient2", "ingredient3"],
        description="A test recipe for demonstration",
        recipe_type="lunch"
    )
    
    str_repr = str(recipe)
    print("Recipe string representation:")
    print(str_repr)
    
    # Check if all fields are present
    checks = [
        ("name", "Test Recipe" in str_repr),
        ("cooking_lvl", "4" in str_repr),
        ("cooking_time", "45" in str_repr),
        ("ingredients", "ingredient1" in str_repr),
        ("description", "A test recipe for demonstration" in str_repr),
        ("recipe_type", "lunch" in str_repr)
    ]
    
    for field, present in checks:
        if present:
            print(f"✓ {field} present in string representation")
        else:
            print(f"✗ {field} missing from string representation")

def run_all_tests():
    """Run all test functions."""
    print("🧪 Starting comprehensive tests for Recipe and Book classes\n")
    
    test_recipe_creation()
    test_recipe_validation()
    test_recipe_str()
    test_book_creation()
    test_book_add_recipe()
    test_book_get_recipe_by_name()
    test_book_get_recipes_by_types()
    
    print("\n🎉 All tests completed!")

if __name__ == "__main__":
    run_all_tests() 