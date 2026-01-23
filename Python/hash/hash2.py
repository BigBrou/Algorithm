phone_book1 = ["119", "97674223", "1195524421"]
phone_book2 = ["123", "456", "789"]
phone_book3 = ["12", "123", "1235", "567", "88"]

def solution(phone_book):
    phone_book.sort()

    result = True

    for idx in range(len(phone_book)-1):
        phone = phone_book[idx]
        phone_next = phone_book[idx+1]
        include_check = phone_next.split(phone)[0]

        if include_check == "":
            result = False
            break

    return result


print(solution(phone_book1))
print(solution(phone_book2))
print(solution(phone_book3))