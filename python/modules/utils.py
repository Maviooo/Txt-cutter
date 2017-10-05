import os
from io import BytesIO

def read_file_chunks(file_object, chunk_size=1024):
	while True:
		data = file_object.read(chunk_size)
		if not data:
			break
		yield data
def read_bytes_chunks(_bytes, chunk_size=1024):
    stream = BytesIO(_bytes)
    while True:
        data = stream.read(chunk_size)
        if not data:
            break
        yield data
def mkdir(path):
	try:
		os.mkdir(path)
	except FileExistsError:
		pass
