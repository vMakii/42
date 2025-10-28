from dataclasses import dataclass

@dataclass
class GotCharacter:
    first_name: str
    is_alive: bool = True

@dataclass
class Lannister(GotCharacter):
    """
    A class representing the Lannister family.
    """
    family_name: str = "Lannister"
    house_words: str = "Hear Me Roar!"

    def print_house_words(self):
        print(f"{self.family_name} house words: {self.house_words}")

    def die(self):
        self.is_alive = False
        print(f"{self.first_name} {self.family_name} has died.")

@dataclass
class Stark(GotCharacter):
    """
    A class representing the Stark family.
    """
    family_name: str = "Stark"
    house_words: str = "Winter is Coming"

    def print_house_words(self):
        print(f"{self.family_name} house words: {self.house_words}")

    def die(self):
        self.is_alive = False
        print(f"{self.first_name} {self.family_name} has died.")

def main():
    # Create a Lannister character
    jaime = Lannister(first_name="Jaime")
    print(jaime.__doc__)
    print(jaime.__dict__)
    jaime.print_house_words()
    print(f"Is {jaime.first_name} alive? {jaime.is_alive}")
    jaime.die()
    print(f"Is {jaime.first_name} alive? {jaime.is_alive}")

    # Create a Stark character
    ned = Stark(first_name="Ned")
    print(ned.__doc__)
    print(ned.__dict__)
    ned.print_house_words()
    print(f"Is {ned.first_name} alive? {ned.is_alive}")
    ned.die()
    print(f"Is {ned.first_name} alive? {ned.is_alive}")

if __name__ == "__main__":
    main()