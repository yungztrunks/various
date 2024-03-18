import pylnk3 as pylnk
import os

lnk_file = ""

lnk_file_path = os.path.join(os.path.dirname(__file__), lnk_file)

with open(lnk_file_path, 'rb') as file:
    lnk = pylnk.Lnk(file)
    print(lnk)
    save = open("output.txt", "w")
    save.write(str(lnk))