import argparse
import sys

from classes.AI import AI
from classes.client import Client


def get_params():
	parser = argparse.ArgumentParser(add_help=False, usage='-p <port> -n <team> [-h <host>]')
	parser.add_argument('-h', type=str, help='Host')
	try:
		parser.add_argument('-p', type=int, help='Port number')
		parser.add_argument('-n', type=str, help='Team name')
		args = parser.parse_args()
		assert args.p > 0 and len(args.n) > 0
	except (argparse.ArgumentError, AssertionError, TypeError):
		sys.exit(1)
	return args


def run_game(c: Client):
	c.connect()
	welcome = c.responses.get()
	if welcome != 'WELCOME':
		raise RuntimeError('invalid x message; got:\t', welcome)
	c.write(c.team)
	c.get_initial_data()
	ai = AI(c)
	while c.r_th.isAlive():
		ai.make_decision()


if __name__ == '__main__':
	params = get_params()

	client = Client(port=params.p, name=params.n, host=params.h if params.h is not None else '127.0.0.1')
	run_game(client)
