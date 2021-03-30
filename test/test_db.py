import sqlite3

con = sqlite3.connect('example.db')
cursor = con.cursor()
# cursor.execute('''
#     CREATE TABLE stocks
#     (date    text,
#      trans   text,
#      symbol  text,
#      qty     real,
#      price   real)
# ''')

# cursor.execute('''
#     INSERT INTO stocks
#         (date, trans, symbol, qty, price)
#     VALUES
#         ('2006-091-05', 'BUY', 'RHAT', 100, 35.14)
# ''')
#
# con.commit()

symbol = 'RHAT'
cursor.execute('''
    SELECT * FROM stocks
    WHERE
        symbol = '%s'
'''%symbol)
print(cursor.fetchone())





con.close()


