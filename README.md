# Bài 1: Tính giá vé công viên

t = int(input())

for _ in range(t):
    age = int(input())
    if age < 4:
        print("FREE")
    elif age < 18:
        print(10)
    elif age < 60:
        print(20)
    else:
        print(15)


# Bài 2: Xử lý chuỗi

n = int(input())

for _ in range(n):
    s = input().split()
    result = []

    for word in s:
        clean_word = ''.join(c for c in word if c.isalpha())
        if len(clean_word) > 0:
            result.append(str(len(clean_word)))

    print(" ".join(result))


# Bài 3: Từ điển song ngữ

q = int(input())
dictionary = {}

for _ in range(q):
    cmd = input().split()

    if cmd[0] == "add":
        eng = cmd[1]
        viet = " ".join(cmd[2:])
        dictionary[eng] = viet

    elif cmd[0] == "find":
        print(dictionary.get(cmd[1], "Not found"))


# Bài 4: Quản lý sinh viên

class Student:
    def __init__(self, id, name, toan, ly, hoa, course, lop):
        self.id = id
        self.name = name
        self.toan = float(toan)
        self.ly = float(ly)
        self.hoa = float(hoa)
        self.course = int(course)
        self.lop = lop
        self.total = self.toan + self.ly + self.hoa

    def __str__(self):
        return f"{self.id} {self.name} {self.total:.2f} {self.lop} {self.course}"


T = int(input())

for t in range(1, T + 1):
    n = int(input())
    students = []

    for _ in range(n):
        parts = input().split()
        id = parts[0]
        toan = parts[-5]
        ly = parts[-4]
        hoa = parts[-3]
        course = parts[-2]
        lop = parts[-1]
        name = " ".join(parts[1:-5])

        students.append(Student(id, name, toan, ly, hoa, course, lop))

    students.sort(key=lambda x: (-x.total, x.id))

    print(f"Case #{t}:")
    for s in students:
        print(s)


# Bài 5: Đọc file JSON và thống kê

import json

with open("tips.json", encoding="utf-8") as f:
    data = json.load(f)["tips"]

n = int(input())

for _ in range(n):
    sex, smoker = input().split()

    bills = []
    for item in data:
        if item["sex"] == sex and item["smoker"] == smoker:
            bills.append(float(item["total_bill"]))

    if bills:
        total = sum(bills)
        avg = total / len(bills)
        max_val = max(bills)
        min_val = min(bills)

        print(f"{total:.4f} {avg:.4f} {max_val:.4f} {min_val:.4f}")
    else:
        print("0.0000 0.0000 0.0000 0.0000")
