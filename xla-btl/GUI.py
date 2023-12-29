import cv2
import numpy as np
import matplotlib.pyplot as plt
from tkinter import filedialog
from tkinter import Tk, Button, Label, Canvas
from PIL import Image, ImageTk

class ImageProcessor:
    def __init__(self, root):
        self.root = root
        self.root.title("Histogram Equalization")

        # Tạo các thành phần giao diện
        self.label = Label(root, text="Chọn ảnh và nhấn nút để cân bằng histogram")
        self.label.pack(pady=10)

        self.canvas = Canvas(root, width=400, height=400)
        self.canvas.pack(pady=10)

        self.button = Button(root, text="Chọn ảnh", command=self.choose_image)
        self.button.pack(pady=10)

    def histogram_equalization_custom(self, image):
        if len(image.shape) > 2:
            img = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        else:
            img = image.copy()

        rows, cols = img.shape

        histogram = np.zeros(256, dtype=int)
        for i in range(rows):
            for j in range(cols):
                histogram[img[i, j]] += 1

        cumulative_histogram = np.cumsum(histogram)
        normalized_cumulative_histogram = (cumulative_histogram - cumulative_histogram.min()) * 255 / (
                cumulative_histogram.max() - cumulative_histogram.min())

        equ = np.zeros_like(img, dtype=np.uint8)
        for i in range(rows):
            for j in range(cols):
                equ[i, j] = normalized_cumulative_histogram[img[i, j]]

        plt.figure(figsize=(10, 5))
        plt.subplot(231), plt.imshow(img, cmap="gray"), plt.title("Ảnh gốc")
        plt.subplot(234), plt.hist(img.flatten(), 256, [0, 256], color="r"), plt.title("Histogram ảnh gốc")

        plt.subplot(232), plt.imshow(equ, cmap="gray"), plt.title("Ảnh đã cân bằng histogram")
        plt.subplot(235), plt.hist(equ.flatten(), 256, [0, 256], color="r"), plt.title("Histogram ảnh đã cân bằng")

        plt.show()

        cv2.imwrite("equ_histogram_custom.jpg", equ)

    def choose_image(self):
        file_path = filedialog.askopenfilename()
        if file_path:
            image = cv2.imread(file_path)
            self.display_image(image)
            self.histogram_equalization_custom(image)

    def display_image(self, image):
        # Chuyển đổi mảng NumPy thành đối tượng PhotoImage của Tkinter sử dụng Pillow
        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        image = Image.fromarray(image)
        image = ImageTk.PhotoImage(image=image)

        # Hiển thị ảnh trên Canvas
        self.canvas.config(width=image.width(), height=image.height())
        self.canvas.create_image(0, 0, anchor="nw", image=image)
        # Lưu reference để ngăn garbage collection
        self.canvas.image = image

if __name__ == "__main__":
    root = Tk()
    app = ImageProcessor(root)
    root.mainloop()
