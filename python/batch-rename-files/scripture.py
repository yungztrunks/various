import os
import random
import string

def generate_random_name(length=12):
    zeichen = string.ascii_letters + string.digits
    return ''.join(random.choice(zeichen) for _ in range(length))

def rename_files_to_random(directory):
    os.chdir(directory)
    files = os.listdir()

    for filename in files:
        name, ext = os.path.splitext(filename)
        new_name = generate_random_name() + ext
        os.rename(filename, new_name)
        print(f"renamed {filename} to {new_name}")

directory_path = os.path.join(os.getcwd(), "YOUR_FOLDER_NAME") # keep empty if script is inside the folder with files already
rename_files_to_random(directory_path)
