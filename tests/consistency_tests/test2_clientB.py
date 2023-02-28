#! /usr/bin/env python3

import os
import fs_util
import sys
import logging
import test2_clientA as test1  # Simply do not want to do test1_common
'''
This is ClientB.
'''
#logging.basicConfig(filename='/tmp/app.log', filemode='w', format='%(name)s - %(levelname)s - %(message)s')
print("outside main")

def run_test():
    #logging.basicConfig(filename='/tmp/app.log', encoding='utf-8', level=logging.DEBUG)
    #logging.basicConfig(filename='/tmp/fs/app.log', filemode='w', format='%(name)s - %(levelname)s - %(message)s')
    print("before signal")
    signal_name_gen = fs_util.get_fs_signal_name()
    #f = open("/tmp/myfile.txt", "a+")
    cur_signal_name = next(signal_name_gen)
    logging.debug(str(cur_signal_name))
    logging.debug(str(test1.TEST_CASE_NO))
    fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                               f'START fname:{test1.FNAME}')
    print("after 1 record")
    print(test1.TEST_CASE_NO)
    print("In run test B after first record result")
    fs_util.wait_for_signal(cur_signal_name)
    print("after wait")

    # first execution, read all-zero file
    if not fs_util.path_exists(test1.FNAME):
        print(str(test1.FNAME))
        fs_util.record_test_result(test1.TEST_CASE_NO, 'B', 'not exist')
        sys.exit(1)

    print(test1.FNAME)
    fd = fs_util.open_file(test1.FNAME)
    read_len = 32768
    read_str = fs_util.read_file(fd, read_len, 0)
    print(len(read_str))
    print(read_len)
    if len(read_str) != read_len:
        print("read str not eual to real len")
        fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                                   f'read_len:{len(read_str)}')
        sys.exit(1)
    for rc in read_str:
        print(rc)
        if rc != '0':
            fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                                       f'read_str:{read_str}')
            sys.exit(1)
    
    # let's do some write
    print("before write")
    print("Starting to write into B")
    cur_str = fs_util.gen_str_by_repeat('b', 100)
    print("Actual write")
    try:
        ret = fs_util.write_file(fd, cur_str, start_off=100)
    except:
        ret = -1
        print("Client crashed on B")
    print("after write")
    fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                               f'Finish Read and Write of b')
    # suppose to flush
    #fs_util.close_file(fd)
    print("afetr flush")

if __name__ == '__main__':
    run_test()
