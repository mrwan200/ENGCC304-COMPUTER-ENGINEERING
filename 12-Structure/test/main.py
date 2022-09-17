import subprocess
import argparse
import json
import os
import time

from threading import Timer

PATH = os.path.abspath(os.path.dirname(__file__))
with open(os.path.join(PATH, "case.json"), "r") as f:
    data_test = json.load(f)

def main(args):
    """
        Test case tool
        Code by: M-307

        Usage: python main.py -c <CASE>
    """
    if not args.case in data_test:
        print("Not found test case. Please check test case in \"case.json\"")
        exit(1)

    process = subprocess.Popen(
        [os.path.join(os.getcwd(), "build", "main.exe")], 
        stdin=subprocess.PIPE, 
        stdout=subprocess.PIPE
    )
    timer = Timer(5, process.kill)

    for caseData in data_test[args.case]:
        process.stdin.write(b' y')
        process.stdin.flush()
        process.stdin.write(((' {}\n').format(caseData["name"])).encode())
        process.stdin.flush()
        process.stdin.write(((' {}\n').format(caseData["salary"])).encode())
        process.stdin.flush()
        process.stdin.write(((' {}\n').format(caseData["duration"])).encode())
        process.stdin.flush()

    process.stdin.write(b' n\n')
    process.stdin.flush()

    _start = time.time()
    try:
        timer.start()
        process.wait()
    finally:
        timer.cancel()

    print("---------------[OUTPUT]---------------")
    index = 0
    has_end = False
    while True:
        line = process.stdout.readline()
        if not line:
            break
            
        text = line.rstrip().decode()
        print(text, end="\n" if has_end else "")

        if index >= len(data_test[args.case]) and not has_end:
            print(" n")
            has_end = True
            continue
        
        if "(y/N):" in text:
            print(" y")
            continue

        if "name:" in text:
            print(" {}".format(data_test[args.case][index]["name"]))
            continue

        if "(Baht/Month):" in text:
            print(" {}".format(data_test[args.case][index]["salary"]))
            continue

        if "(Year):" in text:
            print(" {}".format(data_test[args.case][index]["duration"]))
            index += 1
            continue

    print("---------------------------------------")     
    print("Done {}s".format(round(time.time()-_start, 3)))
    input("Press [ENTER] to exit.")    
    
if __name__ == "__main__":
    parser = argparse.ArgumentParser("Test case service (For lab 12)")
    parser.add_argument(
        "--case",
        "-c",
        type=str,
        required=True,
        help="Test case (Please see in JSON data)"
    )
    args = parser.parse_args()
    main(args)