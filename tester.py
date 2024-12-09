import sys, time, random, subprocess
from colorama import Fore
from os.path import exists

PUSH_SWAP_PATH = "./push_swap"
CHECKER_PATH = "./checker"
for path in ["./checker", "./checker_linux", "./checker_Mac"]:
	if (exists(path)):
		CHECKER_PATH = path
		break

MIN_VALUE = -2147483648
MAX_VALUE = 2147483647
LINE_LIMIT = 5500

def print_color(text, color, end="\n"):
	print(color + text + Fore.RESET, end=end)

def run_commands(arg_string):
	start_time = time.time()
	push_swap_process = subprocess.run(f'{PUSH_SWAP_PATH} {arg_string}', shell=True, capture_output=True, text=True)
	execution_time = time.time() - start_time

	output = push_swap_process.stdout.strip()
	num_lines_count = len(output.split('\n')) if output else 0

	checker_process = subprocess.run(f'{CHECKER_PATH} {arg_string}', input=push_swap_process.stdout, shell=True, capture_output=True, text=True)
	checker_output = checker_process.stdout.strip()

	return num_lines_count, checker_output, execution_time

def main():
	iterations = 20
	if len(sys.argv) == 2:
		try: # negative number -> infinity
			iterations = int(sys.argv[1])
		except ValueError:
			pass

	print_color(f"Running {iterations if iterations >= 0 else 'Infinite'} number of test\n", Fore.GREEN)

	warning_number = 0
	test_number = 0

	while test_number < iterations or iterations < 0:
		length = random.randint(1, 500)
		num_list = random.sample(range(MIN_VALUE, MAX_VALUE + 1), length)
		arg_string = ' '.join(map(str, num_list))

		num_lines, checker_output, execution_time = run_commands(arg_string)

		if iterations > 0:
			print_color(f"List len: {len(num_list)}", Fore.CYAN)
			print_color(f"Number of lines: {num_lines}", Fore.LIGHTBLUE_EX)
			if num_lines > LINE_LIMIT:
				print_color(" ---------- WARNING TO MANY LINE ----------", Fore.YELLOW)
				warning_number += 1
			print_color(f"Checker output: {checker_output}", Fore.MAGENTA)
			print_color(f"Execution time: {execution_time:.4f} seconds", Fore.LIGHTGREEN_EX)

		if checker_output != "OK":
			print_color("\nError: Checker output is 'KO'.\nList: ", Fore.RED, end="")
			print_color(arg_string, Fore.WHITE)
			sys.exit(1)

		if iterations > 0:
			print()
		test_number += 1

	print_color("All test are OK.", Fore.GREEN)
	if warning_number > 0:
		print_color(f"Warning count: {warning_number} ({((test_number - warning_number) / test_number * 100):.1f}% tests are below the limit)", Fore.YELLOW)

if __name__ == "__main__":
	main()
