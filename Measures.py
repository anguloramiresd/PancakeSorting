import subprocess

subprocess.run(["mkdir build"], shell=True, cwd=".")
subprocess.run(["cmake .."], shell=True, cwd="./build")
subprocess.run(["make"], shell=True, cwd="./build")

for i in range(1,100):
    s = subprocess.check_output(["./PancakeSorting"], shell=True, cwd="./build", text=True, input="1 4 7")
    a = s
    print(a)