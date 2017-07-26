import argparse, os, sys
from modules import utils

parser = argparse.ArgumentParser(description='Skrypt do dzielenia pliku na mniejsze')
parser.add_argument('input_file', help='Ścieżka do pliku wejściowego')
parser.add_argument('output_dir', help='Ścieżka do folderu wyjściowego')

args = parser.parse_args()

input_contents = ''

with open(args.input_file) as f:
	for chunk in utils.read_file_chunks(f):
		input_contents += chunk
lines = input_contents.split('\n')
del input_contents
print('Znaleziono {} linii w pliku wejściowym'.format(len(lines)))

while True:
	try:
		lines_per_file = int(input('Podaj ilość linii na plik: '))
		break
	except ValueError:
		print('To musi być liczba!')

utils.mkdir(args.output_dir)

chunks = [lines[i:i + lines_per_file] for i in range(0, len(lines), lines_per_file)]
for i, lines_chunk in enumerate(chunks):
	with open(os.path.join(args.output_dir, '{}.txt'.format(i+1)), 'wb') as f:
		for chunk in utils.read_bytes_chunks(bytes('\n'.join(lines_chunk), 'utf-8')):
			f.write(chunk)
