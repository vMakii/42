from dataclasses import dataclass
from PIL import Image
import numpy as np

@dataclass
class ImageProcessor:
    def load(self, path):
        """
        opens the PNG file specified by the path argument and returns an array
        with the RGB values of the pixels in the image. It must display a message
        specifying the dimensions of the image (e.g. 340 x 500)
        """
        try:
            img = Image.open(path)
            img_array = np.array(img, dtype=np.float32) / 255.0
            print(f"Loading image of dimensions {img_array.shape[0]} x {img_array.shape[1]}")
            return img_array
        except FileNotFoundError as e:
            print(f"Exception: FileNotFoundError -- strerror: {e.strerror}")
            return None
        except OSError as e:
            print(f"Exception: OSError -- strerror: {e.strerror if hasattr(e, 'strerror') else None}")
            return None
        except Exception as e:
            print(f"Exception: {type(e).__name__} -- strerror: {str(e)}")
            return None
        
    def display(self, arr):
        """
        takes a numpy array as an argument does not exist or if it can't be read as an image,
        with an appropriate message of your choice.
        """
        try:
            img = Image.fromarray((arr * 255).astype(np.uint8))
            img.show()
        except Exception as e:
            print(f"Exception: {type(e).__name__} -- {str(e)}")