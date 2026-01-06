import os
import random

def main():
    command = os.path.dirname(__file__) + "/push_swap"
    for i in range(20):
        if i % 2:
            command += " " + str(random.randint(1, 9))
    print(command)
    os.system(command)

if __name__ == '__main__':
    main()
    
    # https://vscza.itch.io/push-swap
    # https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0