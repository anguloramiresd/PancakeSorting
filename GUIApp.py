from tkinter import *
from tkinter import messagebox
from tkinter.font import Font
import subprocess
import sys
import random

def init_make():
    subprocess.run(["mkdir build"], shell=True, cwd=".")
    subprocess.run(["cmake .."], shell=True, cwd="./build")
    subprocess.run(["make"], shell=True, cwd="./build")

def random_permutation(size):
    rand_list = list(range(1, size + 1))
    random.shuffle(rand_list)
    rand_list = " ".join(list(map(str, rand_list)))
    return rand_list

def run_input(input_str):
    s = subprocess.check_output(["./Run_GUI"], shell=True, cwd="./build", text=True, input=input_str)
    return s

def show_error_input(error_str="Input given is not valid"):
    messagebox.showwarning("Non valid input", error_str)

def check_if_valid(input_str):
    try:
        splitted = list(map(int, input_str.split(' ')))
    except:
        show_error_input("Invalid input")
        return False
    
    if len(splitted) != int(permutation_size.get()):
        show_error_input("Not correct amount of values")
        return False

    for i in range(1, int(permutation_size.get()) + 1):
        if i not in splitted:
            show_error_input("Repeated values")
            return False
        else:
            splitted.remove(i)

    return True

def update_input_used(input_list):
    global input_used
    input_used.grid_forget()
    input_used = Label(frame, text="  INPUT USED: " + input_list, font=font_input)
    input_used.grid(column=1, row=6)

def run_exhaustive(input_list):
    if int(permutation_size.get()) > limit_for_exhaustive:
        return
    global randomness
    input_str = "1 " + permutation_size.get() + " "
    if randomness:
        input_list = random_permutation(int(permutation_size.get()))
    input_str += input_list

    update_input_used(input_list)

    if check_if_valid(input_list):
        s = run_input(input_str)
        messagebox.showinfo("Results exhaustive", "Took {} flips to sort those pancakes!".format(s))

def run_3approx(input_list):
    global randomness
    input_str = "2 " + permutation_size.get() + " "
    if randomness:
        input_list = random_permutation(int(permutation_size.get()))
    input_str += input_list

    update_input_used(input_list)

    if check_if_valid(input_list):
        s = run_input(input_str)
        messagebox.showinfo("Results 3-approximation", "Took {} flips to sort those pancakes!".format(s))

def run_2approx(input_list):
    global randomness
    input_str = "3 " + permutation_size.get() + " "
    if randomness:
        input_list = random_permutation(int(permutation_size.get()))
    input_str += input_list

    update_input_used(input_list)

    if check_if_valid(input_list):
        s = run_input(input_str)
        messagebox.showinfo("Results 2-approximation", "Took {} flips to sort those pancakes!".format(s))

def run_all(input_list):
    global randomness
    keep_randomness = randomness
    if randomness:
        input_list = random_permutation(int(permutation_size.get()))
        randomness = False

    update_input_used(input_list)

    if check_if_valid(input_list):
        run_exhaustive(input_list)
        run_3approx(input_list)
        run_2approx(input_list)
    randomness = keep_randomness

def check_exhaustive():
    if int(permutation_size.get()) > limit_for_exhaustive:
        button_exhaustive.grid_forget()
    else:
        button_exhaustive.grid(column=0, row=3)

def change_randomness():
    global randomness
    global input_values
    randomness = not randomness
    if(not randomness):
        input_values.grid(column=1, row=1)
    else:
        input_values.grid_forget()

if __name__ == "__main__":
    init_make()
    root = Tk()
    root.title("Pancake Sorting")
    root.geometry("800x280")
    limit_for_exhaustive = 9

    frame = Frame(root)
    frame.grid()

    font_input = Font(family="Calibri", size=16)

    size_label = Label(frame, text="Size of permutation: ", font=font_input)
    size_label.grid(column=0, row=0)

    permutation_size = Spinbox(frame, from_=1, to=10000, wrap=True, font=font_input, width=8, command=check_exhaustive)
    permutation_size.grid(column=1, row=0)

    input_values = Entry(frame, width=45, font=font_input)
    input_values.grid(column=1, row=1)

    randomness = False

    check_rand = Checkbutton(frame, text="Random permutation", command=change_randomness, height=3, width=20, font=font_input)
    check_rand.grid(column=0, row=1)

    button_exhaustive = Button(frame, text="Run exhaustive algorithm", font=font_input, command=lambda: run_exhaustive(input_values.get()))
    button_exhaustive.grid(column=0, row=3)

    button_3_approx = Button(frame, text="Run 3-approximation algorithm", font=font_input, command=lambda: run_3approx(input_values.get()))
    button_3_approx.grid(column=0, row=4)

    button_2_approx = Button(frame, text="Run 2-approximation algorithm", font=font_input, command=lambda: run_2approx(input_values.get()))
    button_2_approx.grid(column=0, row=5)

    button_all = Button(frame, text="Run all algorithms", font=font_input, command=lambda: run_all(input_values.get()))
    button_all.grid(column=0, row=6)

    input_used = Label(frame, text="  INPUT USED: -", font=font_input)
    input_used.grid(column=1, row=6)

    exit_button = Button(frame, text="Exit", command=root.destroy, font=font_input)
    exit_button.grid(column=1, row = 7)

    root.mainloop()