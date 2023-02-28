#! /usr/bin/env python3

import os
import fs_util
import sys
import logging
import test1_clientA as test1  # Simply do not want to do test1_common
'''
This is ClientB.
'''
#logging.basicConfig(filename='/tmp/app.log', filemode='w', format='%(name)s - %(levelname)s - %(message)s')
print("outside main")

def run_test():
    #logging.basicConfig(filename='/tmp/app.log', encoding='utf-8', level=logging.DEBUG)
    logging.basicConfig(filename='/tmp/app.log', filemode='w', format='%(name)s - %(levelname)s - %(message)s')
    logging.debug("before signal")
    signal_name_gen = fs_util.get_fs_signal_name()
    f = open("/tmp/myfile.txt", "a+")
    cur_signal_name = next(signal_name_gen)
    f.write(str(cur_signal_name))
    f.write(str(test1.TEST_CASE_NO))
    fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                               f'START fname:{test1.FNAME}')
    logging.debug("after 1 record")
    logging.debug(test1.TEST_CASE_NO)
    logging.debug("In run test B after first record result")
    fs_util.wait_for_signal(cur_signal_name)
    logging.debug("after wait")

    # first execution, read all-zero file
    if not fs_util.path_exists(test1.FNAME):
        f.write(str(test1.FNAME))
        fs_util.record_test_result(test1.TEST_CASE_NO, 'B', 'not exist')
        sys.exit(1)

    fd = fs_util.open_file(test1.FNAME)
    read_len = 32768
    read_str = fs_util.read_file(fd, read_len, 0)
    logging.debug(len(read_str))
    if len(read_str) != read_len:
        f.write("read str not eual to real len")
        fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                                   f'read_len:{len(read_str)}')
        sys.exit(1)
    for rc in read_str:
        if rc != '0':
            fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                                       f'read_str:{read_str}')
            sys.exit(1)

    # let's do some write
    print("before write")
    cur_str = fs_util.gen_str_by_repeat('b', 100)
    f.write("Curr str:")
    f.write(str(cur_str))
    print("Curr str:", str(cur_str))
    fs_util.write_file(fd, cur_str, start_off=100)
    print("after write")
    fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                               f'Finish Read and Write of b')
    # suppose to flush
    fs_util.close_file(fd)
    print("afetr flush")
    last_signal_name = cur_signal_name
    cur_signal_name = next(signal_name_gen)
    fs_util.wait_for_signal(cur_signal_name, last_signal_name=last_signal_name)

    fd = fs_util.open_file(test1.FNAME)
    cur_str = fs_util.read_file(fd, 300)
    if len(cur_str) != 300:
        fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                                   f'read_len:{len(cur_str)}')
    for idx, c in enumerate(cur_str):
        if idx < 100:
            if c != 'a':
                fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                                           f'idx:{idx} c:{c}')
                sys.exit(1)
        elif idx < 200:
            if c != 'b':
                fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                                           f'idx:{idx} c:{c}')
                sys.exit(1)
        else:
            if c != '0':
                fs_util.record_test_result(test1.TEST_CASE_NO, 'B',
                                           f'idx:{idx} c:{c}')
                sys.exit(1)
    # done
    fs_util.record_test_result(test1.TEST_CASE_NO, 'B', 'OK')
    f.close()

def test_client_crash():
    print("Client crash")
    if not fs_util.path_exists("/tmp/fs/test_consistency"):
        fs_util.mkdir("/tmp/fs/test_consistency")
    FNAME = "/tmp/fs/test_consistency/case2"
    if not fs_util.path_exists(FNAME):
        fs_util.create_file(FNAME)
    print("File created")
    fd = fs_util.open_file(FNAME)
    cur_str = fs_util.gen_str_by_repeat('a',100)
    print("Starting write")
    try:
        ret = fs_util.write_file(fd, cur_str)
    except:
        ret = -1
        print("Client killed")
    print("Bytes written:", ret)
    if ret > 0:
        print("Fail")
    else:
        print("Success")

def test_server_crash():
    print("Server crash")
    if not fs_util.path_exists("/tmp/fs/test_consistency"):
        fs_util.mkdir("/tmp/fs/test_consistency")
    FNAME = "/tmp/fs/test_consistency/case2"
    if not fs_util.path_exists(FNAME):
        fs_util.create_file(FNAME)
    print("File created")
    fd = fs_util.open_file(FNAME)
    cur_str = fs_util.gen_str_by_repeat('a',100)
    print("Starting write")
    try:
        ret = fs_util.write_file(fd, cur_str)
    except:
        ret = -1
        print("Client killed")
    print("Bytes written:", ret)
    if ret > 0:
        print("Fail")
    else:
        print("Success")



if __name__ == '__main__':
    test_client_crash()
    test_server_crash()
    #run_test()
