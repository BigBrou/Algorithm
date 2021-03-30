
# (Price, Kg)
cargo = [(4, 12), (2, 1), (10, 4), (1, 1), (2, 2)]

def fractional_knapsack(capacity, cargo_data):
    list_ascent = [(per_kg[0], per_kg[1], round(per_kg[0] / per_kg[1], 2)) for per_kg in cargo_data]
    print(list_ascent)

    # sort
    list_ascent = sorted(list_ascent, key=lambda per_kg: per_kg[2], reverse=True)
    print(list_ascent)

    total_price = 0

    for data in list_ascent:
        data_price, data_kg, data_per_price = data[0], data[1], data[2]

        if capacity - data_kg >= 0:
            capacity -= data_kg
            total_price += data_price
        else:
            data_part = round(capacity / data_kg, 2)
            print(data_part)
            total_price += data_part * data_price
            break

    print(total_price)


capacity = 15
fractional_knapsack(capacity, cargo)