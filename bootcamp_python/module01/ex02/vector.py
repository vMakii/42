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
    
    # must be identical
    def __repr__(self):
        return self.__str__()

    # add & radd : only vectors of the same shape.
    def __add__(self, other: 'Vector') -> 'Vector':
        """Add two vectors."""
        if self.shape != other.shape:
            raise ValueError("Vectors must have the same shape for addition")
        
        new_values = [a + b for a, b in zip(self.values, other.values)]
        
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
    
    def __radd__(self, other: 'Vector') -> 'Vector':
        """Support right-hand addition."""
        return self.__add__(other)

    # sub & rsub : only vectors of the same shape.
    def __sub__(self, other: 'Vector') -> 'Vector':
        """Subtract two vectors."""
        if self.shape != other.shape:
            raise ValueError("Vectors must have the same shape for subtraction")
        
        new_values = [a - b for a, b in zip(self.values, other.values)]
        
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
        
    def __rsub__(self, other: 'Vector') -> 'Vector':
        """Support right-hand subtraction."""
        if self.shape != other.shape:
            raise ValueError("Vectors must have the same shape for subtraction")
        
        new_values = [b - a for a, b in zip(self.values, other.values)]
        
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

    # mul & rmul: only scalars (to perform multiplication of a Vector by a scalar).
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
    
    # truediv : only with scalars (to perform division of a Vector by a scalar).
    def __truediv__(self, scalar: Union[int, float]) -> 'Vector':
        """Divide vector by a scalar."""
        if not isinstance(scalar, (int, float)):
            raise TypeError("Can only divide vector by a scalar")
        if scalar == 0:
            raise ZeroDivisionError("division by zero.")
        
        new_values = [v / scalar for v in self.values]
        
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
        
    # rtruediv : raises an NotImplementedError with the message "Division of a scalar by a Vector is not defined here."
    def __rtruediv__(self, scalar: Union[int, float]) -> 'Vector':
        """Support scalar / vector division."""
        raise NotImplementedError("Division of a scalar by a Vector is not defined here.")