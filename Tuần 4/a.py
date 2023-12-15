def solve(a, b, k, x, y):
    # Bước 1: Tính tổng số kẹo của mỗi loại
    total_cam = a * k
    total_chanh = b * k

    # Bước 2: Tính số kẹo đã ăn
    eaten_cam = x
    eaten_chanh = y

    # Bước 3: Tính số kẹo còn lại
    remaining_cam = total_cam - eaten_cam
    remaining_chanh = total_chanh - eaten_chanh

    # Bước 4: Chia đôi số kẹo còn lại và lấy phần nhiều hơn
    half_cam = remaining_cam // 2
    half_chanh = remaining_chanh // 2
    remaining_cam = half_cam + remaining_cam % 2
    remaining_chanh = half_chanh + remaining_chanh % 2

    # Bước 5: In ra kết quả
    print(remaining_cam, remaining_chanh)

# Input
a, b, k, x, y = map(int, input().split())
# Gọi hàm giải bài toán
solve(a, b, k, x, y)
