#!/usr/bin/python3
'''Module to read from stdin and compute metrics'''
import sys

total_size = 0
status_codes = {'200': 0, '301': 0,
                '400': 0, '401': 0,
                '403': 0, '404': 0,
                '405': 0, '500': 0}


def parse_line(line):
    '''Parses a line of log input.

    Args:
    line (str): line from the input logs.

    Returns:
    tuple: A tuple containing the IP address, request type,
           status code, and file size.
    '''
    try:
        # IPアドレスを取得
        ip = line.split(' - ')[0]

        # "GET /projects/260 HTTP/1.1" の部分を取得
        request = line.split("\"")[1]

        # ステータスコードとサイズを取得
        status_size = line.split()[-2:]
        status, size = status_size

        return ip, request, status, size
    except Exception:
        return None, None, None, None


try:
    count = 0  # 行カウント
    for line in sys.stdin:
        count += 1

        ip, request, status, size = parse_line(line)

        if request == "GET /projects/260 HTTP/1.1":
            total_size += int(size)
            status_codes[status] += 1

        if count % 10 == 0:
            print(f'File size: {total_size}')
            for code, times in sorted(status_codes.items()):
                if times:
                    print(f'{code}: {times}')
              
except KeyboardInterrupt:
    pass

finally:
    print(f'File size: {total_size}')
    for code, times in sorted(status_codes.items()):
        if times:
            print(f'{code}: {times}')
