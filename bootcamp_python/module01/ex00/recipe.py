from dataclasses import dataclass

@dataclass
class Recipe:
    name: str
    cooking_lvl: int
    cooking_time: int
    ingredients: list[str]
    description: str = ""
    recipe_type: str = ""
    
    def __post_init__(self):
        """Validate recipe data after initialization."""
        self.validate()
    
    def validate(self):
        """Check that all required fields are properly set."""
        if not isinstance(self.name, str) or not self.name.strip():
            raise ValueError("Recipe name cannot be empty")
        if not isinstance(self.cooking_lvl, int) or not (1 <= self.cooking_lvl <= 5):
            raise ValueError("Cooking level must be an integer between 1 and 5")
        if not isinstance(self.cooking_time, int) or self.cooking_time < 0:
            raise ValueError("Cooking time must be a non-negative integer")
        if not isinstance(self.ingredients, list) or len(self.ingredients) == 0:
            raise ValueError("Ingredients list cannot be empty")
        if not all(isinstance(ing, str) and ing.strip() for ing in self.ingredients):
            raise ValueError("All ingredients must be non-empty strings")
        if not isinstance(self.recipe_type, str) or not self.recipe_type.strip():
            raise ValueError("Recipe type cannot be empty")
        
    def __str__(self):
        """Return a string representation of the recipe."""
        txt = f"Recipe: {self.name}\n"
        txt += f"Cooking Level: {self.cooking_lvl}\n"
        txt += f"Cooking Time: {self.cooking_time} minutes\n"
        txt += f"Ingredients: {', '.join(self.ingredients)}\n"
        txt += f"Description: {self.description}\n"
        txt += f"Recipe Type: {self.recipe_type}\n"
        return txt