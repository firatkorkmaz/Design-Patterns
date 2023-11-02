# Decorator and Facade Design Patterns #

# Using Decorators to Modify Functions: Automatic Time Print #

from time import time
from random import randint as rand


class Decorators:
    def timer_func(func):
        def wrap_func(*args, **kwargs):
            t1 = time()
            result = func(*args, **kwargs)
            t2 = time()
            print(f"\nFunction '{func.__name__}{args}' is executed in {(t2-t1):.6f}s\n")
            return result
        return wrap_func


@(Decorators.timer_func)                    # Activating the timer_func Decorator from the Decorators Class
def randomatrix(row: int, col: int):
    ls = []
    temp = []
    for i in range(row):
        for j in range(col):
            temp.append(rand(0, 9))
        ls.append(temp.copy())
        temp.clear()
    return ls


m=4; n=5
matrix = randomatrix(m, n)            # Calling the randomatrix() Function Calls timer_func() Automatically

print(f"{m}x{n} Matrix:")
for row in matrix:
    for col in row:
        print(col, " ", end="")
    print()


print(end="\n----------------------------\n\n") ####################


# Using Decorators to Modify Functions: Optional Time Print #

from time import time


class Decorators:
    def timer_func(func):
        def wrap_func(*args, **kwargs):
            t1 = time()
            result = func(*args, **kwargs)
            t2 = time()
            #print(f"Function '{func.__name__}{args}' executed in {(t2-t1):.6f}s\n")  # Cancel Automatic Time Print
            return [result, f"{(t2-t1):.6f}"]  # This Makes Any Function Return A List : [return value, time spent]
        return wrap_func


@(Decorators.timer_func)                            # Activating the timer_func Decorator from the Decorators Class
def factoriel(num: int):
    def factorec(num: int):
        if(num > 0):
            return num * factorec(num-1) 
        else: return 1
    return factorec(num)

x = 700
result = factoriel(x)             # The factoriel() Function is Forced to Return a List: [result value, time spent]
print(f"factoriel({x}) = {result[0]}")                                     # Result of the Factoriel Function
print(f"\nfactoriel({x}) is calculated in {result[1]}s")                   # Execution Time is Extracted Optionally


print(end="\n----------------------------\n\n") ####################


# Using Decorators to Modify Facade Methods: Optional Time Print #

from time import time


class Decorators:
    def timer_func(func):
        def wrap_func(*args, **kwargs):
            t1 = time()
            result = func(*args, **kwargs)
            t2 = time()
            #print(f"Function '{func.__name__}{args}' executed in {(t2-t1):.6f}s\n")  # Cancel Automatic Time Print
            return [result, f"{(t2-t1):.6f}"]  # This Makes Any Function Return A List : [return value, time spent]
        return wrap_func

    
class Computer():
    class Loading:
        def load(self):
            print("1.Loading Raw Data...")
            for i in range(100000):
                for j in range(100):
                    pass


    class Processing:
        def process(self):
            print("2.Processing Raw Data...")
            for i in range(40000):
                for j in range(100):
                    pass


    class Saving:
        def save(self):
            print("3.Saving Processed Data...")
            for i in range(30000):
                for j in range(100):
                    pass
    
    
class Process():
    ##### Facade #####
    def __init__(self):
        self.computer = Computer()
        self.loading = self.computer.Loading()
        self.processing = self.computer.Processing()
        self.saving = self.computer.Saving()
        
    @(Decorators.timer_func)                  # Activating the timer_func Decorator from the Decorators Class
    def startProcess(self):
        print("Starting the Process!")
        self.loading.load()
        self.processing.process()
        self.saving.save()
        value = "Process Completed."         # Returning A Value
        return value


if __name__ == "__main__":
    process = Process()                      # The Class that Contains the Facade Method
    result = process.startProcess()          # The 1st Element is either A Returned Value or None
    print(result[0])                         # The 1st Element is the Returned Value If It is Provided
    print(f"\nFinished in: {result[1]}s")    # The 2nd Element is the Time Spent, Provided by the Decorator