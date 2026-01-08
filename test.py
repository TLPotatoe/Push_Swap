import os
import sys
import random


def gen_numbers(min: int, max: int, n: int) -> list[int]:
    numbers = []
    while (len(numbers) < n):
        num = random.randint(min, max)
        if not num in numbers:
            numbers.append(num)
    return numbers


def main():
    if len(sys.argv) < 2:
        sys.argv.append("10")
    command = os.path.dirname(__file__) + "/push_swap"
    for num in gen_numbers(1, 15000, int(sys.argv[1])):
        command += " " + str(num)
    if "print" in sys.argv:
        print(command[command.find("./"):])
    else:
        with open("numbers.txt", "w") as f:
            f.write(command[command.find(
                "./push_swap ") + len("./push_swap "):])
        os.system(command)


if __name__ == '__main__':
    # os.system("clear" if sys.platform == "linux" else "cls")
    main()

    # https://vscza.itch.io/push-swap
    # https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

    # cheapest
    # ft_printf("%d %d %d %d %d\n", stack_b->stack[i], cost_top(stack_b, i),
    # 	stack_a->stack[next_target(stack_a, stack_b->stack[i])],
    # 	cost_top(stack_a, next_target(stack_a, stack_b->stack[i])),
    # 	cost_top(stack_b, i) + cost_top(stack_a, next_target(stack_a,
    # 			stack_b->stack[i])));
