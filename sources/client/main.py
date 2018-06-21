import argparse
import sys

from classes.client import Client
from classes.player import Player
from common.vec import Vec2d


def get_params():
	parser = argparse.ArgumentParser(add_help=False, usage="-p <port> -n <team> [-h <host>]")
	parser.add_argument('-h', type=str, help="Host")
	try:
		parser.add_argument('-p', type=int, help="Port number")
		parser.add_argument('-n', type=str, help="Team name")
		args = parser.parse_args()
		assert args.p > 0 and len(args.n) > 0
	except argparse.ArgumentError and AssertionError:
		sys.exit(1)
	return args


if __name__ == "__main__":
	params = get_params()

	c = Client(port=params.p, name=params.n, host=params.h if params.h is not None else "127.0.0.1")
	v = Vec2d(0, 0)
	p = Player(team=c.teamName, no=0, pos=None)
