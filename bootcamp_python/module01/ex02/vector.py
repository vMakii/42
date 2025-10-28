from dataclasses import dataclass
from typing import Union, List, Tuple

@dataclass
class Vector:
    values: Union[List[float], List[List[float]]]
    shape: Tuple[int, ...] = None

    def __post_init__(self):
        """Validate vector data after initialization."""
        if not isinstance(self.values, list) or len(self.values) == 0:
            raise ValueError("Values must be a non-empty list")
        
        # Auto-calculate shape if not provided
        if self.shape is None:
            if isinstance(self.values[0], list):
                # 2D vector (matrix)
                rows = len(self.values)
                cols = len(self.values[0]) if self.values else 0
                self.shape = (rows, cols)
                # Flatten for internal representation
                flat_values = []
                for row in self.values:
                    if len(row) != cols:
                        raise ValueError("All rows must have the same length")
                    flat_values.extend(row)
                self.values = flat_values
            else:
                # 1D vector
                self.shape = (len(self.values),)
        
        # Validate all values are numeric
        if not all(isinstance(v, (int, float)) for v in self.values):
            raise ValueError("All values must be numeric")
        
    def __str__(self):
        """Return a string representation of the vector."""
        if len(self.shape) == 2:
            # 2D vector - reconstruct matrix format
            rows, cols = self.shape
            matrix = []
            for i in range(rows):
                row = self.values[i * cols:(i + 1) * cols]
                matrix.append(row)
            return f"Vector({matrix})"
        else:
            return f"Vector({self.values})"
    
    def dot(self, other: 'Vector') -> float:
        """Calculate the dot product of this vector with another."""
        if self.shape != other.shape:
            raise ValueError("Vectors must have the same shape for dot product")
        return sum(a * b for a, b in zip(self.values, other.values))
    
    def T(self) -> 'Vector':
        """Return the transpose of the vector."""
        if len(self.shape) == 1:
            # 1D vector becomes column vector
            matrix = [[v] for v in self.values]
            return Vector(matrix)
        elif len(self.shape) == 2:
            # Transpose 2D matrix
            rows, cols = self.shape
            matrix = []
            for i in range(rows):
                row = self.values[i * cols:(i + 1) * cols]
                matrix.append(row)
            
            # Transpose the matrix
            transposed = [[matrix[i][j] for i in range(rows)] for j in range(cols)]
            return Vector(transposed)
        else:
            raise ValueError("Transpose is only defined for 1D or 2D vectors")
    
    def __mul__(self, scalar: Union[int, float]) -> 'Vector':
        """Multiply vector by a scalar."""
        if not isinstance(scalar, (int, float)):
            raise TypeError("Can only multiply vector by a scalar")
        
        new_values = [v * scalar for v in self.values]
        
        if len(self.shape) == 2:
            # Convert back to 2D format for constructor
            rows, cols = self.shape
            matrix = []
            for i in range(rows):
                row = new_values[i * cols:(i + 1) * cols]
                matrix.append(row)
            return Vector(matrix)
        else:
            return Vector(new_values)
    
    def __rmul__(self, scalar: Union[int, float]) -> 'Vector':
        """Support scalar * vector multiplication."""
        return self.__mul__(scalar)