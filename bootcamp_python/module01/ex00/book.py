from dataclasses import dataclass, field
from recipe import Recipe
import datetime

@dataclass
class Book:
    name: str
    last_update: datetime.datetime = field(default_factory=datetime.datetime.now)
    creation_date: datetime.datetime = field(default_factory=datetime.datetime.now)
    recipes_list: dict = field(default_factory=lambda: {
        "starter": [],
        "lunch": [],
        "dessert": []
    })
    
    def __post_init__(self):
        """Runs checks."""
        # if last_update and creation_date are very close (same second),
        # we consider it a creation and synchronize
        if abs((self.last_update - self.creation_date).total_seconds()) < 1:
            self.last_update = self.creation_date
        if not isinstance(self.name, str) or not self.name.strip():
            raise ValueError("Book name cannot be empty")
        if not isinstance(self.creation_date, datetime.datetime):
            raise ValueError("creation_date must be a datetime object")
        if not isinstance(self.last_update, datetime.datetime):
            raise ValueError("last_update must be a datetime object")
        if self.creation_date > self.last_update:
            raise ValueError("creation_date cannot be after last_update")
        if not isinstance(self.recipes_list, dict):
            raise ValueError("recipes_list must be a dictionary")

    def get_recipe_by_name(self, name):
        """Prints a recipe with the name \texttt{name} and returns the instance"""
        if name not in [recipe.name for recipes in self.recipes_list.values() for recipe in recipes]:
            print(f"Recipe '{name}' not found.")
            return None
        for category, recipes in self.recipes_list.items():
            for recipe in recipes:
                if recipe.name == name:
                    print(recipe)
                    return recipe
    
    def get_recipes_by_types(self, recipe_type):
        """Get all recipe names for a given recipe type."""
        if recipe_type not in self.recipes_list:
            print(f"Recipe type '{recipe_type}' not found.")
            return []
        return [recipe.name for recipe in self.recipes_list[recipe_type]]
    
    def add_recipe(self, recipe):
        """Add a recipe to the book and update last_update."""
        if not isinstance(recipe, Recipe):
            print("Invalid recipe. Must be an instance of Recipe.")
            return
        self.recipes_list[recipe.recipe_type].append(recipe)
        self.last_update = datetime.datetime.now()
