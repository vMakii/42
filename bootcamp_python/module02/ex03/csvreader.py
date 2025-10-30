import csv

class CsvReader():
    def __init__(self, filename=None, sep=',', header=False, skip_top=0, skip_bottom=0):
        self.filename = filename
        self.sep = sep
        self.header = header
        self.skip_top = skip_top
        self.skip_bottom = skip_bottom
        self.data = []
        self.header_data = None
        self.file = None

    def __enter__(self):
        # Check if filename is provided
        if self.filename is None:
            return None
        
        # Try to open the file
        try:
            self.file = open(self.filename, 'r')
        except FileNotFoundError:
            return None
        except Exception:
            return None
        
        # Read and parse the CSV file
        try:
            reader = csv.reader(self.file, delimiter=self.sep)
            lines = list(reader)
            
            # Check if file is empty
            if not lines:
                return None
            
            # Validate that all lines have the same number of fields
            expected_fields = len(lines[0])
            for line in lines:
                if len(line) != expected_fields:
                    return None
            
            # Extract header if needed
            start_idx = 0
            if self.header and lines:
                self.header_data = lines[0]
                start_idx = 1
            
            # Apply skip_top and skip_bottom
            start_idx += self.skip_top
            end_idx = len(lines) - self.skip_bottom
            
            # Extract data
            if start_idx < end_idx:
                self.data = lines[start_idx:end_idx]
            else:
                self.data = []
            
            return self
        except Exception:
            return None

    def __exit__(self, exc_type, exc_value, traceback):
        if self.file:
            self.file.close()

    def getdata(self):
        """ Retrieves the data/records from skip_top to skip bottom.
        Returns:
            nested list (list(list, list, ...)) representing the data.
        """
        return self.data

    def getheader(self):
        """ Retrieves the header from the csv file.
        Returns:
            list: representing the data (when self.header is True).
            None: (when self.header is False).
        """
        return self.header_data