import subprocess

subprocess.run(["mkdir", "build"], shell=True, cwd=".")
subprocess.run(["ccmake", ".."], shell=True, cwd="./build")
subprocess.run(["make"], shell=True, cwd="./build")

print("Starting run...")
s = subprocess.check_output(["./PancakeSorting"], 
                            shell=True, cwd="./build", text=True, input="4 7")
a = list(s.decode("utf-8").split())
a = [int(x) for x in a]
print(a)