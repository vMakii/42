from dataclasses import dataclass

@dataclass
class TinyStatistician:

    def mean(self, x):
        if not x:
            return None
        return sum(x) / len(x)