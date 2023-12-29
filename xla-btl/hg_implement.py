import cv2
import numpy as np
import matplotlib.pyplot as plt

def histogram_equalization_custom(image_path):
    # Đọc ảnh
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    rows, cols = img.shape

    # Tính histogram
    histogram = np.zeros(256, dtype=int)
    for i in range(rows):
        for j in range(cols):
            histogram[img[i, j]] += 1

    # Tính histogram tích lũy
    cumulative_histogram = np.cumsum(histogram)

    # Chuẩn hóa histogram tích lũy
    normalized_cumulative_histogram = (cumulative_histogram - cumulative_histogram.min()) * 255 / (
            cumulative_histogram.max() - cumulative_histogram.min())

    # Ánh xạ lại giá trị pixel của ảnh gốc
    equ = np.zeros_like(img, dtype=np.uint8)
    for i in range(rows):
        for j in range(cols):
            equ[i, j] = normalized_cumulative_histogram[img[i, j]]

    # Vẽ histogram của ảnh gốc
    plt.figure(figsize=(10, 5))
    plt.subplot(231), plt.imshow(img, cmap="gray"), plt.title("Ảnh gốc")
    plt.subplot(234), plt.hist(img.flatten(), 256, [0, 256], color="r"), plt.title("Histogram ảnh gốc")

    # Hiển thị ảnh đã cân bằng histogram
    plt.subplot(232), plt.imshow(equ, cmap="gray"), plt.title("Ảnh đã cân bằng histogram")
    plt.subplot(235), plt.hist(equ.flatten(), 256, [0, 256], color="r"), plt.title("Histogram ảnh đã cân bằng")

    plt.show()

    # Lưu ảnh đã cân bằng histogram
    cv2.imwrite("equ_histogram_custom.jpg", equ)

# Thay đổi đường dẫn tới ảnh của bạn
image_path = "png-demo.jpg"

# Gọi hàm cân bằng histogram
histogram_equalization_custom(image_path)
