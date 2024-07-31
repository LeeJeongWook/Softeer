num = input("주민등록번호 입력:")

if((num[7] == '1') or (num[7] == '3')):
    gender = "남자"
elif((num[7] == '2') or (num[7] == '4')):
    gender = "여자"

if((num[7] == '1') or (num[7] == '2')):
    year = "19"
    year += num[0:2]
elif((num[7] == '3') or (num[7] == '4')):
    year = "20"
    year += num[0:2]

print(gender, year, "년 출생")