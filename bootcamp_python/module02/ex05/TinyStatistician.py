from dataclasses import dataclass

@dataclass
class TinyStatistician:
    def mean(self, x):
        if not x:
            return None
        return sum(x) / len(x)
    
    def median(self, x):
        if not x:
            return None
        sorted_x = sorted(x)
        n = len(sorted_x)
        mid = n // 2
        if n % 2 == 0:
            return (sorted_x[mid - 1] + sorted_x[mid]) / 2
        else:
            return sorted_x[mid]
        
    def quartile(self, x):
        if not x:
            return None
        sorted_x = sorted(x)
        n = len(sorted_x)
        
        # Calculate Q1
        q1_pos = (n - 1) * 0.25
        q1_lower = int(q1_pos)
        q1_upper = q1_lower + 1
        q1_weight = q1_pos - q1_lower
        
        if q1_upper < n:
            q1 = sorted_x[q1_lower] * (1 - q1_weight) + sorted_x[q1_upper] * q1_weight
        else:
            q1 = sorted_x[q1_lower]
        
        # Calculate Q3
        q3_pos = (n - 1) * 0.75
        q3_lower = int(q3_pos)
        q3_upper = q3_lower + 1
        q3_weight = q3_pos - q3_lower
        
        if q3_upper < n:
            q3 = sorted_x[q3_lower] * (1 - q3_weight) + sorted_x[q3_upper] * q3_weight
        else:
            q3 = sorted_x[q3_lower]
        
        return [float(q1), float(q3)]
        
    def var(self, x):
        if not x:
            return None
        mean_x = self.mean(x)
        return sum((xi - mean_x) ** 2 for xi in x) / len(x)
    
    def std(self, x):
        variance = self.var(x)
        if variance is None:
            return None
        return variance ** 0.5