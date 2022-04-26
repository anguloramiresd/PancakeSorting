import subprocess

subprocess.run(["mkdir build"], shell=True, cwd=".")
subprocess.run(["cmake .."], shell=True, cwd="./build")
subprocess.run(["make"], shell=True, cwd="./build")

for i in range(1,10):
    s = subprocess.check_output(["./PancakeSorting"], shell=True, cwd="./build", text=True, input="2 7")
    a = s
    print(a)