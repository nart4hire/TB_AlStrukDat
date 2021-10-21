# Tugas Besar Alstrukdat

ToDo List:
  - Main Menu:
    - New Game
    - Load Game
    - Exit
  - Time Mechanism (Time taken from one place to another)
  - Daftar Pesanan:
    - Waktu Pesanan Masuk
    - Lokasi Pick Up
    - Lokasi Drop Off
    - Jenis Item
    - Waktu Pesanan Hangus
  - To Do List:
    - Lokasi Pick Up
    - Lokasi Drop Off
    - Jenis Item
  - In Progress List:
  - Tas (3 item stack)
  - Jenis Item:
    - Normal Item (200 yen)
    - Heavy Item (+1 slow, 400 yen, done: Speed boost)
    - Perishable Item (Time limited, 400 yen, done: increase cap)
    - VIP Item (Priority in todo list, 600 yen, done: return to sender)
  - Ability:
    - Speed boost (1 time = 2 spaces, expires when carrying heavy item || after 10 spaces)
    - Increase Cap (bag cap + 1)
    - Return to sender (top stack back to todo list (undo) (resets time limit for perishable) (cant for VIP)
  - Gadget:
    - Kain Pembungkus waktu (800 yen, reset perishable duration)
    - Senter Pembesar (1200 yen, 2 x bag < max cap)
    - Pintu Kemana Saja (1500 yen, TP no time spent)
    - Mesin Waktu (3000 yen, -50 time min 0)
    - Senter pengecil (800 yen, negates 1 heavy item effect lasts until drop off/return)
  - Inventory ( cap 5 for gadgets )
  - Map ( 10x10 to 20x30 surrounded by '*'):
    - base ('8', buy gadget, start fin)
    - mobita (orange)
    - orders (red)
    - drop off top stack (blue)
    - destination (green)
    - none (black)
    - Priority: Mobita > dropoff > pickup > destination > none)
  - Gerakan:
    - Move (reachable positions)
    - Pickup (pickup item, error if none, fifo if multiple)
    - dropoff (dropoff item, error if none at location)
    - Map (shows map)
    - Todo (cth: 1. G -> R (normal item))
    - In progress (cth: 1. Normal item (Tujuan: R))
    - Buy
    - Inventory
    - Help
    - Save
    - return

Game flow:
  - Start (at base, init todo list)
  - End (when all items done/expired, score + time)

Config:
  - map size
  - hq location
  - number of locations
  - location name and coordds
  - relationship matrix (adjacency matrix)
  - Jumlah pesanan 5 - 30
  - time order in, pickup loc, dropoff loc, item type
