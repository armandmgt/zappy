import argparse
import sys

from classes import client
# noinspection PyBroadException


def get_params():
	parser = argparse.ArgumentParser(add_help=False, usage="-p <port> -n <team> [-h <host>]")
	parser.add_argument('-h', type=str, help="Host")
	try:
		parser.add_argument('-p', type=int, help="Port number")
		parser.add_argument('-n', type=str, help="Team name")
		args = parser.parse_args()
		assert args.p > 0 and len(args.n) > 0
	except Exception:
		sys.exit(1)
	return args


if __name__ == "__main__":
	params = get_params()
	c = client.Client(port=params.p, name=params.n, host=params.h if params.h is not None else "127.0.0.1")
